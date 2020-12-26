#pragma once
#include"Dlist.h"
#include"Bus.h"


class AutoPark
{
public:
	friend class DList;

	void printInRoude();
	void printInAutoPark();
	void buyBus( Bus obj);
	void sendInRoude(const size_t& numberBus);
	void removeFromRoude(const size_t& numberBus);
	void sellBus(const size_t& numberBus);


private:
	Dlist<Bus> inRoude;
	Dlist<Bus> inAutoPark;

};

