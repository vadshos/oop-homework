#pragma once
#include"Dlist.h"
#include"Bus.h"


class AutoPark
{
public:
	friend class Dlist;
	void printInRoude();
	void printInAutoPark();
	void buyBus( Bus obj);
	void sendInRoude(const Bus& numberBus);

private:
	DList inRoude;
	DList inAutoPark;
};

