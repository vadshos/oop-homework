#pragma once
#include <fstream>
#include "Game.h"


class DateBase
{
public:
	static void showDateBase();
	static void addObjectDateBase(const Game& obj);
	static void searchByName(const std::string& name);
	static void searchByCategory(const Game::CATEGORY category);
	static void clear();
	static void erase(const size_t& index);


};

inline void DateBase::showDateBase()
{
	Game game;
	int value;
	std::ifstream in("datebase.dat", std::ios_base::binary);
	if (!in)
	{
		throw std::exception("Error opening file for read");
	}
	size_t index = 0;
	while (in.read((char*)&game, sizeof(game)))
	{
		++index;
		std::cout << index;
		std::cout << game << std::endl;
	}
}

inline void DateBase::addObjectDateBase(const Game& obj)
{
		std::ofstream out("datebase.dat", std::ios_base::binary | std::ios_base::app);
		if (!out)
		{
			std::cerr << "Error opening for writing\n";
			return;
		}

		out.write((char*)&obj ,sizeof(obj));
		out.close(); 
}

inline void DateBase::searchByName(const std::string& name)
{
	Game game;
	int value;
	std::ifstream in("datebase.dat", std::ios_base::binary );
	if (!in)
	{
		throw std::exception("Error opening file for read");
	}
	size_t index = 0;
	while (in.read((char*)&game, sizeof(game)))
	{
		if (game.getName() == name) {
			std::cout << "Number game" << index << std::endl;
			std::cout << game << std::endl;
		}
	}
}

inline void DateBase::clear()
{
	std::ofstream out("datebase.dat", std::ios_base::binary);
}

inline void DateBase::erase(const size_t& index)
{
	Game game;
	int value;
	std::ifstream in("datebase.dat", std::ios_base::binary);
	std::ofstream out("datebaseCopy.dat", std::ios_base::binary);
	if (!in)
	{
		throw std::exception("Error opening file for read");
	}
	size_t indexObj = 0;
	while (in.read((char*)&game, sizeof(game)))
	{
		out.write((char*)&game, sizeof(game));
	}
	out.close();
	out.open("datebase.dat");
	in.close();
	in.open("datebaseCopy.dat");
	clear();
	if (!in)
	{
		throw std::exception("Error opening file for read");
	}
	while (in.read((char*)&game, sizeof(game)))
	{
		if (indexObj != index)
			out.write((char*)&game, sizeof(game));
		indexObj++;
	}
}

inline void DateBase::searchByCategory(const Game::CATEGORY category)
{
	Game game;
	std::ifstream in("datebase.dat", std::ios_base::binary | std::ios::ate);
	if (!in)
	{
		throw std::exception("Error opening file for read");
	}
	size_t index = 0;
	while (in.read((char*)&game, sizeof(game)))
	{
		if (game.getCategory() == category) {
			std::cout << "Number game" << index << std::endl;
			std::cout << game << std::endl;
		}
	}
}
