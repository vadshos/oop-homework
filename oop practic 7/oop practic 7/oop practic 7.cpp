#include <iostream>
#include <string>
#include "remote.h"
#include <conio.h>
#include"windows.h"


void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

int main()
{
	int temp = 0;
	std::cout << "Enter max channel for 1 TV" << std::endl;
	std::cin >> temp;
	TV tv1(temp);
	std::cout << "Enter max channel for 2 TV" << std::endl;
	std::cin >> temp;
	TV tv2(temp);
	std::cout << "If you want to use enter 1";
	std::cin >> temp;
	TV t = tv1;

	remote r(&t);
	int achion = 0;
	if (temp == 1) {
		while (achion != 7) {
			std::string list[] = {
				"channel+",
				"channel-",
				"volume+",
				"volume-",
				"go to chennel",
				"swich TV",
				"print",
				"EXIT"
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
				if (achion == 1) {
					++r;
				}
				else if (achion == 2) {
					--r;
				}
				else if (achion == 3) {
					r.incVolume();
				}
				else if (achion == 4) {
					r.decVolume();
				}
				else if (achion == 5) {
					std::cout << "Enter number channel" << std::endl;
					std::cin >> temp;
					r.goToChannel(temp);
				}
				else if (achion == 6) {
					r.setTv(&tv2);
				}
				else if (achion == 7) {
					t.print();
				}
			}
		}



	}
	else {
		std::string list[] = {
		"channel+",
		"channel-",
		"volume+",
		"volume-",
		"swich TV",
		"print",
		"EXIT"
		};

		int a = 0;
		while (a != 13) {
			system("cls");
			for (int i = 0; i < 7; i++) {
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
					achion = 6;
				}
			}
			else if (a == 115) {
				achion++;
				if (achion > 8) {
					achion = 1;
				}
			}
			if (achion == 1) {
				t.nextChannel();
			}
			else if (achion == 2) {
				t.prevChannel();
			}
			else if (achion == 3) {
				t.incVolume();
			}
			else if (achion == 4) {
				t.decVolume();
			}
			else if (achion == 5) {
				r.setTv(&tv2);
			}
			else if (achion == 6) {
				t.print();
			}
		}
	}



}
	

