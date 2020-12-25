#include "Battle.h"
#include "windows.h"

#include <ctime>

void Battle::battle(const Fortress& objFirst, const Fortress& objSecond)
{
	double hpFirstFortress = 1000 * objFirst.levelFortess;
	double hpSecondFortress = 1000 * objSecond.levelFortess;
	double damageArc = 5.7 * objSecond.levelFortess;
	double damageRange = 8.3 * objSecond.levelFortess;
	double damageCatapult = 5.7 * objSecond.levelFortess;
	srand(time(NULL));
	while (hpFirstFortress >= 0 || hpSecondFortress >= 0) {
		size_t numberAmunition = 1 + rand() % 6;
		if (numberAmunition % 2 == 0) {
			hpSecondFortress -= damageRange;

		}
		else if (numberAmunition == 5) {
			hpSecondFortress -= damageCatapult;

		}
		else {
			hpSecondFortress -= damageArc;

		}
		numberAmunition = 1 + rand() % 6;
		if (numberAmunition % 2 == 0) {
			hpFirstFortress -= damageRange;

		}
		else if (numberAmunition == 5) {
			hpFirstFortress -= damageCatapult;

		}
		else {
			hpFirstFortress -= damageArc;

		}
		
	}
	std::cout << "Winner is Fortress " << (hpFirstFortress > hpSecondFortress ? "First tower" : "Second tower") << std::endl;

}
