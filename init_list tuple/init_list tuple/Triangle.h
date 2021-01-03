#pragma once
#include<iostream>
#include<tuple>


class Triangle
{
public:
	template <typename T>Triangle(const std::tuple<T, T, T>& tuple);
	template <typename T>Triangle(const T& firstSide,const T& secondSide,const T& thirdSide );
	float area() const;
	float length() const;
	friend std::ostream& operator<<(std::ostream& os, const Triangle& obj);
	template <typename T> void setTriangle(const T& firstSide, const T& secondSide, const T& thirdSide);
private:
	std::tuple<float,float,float> tuple;
};
template <typename T>
inline Triangle::Triangle(const std::tuple<T, T, T>& tuple)
{
	setTriangle(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple));
}

template<typename T>
inline Triangle::Triangle(const T& firstSide, const T& secondSide, const T& thirdSide)
{
	setTriangle(firstSide,secondSide,thirdSide);

}

template<typename T>
inline void Triangle::setTriangle(const T& firstSide, const T& secondSide, const T& thirdSide)
{
	if (firstSide != 0 && secondSide != 0 && thirdSide != 0) {
		std::get<0>(tuple) = firstSide;
		std::get<1>(tuple) = secondSide  ;
		std::get<2>(tuple ) = thirdSide;
	}
	else {
		std::cerr << "invalid number" << std::endl;
	}
}

inline float Triangle::area() const
{

	float p = (std::get<0>(tuple) + std::get<1>(tuple)+ std::get<2>(tuple))/2;
	float s = sqrt(p * (p - std::get<0>(tuple)) * (p - std::get<1>(tuple)) * (p - std::get<2>(tuple)));
	return s;
}

inline float Triangle::length() const
{
	return (std::get<0>(tuple) + std::get<1>(tuple) + std::get<2>(tuple));
}
