#pragma once
#include "Passport.h"
#include "Visa.h"

#include<vector>


class ForeignPassport : Passport
{
public:
	ForeignPassport(const std::string& fullName, const std::string& seria, const size_t& number, const Date& date, const Date& dateGive);
	void addVisa(const std::string& country,const Date& date);
	void addVisa(const Visa& v);
	void printVisa() const;
	friend std::ostream& operator<<(std::ostream& os, const ForeignPassport& obj);
private:
	std::vector<Visa> visas;
};

