#pragma once
#include <iostream>
#include <time.h>
#include <vector>
#include "Car.h"

class Train
{
public:
	void setNumber(const int& number);
	void setName(const string& name);
	const int getSize()const;
	const int getNumber()const;
	const string getName()const;
	void print()const;
	void printAll()const;
	Car getMaxPassagers( const int size)const;
	Car getMinPassagers( const int size)const;
	const int getAllPasseger()const;
	Train();
	Train(const int& size_);
	Train(const int& size_, const int& number, const string& name);
	Train(const Train& other);
	Train& operator=(const Train& other);
	~Train();
private:
	const int size;
	int number;
	string name;
	std::vector<Car> list;
	void copyCars(const Train& other);
};