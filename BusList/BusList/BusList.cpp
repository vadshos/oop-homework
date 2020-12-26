#include <iostream>
#include <string>

#include"AutoPark.h"
#include"windows.h"
#include"conio.h"


void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

int main()
{
	AutoPark park;
	park.buyBus({ "Shostak V.V.",3 });
	park.buyBus({ "Shostak V.M." ,5 });
	park.buyBus({ "Shostak M.V.",10 });

	park.printInAutoPark();
	int achion = 1;
	while (achion != 7) {
		std::string list[] = {
			"List achion autopark",
			"1.Buy bus",
			"2.Sell bus",
			"3.Print bus in roud",
			"4.Print bus in autopark",
			"5.remove bus from roud",
			"6.send bus in roud" ,
			"7.EXIT"
		};

		int a = 0;
		while (a != 13) {
			system("cls");
			for (int i = 0; i < 8; i++) {
				if (i == achion) {
					SetColor(0, 14);
				}
				if (i != achion) {
					SetColor(0, 15);
				}
				std::cout << list[i] << std::endl;
				SetColor(0, 15);
			}
			a = _getch();
			if (a == 119) {
				achion--;
				if (achion < 1) {
					achion = 7;
				}
			}
			else if (a == 115) {
				achion++;
				if (achion > 8) {
					achion = 1;
				}
			}
		}
		switch (achion)
		{
		case 1: {
			std::string Fullname;
			std::size_t numberRoad;
			std::cout << "Enter name new rider ->";
			getline(std::cin, Fullname);
			std::cout << "Enter number road ->";
			std::cin >> numberRoad;
			park.buyBus({ Fullname, numberRoad });
		}

		    break;
		case 2: {
			park.printInAutoPark();
			std::size_t numberBus;
			std::cout << "Enter number bus->";
			std::cin >> numberBus;
			park.sellBus(numberBus);
		}
		    break;
		case 3:
			park.printInRoude();
			system("pause");
			break;
		case 4:
			park.printInAutoPark();
			system("pause");
			break;
		case 5:
		{
			park.printInRoude();
			std::size_t numberBus;
			std::cout << "Enter number bus->";
			std::cin >> numberBus;
			park.removeFromRoude(numberBus);
		}
			break;
		case 6:
		{
			park.printInAutoPark();
			std::size_t numberBus;
			std::cout << "Enter number bus->";
			std::cin >> numberBus;
			park.sendInRoude(numberBus);
		}
			break;
		default:
			break;
		}
	}
}

