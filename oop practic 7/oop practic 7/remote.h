#pragma once
#include <iostream>
#include "TV.h"
class remote
{
public:
	remote(TV* temp)
	: tv(temp)
	{

	}
	remote& power();
	remote& operator++();
	remote& operator--();
	remote& setTv(TV* temp);
	remote& incVolume();
	remote& decVolume();
	remote& goToChannel(size_t channel);
private:
	TV* tv;

};

