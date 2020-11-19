#pragma once

class Fraction
{
	Fraction fraction(Fraction& result);
	int num = 0, denom = 1, WholeNumber = 0;
public:
	void print() const;
	void setDenom(int denom);
	void setNum(int num) { this->num = num; };
	Fraction plus(const Fraction& two);
	Fraction comparison(const Fraction& two);
	Fraction mult(const Fraction& two);
	Fraction minus(const Fraction& two);
	Fraction  division(const Fraction& two);
	Fraction() = default;
	Fraction(int num, int denom);
	Fraction(int num);
		
};

