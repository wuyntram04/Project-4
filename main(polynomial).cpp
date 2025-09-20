#include <iostream>
#include "input.h"
#include "polynomial.h"

using namespace std;

//PROTOTYPE

void mainMenu();

// #3
void polynomialMenu();
void optionA_Polynomial(polynomial &p);
void optionB_Polynomial();

int main()
{
	mainMenu();
}

void mainMenu()
{
	while (true)
	{
		system("cls");

		cout << "\n\tCMPR131 Chapter4: Complex Numbers, Rational Numbers, Polynomials by Thinh & Minh (09/16/25)";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\t1> Complex Numbers";
		cout << "\n\t\t2> Rational Numbers";
		cout << "\n\t\t3> Polynomials";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0> exit";
		cout << "\n\t" << string(80, char(205));

		switch (inputChar("\n\t\tOption: ", static_cast<string>("1230")))
		{
		case '1':
			break;
		case '2':
			break;
		case '3':
			polynomialMenu();
			break;
		case '0':
			return;
		}
	}
}

void polynomialMenu()
{
	while (true)
	{
		polynomial p;
		system("cls");

		cout << "\n\tA polynomial is an expression consisting of variables(also called indeterminates) and";
		cout << "\n\tcoefficients, that involves only the operations of addition, substraction, multiplication";
		cout << "\n\tand non-negative integer exponentiation of variables";

		cout << "\n\t3>Polynomials";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\tA> A Polynomial";
		cout << "\n\t\tB> Multiple Polynomials";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(80, char(205));

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("AB0"))))
		{
		case 'A':
			optionA_Polynomial(p);
			break;
		case 'B':
			optionB_Polynomial();
			break;
		case '0':
			cout << "\n";
			return;
		}

		cout << "\n";
		system("pause");
	}
	
}


void optionA_Polynomial(polynomial &p)
{

	bool isCase2Active = false;

	while (true)
	{
		system("cls");

		cout << "\n\tA> Single Polynomial";
		cout << "\n\t" << string(80, char(205));
		cout << "\n\t\t1. Enter the number of terms";
		cout << "\n\t\t2. Specify the coefficients";
		cout << "\n\t\t3. Evaluate expression";
		cout << "\n\t\t4. Solve for the derivative";
		cout << "\n\t\t5. Solve for the integral";
		cout << "\n\t" << string(80, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(80, char(205));

		switch (inputInteger("\n\t\tOption: ", 0, 5))
		{
		case 1:
			p.setTerms(inputInteger("\n\t\tEnter the number of terms(1..100): ", 1, 100));
			isCase2Active = false;
			break;
		case 2:
		{
			if (p.getTerms() > 0)
			{
				cout << "\n";
				for (int i = p.getTerms() - 1; i > -1; i--)
				{
					double amount = inputDouble("\t\tEnter the coefficient for term #" + to_string(p.getTerms() - i) + ": ");

					p.add_to_coef(amount, i);
				}
				cout << "\n\t\tThe P(x) is entered: " << p << "\n";
				isCase2Active = true;
			}
			else
				cout << "\n\t\tERROR: 0 term. Please enter the number of terms\n";
		}
		break;

		case 3:
			if (p.getTerms() > 0 && isCase2Active)
			{
				cout << "\n\t\tP1(x) =" << p << "\n";
				double x = inputDouble("\n\t\tEnter the value of x to evaluate the polynomial: ");

				for (int i = p.getTerms() - 1; i > -1; i--)
				{
					if (i == 0)
						cout << "\n\t\t +";
					else
						cout << "\n\t\t  ";

					cout << setw(13) << setprecision(5)
						<< p.getCoefficient(i) * pow(x, i);

					cout << " <-" << setw(15) << fixed << setprecision(2)
						<< p.getCoefficient(i) << "x^" << i;
\
					cout.unsetf(ios::fixed); //take off the fixed.
				}
				cout << "\n\t\t" << string(40, char(196));
				cout << "\n\t\t  " << setw(13) << setprecision(5) << p.evaluate(x);
				cout << "\n";
			}
			else if (p.getTerms() == 0)
				cout << "\n\t\tERROR: 0 term. Please enter the number of terms\n";
			else
				cout << "\n\t\tERROR: expression. Please specify the coefficients.\n";
			break;
		case 4:
		{
			if (p.getTerms() > 0 && isCase2Active)
			{
				cout << "\n\t\tPolynomial(x) = " << p;
				polynomial d = p.derivative();
				cout << "\n\n\t\tDerivative    = " << d;
				cout << "\n";
			}
			else if (p.getTerms() == 0)
				cout << "\n\t\tERROR: 0 term. Please enter the number of terms\n";
			else
				cout << "\n\t\tERROR: expression. Please specify the coefficients.\n";
		}
			break;
		case 5:
		{
			if (p.getTerms() > 0 && isCase2Active)
			{
				cout << "\n\t\tPolynomial(x) = " << p;
				polynomial i = p.integral();
				cout << "\n\n\t\tIntegral      = " << i;
				cout << "\n";
			}
			else if (p.getTerms() == 0)
				cout << "\n\t\tERROR: 0 term. Please enter the number of terms\n";
			else
				cout << "\n\t\tERROR: expression. Please specify the coefficients.\n";
		}
			break;
		case 0:
			return;
		}

		cout << "\n";
		system("pause");
	}
}

void optionB_Polynomial()
{
	system("cls");

	cout << "\n\tB> Two Polynomials";

	polynomial p1;
	polynomial p2;

	p1.setTerms(inputInteger("\n\t\tEnter the number of terms(1..100) for the first polynomial (P1): ", true));

	for (int i = p1.getTerms() - 1; i > -1; i--)
	{
		double amount = inputDouble("\t\t\tEnter the coefficient for term#" + to_string(p1.getTerms() - i) + ": ");

		p1.add_to_coef(amount, i);
	}
	cout << "\n\tThe first polynomial (P1) is entered: " << p1 << "\n";

	p2.setTerms(inputInteger("\n\t\tEnter the number of terms(1..100) for the first polynomial (P2): ", true));

	for (int i = p2.getTerms() - 1; i > -1; i--)
	{
		double amount = inputDouble("\t\t\tEnter the coefficient for term#" + to_string(p2.getTerms() - i) + ": ");

		p2.add_to_coef(amount, i);
	}
	cout << "\n\tThe second polynomial (P1) is entered: " << p2 << "\n";

	polynomial p3;

	p3 = p1 + p2;
	cout << "\n\tAddition of polynomials       -> P1 + P2 = " << p3;

	p3 = p1 - p2;
	cout << "\n\tSubtraction of polynomials    -> P1 - P2 = " << p3;

	p3 = p1 * p2;
	cout << "\n\tSubtraction of polynomials    -> P1 * P2 = " << p3;

	double constValue = inputDouble("\n\n\t\tEnter a constant value: ");
	cout << "\n\t";

	cout << fixed << setprecision(6);

	p3 = constValue * p1;

	cout << constValue << " * Polynomial(P1) = " << p3 << "\n\t";

	p3 = p2 * constValue;


	cout << fixed << setprecision(6);

	cout << "Polynomial(P2) * " << constValue << " = " << p3 << "\n";
}
