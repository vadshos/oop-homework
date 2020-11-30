#pragma once
#include<iostream>
#include"car.h"

using namespace std;

class Train {
public:
	Train(string NameTrain, size_t QuentityCars);
	Train(string NameTrain, size_t QuentityCars , size_t pass[],car::typeCar TypeCar);
	Train();
	string getName() const;
	size_t maxCarPassIndex() const;
	size_t minCarPassIndex() const;
	size_t getNumber() const;
	size_t getQuentity() const;
	void setName(string NameTrain);
	void setQuentity(size_t QuentityCars);
	void Print() const;
	void FuctionalPrint() const;
	~Train();
private:
	size_t QuntityPass = 0;
	static size_t NumberTrain;
	string NameTrain;
	size_t QuentityCars;
	car* Cars = nullptr;
};
