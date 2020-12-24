#pragma once
#include <iostream>
using namespace std;

class Animal
{
public:
    Animal(const size_t age = 0, const double weight = 0.1);
    void setAge(const size_t age);
    void setWeight(const double weight);
    virtual void print() const;
    virtual void eat() const abstract;
    virtual void sound() const abstract;
    virtual void type() const abstract;
private:
    size_t age;
    double weight;
};
