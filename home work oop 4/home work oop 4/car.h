#pragma once
#include<iostream>
#include<ctime>

using namespace std;
class car
{
public:
	enum class typeCar { COMPARTMENT, PLACCART, SLEEPING };
	car() {
		
		TypeCar = (typeCar)(rand() % ((int)typeCar::SLEEPING + 1));
		pass = rand() % quentityPlace[(int)TypeCar] + 1;
	}
	car(typeCar TypeCar,size_t pass);
	void setTypeCar(typeCar typeCar);
	void setPass(size_t pass);
	void print() const;
	const typeCar getType() const;
	const size_t getPass() const; 

private:
	string getTypeCarStr() const;
	size_t pass = 0;
	const static size_t quentityPlace[];
	typeCar TypeCar = typeCar::SLEEPING;


};
inline 	const car::typeCar car::getType() const{
	return this->TypeCar;
}
inline const size_t car::getPass() const {
	return this->pass;
}

