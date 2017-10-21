//
// Created by en on 2017.10.21..
//

#ifndef CPP_WASTE_RECYCLING_EXCEPTIONS_H
#define CPP_WASTE_RECYCLING_EXCEPTIONS_H

#include <exception>

class DustbinContentError : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "The alarm is switched on because of DustbinContentError";
    }
};

class DustbinIsFull : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "Dustbin is full! You have to empty it before throwing out any more garbage!";
    }
};


#endif //CPP_WASTE_RECYCLING_EXCEPTIONS_H
