/*
** EPITECH PROJECT, 2023
** GraphicalMode.hpp
** File description:
** GraphicalMode
*/

#ifndef GRAPHICALMODE_HPP_
    #define GRAPHICALMODE_HPP_
    #include "Informations.hpp"
    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include <iostream>
    #include <unistd.h>
    #include <utility>
    #include <sys/utsname.h>
    #include <ctime>
    #include <fstream>
    #include <sstream>

class GraphicalMode {
    public:
        GraphicalMode();
        ~GraphicalMode();

        enum sfTextIndex {
            CPU_VENDOR,
            CPU_MODEL,
            USER_NAME,
            HOST_NAME,
            OPERATING_SYSTEM,
            KERNEL_VERSION,
            DATETIME,
            CPU_CORES,
            CPU_ACTIVITY,
            TOTAL_MEMORY,
            FREE_MEMORY,
            RECEIVE,
            TRANSMIT
        };
        enum sfTextTitle {
            RAM,
            USER,
            OS,
            CPU_NB,
            CPU_MOD,
            CORE,
            NETWORK
        };
        void draw_ram_bar(Informations informations, sf::RenderWindow &window);
        void initializeRamBar(float x, float y);
        void initializeSfTitleArrayString();
        void setSfText(int index, int size, float x, float y);
        void setSfTextString(int index, std::string str);
        void initializeSfTextArray(void);
        void initializeTitle(void);
        void initializeSfTextArrayString(Informations informations);
        void setSfTitle(int index, int size, float x, float y);
        void setSfTitleString(int index, std::string str);
        void drawTitle(sf::RenderWindow &window);
        void initializeProgressBar(float x, float y, int offSet);
        void fillProgressBar(Informations informations, sf::RenderWindow &window);
        void drawProgressBar(sf::RenderWindow &window);
        void drawSfText(sf::RenderWindow &window);
        int displayerGraphicalMode(void);

    protected:
    private:
        size_t _size;
        size_t _core;
        sf::Font _font;
        sf::Text *_sfTextArray;
        sf::Text *_sfTextTitle;
        sf::RectangleShape *_progressBarOutline;
        sf::RectangleShape *_progressBarFill;
        sf::RectangleShape _progressBarRam;
        sf::RectangleShape _progressBarFillRam;
};

#endif /* !GRAPHICALMODE_HPP_ */
