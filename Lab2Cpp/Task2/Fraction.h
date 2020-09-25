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
private:
	int nominator_;
	int denominator_;
};
inline Fraction operator + (Fraction f1, Fraction f2) {
	return Fraction(f1.getNom() * f2.getDenom() + f2.getNom() * f1.getDenom(), f1.getDenom() * f2.getDenom());
}
inline Fraction operator - (Fraction f1, Fraction f2) {
	return Fraction(f1.getNom() * f2.getDenom() - f2.getNom() * f1.getDenom(), f1.getDenom() * f2.getDenom());
}
inline Fraction operator * (Fraction f1, Fraction f2) {
	return Fraction(f1.getNom() * f2.getNom(), f1.getDenom() * f2.getDenom());
}
inline Fraction operator / (Fraction f1, Fraction f2) {
	return Fraction(f1.getNom() * f2.getDenom(), f1.getDenom() * f2.getNom());
}
