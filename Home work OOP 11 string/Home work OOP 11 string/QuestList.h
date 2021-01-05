#pragma once
#include <iostream>
#include<vector>
#include<string>
#include"Quest.h"
#include<fstream>
#include<ctime>

class QuestList
{

	std::vector <Quest> list;
public:
	QuestList();
	const Quest& getQuest(); // отримати пару питання-відповідь із  бази
	size_t getSize() const
	{
		return list.size();
	}
};
