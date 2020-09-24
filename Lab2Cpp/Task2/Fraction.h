#pragma once
#include <string>
class Fraction
{

public:	
	static int counter;
	Fraction();
	Fraction(int nominator, int denominator);
	~Fraction();
	void reduce();
	void printFraction();
	void setNominator(int nominator);
	void setDenominator(int denominator);
	int getNom();
	int getDenom();
	int gcd(int n, int m);
	void printAsFraction(double decimal_fraction);
	void printAsFraction(std::string decimal_fraction);
	Fraction summarize(Fraction fraction1, Fraction fraction2);
	Fraction subtract(Fraction fraction1, Fraction fraction2);
	Fraction multiply(Fraction fraction1, Fraction fraction2);
	Fraction divide(Fraction fraction1, Fraction fraction2);
private:
	int nominator_;
	int denominator_;
};

