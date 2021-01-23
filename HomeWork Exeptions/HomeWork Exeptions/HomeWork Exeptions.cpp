#include <iostream>
#include <vector>
#include "Figure.h"
#include "Reservoirs.h"



int main()
{
	//TASK 1
	/*try {
		Triangle triangle(2, 5, 8);
	}
	catch(const double& ex){
		std::cout << "Bad side " << ex << std::endl;
    }
	catch (const std::string& ex) {
		std::cout  << ex << std::endl;
	}*/
	/*try {
		Reservoirs triangle("ddepth",2,4,5);
	}
	catch(const myExeption& ex){
		std::cout  << ex.what()<<std::endl;
	}
	catch (const std::string& ex) {
		std::cout  << ex << std::endl;
	}*/

	//TASK 2
	/*try {
		vector<string> v{ "3","3","4" };
		v.at(5) = 5;
		for (auto& i : v)
		{
			std::cout << i << std::endl;
		}
	}
	catch (const std::out_of_range& ex) {
		std::cout << ex.what() << std::endl;
	}*/



	//TASK 3
	/*try {
		std::string str = "We think in generalities, but we live in details.";
		std::string str2 = str.substr(100);
		std::cout << str2;
	}
	catch (const std::out_of_range& ex) {
		std::cout << ex.what() << std::endl;
	}*/

	//TASK 4
}
