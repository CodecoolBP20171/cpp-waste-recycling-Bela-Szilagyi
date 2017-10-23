#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <algorithm>
#include "Dustbin.h"
#include "Dustbin9000.h"
#include "Garbage.h"
#include "Exceptions.hpp"
#include "Commands.hpp"
#include "Commands.hpp"

std::string getInput(std::string &output) {
    std::cout<<output<<std::endl;
    std::string input;
    getline(std::cin, input);
    return input;
}

GarbageType inputToGarbageType(const std::string& input) {

    GarbageType garbageType = GarbageType::INVALID_GARBAGE;

    if(GarbageTypeStrings::Waste.end() !=
       std::find(GarbageTypeStrings::Waste.begin(),
                 GarbageTypeStrings::Waste.end(), input)) {
        garbageType = GarbageType ::WASTE;
    } else if(GarbageTypeStrings::Paper.end() !=
              std::find(GarbageTypeStrings::Paper.begin(),
                        GarbageTypeStrings::Paper.end(), input)) {
        garbageType = GarbageType ::PAPER;
    } else if(GarbageTypeStrings::Plastic.end() !=
              std::find(GarbageTypeStrings::Plastic.begin(),
                        GarbageTypeStrings::Plastic.end(), input)) {
        garbageType = GarbageType ::PLASTIC;
    } else if(GarbageTypeStrings::Metal.end() !=
              std::find(GarbageTypeStrings::Metal.begin(),
                        GarbageTypeStrings::Metal.end(), input)) {
        garbageType = GarbageType ::METAL;
    } else if(GarbageTypeStrings::Cap.end() !=
              std::find(GarbageTypeStrings::Cap.begin(),
                        GarbageTypeStrings::Cap.end(), input)) {
        garbageType = GarbageType::CAP;
    }
    return garbageType;
}

Configuration inputToConfiguration(const std::string& input) {

    Configuration configuration = Configuration::INVALID_CONFIG;

    if (ConfigurationStrings::Name.end() !=
        std::find(ConfigurationStrings::Name.begin(),
                  ConfigurationStrings::Name.end(), input)) {
        configuration = Configuration ::NAME;
    } else if (ConfigurationStrings::Squeeze.end() !=
               std::find(ConfigurationStrings::Squeeze.begin(),
                         ConfigurationStrings::Squeeze.end(), input)) {
        configuration = Configuration ::SQUEEZE;
    } else if (ConfigurationStrings::Clean.end() !=
               std::find(ConfigurationStrings::Clean.begin(),
                         ConfigurationStrings::Clean.end(), input)) {
        configuration = Configuration ::CLEAN;
    } else if (ConfigurationStrings::Color.end() !=
               std::find(ConfigurationStrings::Color.begin(),
                         ConfigurationStrings::Color.end(), input)) {
        configuration = Configuration ::COLOR;
    }
    return configuration;
}

Command inputToCommand(const std::string& input) {

    Command command = Command::INVALID_COMMAND;

    if (CommandStrings::Throwout.end() !=
        std::find(CommandStrings::Throwout.begin(),
                  CommandStrings::Throwout.end(), input)) {
        command = Command::THROWOUT;
    } else if (CommandStrings::Empty.end() !=
               std::find(CommandStrings::Empty.begin(),
                         CommandStrings::Empty.end(), input)) {
        command = Command::EMPTY;
    } else if (CommandStrings::Help.end() !=
               std::find(CommandStrings::Help.begin(),
                         CommandStrings::Help.end(), input)) {
        command = Command::HELP;
    } else if (CommandStrings::Exit.end() !=
               std::find(CommandStrings::Exit.begin(),
                         CommandStrings::Exit.end(), input)) {
        command = Command::EXIT;
    }
    return command;
}

void handleInvalidInput() {
    std::cout << "Invalid Input. For help type 'h' or 'help'." << std::endl;
}

Configuration configureGarbage() {
    std::string output = "Please configure your garbage: ";
    return inputToConfiguration(getInput(output));
}


