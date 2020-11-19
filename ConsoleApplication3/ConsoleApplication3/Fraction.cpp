#include <iostream>
#include "Fraction.h"
#include <Math.h>
Fraction Fraction::fraction(Fraction& result)
{
	if (result.num == result.denom) {
		result.num = 1;
		result.denom = 1;
	}
	int i = 0;
	if (result.num < result.denom) {
		i = result.num;
	}
	else {
		i = result.denom;
	}
	for (; i > 0; i--) {
		if (result.num % i == 0 && result.denom % i == 0) {
			result.num /= i;
			result.denom /= i;
		}
	}
	return result;
}
void Fraction::print() const
{
	std::cout << num << "/" <<denom<< std::endl;
}

void Fraction::setDenom(int denom)
{
	if (denom == 0) {
		denom = 1;
	}
	else if (denom < 0) {
		num = -num;
		denom = -denom;
	}
	this->denom = denom;
}

Fraction Fraction::plus(const Fraction& two)
{
	Fraction result;
	result.num = (this->num * two.denom) + (two.num * this->denom);
	result.denom = (this->denom * two.denom);
	fraction(result);
	return result;
}


Fraction Fraction::mult(const Fraction& two)
{
	Fraction result;
	result.num = this->num * two.num;
	result.denom = this->num * two.denom;
	fraction(result);
	return result;

}

Fraction Fraction::minus(const Fraction& two)
{
	Fraction result;
	result.num = (this->num * two.denom) - (two.num * this->denom);
	result.denom = (this->denom * two.denom);
	fraction(result);
	return result;
}

Fraction Fraction::division(const Fraction& two)
{
	Fraction result;
	Fraction temp;
	temp.num = two.denom;
	temp.denom = two.num;
	result.num = this->num * temp.num;
	result.denom = this->num * temp.denom;
	fraction(result);
	return result;
}

Fraction::Fraction(int num, int denom)
{
	setNum(num);
	setDenom(denom);
}

Fraction::Fraction(int num) : Fraction(num, denom = 1) {

}




