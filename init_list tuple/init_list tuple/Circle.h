#pragma once
#include<iostream>

class Circle
{
public:
	template<typename T> Circle(const T& radius);
	float area() const;
	float length() const;
	float getRadius() const;
	friend std::ostream& operator<<(std::ostream& os,const Circle& obj )  ;
private:
	float radius;
};
template<typename T>
inline Circle::Circle(const T& radius)
{
	if (radius != 0) {
		this->radius = radius;
	}
}

inline float Circle::area() const
{
	return 3.14 * (pow((radius),2));
}

inline float Circle::length() const
{
	return (3.14*radius*2);
}

inline float Circle::getRadius() const
{
	return radius;
}

