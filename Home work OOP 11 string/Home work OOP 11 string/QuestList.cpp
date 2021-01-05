#include "QuestList.h"

QuestList::QuestList()
{
	std::ifstream date;
	date.open("question.txt");
	if (date.is_open()) {
		std::string answer;
		std::string question;
		while (!date.eof())
		{
			getline(date,question);
			getline(date, answer);
			list.push_back(Quest(question,answer));
		}
	}
}

const Quest& QuestList::getQuest()
{
	srand(time(NULL));
	int i = rand() % list.size();
	return *(list.begin()+i);
}
