#pragma once
#include<iomanip>
class polynomial
{
private:
	size_t terms = 0;
	double* coefficients = nullptr;

public:

	//Default Constructor
	polynomial()
	{
		for (int i = 0; i < terms; i++)
		{
			coefficients[i] = 0;
		}
	}

	//Parameterized Constructor
	polynomial(double a0)
	{
		if (coefficients != nullptr)
		{
			coefficients[0] = a0;
		}
	}
	
	//Copy Constructor
	polynomial(const polynomial& source)
	{
		terms = source.terms;
		coefficients = new double[terms];

		for (int i = 0; i < terms; i++)
		{
			coefficients[i] = source.coefficients[i];
		}
	}

	//Overload assignment operator =
	void operator=(const polynomial& obj)
	{
		if (obj.terms == 0)
			return;
		 
		terms = obj.terms;
		coefficients = new double[terms];

		for (int i = terms - 1; i > -1; i--)
		{
			coefficients[i] = obj.coefficients[i];
		}
	}

	//Destructor
	~polynomial()
	{
		delete [] coefficients;
	}

	//Precondition: The terms must be existed.
	//Postcondition: Adds the given amount to the coefficient of specified exponent. 
	void add_to_coef(double amount, unsigned int exponent)
	{
		coefficients[exponent] += amount;
	}

	//Precondition: The terms must be existed.
	//Postcondition: Sets the coefficient for the specifed exponent.
	void assign_coef(double coefficient, unsigned int exponent)
	{
		coefficients[exponent] = coefficient;
	}

	//Precondition: The terms must be existed.
	//Postcondition: All coefficient 
	void clear()
	{
		if (terms > -1)
			for (int i = 0; i < terms; i++)
			{
				coefficients[i] = 0;
			}
	}

	//Precondition: The input should not be less than the previous terms.
	//Postcondition: Sets new terms.
	void reserve(size_t number)
	{
		if (terms < number)
		{
			double* temp = new double[number];

			for (int i = 0; i < terms; i++)
			{
				temp[i] = coefficients[i];
			}

			terms = number;

			delete[] coefficients;
			coefficients = temp;
		
		}
	}

	//Postcondition: Sets the terms for an equation.
	void setTerms(size_t number)
	{
		//delete[] coefficients;
		terms = number;
		coefficients = new double[terms]();
	}

	//Postcondition: Returns the terms.
	size_t getTerms() const
	{
		return terms;
	}

	//Postcondition: Returns the coefficient
	double getCoefficient(int exponent) const
	{
		return coefficients[exponent];
	}

	//Postcondition: Return the evaluation based on x.
	double evaluate(double value)
	{
		double evaluationResult = 0.0;

		for (int i = terms - 1; i > -1; i--)
		{
			evaluationResult += coefficients[i] * pow(value, i);
		}

		return evaluationResult;
	}

	// Precondition: terms >= 1; coefficients is valid for indices.
	// Postcondition: Returns the formal derivative. 
	polynomial derivative() const
	{
		polynomial d;
		size_t dTerms = terms - 1;
		d.setTerms(dTerms);

		for (int i = terms - 1; i > 0; i--)
		{
			d.assign_coef((double(i) * coefficients[i]), (i - 1));
		}

		return d;
	}

	// Precondition: terms >= 1; coefficients is valid for indices.
	// Postcondition: Returns an antiderivative.
	polynomial integral() const
	{
		polynomial inte;
		size_t iTerms = terms + 1;
		inte.setTerms(iTerms);

		for (int i = terms; i > 0; i--)
		{
			inte.assign_coef(coefficients[i - 1] / double(i), i);
		}

		return inte;
	}
	
