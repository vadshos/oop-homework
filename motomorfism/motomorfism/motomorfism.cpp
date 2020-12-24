#include <iostream>
#include "Cat.h"
#include "Zoo.h"
#include "Dog.h"

int main()
{
	Cat luky (2, 2.5, "Petro", "chesir",3.5);
	Dog  petty(2, 2.5, "Petro", "chesir");
	Zoo zoo;
	zoo.add(&petty);
	zoo.add(&luky);

	zoo.print();
	zoo.edit(5.3, 0);
	zoo.print();
}

