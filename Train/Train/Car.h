#pragma once
#include <iostream>
#include <string>
using namespace std;
class Car
{
public:
	enum class Type_cars { SEAT, COMPACT, SLEEPING }; // 0 1 2
	void setTypeCar(const int& type_car);
	void setCountPassengers(const size_t& count_passengers);
	void input();
	const string getTypeCar()const;
	const size_t getCountPassengers()const;
	Car();
	Car(const int& type_car, const size_t& count_passengers);
	Car(const Car& other);
	Car& operator=(const Car& other);
	~Car();
	friend std::ostream& operator<<(std::ostream& os,const Car& obj);
private:
	Type_cars type_car;
	size_t count_passengers;
	const static size_t maxPlaces[];
};

