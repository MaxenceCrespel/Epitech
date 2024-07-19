/*
** EPITECH PROJECT, 2023
** GraphicalMode.cpp
** File description:
** GraphicalMode
*/

#include "GraphicalMode.hpp"
#include <thread>

GraphicalMode::GraphicalMode()
{
    _core = std::thread::hardware_concurrency();
    _size = 13;
    _sfTextArray = new sf::Text[_size];
    _sfTextTitle = new sf::Text[8];
    if (!_font.loadFromFile("arial.ttf"))
        std::cout << "Error, font is not loaded." << std::endl;
    _progressBarOutline = new sf::RectangleShape[_core];
    _progressBarFill =  new sf::RectangleShape[_core];
}

GraphicalMode::~GraphicalMode()
{
    delete[] _sfTextArray;
    delete[] _sfTextTitle;
}

void GraphicalMode::setSfText(int index, int size, float x, float y)
{
    _sfTextArray[index].setFont(_font);
    _sfTextArray[index].setCharacterSize(size);
    _sfTextArray[index].setFillColor(sf::Color::Magenta);
    _sfTextArray[index].setPosition(x, y);
}

void GraphicalMode::setSfTitle(int index, int size, float x, float y)
{
    _sfTextTitle[index].setFont(_font);
    _sfTextTitle[index].setCharacterSize(size);
    _sfTextTitle[index].setFillColor(sf::Color::Black);
    _sfTextTitle[index].setPosition(x, y);
}

void GraphicalMode::setSfTextString(int index, std::string str)
{
    _sfTextArray[index].setString(str);
}

void GraphicalMode::setSfTitleString(int index, std::string str)
{
    _sfTextTitle[index].setString(str);
}

void GraphicalMode::initializeSfTextArray(void)
{
    int size = 24;

    setSfText(CPU_VENDOR, size, 1180, 240);
    setSfText(CPU_MODEL, size, 1180, 310);
    setSfText(USER_NAME, size, 130, 240);
    setSfText(HOST_NAME, size, 130, 310);
    setSfText(OPERATING_SYSTEM, size, 470, 240);
    setSfText(KERNEL_VERSION, size, 470, 310);
    setSfText(DATETIME, size, 835, 80);
    setSfText(CPU_CORES, size, 830, 240);
    setSfText(CPU_ACTIVITY, size, 830, 310);
    setSfText(RECEIVE, size, 1502, 240);
    setSfText(TRANSMIT, size, 1502, 310);
    setSfText(TOTAL_MEMORY, size, 1270, 520);
    setSfText(FREE_MEMORY, size, 1210, 520);
}

void GraphicalMode::initializeTitle(void)
{
    int size = 24;

    setSfTitle(RAM, size, 850, 470);
    setSfTitle(USER, size, 180, 170);
    setSfTitle(OS, size, 540, 170);
    setSfTitle(CPU_NB, size, 890, 170);
    setSfTitle(CPU_MOD, size, 1250, 170);
    setSfTitle(CORE, size, 850, 580);
    setSfTitle(NETWORK, size, 1600, 170);
}

void GraphicalMode::initializeSfTitleArrayString()
{
    setSfTitleString(RAM, "Ram");
    setSfTitleString(USER, "User");
    setSfTitleString(OS, "Os");
    setSfTitleString(CPU_NB, "Cpu Info");
    setSfTitleString(CPU_MOD, "Cpu model");
    setSfTitleString(CORE, "Core frequency");
}

void GraphicalMode::initializeSfTextArrayString(Informations informations)
{
    auto core = informations.getCore();
    auto user = informations.getUserInfo();
    auto os = informations.getOSInfo();
    auto cpu = informations.getCPUInfo();
    auto date = informations.getDateTime();
    auto network = informations.getNetworkLoad();
    auto ram = informations.getRAMInfo();

    setSfTextString(CPU_VENDOR, core.first);
    setSfTextString(CPU_MODEL, core.second);
    setSfTextString(USER_NAME, user.first);
    setSfTextString(HOST_NAME, user.second);
    setSfTextString(OPERATING_SYSTEM, os.first);
    setSfTextString(KERNEL_VERSION, os.second);
    setSfTextString(DATETIME, date);
    setSfTextString(CPU_CORES, std::string("Core: ") + std::to_string(cpu.first).c_str());
    setSfTextString(CPU_ACTIVITY, std::string("Usage: ") + std::to_string(cpu.second).c_str() + std::string(" %"));
    setSfTextString(TOTAL_MEMORY, std::string(" "));
    setSfTextString(FREE_MEMORY, std::to_string(ram.second).c_str() + std::string("Mo / ") + std::to_string((ram.first)).c_str() + std::string("Mo"));
    setSfTextString(RECEIVE, std::string("RECEIVE: ") + std::to_string(network.first).c_str());
    setSfTextString(TRANSMIT, std::string("TRANSMIT: ") + std::to_string(network.second).c_str());
    auto tmp = informations.getInterfaceName();
    setSfTitleString(NETWORK, tmp);
}

void GraphicalMode::drawSfText(sf::RenderWindow &window)
{
    for (size_t i = 0; i < _size; i++)
        window.draw(_sfTextArray[i]);
}

