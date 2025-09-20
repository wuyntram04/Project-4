#include<iostream>
#include"input.h"
#include "Rational.h"

using namespace std;



void mainMenu();
void RationalFunction();
void RationalFunctionA();
void RationalFunctionB();

int main()
{
	do
	{
		system("cls");
		mainMenu();
		switch (toupper(inputInteger("\n\t\tOption: ", 0, 3)))
		{
		case 1:
			break;
		case 2: RationalFunction();
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

void RationalNumberMenu()
{
	cout << "\n\tA rational number is a number that can be written as a fraction, a/b, where a is numerator and";
	cout << "\n\tb is denominator. Rational numbers are all real numbers, and can be positive or negative. A";
	cout << "\n\tnumber that is not rational is called irrational. Most of the numbers that people use in everyday";
	cout << "\n\tlife are rational.These include fractions, integers and numbers with finite decimal digits.";
	cout << "\n\tIn general, a number that can be written as a fraction while it is in its own form is rational.";
	cout << "\n\n\t2> Rational Numbers";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t\tA> A Rational Number";
	cout << "\n\t\tB> Multiple Rational Numbers";
	cout << "\n\t" << string(80, char(196));
	cout << "\n\t\t0> return";
	cout << "\n\t" << string(80, char(205));
}


void RationalFunction()
{
	do
	{
		system("cls");
		RationalNumberMenu();
		switch (toupper(inputChar("\n\tOption: ")))
		{
		case 'A': 
			RationalFunctionA();
			break;
		case 'B': RationalFunctionB();
			break;
		case '0': return;
		default:
			cout << "\n\tERROR: Invalid Input.";
			break;

		}

		cout << "\n\n\t";
		system("pause");

	} while (true);

}

void RationalMenuA()
{
	cout << "\n\tA> A Rational Numbera";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t\t1. Enter the numerator";
	cout << "\n\t\t2. Enter the deminator";
	cout << "\n\t\t3. Display the rational number";
	cout << "\n\t\t4. Normalize the rational number";
	cout << "\n\t\t5. Negate the rational number";
	cout << "\n\t\t6. Add (+) the rational number with a constant";
	cout << "\n\t\t7. Subtract (-) the rational number with a constant";
	cout << "\n\t\t8. Multiply (*) the rational number with a constant";
	cout << "\n\t\t9. Divide (/) the rational number with a constant";
	cout << "\n\t" << string(80, char(196));
	cout << "\n\t\t0. Return";
	cout << "\n\t" << string(80, char(205));
}


void RationalFunctionA()
{
	Rational R1;
	Rational R2;


	do
	{
		system("cls");

		try
		{
			RationalMenuA();
			switch (inputInteger("\n\tOption: "))
			{
			case 1:
			{
				int n = inputInteger("\n\tEnter the value for the numerator: ");

				R1.setNumerator(n);

			}

			break;
			case 2:
			{
				int d = inputInteger("\n\tEnter the value for the denominator: ");

				R1.setDenominator(d);

			}
			break;

			case 3:
			{
				cout << "\n\tRational number R1: " << R1.getNumerator() << "/" << R1.getDenominator();
			}
			break;
			case 4:
			{
				cout << "\n\tNormalized rational number R2 (a copy of R1)";
				R1.normalize();
				cout << "\n\t" << R1;
			}
			break;
			case 0:
				return;

			default: cout << "\n\tERROR: Invalid Input";
			}

		}
		catch (const runtime_error& e)
		{
			cout << "\n\tERROR: " << e.what();
		}

		cout << "\n\n\t";
		system("pause");
	} while (true);

}



void RationalMenuB()
{
	cout << "\n\tB> Multiple Rational Numbers";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t\t1. Enter rational number R1";
	cout << "\n\t\t2. Enter rational number R2";
	cout << "\n\t\t3. Verify condition operators (==, !=, >=, >, <= and <) of R1 and R2";
	cout << "\n\t\t4. Evaluate arithmatic operators (+, - , * and /) of R1 and R2";
	cout << "\n\t\t5. Evaluate (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889";
	cout << "\n\t" << string(80, char(196));
	cout << "\n\t\t0. Return";
	cout << "\n\t" << string(80, char(205));
}
void RationalFunctionB()
{
	Rational R1;
	Rational R2;


	do
	{
		system("cls");
		
		try
		{
			RationalMenuB();
			switch (toupper(inputChar("\n\tOption: ")))
			{
			case '1':
			{
				int n = inputInteger("\n\tEnter the value for the numerator: ");
				int d = inputInteger("\n\tEnter the value for the denominator: ");

				R1.setNumerator(n);
				R1.setDenominator(d);

				
				cout << "\n\tR1 = " << R1;
				

			}
			
			break;
			case '2':
			{
				int n = inputInteger("\n\tEnter the value for the numerator: ");
				int d = inputInteger("\n\tEnter the value for the denominator: ");

				R2.setNumerator(n);
				R2.setDenominator(d);

				
				cout << "\n\tR2 = " << R2;
				

			}
			break;
			case '3':
			{
				cout << boolalpha;
				bool anyUndef = R1.isUndefined() || R2.isUndefined();

				cout << "\n\n\tR1 == R2 -> (" << R1 << ") == (" << R2 << ") ? " << (R1 == R2);
				cout << "\n\tR1 != R2 -> (" << R1 << ") != (" << R2 << ") ? " << (R1 != R2);
				cout << "\n\tR1 >= R2 -> (" << R1 << ")  >= (" << R2 << ") ? " << (R1 >= R2);
				cout << "\n\tR1  > R2 -> (" << R1 << ")  > (" << R2 << ") ? " << (R1 > R2);
				cout << "\n\tR1 <= R2 -> (" << R1 << ") <= (" << R2 << ") ? " << (R1 <= R2);
				cout << "\n\tR1 < R2 -> (" << R1 << ") < (" << R2 << ") ? " << (R1 < R2);
			}
			break;
			case '4':
			{
				cout << "\n\tAddition    : R1 + R2 -> (" << R1 << ") + (" << R2 << ") = " << (R1 + R2);
				cout << "\n\tSubtraction : R1 - R2 -> (" << R1 << ") - (" << R2 << ") = " << (R1 - R2);
				cout << "\n\tMutiplication: R1 * R2 -> (" << R1 << ") * (" << R2 << ") = " << (R1 * R2);

				cout << "\n\tDivision    : R1 / R2 -> (" << R1 << ") / (" << R2 << ") = " << (R1 / R2);
			}
			break;
			//case '5':
			//{
			//	cout << "\n\tEvaluating expression..." << "\n\t\t(3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889 ?";

			//	// step #1: (R1 + R2) and (R1 / 9), propagate undefined via if / else
			//	Rational sum12;
			//	if (R1.isUndefined() || R2.isUndefined())
			//		sum12 = Rational(0, 0);            // undefined
			//	else
			//		sum12 = R1 + R2;

			//	Rational R1div9;
			//	if (R1.isUndefined())
			//		R1div9 = Rational(0, 0);           // undefined
			//	else
			//		R1div9 = R1 / Rational(9, 1);      // 9 != 0, so safe

			//	cout << "\n\tStep #1: (3 * (" << sum12 << ") / 7) / (R2 - (" << R1div9 << ")) >= 621/889 ?";


			//	// ---------- step #2: leftPart = 3*(R1+R2)/7, rightDen = R2 - R1/9 ----------

			//	Rational leftPart;
			//	if (sum12.isUndefined())
			//		leftPart = Rational(0, 0);
			//	else
			//		leftPart = (Rational(3, 1) * sum12) / Rational(7, 1); // 7 != 0

			//	Rational rightDen;
			//	if (R2.isUndefined() || R1div9.isUndefined())
			//		rightDen = Rational(0, 0);
			//	else
			//		rightDen = R2 - R1div9;

			//	cout << "\n\tStep #2: (" << leftPart << ") / (" << rightDen << ") >= 621/889 ?";

			//	// ---------- Step #3: wholeLeft = leftPart / rightDen ----------
			//	Rational wholeLeft;
			//	if (leftPart.isUndefined() || rightDen.isUndefined())
			//	{
			//		wholeLeft = Rational(0, 0);
			//	}
			//	else
			//	{
			//		// avoid division by zero (numerator==0 -> rightDen == 0)
			//		if (rightDen.getNumerator() == 0)
			//			wholeLeft = Rational(0, 0);
			//		else
			//			wholeLeft = leftPart / rightDen;
			//	}

			//	cout << "\n\tstep #3: " << wholeLeft << " >= 621/889 ?";
			//	
			//	// ---------- step #4: Right side ----------
			//	Rational rightSide(621, 889);
			//	cout << "\n\tstep #4: " << wholeLeft << " >= " << rightSide << " ?";

			//	// ---------- step #5: final compare ----------
			//	// Your rule: if left side is undefined -> print false
			//	if (wholeLeft.isUndefined())
			//	{
			//		cout << "\n\tstep #5: false";
			//	}
			//	else
			//	{
			//		bool ans;
			//		if (wholeLeft >= rightSide) 
			//			ans = true;
			//		else                 
			//			ans = false;
			//		cout << "\n\tstep #5: " << (ans ? "true" : "false");
			//	}
			//}
			//break;
			case '0':
				return;

			default: cout << "\n\tERROR: Invalid Input";
			}

		}
		catch (const runtime_error& e)
		{
			cout << "\n\tERROR: " << e.what();
		}

		cout << "\n\n\t";
		system("pause");
	} while (true);

}
