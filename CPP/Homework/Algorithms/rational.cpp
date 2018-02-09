//Tyler Champagne
//Ser 221
//Assignment 2


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

class Rational
{
public:
	int numerator;
	int denominator;
	Rational(int numeratorInput, int denominatorInput)//Constructor for num and denom
	{
		this->numerator = numeratorInput;
		this->denominator = denominatorInput;
	}
	Rational(int wholeNumber)//Constructor for a whole number
	{
		this->numerator = wholeNumber;
		this->denominator = 1;
	}
	Rational()//Default constructor
	{
		this->numerator = 0;
		this->denominator = 1;
	}
	void setNumerator(int numeratorInput)//Sets the numerator
	{
		this->numerator = numeratorInput;
	}
	void setDemoninator(int denominatorInput)//Sets the denominator
	{
		this->denominator = denominatorInput;
	}
	void reduction()//Reduces and changes the fraction
	{
		int c;
		if(this->denominator == 0 || this->numerator == 0)//Makes sure the program doesnt divide by 0
		{
			this->numerator = 0;
			this->denominator = 1;
		}

		if(this->denominator < 0)//Changes the numerator to positive
		{
			this->numerator *= (-1);
			this->denominator *= (-1);
		}

		c = gcf(numerator,denominator);//retrives the greatest common factor
		this->numerator /= c;//Reduces by it
		this->denominator /= c;
	}
	int gcf(int a, int b)//Greatest common factor
	{
		if(b==0) return abs(a);
		else return gcf(b, a % b);
	}
	int lcm(int a, int b)//Least common multiple
	{
		int c;
		c = gcf(a,b);
		return a / c *b;
	}
	bool operator==(const Rational& a) const//Checks to see if the fractions are equal
	{
		return this->numerator*a.denominator == this->denominator*a.numerator;
	}
	bool operator<(const Rational& a) const//Checks to see if the fraction is less than the other
	{
		return a > *this;
	}
	bool operator<=(const Rational& a) const//Checks to see if the fraction is less than or equal to the other
	{
		return !(*this == a);
	}
	bool operator>(const Rational& a) const//Checks to see if the fraction is greater than the other
	{
		return (float) this->numerator/this->denominator > (float) a.numerator/a.denominator;
	}
	bool operator>=(const Rational& a) const//Checks to see if the fraction is greater than or equal the other
	{
		return !(*this < a);
	}
	Rational operator+(const Rational& a) const//Adds the fractions
	{
		return Rational((this->numerator*a.denominator) + (this->denominator*a.numerator),a.denominator*this->denominator);
	}
	Rational operator-(const Rational& a) const//Subtracts the fractions
	{
		return Rational((this->numerator*a.denominator) - (this->denominator*a.numerator),a.denominator*this->denominator);
	}
	Rational operator*(const Rational& a) const//Multiplies the fractions
	{
		return Rational(this->numerator * a.numerator,this->denominator * a.denominator);
	}
	Rational operator/(const Rational& a) const//Divides the fractions
	{
		return Rational(this->numerator / a.denominator,this->denominator / a.numerator);
	}
	friend istream& operator>>(istream& in, Rational& a)//Allows input of fractions via cin
	{
		int num,dem;

		in >> num;
		a.setNumerator(num);

		in.ignore(1,'/');

		in >> dem;
		a.setDemoninator(dem);
	}
	friend ostream& operator<<(ostream& out, const Rational& a)//allows output of fractions via cout
	{
		return out << a.numerator << "/" << a.denominator;
	}
};



int main(int argc, char const *argv[])
{
	Rational fraction1, fraction2, fraction3;//Declares the variables
	cout << "Enter fraction 1 (Format:(1/2)): ";
	cin >> fraction1;
	cout << endl;
	cout << "Enter fraction 2 (Format:(3/2)): ";
	cin >> fraction2;

	fraction3 = fraction1 + fraction2;
	cout << fraction3 << endl;

	fraction3 = fraction1 - fraction2;
	cout << fraction3 << endl;

	fraction3 = fraction1 / fraction2;
	cout << fraction3 << endl;

	fraction3 = fraction1 * fraction2;
	cout << fraction3 << endl;

	fraction3 = fraction1 + fraction2;
	fraction3.reduction();
	cout << fraction3 << endl;

	fraction3 = fraction1 - fraction2;
	fraction3.reduction();
	cout << fraction3 << endl;

	fraction3 = fraction1 / fraction2;
	fraction3.reduction();
	cout << fraction3 << endl;

	fraction3 = fraction1 * fraction2;
	fraction3.reduction();
	cout << fraction3 << endl;

	system("PAUSE");
	return 0;
}