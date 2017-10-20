//
// Created by en on 2017.10.16..
//

#ifndef CPP_WASTE_RECYCLING_PAPERGARBAGE_H
#define CPP_WASTE_RECYCLING_PAPERGARBAGE_H


#include "Garbage.h"

class PaperGarbage : public Garbage {
public:
    PaperGarbage() {}
    PaperGarbage(std::string name)
        : Garbage(name)
        , isSqueezed(false)
    {}

    void squeeze();

    bool isSqueezed;

};


#endif //CPP_WASTE_RECYCLING_PAPERGARBAGE_H