/*
void useDustbin(Garbage &garbage, GarbageType &garbageType) {
    Dustbin9000 d9000;
    std::string output = "Please use the dustbin: ";
    Command command = inputToCommand(getInput(output));
    if ( command = Command::THROWOUT ) {
        switch (garbageType) {
            case WASTE : {
                d9000.throwOutGarbage(garbage);
                break;
            }
            case PAPER : {
                d9000.throwOutPaperGarbage( (PaperGarbage)garbage );
                break;
            }
            case PLASTIC : {
                d9000.throwOutPaperGarbage(garbage);
                break;
            }
            case METAL : {

            }
        }
    }
}
*/
static const std::map<std::string, std::vector<std::string> > Commands = {
        {"Garbage type: waste", GarbageTypeStrings::Waste},
        {"Garbage type: paper", GarbageTypeStrings::Paper},
        {"Garbage type: plastic", GarbageTypeStrings::Plastic},
        {"Garbage type: metal", GarbageTypeStrings::Metal},
        {"Garbage type: cap", GarbageTypeStrings::Cap},
        {"Garbage configuration: squeeze", ConfigurationStrings::Squeeze},
        {"Garbage configuration: clean", ConfigurationStrings::Clean},
        {"Dustbinn commands: throwout", CommandStrings::Throwout},
        {"Dustbinn commands: empty", CommandStrings::Empty},
        {"Dustbinn commands: help", CommandStrings::Help},
        {"Dustbinn commands: exit", CommandStrings::Exit},
};

void printHelp() {
    for(const auto& helpInfo : Commands){
        std::cout << helpInfo.first << ":\t";
        for(int i = 0; i < helpInfo.second.size(); ++i){
            std::cout << helpInfo.second[i];
            if(i != helpInfo.second.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool handleConsoleInterface() {
    Dustbin9000 d9000;
    std::string output = "Please input garbage type: ";
    std::string input = getInput(output);
    std::string name;
    std::string color;
    Garbage garbage;
    GarbageType garbageType = inputToGarbageType(input);
    if (GarbageType::INVALID_GARBAGE != garbageType) {
        output = "Please input garbage name: ";
        name = getInput(output);
        output = "Please input command: ";
        Command command = inputToCommand(getInput(output));
        switch (command) {
            case EXIT : {
                return false;
            }
            case EMPTY : {
                d9000.emptyContents();
                return true;
            }
            case HELP : {
                printHelp();
                return true;
            }
            case THROWOUT : {
                try {
                    switch (garbageType) {
                        case WASTE : {
                            Garbage g(name);
                            d9000.throwOutGarbage(g);
                            std::cout<<g.getName()<<" thrown out."<<std::endl;
                            break;
                        }
                        case PAPER : {
                            PaperGarbage g(name);
                            output = "Configuration?";
                            Configuration configuration = inputToConfiguration(getInput(output));
                            if (configuration == Configuration::SQUEEZE) {
                                g.squeeze();
                            }
                            try {
                                d9000.throwOutPaperGarbage(g);
                                std::cout<<g.getName()<<" thrown out."<<std::endl;
                            } catch (DustbinContentError &err) {
                                std::cout << err.what() << std::endl;
                            }
                            break;
                        }
                        case PLASTIC : {
                            PlasticGarbage g(name);
                            output = "Configuration?";
                            Configuration configuration = inputToConfiguration(getInput(output));
                            if (configuration == Configuration::CLEAN) {
                                g.clean();
                            }
                            try {
                                d9000.throwOutPlasticGarbage(g);
                                std::cout<<g.getName()<<" thrown out."<<std::endl;
                            }
                            catch (DustbinContentError &err) {
                                std::cout << err.what() << std::endl;
                            }
                            break;
                        }
                        case METAL : {
                            MetalGarbage g(name);
                            d9000.throwOutMetalGarbage(g);
                            std::cout<<g.getName()<<" thrown out."<<std::endl;
                            break;
                        }
                        case CAP : {
                            output = "Color?";
                            color = getInput(output);
                            BottleCap g(name, color);
                            try {
                                d9000.throwOutBottleCap(g);
                                std::cout<<g.getName()<<" thrown out."<<std::endl;
                            } catch (BottleCapException &err) {
                                std::cout << err.what() << std::endl;
                            }
                            break;
                        }
                        default : {
                            return true;
                        }
                    }
                } catch (DustbinIsFull &err) {
                    std::cout<<err.what()<<std::endl;
                    return true;
                }
            }
        }
    }
}


void handleInput(const std::string &input) {
    GarbageType garbageType = inputToGarbageType(input);
    if (GarbageType ::INVALID_GARBAGE != garbageType){
        return;
    }

    Configuration configuration = inputToConfiguration(input);
    if (Configuration::INVALID_CONFIG != configuration){
        return;
    }

    Command command = inputToCommand(input);
    if (Command::INVALID_COMMAND != command) {
        return;
    }
    std::cout << "Invalid Input. For help type 'h' or 'help'." << std::endl;
}

int main(int argc, char* argv[]) {

    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    do {
    } while (handleConsoleInterface() );

    return 0;
}

//TODO console
//TODO delete comments
