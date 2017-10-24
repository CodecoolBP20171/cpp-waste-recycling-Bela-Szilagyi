//
// Created by en on 2017.10.24..
//

#ifndef CPP_WASTE_RECYCLING_CONSOLEINTERFACE_H
#define CPP_WASTE_RECYCLING_CONSOLEINTERFACE_H

#include <iostream>
#include <map>
#include "Commands.hpp"
#include "Dustbin9000.h"

class ConsoleInterface {
public:
    void run();
private:
    static const std::map<std::string, std::vector<std::string> > Commands;
    Dustbin9000 d9000;

    std::string getInput(std::string &output);
    GarbageType inputToGarbageType(const std::string& input);
    Configuration inputToConfiguration(const std::string& input);
    Command inputToCommand(const std::string& input);
    void printHelp();
    bool handleConsoleInterface();
};


#endif //CPP_WASTE_RECYCLING_CONSOLEINTERFACE_H
