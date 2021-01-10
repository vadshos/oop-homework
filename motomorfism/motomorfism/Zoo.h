#pragma once
#include"Animal.h"
#include <iostream>
#include <vector>


class Zoo
{
public:
	template<typename MyType>void add(MyType* obj);
	virtual void print() const;
	template<typename MyType> void edit(MyType var ,const size_t index);
	void erase(const size_t& index);
private:
	vector<Animal*> zoo;
};

template<typename MyType>
inline void Zoo::add(MyType* obj)
{
	zoo.push_back(obj);
}

template<typename MyType>
inline void Zoo::edit(MyType var, const size_t index)
{
	std::string str = typeid(var).name();
	if(index < zoo.size())
	if (str == "double") {
		zoo[index]->setWeight(var);
	}
	else if(str == "int") {
	 zoo[index]->setAge(var);
	}
	
}
