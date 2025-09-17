#pragma once
#include<iostream>
#include"input.h"
using namespace std;

class Complex
{

public:


	void menuA()
	{
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
				break;
			case 2:
				break;
			case 3:
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
			case 0: return;
			default:
				cout << "\n\tInvalid input";
				break;

			}

			cout << "\n\n\t";
			system("pause");

		} while (true);
	}

	void menuB()
	{
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
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 0: return;
			default:
				cout << "\n\tInvalid input";
				break;

			}

			cout << "\n\n\t";
			system("pause");

		} while (true);
	}
};


