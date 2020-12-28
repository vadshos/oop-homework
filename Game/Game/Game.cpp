#include <iostream>
#include"Team.h"
#include "GAME.h"

int main()
{
    Team TEAM2("Name");
    Team TEAM("NAME");
    GAME game;

    game.Battle(TEAM, TEAM2);
    game.Battle(TEAM, TEAM2);

}


