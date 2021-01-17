#include "Zoo.h"



void Zoo::print() const
{
	std::cout << sizeof(zoo.begin()) << std::endl;
	for (auto& i : zoo)
	{
		
		i->print();
	}
}

void Zoo::erase(const size_t& index)
{
	if (index <= zoo.size()) {
		zoo.erase(zoo.begin()+index);
	}
}
