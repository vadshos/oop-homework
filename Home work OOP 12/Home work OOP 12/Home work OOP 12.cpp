#include <iostream>
#include"Automaton.h"

int main()
{
	Charge ch;
	Barrage br;
	br.push(ch);
	Automaton aut(&br);
	aut.shot();
}
