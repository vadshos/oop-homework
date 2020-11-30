#pragma once
#include <iostream>

class TV
{
public:
	friend class remote;
	TV(size_t maxCh)
		: maxChannel(maxCh) 
	{
		isOn = (!isOn);
	}
	TV()
		:TV(100)
	{

	}
	void power();
	void nextChannel();
	void prevChannel();
	void incVolume();
	void decVolume();
	void print();
private:
	const size_t maxChannel = 100;
	const size_t maxVolume = 100;
	bool isOn = false;
	size_t currentChannel = 20;
	size_t currentVolume = 20;

};

