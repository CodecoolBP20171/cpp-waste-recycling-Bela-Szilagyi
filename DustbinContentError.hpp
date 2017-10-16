//
// Created by en on 2017.10.16..
//

#ifndef CPP_WASTE_RECYCLING_DUSTBINCONTENTERROR_H
#define CPP_WASTE_RECYCLING_DUSTBINCONTENTERROR_H

#include <iostream>
#include <exception>

class DustbinContentError : public std::exception {
    virtual const char* what() const noexcept {
        return "The alarm is switched on because of DustbinContentError";
    }
};


#endif //CPP_WASTE_RECYCLING_DUSTBINCONTENTERROR_H
