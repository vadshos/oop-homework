#pragma once
#include <iostream>
#include"QuestList.h"

class Game 
{
private:
	static const char filler = '#';
	QuestList list; // default ctor, заповнення питаннями вектору
	std::string userWord;  // шаблон слова, спочатку заповнити певним символом
	std::string answer;
	std::string question;
	void run();
	void updateUserWord(char letter);
public:
	void  start(); // обрати випадковим чином пару запитання–відповідь з бази запитань list

};