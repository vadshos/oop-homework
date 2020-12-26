#pragma once
#include<iostream>


class Bus
{
public:
	friend  class Node;
	Bus(const std::string& fullName = "NoName", const size_t& numberRoad = 1);
	Bus(const Bus& obj);
	void setFullName(const std::string& fullName);
	void setNumberRoad(const size_t& numberRoad);
	friend std::ostream& operator<<(std::ostream& os,Bus obj);
	Bus& operator=(const Bus& obj);
	bool operator==(const Bus& obj);
	size_t id;
private:
	static size_t numberBus;
	std::string fullName;
	size_t numberRoad;
};

