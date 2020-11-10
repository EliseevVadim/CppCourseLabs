#include "Divisor.h"
#include <iostream>
#include <fstream>
Divisor::Divisor() {
	mas = new double[20];
	for (int i = 0; i < 20; i++) {
		mas[i] = 0;
	}
	length = 20;
}
Divisor::Divisor(size_t n) {
	mas = new double[n];
	for (int i = 0; i < n; i++) {
		mas[i] = 0;
	}
	length = n;
}
double Divisor::calculate() const {
	double res = mas[0];
	for (size_t i = 1; i < length; i++) {
		res /= mas[i];
	}
	return res;
}
void Divisor::logToScreen() const {
	for (size_t i = 0; i < length; i++) {
		if (mas[i] >= 0) {
			int zeros = 0;
			std::string temp = std::to_string(mas[i]);
			for (int i = temp.length() - 1; i >= 0; i--) {
				if (temp[i] == '0') {
					temp.erase(i, 1);
				}
				else if (temp[i] == '.')
				{
					temp.erase(i, 1);
					break;
				}
				else if (temp[i] != '0' && temp[i] != '.')
				{
					break;
				}
			}
			if (i != length - 1)
				std::cout << temp << "/";
			else
			{
				std::cout << temp;
			}
		}
		else
		{
			int zeros = 0;
			std::string temp = std::to_string(mas[i]);
			for (int i = temp.length() - 1; i >= 0; i--) {
				if (temp[i] == '0') {
					temp.erase(i, 1);
				}
				else if (temp[i] == '.')
				{
					temp.erase(i, 1);
					break;
				}
				else if (temp[i] != '0' && temp[i] != '.')
				{
					break;
				}
			}
			if (i != length - 1)
				std::cout << "(" << temp << ")" << "/";
			else
			{
				std::cout << "(" << temp << ")";
			}
		}
	}
	std::cout << " <" << "Total " << length << ">\n";
	std::cout << "<" << "Result " << calculate() << ">\n";
}
void Divisor::logToFile(const std::string& filename) const {
	std::ofstream log(filename, std::ios_base::app | std::ios_base::out);
	for (size_t i = 0; i < length; i++) {
		if (mas[i] >= 0) {
			int zeros = 0;
			std::string temp = std::to_string(mas[i]);
			for (int i = temp.length() - 1; i >= 0; i--) {
				if (temp[i] == '0') {
					temp.erase(i, 1);
				}
				else if (temp[i] == '.')
				{
					temp.erase(i, 1);
					break;
				}
				else if (temp[i] != '0' && temp[i] != '.')
				{
					break;
				}
			}
			if (i != length - 1)
				log << temp << "/";
			else
			{
				log << temp;
			}
		}
		else
		{
			int zeros = 0;
			std::string temp = std::to_string(mas[i]);
			for (int i = temp.length() - 1; i >= 0; i--) {
				if (temp[i] == '0') {
					temp.erase(i, 1);
				}
				else if (temp[i] == '.')
				{
					temp.erase(i, 1);
					break;
				}
				else if (temp[i] != '0' && temp[i] != '.')
				{
					break;
				}
			}
			if (i != length - 1)
				log << "(" << temp << ")" << "/";
			else
			{
				log << "(" << temp << ")";
			}
		}
	}
	log << " <" << "Total " << length << ">\n";
	log << "<" << "Result " << calculate() << ">\n";
}