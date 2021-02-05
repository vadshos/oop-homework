#pragma once
#include <iostream>

class Game
{
public:
	enum class CATEGORY {SHUTER,HORROR,RACCING};
	Game(const std::string name = "no name", CATEGORY category = CATEGORY::SHUTER, const size_t& popularity = 0) {
		if (!name.empty()&&name.size()<80) {
			strcpy_s(this->name ,name.c_str());
			this->category = category;
			if (popularity < 11) {
				this->popularity = popularity;
			}
			else {
				this->popularity = 10;
			}
		}
	}
	friend std::ostream& operator<<(std::ostream& os,const Game& game) {
		std::string categ[] = { "shuter","horror","raccing" };
		os << "Name : " << game.name<<std::endl;
		os << "Category : " << categ[(int)game.category] << std::endl;
		os << "popularity : " << game.popularity << "/10"<<std::endl;
		return os;
	};
	const std::string& getName() const {
		return name;
	};
	const CATEGORY& getCategory() const {
		return category;
	};
private:
	char name[80];
	CATEGORY category;
	size_t popularity;
};

