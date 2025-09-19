#pragma once
#include<iostream>
#include <sstream>
#include <cmath>
#include "input.h"
using namespace std;

class Complex
{
private:
	float *realNum;
	float *iNum;
public:
	const float EPS = 1e-6f;

	Complex() {
		realNum = new float(0.0);
		iNum = new float(0.0);
	}

	~Complex()
	{
		delete realNum;
		delete iNum;
	}

	Complex(float real, float imag) 
	{
		realNum = new float(real);
		iNum = new float(imag);
	}

	// copy constructor
	Complex(const Complex& other)
	{ 
		realNum = new float(*other.realNum);
		iNum = new float(*other.iNum);
	}

	//Copy Assignment Constructor
	Complex& operator=(const Complex& other) 
	{
		if (this != &other) {
			*realNum = *other.realNum;
			*iNum = *other.iNum;
		}
		return *this;
	}

	void setRealNum(float real)
	{
		*realNum = real;
	}

	float getRealNum() const
	{
		return *realNum;
	}

	void setiNum(float i)
	{
		*iNum = i;
	}

	float getiNum() const
	{
		return *iNum;
	}

	void showFomular(const string& name = "C") const
	{
		cout << "\n\tComplex Number " << name << " = ";

		if (*realNum == 0 && *iNum == 0)
		{
			cout << "0";
		}
		else if (*realNum != 0 && *iNum == 0)
		{
			cout << *realNum;
		}
		else if (*realNum == 0 && *iNum != 0)
		{
			cout << *iNum << "i";
		}
		else
		{
			cout << *realNum;
			if (*iNum > 0)
			{
				cout << " + " << *iNum << "i";
			}
			else
			{
				cout  << " - " << fabs(*iNum) << "i";
			}
		}
		cout << "\n";
	}

	//////////////////////==============MENU B============////////////////////////////
	
	//////////////////////==============INPUT================//////////////////////
	void setComplex()
	{
		*realNum = static_cast<float>(inputDouble("\n\tEnter a number(double value) for the real part : "));
		*iNum = static_cast<float>(inputDouble("\n\tEnter a number(double value) for the imaginary part : "));
	}

	////////////////////// ---------- Operators ----------///////////////////////
	Complex operator+(const Complex& other) const
	{
		return Complex(getRealNum() + other.getRealNum(),
			getiNum() + other.getiNum());
	}

	Complex operator-(const Complex& other) const {
		return Complex(getRealNum() - other.getRealNum(),
			getiNum() - other.getiNum());
	}

	Complex operator*(const Complex& other) const {
		float a = getRealNum(), b = getiNum();
		float c = other.getRealNum(), d = other.getiNum();
		return Complex(a * c - b * d, a * d + b * c);
	}

	Complex operator/(const Complex& other) const {
		float c = other.getRealNum(), d = other.getiNum();
		float denom = c * c + d * d;
		if (denom <= EPS)
		{
			cout << "\n\n\t\tERROR: Division by zero complex number.\n";
			return Complex(0.0f, 0.0f);
		}
		float a = getRealNum(), b = getiNum();
		return Complex((a * c + b * d) / denom,
			(b * c - a * d) / denom);
	}

	///////////////////================ Scalar ops ================////////////////////////
	Complex operator*(float k) const
	{
		return Complex(getRealNum() * k, getiNum() * k);
	}

	Complex operator/(float k) const
	{
		if (fabs(k) <= EPS)
		{
			cout << "\n\tERROR: Division by zero scalar.\n";
			return Complex(0.0f, 0.0f);
		}
		return Complex(getRealNum() / k, getiNum() / k);
	}

	friend Complex operator*(float k, const Complex& z) { return z * k; }

	///////////////////// ---------- Comparisons --------------------///////////////////
	bool operator==(const Complex& other) const
	{
		return fabs(getRealNum() - other.getRealNum()) <= EPS &&
			fabs(getiNum() - other.getiNum()) <= EPS;
	}
	bool operator!=(const Complex& other) const { return !(*this == other); }

