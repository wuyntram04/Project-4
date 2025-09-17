#pragma once
#include<iostream>
#include "input.h"
using namespace std;

class Complex
{
private:
	double realNum;
	double iNum;
public:

	Complex() {
		realNum = 0.0;
		iNum = 0.0;
	}

	void setRealNum(double real)
	{
		realNum = real;
	}

	double getRealNum() const
	{
		return realNum;
	}

	void setiNum(double i)
	{
		iNum = i;
	}

	double getiNum() const
	{
		return iNum;
	}

	void showFomular() const
	{
		cout << "\n\tComplex Number C1 = ";

		if (realNum == 0 && iNum == 0) {
			cout << "0";
		}
		else if (realNum != 0 && iNum == 0) {
			cout << realNum;
		}
		else if (realNum == 0 && iNum != 0) {
			cout << iNum << "i";
		}
		else
		{
			cout << realNum;
			if (iNum > 0)
			{
				cout << " + " << iNum << "i";
			}
			else
			{
				cout << iNum << "i";
			}
		}
		cout << "\n";
	}

	
};




