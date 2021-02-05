#include <iostream>
#include"DateBase.h"
#include"Game.h"



int main()
{
	Game game("Game",Game::CATEGORY::HORROR,9);
	Game game1("Game2", Game::CATEGORY::SHUTER, 9);
	DateBase::clear();
	DateBase::addObjectDateBase(game1);
	DateBase::addObjectDateBase(game);
	DateBase::addObjectDateBase(game);
	DateBase::addObjectDateBase(game);
	DateBase::showDateBase();
	DateBase::erase(0);
	DateBase::showDateBase();
}

