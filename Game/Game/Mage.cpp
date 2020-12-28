#include "Mage.h"

Mage::Mage() : Unit("Mage",8,10,30)
{
}

void Mage::upLevel()
{
	Unit::upLevel();
}
