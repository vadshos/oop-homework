#pragma once
#include <iostream>

class Shooter
{
protected:
    void shot();
    Shooter(const std::string& NameAmunition, const size_t& countAmunition);
    void addAmunition(const std::string& NameAmunition ,const size_t& countAmunition );
    size_t getCount() const;
    void setCount(const size_t& countAmunition);
private:
    std::string NameAmunition;
    size_t countAmunition;
};

