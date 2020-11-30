#include "TV.h"
#include <iostream>

void TV::power()
{
	isOn = !isOn;
}

void TV::nextChannel()
{
	if (currentChannel < maxChannel&&isOn) {
		currentChannel++;
	}
}

void TV::prevChannel()
{
	if (currentChannel != 0 && isOn) {
		currentChannel--;
	}
}

void TV::incVolume()
{
	if (currentVolume < maxVolume && isOn) {
		currentVolume++;
	}
}

void TV::decVolume()
{
	if (currentVolume != 0 && isOn) {
		currentVolume--;
	}
}

void TV::print()
{
	if (isOn) {
		std::cout << "current channel" << currentChannel << std::endl;
		std::cout << "current volume" << currentVolume << std::endl;
	}
	else {
		std::cout << "max channel" << maxChannel << std::endl;
		std::cout << "max volume" << maxVolume << std::endl;
	}
}
