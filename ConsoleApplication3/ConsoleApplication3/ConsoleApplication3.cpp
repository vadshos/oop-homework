#include<iostream>
#include "Fraction.h"
#include"windows.h"
#include<conio.h>

using namespace std;

void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

int main() {
	int a = 0;
	int achion = 0;
	int count = 5;
	string list[] = { "+","-","*","/","x" };
	
	while (a != 13) {
		achion = 0;
		system("cls");
		for (int i = 0; i < count; i++) {
			if (i == achion) {
				SetColor(0, 14);
			}
			if (i != achion) {
				SetColor(0, 15);
			}
			cout << list[i] << endl;
			SetColor(0, 15);
		}

		a = _getch();
		if (a == 119) {
			achion--;
			if (achion < 0) {
				achion = count;
			}
		}
		else if (a == 115) {
			achion++;
			if (achion > count) {
				achion = 0;
			}
		}
	}
	if (achion < 5) {
		int denom = 0;
		int num = 0;
		system("cls");
		cout << "Enter num first-> ";
		cin >> num;
		cout << "Enter denom first-> ";
		cin >> denom;
		Fraction one(num, denom);
		cout << "Enter num second-> ";
		cin >> num;
		cout << "Enter denom second-> ";
		cin >> denom;
		Fraction result;
		Fraction two(num, denom);
		if (achion == 0) {
			result = two.plus(one);
			result.print();
		}
		else if (achion == 1) {
			result = two.minus(one);
			result.print();
		}
		else if (achion == 2) {
			result = two.mult(one);
			result.print();
		}
		else if (achion == 3) {
			result = two.division(one);
			result.print();
		}
		
	}
 

}
