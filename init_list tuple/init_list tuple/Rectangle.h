#pragma once
#include<iostream>
#include<utility>
class Rectangle
{
public:
	template<typename T>Rectangle(const std::pair<T,T>& pair);
	template<typename T>Rectangle(const T& first,const T& second);
	template<typename T>void setRectangle(const T& first, const T& second);
	float area()const;
	float length()const;
	friend std::ostream& operator<<(std::ostream& os,const Rectangle& obj );

private:
	std::pair<float, float> pair;
};

template<typename T>
inline Rectangle::Rectangle(const std::pair<T, T>& pair)
{
	setRectangle(pair.first,pair.second);
}

template<typename T>
inline Rectangle::Rectangle(const T& first, const T& second)
{
	setRectangle(first,second);
}

template<typename T>
inline void Rectangle::setRectangle(const T& first, const T& second)
{
	if (first != 0 && second != 0) {
		pair.first = first;
		pair.second = second;
	}
	else {
		std::cout << "invalid number" << std::endl;
	}
}

inline float Rectangle::area() const
{
	return pair.first * pair.second;
}

inline float Rectangle::length() const
{
	return (pair.first + pair.second)*2;
}
