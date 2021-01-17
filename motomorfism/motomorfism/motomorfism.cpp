#include <iostream>
#include "Cat.h"
#include "Zoo.h"
#include "Dog.h"

int main()
{
	Cat luky (2, 2.5, "Petro", "chesir",3.5);
	Dog  petty(2, 2.5, "Petro", "chesir");
	std::cout << sizeof(petty)<<std::endl;
	Zoo zoo;
	zoo.add(&petty);
	zoo.add(&luky);

	zoo.print();
	
}

