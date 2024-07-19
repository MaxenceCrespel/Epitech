/*
** EPITECH PROJECT, 2023
** Informations.cpp
** File description:
** informations
*/

#include "Informations.hpp"
#include <unistd.h>
#include <utility>
#include <sys/utsname.h>
#include <ctime>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <thread>
#include <vector>

Informations::Informations() : _interfaceName(std::string(""))
{
    _size = std::thread::hardware_concurrency();
    _previousTotal = new long[_size];
    _previousIdled = new long[_size];
    _currentTotal = new long[_size];
    _currentIdled = new long[_size];
}

Informations::~Informations()
{
}

size_t Informations::getSize()
{
    return (_size);
}

// Function to get system information
std::pair<std::string, std::string> Informations::getCore()
{
    std::string line;
    std::ifstream file("/proc/cpuinfo");

    if (file.fail())
        return {std::string(""), std::string("")};
    if (!file.is_open())
        return {std::string(""), std::string("")};
    std::getline(file, line);
    std::string vendor = line.substr(13);
    std::getline(file, line);
    std::string model = line.substr(9);
    file.close();
    return {vendor, model};
}

std::pair<std::string, std::string> Informations::getUserInfo()
{
    char hostname[256];
    gethostname(hostname, sizeof(hostname));
    char username[256];
    getlogin_r(username, sizeof(username));
    return {username, hostname};
}

std::pair<std::string, std::string> Informations::getOSInfo()
{
    struct utsname unameData;
    uname(&unameData);
    std::string os_name(unameData.sysname);
    std::string kernel_version(unameData.release);
    return {os_name, kernel_version};
}

std::string Informations::getDateTime()
{
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
    return buffer;
}

std::pair<int,float> Informations::getCPUInfo()
{
    std::string line;
    std::ifstream file("/proc/stat");

    if (file.fail())
        return {0, 0};
    if (!file.is_open())
        return {0, 0};
    std::getline(file, line);
    std::istringstream iss(line);
    std::string cpu;
    iss >> cpu;
    long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    iss >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;
    file.close();
    long long total = user + nice + system + idle + iowait + irq + softirq + steal;
    float activity = total - idle;
    activity = activity / total * 100;
    return {sysconf(_SC_NPROCESSORS_ONLN),activity};
}

std::pair<long long,long long> Informations::getRAMInfo()
{
    std::string line;
    std::ifstream file("/proc/meminfo");

    if (file.fail())
        return {0, 0};
    if (!file.is_open())
        return {0, 0};
    std::getline(file, line);
    std::istringstream iss(line);
    std::string mem;
    iss >> mem;
    long long total_mem;
    iss >> total_mem;
    std::getline(file, line);
    iss.str(line);
    iss.clear();
    iss >> mem;
    long long free_mem;
    iss >> free_mem;
    file.close();
    return {total_mem/1024,free_mem/1024};
}

std::pair<long long, long long> Informations::getNetworkLoad()
{
    std::string line;
    std::ifstream file("/proc/net/dev");
    std::string interface;
    if (file.fail())
        return {0, 0};
    if (!file.is_open())
        return {0, 0};
    std::getline(file, line); // Ignore the first line
    std::getline(file, line); // Ignore the second line
    long long receive = 0, transmit = 0;
    long long temp1 = 0, temp2 = 0;
    while(std::getline(file, line))
    {
        std::istringstream iss(line);
        iss >> interface;
        interface = interface.substr(0, interface.length() - 1);
        long long r, t;
        iss >> temp1 >> r >> r >> r >> t >> t >> t >> t >> temp2;
        if (temp1 > receive && temp2 > transmit) {
            receive = temp1;
            transmit = temp2;
            _interfaceName = interface;
        }
        //std::cout << interface << " " << receive << " " << transmit << std::endl;
    }
    file.close();
    _interfaceName = interface;
    return {receive, transmit};
}

int Informations::getPreviousCoreActivity()
{
    std::vector<float> coreActivity;
    std::string line;
    size_t i = 0;
    std::ifstream file("/proc/stat");

    if (file.fail())
        return 84;
    if (!file.is_open())
        return 84;
    while (std::getline(file, line)) {
        if (i == _size)
            break;
        std::istringstream iss(line);
        std::string cpu;
        iss >> cpu;
        if (cpu.substr(0, 3) == "cpu") {
            long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

            iss >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;

            _previousTotal[i] = user + nice + system + irq + softirq + steal + guest + guest_nice;
            _previousIdled[i] = idle + iowait;
            i++;
        }
    }
    file.close();
    return 0;
}


int Informations::getCurrentCoreActivity()
{
    std::vector<float> coreActivity;
    std::string line;
    size_t i = 0;
    std::ifstream file("/proc/stat");

    if (file.fail())
        return 84;
    if (!file.is_open())
        return 84;
    while (std::getline(file, line)) {
        if (i == _size)
            break;
        std::istringstream iss(line);
        std::string cpu;
        iss >> cpu;
        if (cpu.substr(0, 3) == "cpu") {
            long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

            iss >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;

            _currentTotal[i] = user + nice + system + irq + softirq + steal + guest + guest_nice;
            _currentIdled[i] = idle + iowait;
            i++;
        }
    }
    file.close();
    return 0;
}

std::vector<float> Informations::getCoreActivity()
{
    std::vector<float> coreActivity;
    getPreviousCoreActivity();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    getCurrentCoreActivity();
    float activity;
    float tmpTotal;
    float tmpIdled;

    for (int i = 0; i < (int)_size; i++) {
        tmpTotal = _currentTotal[i] - _previousTotal[i];
        tmpIdled = _currentIdled[i] - _previousIdled[i];
        activity = (tmpTotal / (tmpTotal + tmpIdled)) * 100;
        coreActivity.push_back(activity);
    }
    return coreActivity;
}

std::string Informations::getInterfaceName()
{
    return (_interfaceName);
}