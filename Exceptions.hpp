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

class BottleCapException : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "Sorry, but it is a non-pink cap, therefore I have to fire it back to your face. You should run!";
    }
};

#endif //CPP_WASTE_RECYCLING_EXCEPTIONS_H
