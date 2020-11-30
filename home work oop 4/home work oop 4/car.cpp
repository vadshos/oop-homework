#include "car.h"

car::car(typeCar TypeCar, size_t pass)
{
	setTypeCar(TypeCar);
	if (pass > 0 && pass < quentityPlace[(int)TypeCar]) {
		setPass(pass);
	}
}
void car::setTypeCar(typeCar typeCar)
{
   this->TypeCar = TypeCar;
}
const size_t  car::quentityPlace[]{ 56,22,16 };
void car::setPass(size_t pass)
{
	if (pass <= quentityPlace[(int)TypeCar]) {
		this->pass = pass;
	}
}

string car::getTypeCarStr() const
{
	
	string temp[] = { "COMPARTMENT","PLACCART","SLEEPING" };
	return  temp[(int)TypeCar];
}
void car::print() const
{
	cout << this->getPass() << endl;
	cout << this->getTypeCarStr() << endl;
}
