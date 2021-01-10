#include <iostream>
#include <string>
#include"String.h"
#include "var.h"

int main()
{
    String t("dsfs");
    Var a = 15;
    Var b = t;
    t = "ds34";
    Var c = 7.8;
    Var d = t;
    c +=d;
    std::cout << c;
}
