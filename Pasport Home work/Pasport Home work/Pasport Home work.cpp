#include <iostream>
#include "ForeignPassport.h"


int main()
{
	ForeignPassport ps1("Vadym Kyryc Vyachefsdgfsdgd", "AA", 123456789, {9,9,2003}, { 14,11,2017 });
	ps1.addVisa({ "Ukraine",{9,5,2021} });
	std::cout << ps1 << std::endl;
}
