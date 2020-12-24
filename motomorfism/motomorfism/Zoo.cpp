#include "Zoo.h"



void Zoo::print() const
{
	for (auto& i : zoo)
	{
		i->print();
	}
}
