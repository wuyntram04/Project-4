#include<iostream>
#include"input.h"
using namespace std;



void mainMenu();

int main()
{
	do
	{
		system("cls");
		mainMenu();
		switch (toupper(inputInteger("\n\t\tOption: ", 0,3)))
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 0:
			exit(0);
		default:
			cout << "\n\tERROR: Invalid Input.";
			break;
		}
		
		cout << "\n\n\t";
		system("pause");

	} while (true);


	return EXIT_SUCCESS;

}

void mainMenu()
{
	cout << "\n\tCMPR131 Chapter 4: Complex Numbers, Rational Numbers, Polynomials by Thi Ho, Khang Quach, Thi Ngoc Quynh Pham (09/15/2025)";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t\t1> Complex Numbers";
	cout << "\n\t\t2> Rational Numbers";
	cout << "\n\t\t3> Polynomials";
	cout << "\n\t" << string(80, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(80, char(205));
}

void complexNumberMenu()
{
	cout << "\n\tA complex number is a number that can be expressed in the form a + b i, where a and b are real";
	cout << "\n\tnumbers, and i represents the \"imaginary unit\", satisfying the equation i^2 = -1. Because no";
	cout << "\n\treal number satisfies this equation, i is called an imaginary number. For the complex number";
	cout << "\n\ta + b i, a is called the real part and b is called the imaginary part.";
	cout << "\n\n\t1> Complex Numbers";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t\tA> A Complex Number";
	cout << "\n\t\tB> Multiple Complex Numbers";
	cout << "\n\t" << string(80, char(196));
	cout << "\n\t\t0> return";
	cout << "\n\t" << string(80, char(205));

}
