#include <iostream>
#include <windows.h>
#include "String.h"



using namespace std;
class Var
{
private:
    int num;
    double real;
    String str;
public:
    Var(int temp)
    {
        num = temp;
        real = NULL;
        str = "";
    }
    Var(double temp)
    {
        num = NULL;
        real = temp;
        str = "";
    }
    Var(String temp)
    {
        num = NULL;
        real = NULL;
        str = temp;
    }

    const Var operator+(Var& obj);
    const Var to_string();
    const Var to_integer();
    const Var to_double();
    const Var operator+=(Var& obj);
    const Var operator-(const Var& obj);
    const Var operator-=(Var& obj);
    const Var operator*(Var& obj);
    const Var operator*=(Var& obj);
    const Var operator/(Var& obj);
    const Var operator/=(Var& obj);
    const bool operator<(Var& obj) const;
    const bool operator>(Var& obj) const;
    const Var operator>=(Var& obj) const ;
    const Var operator<=(Var& obj) const;
    const Var operator==(Var& obj) const;
    const Var operator!=(Var& obj) const ;

    friend std::ostream& operator<<(std::ostream& os,const Var& obj);
};