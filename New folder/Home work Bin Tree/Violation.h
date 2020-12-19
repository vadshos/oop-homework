#pragma once
#include <iostream>
#include <vector>
#include "Date.h"

class Violation
{
public:
	size_t sumViolation = 0 ;
	Violation() = default;
	Violation(std::string name, size_t sumViolation, date Date) : sumViolation(sumViolation)
	{
		size++;
		NameViolation.push_back(name);
		this->Date.push_back(Date);
	};
	friend class Base_DAI;
	void pushNewViolation(std::string name, size_t sumViolation, date date);
	void pushCopy(Violation v);
private:
	std::vector<std::string> NameViolation;
	size_t size = 0;
	std::vector<date> Date;
};
inline void Violation::pushNewViolation(std::string name, size_t sumViolation, date Date)
{
	this->sumViolation += sumViolation;
	this->sumViolation = sumViolation;
	NameViolation.push_back(name);
	this->Date.push_back(Date);
}

inline void Violation::pushCopy(Violation v)
{
	size++;
	sumViolation += v.sumViolation;
	this->sumViolation = v.sumViolation;
	this->NameViolation.push_back(v.NameViolation[0]);
	this->Date.push_back(v.Date[0]);
}

