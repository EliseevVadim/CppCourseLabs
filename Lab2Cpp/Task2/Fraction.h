#pragma once
#include <string>
class Fraction
{
public:	
	static int counter;
	Fraction();
	Fraction(int nominator, int denominator);
	~Fraction();
	Fraction operator+ (Fraction f);
	Fraction operator- (Fraction f);
	Fraction operator* (Fraction f);
	Fraction operator/ (Fraction f);
	void reduce();
	void printFraction();
	void setNominator(int nominator);
	void setDenominator(int denominator);
	int getNom();
	int getDenom();
	int gcd(int n, int m);
	void printAsFraction(double decimal_fraction);
	void printAsFraction(std::string decimal_fraction);
private:
	int nominator_;
	int denominator_;
};
