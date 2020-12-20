#pragma once
#include<iostream>
class Charge
{
public:
	Charge();
	void shot() const;
private:
	static size_t charge ;
};
size_t Charge::charge = 1 + rand() % 100;
inline Charge::Charge()
{
	++charge;
}

inline void Charge::shot() const
{
	int num = 0 + rand() % 10;
	if (num < 7) {
		std::cout << "The machine gun fired a bullet " << charge << ", and hit."<<std::endl;
	}
	else {
		std::cout << "The machine gun fired a bullet " << charge << ", and missed." << std::endl;

	}
}