void GraphicalMode::drawTitle(sf::RenderWindow &window)
{
    for (size_t i = 0; i < 7; i++)
        window.draw(_sfTextTitle[i]);
}
void displayBackground(sf::RenderWindow &window, sf::Texture &bgTexture)
{
    sf::Sprite bgSprite;
    bgSprite.setTexture(bgTexture);
    window.draw(bgSprite);
}

void GraphicalMode::initializeProgressBar(float x, float y, int offSet)
{
    sf::Vector2f barSize(200, 30);
    sf::Vector2f barPosition(0, 0);

    for (int i = 0; i < (int)_core; i++) {
        if (i < 8) {
            barPosition.x = x;
            barPosition.y = y + (i * offSet);
        } else {
            barPosition.x = x + 315;
            barPosition.y = y + ((i - 8) * offSet);
        }
        _progressBarOutline[i].setSize(barSize);
        _progressBarOutline[i].setPosition(barPosition);
        _progressBarOutline[i].setOutlineThickness(2);
        _progressBarOutline[i].setOutlineColor(sf::Color::Black);
        _progressBarOutline[i].setFillColor(sf::Color::Transparent);
        _progressBarFill[i].setSize(sf::Vector2f(0, 0));
        _progressBarFill[i].setPosition(barPosition);
        _progressBarFill[i].setFillColor(sf::Color::Green);
    }
}

void GraphicalMode::initializeRamBar(float x, float y)
{
    sf::Vector2f barSize(300, 30);
    sf::Vector2f barPosition(x, y);
    _progressBarRam.setSize(barSize);
    _progressBarRam.setPosition(barPosition);
    _progressBarRam.setOutlineThickness(2);
    _progressBarRam.setOutlineColor(sf::Color::Black);
    _progressBarRam.setFillColor(sf::Color::Transparent);
    _progressBarFillRam.setSize(sf::Vector2f(0, 0));
    _progressBarFillRam.setPosition(barPosition);
    _progressBarFillRam.setFillColor(sf::Color::Green);
}

sf::Color setColorBasedOnPercent(float percent)
{
    if (percent < 20)
        return (sf::Color::Green);
    if (percent < 40)
        return (sf::Color::Yellow);
    if (percent < 60)
        return (sf::Color(255, 180, 0));
    return (sf::Color::Red);
}

sf::Vector2f getRectanglePosition(const sf::RectangleShape& rectangle) {
    return rectangle.getPosition();
}

void GraphicalMode::fillProgressBar(Informations informations, sf::RenderWindow &window)
{
    int i = 0;
    sf::Vector2f barSize(200, 30);
    std::vector<float> activities = informations.getCoreActivity();
    sf::Text percentage;
    percentage.setFont(_font);
    percentage.setCharacterSize(16);
    percentage.setFillColor(sf::Color::Cyan);
    percentage.setString("1");
    sf::Vector2f position;
    for (auto percent : activities) {
        position = getRectanglePosition(_progressBarOutline[i]);
        position.x += 215;
        position.y += 3;
        percentage.setPosition(position);
        std::string tmp = std::to_string(percent).c_str();
        percentage.setString(tmp.substr(0, tmp.find(".")+3) + std::string(" %"));
        window.draw(percentage);
        _progressBarFill[i].setFillColor(setColorBasedOnPercent(percent));
        _progressBarFill[i].setSize(sf::Vector2f(barSize.x * (percent / 100.0f), barSize.y));
        i++;
    }
}

void GraphicalMode::draw_ram_bar(Informations informations, sf::RenderWindow &window)
{
    auto ram = informations.getRAMInfo();
    float pourcent = ((float)ram.second / (float)ram.first);
    _progressBarFillRam.setSize(sf::Vector2f(300 * (pourcent), 30));
    window.draw(_progressBarRam);
    window.draw(_progressBarFillRam);
}

void GraphicalMode::drawProgressBar(sf::RenderWindow &window)
{
    sf::Text number;
    number.setFont(_font);
    number.setCharacterSize(24);
    number.setFillColor(sf::Color::Cyan);
    number.setString("1");
    sf::Vector2f position;
    for (size_t i = 0; i < _core; i++) {
        position = getRectanglePosition(_progressBarOutline[i]);
        position.x += -27;
        number.setPosition(position);
        number.setString(std::to_string(i).c_str());
        window.draw(number);
        window.draw(_progressBarOutline[i]);
        window.draw(_progressBarFill[i]);
    }
}

int GraphicalMode::displayerGraphicalMode(void)
{
    Informations informations;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "MyGKrellm");
    initializeTitle();
    initializeSfTextArray();
    initializeProgressBar(852, 700, 40);
    initializeRamBar(890, 520);
    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("version3.png"))
    {
        std::cout << "Failed to load background image." << std::endl;
        return 1;
    }
    // Boucle principale
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Effacement de la fenêtre
        window.clear(sf::Color::Black);
        displayBackground(window, bgTexture);
        initializeSfTextArrayString(informations);
        initializeSfTitleArrayString();
        fillProgressBar(informations, window);
        draw_ram_bar(informations, window);
        drawSfText(window);
        drawTitle(window);
        drawProgressBar(window);

        // Affichage de la fenêtre
        window.display();
    }

    return 0;
}