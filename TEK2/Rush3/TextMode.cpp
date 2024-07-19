/*
** EPITECH PROJECT, 2023
** B-PDG-300-LIL-3-1-PDGRUSH3-mahe.fauvart
** File description:
** test
*/

#include <iostream>
#include <unistd.h>
#include <utility>
#include <sys/utsname.h>
#include <ctime>
#include <fstream>
#include <sstream>
#include <ncurses.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include "GraphicalMode.hpp"
#include "Informations.hpp"

// Function to get system information

std::pair<std::string, std::string> getUserInfo()
{
    char hostname[256];
    gethostname(hostname, sizeof(hostname));
    char username[256];
    getlogin_r(username, sizeof(username));
    return {username, hostname};
}

std::pair<std::string, std::string> getOSInfo()
{
    struct utsname unameData;
    uname(&unameData);
    std::string os_name(unameData.sysname);
    std::string kernel_version(unameData.release);
    return {os_name, kernel_version};
}

std::string getDateTime()
{
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
    return buffer;
}

void print_cpu(Informations informations)
{
    int i = 0;
    sf::Vector2f barSize(300, 30);
    std::vector<float> activities = informations.getCoreActivity();
    mvprintw(10, 142, "CORE");
    for (auto percent : activities) {
        mvprintw((i * 2) + 11, 130, std::to_string(i).c_str());
        int j = 0;
        while (j < percent / 5) {
            init_pair(3, COLOR_GREEN, COLOR_GREEN);
            attron(COLOR_PAIR(3));
            mvprintw((i * 2) + 11, 133 + j, "-");
            j++;
            attroff(COLOR_PAIR(3));
        }
        mvprintw((i * 2) + 11, 150, std::to_string(percent).c_str());
        i += 1;
    }
}

int displayTextMode()
{
    Informations informations;
    initscr();
    start_color();
    while (true)
    {
        move(8, 75);
        for (int i = 0; i < 89; i++) {
            attron(COLOR_PAIR(1));
            addch(' ');
            attroff(COLOR_PAIR(1));
        }
        for (int j = 0; j < 32; j++) {
            move(9 + j, 75);
            attron(COLOR_PAIR(1));
            addch(' ');
            addch(' ');
            attroff(COLOR_PAIR(1));
                for (int i = 0; i < 85; i++)
                    addch(' ');
            attron(COLOR_PAIR(1));
            addch(' ');
            addch(' ');
            attroff(COLOR_PAIR(1));
        }
        move(41, 75);
        for (int i = 0; i < 89; i++) {
            attron(COLOR_PAIR(1));
            addch(' ');
            attroff(COLOR_PAIR(1));
        }
        auto core = informations.getCore();
        auto user = informations.getUserInfo();
        auto os = informations.getOSInfo();
        auto network = informations.getNetworkLoad();
        auto interface = informations.getInterfaceName();
        init_pair(1, COLOR_WHITE, COLOR_RED);
        attron(COLOR_PAIR(1));
        mvprintw(11, 85, "CPU Model");
        mvprintw(14, 85, "Username");
        mvprintw(16, 85, "Hostname");
        mvprintw(19, 85, "Operating System");
        mvprintw(21, 85, "Kernel version");
        mvprintw(24, 85, "CPU Cores");
        mvprintw(26, 85, "CPU Activity");
        mvprintw(29, 85, "Total memory");
        mvprintw(31, 85, "Free memory");
        mvprintw(34, 85, interface.c_str());
        mvprintw(36, 90, "Receive");
        mvprintw(38, 90, "Transmit");
        attroff(COLOR_PAIR(1));
        init_pair(6, COLOR_BLACK, COLOR_WHITE);
        attron(COLOR_PAIR(6));
            mvprintw(4, 110, getDateTime().c_str());
        attroff(COLOR_PAIR(6));
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
        attron(COLOR_PAIR(2));
        mvprintw(11, 105, core.second.c_str());
        mvprintw(14, 105, user.first.c_str());
        mvprintw(16, 105, user.second.c_str());
        mvprintw(19, 105, os.first.c_str());
        mvprintw(21, 105, os.second.c_str());
        mvprintw(24, 105, std::to_string(informations.getCPUInfo().first).c_str());
        mvprintw(26, 105, std::to_string(informations.getCPUInfo().second).c_str());
        mvprintw(29, 105, std::to_string(informations.getRAMInfo().first).c_str());
        mvprintw(31, 105, std::to_string(informations.getRAMInfo().second).c_str());
        mvprintw(36, 110, std::to_string(network.first).c_str());
        mvprintw(38, 110, std::to_string(network.second).c_str());
        attroff(COLOR_PAIR(2));
        print_cpu(informations);
        refresh();
    }
    endwin();
    return 0;
}
