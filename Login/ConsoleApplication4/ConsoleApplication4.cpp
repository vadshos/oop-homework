#include <iostream>
#include"OOP.h"

int main()
{
	Menu menu;
	try {
		menu.menu();
	}
	catch( const badLogin& ex){
		std::cout<<ex.what();
	}
	catch (const badPassword& ex) {
		std::cout<<ex.what();
	}
	catch (const ExeptionUserIsAlreadyCreate& ex) {
		std::cout << ex.what();
	}
}

