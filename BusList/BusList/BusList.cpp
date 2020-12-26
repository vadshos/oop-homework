#include <iostream>
#include"AutoPark.h"

int main()
{
	AutoPark park;
	park.buyBus({"Shostak.V.V",3});
	park.buyBus({ "Shostak.V.M" ,5});
	park.buyBus({ "Shostak.M.V",10 });
	park.printInAutoPark();
	
}

