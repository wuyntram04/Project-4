#include<iostream>
#include"input.h"
#include"Complex.h"
using namespace std;


void mainMenu();
void complexNumberMenu();
void complexMenuA();
void complexMenuB();

int main()
{
	do
	{
		system("cls");
		mainMenu();
		switch (toupper(inputInteger("\n\t\tOption: ", 0, 3)))
		{
		case 1:complexNumberMenu();
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
	

	do
	{
		system("cls");

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


		switch (toupper(inputChar("\n\tOption: ")))
		{
		case 'A': complexMenuA();
			break;
		case 'B': complexMenuB();
			break;
		case '0':
			return;
		default:
			cout << "\n\tInvalid input";
			break;

		}

	} while (true);

}

void complexMenuA() {
	Complex c;

	do
	{
		system("cls");

		cout << "\n\tA> A Complex Number";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\t1. Enter the real number";
		cout << "\n\t\t2. Enter the imaginary number";
		cout << "\n\t\t3. Display the complex number";
		cout << "\n\t\t4. Negate the complex number";
		cout << "\n\t\t5. Add (+) the complex number with a constant";
		cout << "\n\t\t6. Subtract (-) the complex number with a constant";
		cout << "\n\t\t7. Multiply (*) the complex number with a constant";
		cout << "\n\t\t8. Divide (/) the complex number with a constant";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0. return";
		cout << "\n\t" << string(80, char(205));

		switch (toupper(inputInteger("\n\t\tOption: ", 0, 8)))
		{
		case 1:
			c.setRealNum(inputDouble("\n\tEnter a number (double value) for the real part: "));
			break;
		case 2:
			c.setiNum(inputDouble("\n\tEnter a number (double value) for the imaginary part: "));
			break;
		case 3:
			c.showFomular();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 0:
			return;
		default:
			cout << "\n\tInvalid input";
			break;

		}

		cout << "\n\n\t";
		system("pause");

	} while (true);
}

void complexMenuB()
{
	Complex c1;
	Complex c2;

	do
	{
		system("cls");

		cout << "\n\tB> Multiple Complex Numbers";
		cout << "\n\t" << string(90, char(205));
		cout << "\n\t\t1. Enter complex number C1";
		cout << "\n\t\t2. Enter complex number C2";
		cout << "\n\t\t3. Verify condition operators (== and !=) of C1 and C2";
		cout << "\n\t\t4. Evaluate arithmatic operators (+, - , * and /) of C1 and C2";
		cout << "\n\t\t5. Evaluate steps in (3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (1.07109 + 0.120832i) ?";
		cout << "\n\t" << string(90, char(196));
		cout << "\n\t\t0. return";
		cout << "\n\t" << string(90, char(205));

		switch (toupper(inputInteger("\n\t\tOption: ", 0, 8)))
		{
		case 1:
		{
			c1.setComplex();
			c1.showFomular("C1");
			break;
		}
		case 2:
		{
			c2.setComplex();
			c2.showFomular("C2");
			break;
		}	
		case 3: Complex::verifyComparisons(c1, c2);
			break;
		case 4: Complex::evaluateArithmetic(c1, c2);
			break;
		case 5: Complex::evaluateExpression(c1, c2);
			break;
		case 0: return;
		default:
			cout << "\n\tInvalid input";
			break;

		}

		cout << "\n\n\t";
		system("pause");

	} while (true);

