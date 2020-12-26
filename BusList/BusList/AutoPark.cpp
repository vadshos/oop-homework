#include "AutoPark.h"

void AutoPark::printInRoude() 
{
	std::cout << "Bus in road" << std::endl;

	inRoude.print();
}

void AutoPark::printInAutoPark()
{
	std::cout << "Bus in auto park" << std::endl;
	inAutoPark.print();
}

void AutoPark::buyBus(Bus obj)
{

	inAutoPark.pushFront(obj);
}

void AutoPark::sendInRoude(const size_t& numberBus)
{
	if (numberBus < inAutoPark.getSize()) {
		inRoude.pushFront(inAutoPark.findAndReturnBusNode(numberBus));
		inAutoPark.popSomeElement(numberBus);
	}
}

void AutoPark::removeFromRoude(const size_t& numberBus)
{
	if (numberBus < inRoude.getSize()) {
		inAutoPark.pushFront(inAutoPark.findAndReturnBusNode(numberBus));
		inRoude.popSomeElement(numberBus);
	}
}

void AutoPark::sellBus(const size_t& numberBus)
{
	if(numberBus < inAutoPark.getSize())
	inAutoPark.popSomeElement(numberBus);
	else {
		std::cout << "incorect number bus" << std::endl;
	}
}


