#include "String.h"
#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL, ""); 
	String g("Abfg");
	String s("Abcd");
	cout << (g * s) << endl;
}