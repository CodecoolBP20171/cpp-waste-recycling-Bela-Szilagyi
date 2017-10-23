//
// Created by en on 2017.10.23..
//

#ifndef CPP_WASTE_RECYCLING_COMMANDS_H
#define CPP_WASTE_RECYCLING_COMMANDS_H

#include <iostream>
#include <vector>

/*
enum binTypes {
    DUSTBIN,
    DUSTBIN9000,
    INVALID_DUSTBIN
};
*/

enum GarbageType {
    WASTE,
    PAPER,
    PLASTIC,
    METAL,
    CAP,
    INVALID_GARBAGE
};

enum Configuration {
    NAME,
    SQUEEZE,
    CLEAN,
    COLOR,
    INVALID_CONFIG
};

enum Command {
    THROWOUT,
    EMPTY,
    HELP,
    EXIT,
    INVALID_COMMAND
};

namespace GarbageTypeStrings {
    static const std::vector<std::string> Waste = {"w", "waste"};
    static const std::vector<std::string> Paper = {"pa", "paper"};
    static const std::vector<std::string> Plastic = {"pl", "plastic"};
    static const std::vector<std::string> Metal = {"m", "metal"};
    static const std::vector<std::string> Cap = {"c", "cap"};
}

namespace ConfigurationStrings {
    static const std::vector<std::string> Name = {"n", "name"};
    static const std::vector<std::string> Squeeze = {"sq", "squeeze"};
    static const std::vector<std::string> Clean = {"cl", "clean"};
    static const std::vector<std::string> Color = {"c", "color"};
}

namespace CommandStrings {
    static const std::vector<std::string> Throwout = {"t", "throwout"};
    static const std::vector<std::string> Empty = {"e", "empty"};
    static const std::vector<std::string> Help = {"h", "help"};
    static const std::vector<std::string> Exit = {"x", "exit"};
}


#endif //CPP_WASTE_RECYCLING_COMMANDS_H