	////////////////////// ---------- Menu Helpers ------------------////////////////////////
	static void verifyComparisons(const Complex& C1, const Complex& C2)
	{
		cout << "\n\t\tC1 == C2 -> (" << C1.toString() << ") == ("
			<< C2.toString() << ") ? " << (C1 == C2 ? "true" : "false");
		cout << "\n\t\tC2 != C1 -> (" << C2.toString() << ") != ("
			<< C1.toString() << ") ? " << (C2 != C1 ? "true" : "false") << "\n";
	}

	static void evaluateArithmetic(const Complex& C1, const Complex& C2)
	{
		Complex sum = C1 + C2;
		Complex diff = C2 - C1;
		Complex prod = C1 * C2;
		

		cout << "\n\t\tAddition\t: C1 + C2 -> (" << C1.toString()
			<< ") + (" << C2.toString() << ") = " << sum.toString();
		cout << "\n\t\tSubtraction\t: C2 - C1 -> (" << C2.toString()
			<< ") - (" << C1.toString() << ") = " << diff.toString();
		cout << "\n\t\tMultiplication\t: C1 * C2 -> (" << C1.toString()
			<< ") * (" << C2.toString() << ") = " << prod.toString();
		if (fabs(C1.getRealNum()) < C1.EPS && fabs(C1.getiNum()) < C1.EPS) {
			cout << "\n\t\tDivision\t: C2 / C1 -> (" << C2.toString()
				<< ") / (" << C1.toString() << ") = undefined\n";
		}
		else {
			Complex quot = C2 / C1;
			cout << "\n\t\tDivision\t: C2 / C1 -> (" << C2.toString()
				<< ") / (" << C1.toString() << ") = " << quot.toString() << "\n";
		}

	}

	static void evaluateExpression(const Complex& C1, const Complex& C2) {
		Complex C3(1.07109f, 0.120832f);

		cout << "\n\t\tC1 = " << C1.toString()
			<< "\n\t\tC2 = " << C2.toString()
			<< "\n\t\tC3 = " << C3.toString();

		cout << "\n\n\t\tEvaluating expression..."
			<< "\n\t\t\t (3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (" << C3.toString() << ") ?";

		// Step 1: C1 + C2
		Complex sum = C1 + C2;
		
		Complex step1_den = C1 / 9.0f;
		cout << "\n\t\tstep #1: (3 * (" << sum.toString()
			<< ") / 7) / (C2 - (" << step1_den.toString() << ")) != (" << C3.toString() << ")";

		// Step 2: numerator divide by 7
		Complex step1_num = 3 * sum;
		Complex step2_C2 = C2 - step1_den;
		Complex step2_num = step1_num / 7.0f;
		cout << "\n\t\tstep #2: ((" << step1_num.toString()
			<< ") / 7) / (" << step2_C2.toString() << ") != (" << C3.toString() << ")";

		// Step 3: numerator / denominator
		Complex step3 = step2_num / step2_C2;
		cout << "\n\t\tstep #3: (" << step2_num.toString() << ") / (" << step2_C2.toString()
			<< ") != (" << C3.toString() << ")";

		//Step 4: 
		cout << "\n\t\tstep #4: (" << step3.toString() << ") != (" << C3.toString() << ")";

		// Step 5: Final comparison
		bool result = (step3 != C3);
		cout << "\n\t\tstep #5: " << (result ? "true" : "false") << "\n";
	}

	string toString() const 
	{
		ostringstream out;

		float re = *realNum;
		float im = *iNum;

		// Treat tiny values as 0
		if (fabs(re) <= EPS) re = 0.0f;
		if (fabs(im) <= EPS) im = 0.0f;

		// Case 1: both zero
		if (re == 0.0f && im == 0.0f) 
		{
			out << "0";
		}
		// Case 2: imaginary zero  just real
		else if (im == 0.0f) {
			out << re;
		}
		// Case 3: real zero  just imaginary
		else if (re == 0.0f)
		{
			out << im << "i";
		}
		// Case 4: both present  force pretty "a ± bi"
		else {
			out << re;
			if (im >= 0)
				out << " + " << im << "i";       // positive imaginary
			else
				out << " - " << fabs(im) << "i"; // negative imaginary
		}

		return out.str();
	}

};



