/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** plazza
*/

#include "include/reception_backprocess.hpp"

ReceptionBackProcess::ReceptionBackProcess(std::shared_ptr<SafeValue<std::shared_ptr<ReceptionData>>> receptionData)
    : _receptionData(std::move(receptionData))
{
}

ReceptionBackProcess::~ReceptionBackProcess() = default;

void ReceptionBackProcess::processBackProcess()
{
    while (42) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        while (readFromFds());
        sendPizzasToKitchens();
        trySendStatusRequest();
        if (_receptionData->getValue()->getEnded())
            return;
    }
}

void ReceptionBackProcess::trySendStatusRequest()
{
    std::unique_lock<std::mutex> lock(_receptionData->getMutex());

    if (!_receptionData->getValueUnsafe()->getStatusToGet())
        return;

    auto &kitchens = _receptionData->getValueUnsafe()->getKitchens();

    auto kitchenIt = kitchens.begin();
    size_t kitchen_size = kitchens.size();

    if (kitchenIt == kitchens.end()) {
        _receptionData->getValueUnsafe()->setStatusToGet(false);
        return;
    }

    for (size_t i = 0; i < kitchen_size; i++) {
        sendStatusRequest(kitchenIt->second.getParentWriterWriteFd());
        ++kitchenIt;
    }

    _receptionData->getValueUnsafe()->setStatusToGet(false);
}

void ReceptionBackProcess::print_InfosOfKitchens()
{
    int a = 0;
    auto &kitchenPizzasAmount = _receptionData->getValueUnsafe()->getKitchenPizzasAmount();

    auto pizzaAmountIt = kitchenPizzasAmount.begin();
    if (pizzaAmountIt == kitchenPizzasAmount.end())
        return;
}

bool ReceptionBackProcess::readFromFds()
{
    std::unique_lock<std::mutex> lock(_receptionData->getMutex());

    auto &kitchens = _receptionData->getValueUnsafe()->getKitchens();
    auto &kitchenPizzasAmount = _receptionData->getValueUnsafe()->getKitchenPizzasAmount();

    auto kitchenIt = kitchens.begin();
    auto pizzaAmountIt = kitchenPizzasAmount.begin();

    size_t kitchenOffsetCounter = -1;
    bool hasRead = false;

    while (kitchenIt != kitchens.end() && pizzaAmountIt != kitchenPizzasAmount.end()) {
        kitchenOffsetCounter++;
        std::string buffer = kitchenIt->second.tryRead(1);

        if (buffer.length() == 0) {
            ++kitchenIt;
            ++pizzaAmountIt;
            continue;
        } else
            hasRead = true;

        if (buffer[0] == '9') {
            std::stringstream ss;
            ss << "Kitchen [" << std::left << std::setw(2) << std::setfill(' ') << kitchenOffsetCounter << "] Closed."
                << std::endl;
            std::cout << ss.str();
            appendToLogFile(ss.str());
            waitpid(kitchenIt->second.getPid(), nullptr, 0);

            kitchenIt = kitchens.erase(kitchenIt);
            pizzaAmountIt = kitchenPizzasAmount.erase(pizzaAmountIt);
            continue;
        }

        if (buffer[0] == '1') {
            if (!checkIfCanRead(kitchenIt->second.getChildWriterReadFd()))
                break;

            APizza pizza = receivePizza(kitchenIt->second.getChildWriterReadFd());
            std::stringstream ss;
            ss << "Pizza received: ["
                << std::left << std::setw(9) << std::setfill(' ') << revMapPizzaType[pizza.getType()]
                << " " << std::left << std::setw(3) << std::setfill(' ') << revMapPizzaSize[pizza.getSize()]
                << "] from kitchen ["
                << std::setw(2) << std::setfill(' ') << kitchenOffsetCounter << "]"
                << std::endl;
            std::cout << ss.str();
            appendToLogFile(ss.str());

            (*pizzaAmountIt)--;
        }
        if (buffer[0] == '2') {
            if (!checkIfCanRead(kitchenIt->second.getChildWriterReadFd()))
                break;

            Status status = receiveStatus(kitchenIt->second.getChildWriterReadFd(),
                _receptionData->getValueUnsafe()->getCooksNb());

            std::stringstream ss;
            ss << "Kitchen [" << std::left << std::setw(2) << std::setfill(' ') << kitchenOffsetCounter << "]"
                << " status : " << std::endl;
            std::cout << ss.str();
            appendToLogFile(ss.str());
            status.printStatus();
        }

        ++kitchenIt;
        ++pizzaAmountIt;
    }
    return hasRead;
}

