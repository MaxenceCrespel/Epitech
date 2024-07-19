/*
** EPITECH PROJECT, 2023
** base
** File description:
** base
*/

#ifndef RECEPTIONBACKPROCESS_HPP
#define RECEPTIONBACKPROCESS_HPP

#include "base.hpp"
#include "pizzas.hpp"
#include "utils.hpp"
#include "process.hpp"
#include "safe_queue.hpp"
#include "safe_value.hpp"
#include "reception.hpp"
#include "reception_data.hpp"
#include "log_file.hpp"

class ReceptionBackProcess {
public:
    explicit ReceptionBackProcess(std::shared_ptr<SafeValue<std::shared_ptr<ReceptionData>>> receptionData);
    ~ReceptionBackProcess();

    void processBackProcess();
    void sendPizzasToKitchens();
    bool readFromFds();
    bool checkIfAllKitchensAreFull(std::list<std::pair<int, Process<int, int, double>>> &kitchens);
    void noKitchenAdding(
        std::vector<APizza> &pizzas, std::list<std::pair<int, Process<int, int, double>>> &kitchens, size_t pizzas_amount
    );
    void addPizzasToKitchens(
        std::vector<APizza> &pizzas, std::list<std::pair<int, Process<int, int, double>>> &kitchens);

    void print_InfosOfKitchens();
    void trySendStatusRequest();
private:
    std::shared_ptr<SafeValue<std::shared_ptr<ReceptionData>>> _receptionData;
};

void process_reception_backprocess(std::shared_ptr<SafeValue<std::shared_ptr<ReceptionData>>> receptionData);

#endif //RECEPTIONBACKPROCESS_HPP
