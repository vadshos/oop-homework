#include "ForeignPassport.h"

ForeignPassport::ForeignPassport(const std::string& fullName, const std::string& seria, const size_t& number, const Date& date, const Date& dateGive) : Passport(fullName, seria,number, date, dateGive)
{
}

void ForeignPassport::addVisa(const std::string& country, const Date& date)
{
	Visa v(country, date);
	visas.push_back(v);
}
void ForeignPassport::addVisa(const Visa& v)
{
	visas.push_back(v);
}

void ForeignPassport::printVisa() const
{
	for (auto& v : visas) {
		std::cout << v << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const ForeignPassport& obj)
{
	Passport pass(obj);
	std::cout << pass << std::endl;
	os << "____VISA_____" << std::endl;
	for (auto& v : obj.visas) {
		os<< v << std::endl;
	};
	return os;
}
