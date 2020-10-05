#include "Fraction.h"
#include <iostream>
#include <cmath>
#include <string>
Fraction::Fraction() {
	nominator_ = 0;
	denominator_ = 0;
	counter++;
}
Fraction::Fraction(int nominator, int denominator) {
	if (denominator != 0) {
		nominator_ = nominator;
		denominator_ = denominator;;
		counter++;
	}
	else
	{
		std::cout << "Error" << std::endl;
	}
}
Fraction::~Fraction() {
}
void Fraction::printFraction() {
	if (nominator_ != 0) {
		std::cout << nominator_ << "/" << denominator_ << std::endl;
	}
	else
	{
		std::cout << 0 << std::endl;
	}
}
void Fraction::reduce() {
	int gcd1 = gcd(nominator_, denominator_);
	nominator_ /= gcd1;
	denominator_ /= gcd1;
}
int Fraction::getNom() {
	return nominator_;
}
int Fraction::getDenom() {
	return denominator_;
}
void Fraction::printAsFraction(std::string decimal_fraction) {	
	std::string s2;
	std::string s1;
	bool flag = false;
	int pos = 0;
	for (int i = 0; i < decimal_fraction.length(); ++i) {
		if (flag) {
			s2 += decimal_fraction[i];
		}
		else
		{
			s1 += decimal_fraction[i];
		}
		if (decimal_fraction[i] == '.') {
			flag = true;
		}
	}
	for (int i = s2.length() - 1; i >= 0; --i) {
		if (s2[i] == '0') {
			s2.erase(i, 1);
		}
		else
		{
			break;
		}
	}
	s1.erase(s1.length() - 1, 1);
	int nom = atoi(s1.c_str());
	int zeros = 0;
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] != '0') {
			break;
		}
		else
		{
			zeros++;
		}
	}
	int denom = atoi(s2.c_str());
	Fraction f;
	if (denom != 0) {
		int newdenom = 1;
		while (denom / newdenom > 0)
		{
			newdenom *= 10;
		}
		nom = nom * newdenom + denom;
		f.setNominator(nom);
		f.setDenominator(newdenom*std::pow(10, zeros));
		f.reduce();
		f.printFraction();
	}
	else {
		std::cout << nom<<std::endl;
	}
}
void Fraction::setNominator(int nominator) {
	nominator_ = nominator;
}
void Fraction::setDenominator(int denominator) {
	denominator_ = denominator;
}
void Fraction::printAsFraction(double decimal_fraction) {
	std::string s;
	s = std::to_string(decimal_fraction);
	std::string s2;
	std::string s1;
	bool flag = false;
	int pos = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (flag) {
			s2 += s[i];
		}
		else
		{
			s1 += s[i];
		}
		if (s[i] == '.') {
			flag = true;
		}
	}
	for (int i = s2.length() - 1; i >= 0; --i) {
		if (s2[i] == '0') {
			s2.erase(i, 1);
		}
		else
		{
			break;
		}
	}
	s1.erase(s1.length() - 1, 1);
	int nom = atoi(s1.c_str());
	int zeros = 0;
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] != '0') {
			break;
		}
		else
		{
			zeros++;
		}
	}
	
	int denom = atoi(s2.c_str());
	Fraction f;
	if (denom != 0) {
		int newdenom = 1;
		while (denom / newdenom > 0)
		{
			newdenom *= 10;
		}
		nom = nom * newdenom + denom;
		f.setNominator(nom);
		f.setDenominator(newdenom * std::pow(10, zeros));
		f.reduce();
		f.printFraction();
	}
	else {
		std::cout << nom << std::endl;
	}
}
Fraction Fraction::operator+ (Fraction f) {
	Fraction res(this->nominator_ * f.denominator_ + f.nominator_ * this->denominator_, this->denominator_ * f.denominator_);
	res.reduce();
	return res;
}
Fraction Fraction::operator-(Fraction f) {
	Fraction res(this->nominator_ * f.denominator_ - f.nominator_ * this->denominator_, this->denominator_ * f.denominator_);
	res.reduce();
	return res;
}
Fraction Fraction::operator* (Fraction f) {
	Fraction res(this->nominator_ * f.nominator_, this->denominator_ * f.denominator_);
	res.reduce();
	return res;
}
Fraction Fraction::operator/ (Fraction f) {
	Fraction res(this->nominator_ * f.denominator_, this->denominator_ * f.nominator_);
	res.reduce();
	return res;
}
int Fraction::gcd(int n, int m) {
	int gcd = 1;
	while (m != 0)
	{
		gcd = m;
		m = n % m;
		n = gcd;
	}
	return gcd;
}
int Fraction::counter = 0;
