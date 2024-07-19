/*
** EPITECH PROJECT, 2023
** Informations.hpp
** File description:
** informations
*/

#ifndef INFORMATIONS_HPP_
    #define INFORMATIONS_HPP_
    #include <iostream>
    #include <vector>
class Informations
{
    public:
        Informations();
        ~Informations();
        std::pair<std::string, std::string> getCore();
        std::pair<std::string, std::string> getUserInfo();
        std::pair<std::string, std::string> getOSInfo();
        std::string getDateTime();
        std::pair<int,float> getCPUInfo();
        std::pair<long long,long long> getRAMInfo();
        std::pair<long long, long long> getNetworkLoad();
        std::string getInterfaceName();
        int getPreviousCoreActivity();
        int getCurrentCoreActivity();
        std::vector<float> getCoreActivity();
        size_t getSize();

    private:
        std::string _interfaceName;
        size_t _size;
        long *_previousTotal;
        long *_previousIdled;
        long *_currentTotal;
        long *_currentIdled;

};

#endif /* !INFORMATIONS_HPP_ */
