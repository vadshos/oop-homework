#pragma once
#include <iostream>

class Quest
{
public:
	Quest(const std::string question,const std::string answer);
	const std::string& getQuestion() const;
	const std::string& getAnswer() const;
private:
	std::string question;
	std::string answer;
};