	// Precondition: both have valid data.
	// Postcondition: return sum of two polynomials.
	polynomial operator + (const polynomial& obj)
	{
		polynomial sum;
		size_t maxTerm = 0;

		if (terms > obj.terms)
		{
			maxTerm = terms;
		}
		else
		{
			maxTerm = obj.terms;
		}

		sum.setTerms(maxTerm);

		for (int i = maxTerm - 1; i > -1; i--)
		{
			double a = 0.0;

			if (i < terms)
			{
				a = coefficients[i];
			}

			double b = 0.0;

			if (b < obj.terms)
			{
				b = obj.coefficients[i];
			}

			sum.add_to_coef(a + b, i);
		}

		return sum;
	}

	// Precondition: both have valid data
	// Postcondition: return difference of two polynomials
	polynomial operator - (const polynomial& obj)
	{
		polynomial sub;
		size_t maxTerm = 0;

		if (terms > obj.terms)
		{
			maxTerm = terms;
		}
		else
		{
			maxTerm = obj.terms;
		}

		sub.setTerms(maxTerm);

		for (int i = maxTerm - 1; i > -1; i--)
		{
			double a = 0.0;

			if (i < terms)
			{
				a = coefficients[i];
			}

			double b = 0.0;

			if (b < obj.terms)
			{
				b = obj.coefficients[i];
			}

			sub.add_to_coef(a - b, i);
		}

		return sub;
	}

	// Precondition: both have valid data.
	// Postcondition: return product polynomial.
	friend polynomial operator * (const polynomial& obj1, const polynomial& obj2)
	{
		polynomial multi;
		size_t maxTerm = 0;

		// product degree is (terms-1) + (obj.terms-1)  → size = terms + obj.terms - 1
		if (obj1.terms == 0 || obj2.terms == 0)
		{
			maxTerm = 1; // represent zero polynomial as size 1 with coef[0] = 0
		}
		else
		{
			maxTerm = obj1.terms + obj2.terms - 1;
		}

		multi.setTerms(maxTerm);

		// Fill with sums of pairwise products
		for (int i = static_cast<int>(obj1.terms) - 1; i >= 0; --i)
		{
			for (int j = static_cast<int>(obj2.terms) - 1; j >= 0; --j)
			{
				// i + j is the power; add to existing coeff (convolution)
				multi.add_to_coef(obj1.coefficients[i] * obj2.coefficients[j], static_cast<size_t>(i + j));
			}
		}

		return multi;
	
	}

	// Precondition: obj has valid data.
	// Postcondition: return scaled polynomial.
	friend polynomial operator * (double value, const polynomial& obj)
	{
		polynomial scale;
		size_t maxTerm = obj.terms;

		scale.setTerms(maxTerm);

		for (int i = static_cast<int>(obj.terms) - 1; i >= 0; --i)
		{
			scale.add_to_coef(value * obj.coefficients[i], static_cast<size_t>(i));
		}

		return scale;
	}

	// Precondition: obj has valid data.
	// Postcondition: return scaled polynomial.
	friend polynomial operator*(const polynomial& obj, double value)
	{
		return value * obj; 
	}

	// Precondition: obj has valid data.
	// Postcondition: output polynomial to stream.
	friend ostream& operator<<(ostream& os, const polynomial& obj)
	{
		cout.unsetf(ios::fixed); // make sure 'fixed' manipulator doesn't not mess up the format.

		if (obj.terms == 0)
		{
			os << 0;
			return os;
		}

		for (int i = obj.getTerms() - 1; i > -1; i--)
		{
			if (obj.coefficients[i] < 0)
			{
				os << " - ";
			}

			if (i != 0 && obj.coefficients[i] != 0)
			{
				os << setprecision(5) << abs(obj.coefficients[i]);

				if (i != 1)
				{
					os << "x^" + to_string(i);
				}
				else
				{
					os << "x";
				}

				if (obj.coefficients[i - 1] > 0 && i - 1 != -1)
				{
					os << " + ";
				}
			}
			else if (obj.coefficients[i] != 0)
				os << setprecision(5) << abs(obj.coefficients[i]);

		}
		return os;
	}
};

