#include "Game.h"

void Game::run()
{
	std::string temp;
	std::cout << question << std::endl;
	std::cout << userWord << std::endl;
	getline(std::cin,temp);
	for (size_t i = 0; i < answer.size() + 1; i++)
	{
		if (answer[i] == temp[i]) {
			userWord[i] = temp[i];
		}
	}
	if (temp == answer) {
		std::cout << "You win!!!!!" << std::endl;
	}
	else {
		run();
	}
}

void Game::start()
{
	
	Quest question =  list.getQuest();
	this->question = question.getQuestion();
	answer = question.getAnswer();
	userWord ;
	for (size_t i = 0; i < answer.size()+1; i++)
	{
		userWord += filler;
	}
	run();
}