void ReceptionBackProcess::sendPizzasToKitchens()
{
    std::unique_lock lock(_receptionData->getMutex());

    std::vector<APizza> &pizzas = _receptionData->getValueUnsafe()->getPizzas();
    std::list<std::pair<int, Process<int, int, double>>> &kitchens = _receptionData->getValueUnsafe()->getKitchens();
    size_t kitchens_amount = kitchens.size();
    size_t pizzas_amount = pizzas.size();

    if (pizzas.empty())
        return;

    std::stringstream ss;
    ss << "Sending [" << pizzas_amount << "] pizzas to kitchens." << std::endl;
    std::cout << ss.str();
    appendToLogFile(ss.str());

    if (kitchens_amount == 0 || checkIfAllKitchensAreFull(kitchens)) {
        noKitchenAdding(pizzas, kitchens, pizzas_amount);
        return;
    }
    addPizzasToKitchens(pizzas, kitchens);
}

void ReceptionBackProcess::addPizzasToKitchens(
    std::vector<APizza> &pizzas, std::list<std::pair<int, Process<int, int, double>>> &kitchens
)
{
    auto kitchenPizzasAmountIt = _receptionData->getValueUnsafe()->getKitchenPizzasAmount().begin();
    size_t min = *kitchenPizzasAmountIt;

    for (size_t i = 0; i < kitchens.size(); i++) {
        if (*kitchenPizzasAmountIt < min)
            min = *kitchenPizzasAmountIt;
        ++kitchenPizzasAmountIt;
    }

    auto kitchenIt = kitchens.begin();
    size_t kitchens_size = kitchens.size();

    print_InfosOfKitchens();

    while (!pizzas.empty()) {
        kitchenIt = kitchens.begin();
        kitchenPizzasAmountIt = _receptionData->getValueUnsafe()->getKitchenPizzasAmount().begin();

        if (checkIfAllKitchensAreFull(kitchens))
            return;

        for (size_t i = 0; i < kitchens_size; i++) {
            while (*kitchenPizzasAmountIt < min) {
                if (pizzas.empty())
                    return;
                if ((*kitchenPizzasAmountIt) >= _receptionData->getValueUnsafe()->getCooksNb() * 2)
                    break;
                sendPizza(pizzas.front(), (*kitchenIt).second.getParentWriterWriteFd());
                pizzas.erase(pizzas.begin());
                (*kitchenPizzasAmountIt)++;
            }
            ++kitchenPizzasAmountIt;
            ++kitchenIt;
        }
        min++;
    }
}

bool ReceptionBackProcess::checkIfAllKitchensAreFull(std::list<std::pair<int, Process<int, int, double>>> &kitchens)
{
    auto kitchenPizzasAmount = _receptionData->getValueUnsafe()->getKitchenPizzasAmount().begin();

    for (size_t i = 0; i < kitchens.size(); i++) {
        if (*kitchenPizzasAmount < _receptionData->getValueUnsafe()->getCooksNb() * 2)
            return false;
        ++kitchenPizzasAmount;
    }
    return true;
}

void ReceptionBackProcess::noKitchenAdding(
    std::vector<APizza> &pizzas, std::list<std::pair<int, Process<int, int, double>>> &kitchens, size_t pizzas_amount
)
{
    int cooks_nb = _receptionData->getValueUnsafe()->getCooksNb();
    size_t new_kitchens_needed = pizzas_amount / (cooks_nb * 2);

    if (pizzas_amount % (cooks_nb * 2) != 0)
        new_kitchens_needed++;
    for (size_t i = 0; i < new_kitchens_needed; i++) {
        if (kitchens.size() >= 99) {
            std::stringstream ss;
            ss << "Max kitchens reached, can't add more. Waiting for available kitchens (99)." << std::endl;
            std::cout << ss.str();
            appendToLogFile(ss.str());
            return;
        }
        _receptionData->getValueUnsafe()->addKitchen(cooks_nb,
            _receptionData->getValueUnsafe()->getReplaceTime(),
            _receptionData->getValueUnsafe()->getMultiplier());
        auto &kitchenPizzasAmount = _receptionData->getValueUnsafe()->getKitchenPizzasAmount();
        kitchenPizzasAmount.push_back(0);
    }
    std::stringstream ss;
    ss << "New kitchens added, amount: [" << new_kitchens_needed << "]" << std::endl;
    std::cout << ss.str();
    appendToLogFile(ss.str());

    while (!pizzas.empty()) {
        auto kitchenPizzasAmount = _receptionData->getValueUnsafe()->getKitchenPizzasAmount().begin();
        auto kitchenIt = kitchens.begin();
        size_t kitchens_size = kitchens.size();

        for (size_t i = 0; i < kitchens_size; i++) {
            if (pizzas.empty())
                break;
            if (*kitchenPizzasAmount >= cooks_nb * 2) {
                ++kitchenIt;
                ++kitchenPizzasAmount;
                continue;
            }
            try {
                sendPizza(pizzas.front(), (*kitchenIt).second.getParentWriterWriteFd());
                pizzas.erase(pizzas.begin());
                *kitchenPizzasAmount += 1;
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
            ++kitchenPizzasAmount;
            ++kitchenIt;
        }
    }
}

void process_reception_backprocess(std::shared_ptr<SafeValue<std::shared_ptr<ReceptionData>>> receptionData)
{
    ReceptionBackProcess back_process(std::move(receptionData));

    back_process.processBackProcess();
}
