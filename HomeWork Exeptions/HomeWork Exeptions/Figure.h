#pragma once
#include <iostream>
#include <string>
#include<tuple>

class Triangle
{
public:
	template <typename T>Triangle(const std::tuple<T, T, T>& tuple);
	template <typename T>Triangle(const T& firstSide, const T& secondSide, const T& thirdSide);
	float area() const;
	float length() const;
	friend std::ostream& operator<<(std::ostream& os, const Triangle& obj);
	template <typename T> void setTriangle(const T& firstSide, const T& secondSide, const T& thirdSide);
private:
	std::tuple<float, float, float> tuple;
};
template <typename T>
inline Triangle::Triangle(const std::tuple<T, T, T>& tuple)
{
	setTriangle(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple));
}

template<typename T>
inline Triangle::Triangle(const T& firstSide, const T& secondSide, const T& thirdSide)
{
	setTriangle(firstSide, secondSide, thirdSide);

}

template<typename T>
inline void Triangle::setTriangle(const T& firstSide, const T& secondSide, const T& thirdSide)
{
	if (firstSide <= 0) {
		throw (double)firstSide;
	}
	else if (firstSide >= secondSide + thirdSide) {
		throw std::string("It is impossible to form a triangle through the side " + std::to_string(firstSide));
	}
	else {
		std::get<0>(tuple) = firstSide;
		}
	if (secondSide <= 0) {
		throw (double)secondSide;
	}
	else if (secondSide >= thirdSide + firstSide) {
		throw std::string("It is impossible to form a triangle through the side " + std::to_string(secondSide));
	}
	else {
		std::get<1>(tuple) = firstSide;
	}
	if (thirdSide <= 0) {
		throw (double)firstSide;
	}
	else if (thirdSide >= secondSide + firstSide) {
		throw std::string("It is impossible to form a triangle through the side " + std::to_string(thirdSide));
	}
	else {
		std::get<2>(tuple) = thirdSide;
	}
}

inline std::ostream& operator<<(std::ostream& os, const Triangle& obj)
{
	os << "First side triangle : " << std::get<0>(obj.tuple) << std::endl;
	os << "Second side triangle : " << std::get<1>(obj.tuple) << std::endl;
	os << "Third side triangle : " << std::get<2>(obj.tuple) << std::endl;
	os << "Area : " << obj.area() << std::endl;
	os << "Length : " << obj.length() << std::endl;
	os << std::endl;
	return os;
}

inline float Triangle::area() const
{

	float p = (std::get<0>(tuple) + std::get<1>(tuple) + std::get<2>(tuple)) / 2;
	float s = sqrt(p * (p - std::get<0>(tuple)) * (p - std::get<1>(tuple)) * (p - std::get<2>(tuple)));
	return s;
}

inline float Triangle::length() const
{
	return (std::get<0>(tuple) + std::get<1>(tuple) + std::get<2>(tuple));
}