#pragma once
#include"Stack.h"
#include"Charge.h"

class Barrage
{
public:
	void shot();
	void push(Charge obj);
private:
	Stack<Charge> barrage;
};
inline void Barrage::shot()
{
	barrage.peak().shot();
	barrage.pop();
}
inline void Barrage::push(Charge obj)
{
	barrage.push(obj);
}
