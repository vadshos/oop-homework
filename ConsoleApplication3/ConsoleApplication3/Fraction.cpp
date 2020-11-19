#include <iostream>
#include "Fraction.h"
#include <Math.h>
Fraction Fraction::fraction(Fraction& result)
{
	int i = 0;
	if (result.num == result.denom) {
		result.num = 1;
		result.denom = 1;
	}
	if (result.num > result.denom) {
		int  j = 0;
		while (true) {			
			if ((result.num - result.denom) > 0) {
				result.num -= result.denom;
				j++;
			}
			else {
				break;
			}
		}
		result.WholeNumber = j;
		
	}	
	i = 0;
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
	if (WholeNumber == 0) {
		std::cout << num << "/" << denom << std::endl;
	}
	else {
		std::cout << WholeNumber << " " << num << "/" << denom << std::endl;
	}
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

Fraction Fraction::comparison(const Fraction& two)
{
	
	if ((two.num / two.denom) > (this->num / this->denom)) {
		return two;
	}
	else if((two.num / two.denom) < (this->num / this->denom)){
		return *this;
	}
	else {
		return 0;
	}
	
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




