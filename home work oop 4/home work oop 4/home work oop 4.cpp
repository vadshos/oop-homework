#include<iostream>
#include"train.h"

int main() {
	const string str = "Москва-Ковель";
	const size_t a = 4;
	size_t arr[a] = {1,2,3,4};
	Train train(str,a, arr,car::typeCar::COMPARTMENT);
	train.FuctionalPrint();
}