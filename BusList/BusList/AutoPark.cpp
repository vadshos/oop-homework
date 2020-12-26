#include "AutoPark.h"

void AutoPark::printInRoude() 
{
	inRoude.print();
}

void AutoPark::printInAutoPark()
{
	inAutoPark.print();
}

void AutoPark::buyBus(Bus obj)
{
	inAutoPark.pushFront(obj);
}

void AutoPark::sendInRoude(const Bus& numberBus)
{
	/*inAutoPark.popSomeElement(numberBus);
	inRoude.pushFront(numberBus);*/
}
