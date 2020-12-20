#pragma once
#include"Barrage.h"
class Automaton
{
public:
	Automaton(Barrage *barrage);
	void shot();
	Barrage* barrage;
private:

};

inline Automaton::Automaton(Barrage *barrage)
{
	this->barrage = barrage;
}

inline void Automaton::shot()
{
	barrage->shot();
}
