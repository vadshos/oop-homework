#pragma once
#include"Triangle.h"
#include"Circle.h"
#include"Rectangle.h"

class Function
{
public:
	static Triangle maxAreaTringle(const std::initializer_list<Triangle>& list);
    template<typename T>static Circle lessThanNumber(const std::initializer_list<Circle>& list,const T& number);
	template<typename T>static void print(const std::initializer_list<T>& list);
	template<typename T>static std::tuple<size_t, size_t, size_t> returnCounterForSomeParameters(const std::initializer_list<T>& list,const float& number);

};

inline Triangle Function::maxAreaTringle(const std::initializer_list<Triangle>& list)
{
	auto* maxArea = list.begin();
	for (auto& l : list) {
		if (l.area() > maxArea->area()) {
			maxArea = &l;
		}
	}
	
	return *maxArea;
}

template<typename T>
inline Circle Function::lessThanNumber(const std::initializer_list<Circle>& list, const T& number)
{
	for (auto& l : list) {
		if (l.getRadius() < number) {
			return l;
		}
	}
	return Circle(0);
}

template<typename T>
inline void Function::print(const std::initializer_list<T>& list)
{
	for (auto& l : list)
		std::cout << l << std::endl;
}

template<typename T>
inline std::tuple<size_t,size_t,size_t> Function::returnCounterForSomeParameters(const std::initializer_list<T>& list, const float& number)
{
	size_t countLow = 0;
	size_t countHigth = 0;
	size_t countEquale = 0;
	for (auto& l : list) {
		std::cout << l.area();
		if (l.area() < number) {
			++countLow;
		}
		else if (l.area() == number) {
			++countEquale;
		}
		else {
			++countHigth;
		}
	}
	return std::make_tuple(countLow, countHigth, countEquale);

}
