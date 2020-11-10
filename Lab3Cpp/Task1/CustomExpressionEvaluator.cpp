#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <string>
#include <fstream>
CustomExpressionEvaluator::CustomExpressionEvaluator() {
	mas = new double[20];
	for (int i = 0; i < 20; i++) {
		mas[i] = 0;
	}
	length = 20;
}
CustomExpressionEvaluator::CustomExpressionEvaluator(size_t n) {
	mas = new double[n];
	for (int i = 0; i < n; i++) {
		mas[i] = 0;
	}
	length = n;
}
double CustomExpressionEvaluator::calculate() const {	
	if (length % 2 != 0) {
		double res = mas[0];
		double temp = 1;
		for (size_t i = 1; i < length; i += 2) {
			temp *= mas[i];
			temp *= mas[i + 1];
			res += temp;
			temp = 1;
		}
		return res;
	}
	else {
		double res = mas[0];
		double temp = 1;
		for (size_t i = 1; i < length-1; i += 2) {
			temp *= mas[i];
			temp *= mas[i + 1];
			res += temp;
			temp = 1;
		}
		return res+mas[length-1];
	}
}
void CustomExpressionEvaluator::logToScreen() const {
	bool plus = true;
	for (size_t i = 0; i < length; i++) {
		if (plus) {
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
				if(i!=length-1)
				std::cout << temp << "+";
				else
				{
					std::cout << temp;
				}
				plus = false;
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
				std::cout << "(" << temp << ")" << "+";
				else
				{
					std::cout << "(" << temp << ")";
				}
				plus = false;
			}
		}
		else 
		{
			if (mas[i] >= 0) {
				int zeros = 0;
				std::string temp = std::to_string(mas[i]);
				for (int i = temp.length() - 1; i >= 0; i--) {
					if (temp[i] == '0' ) {
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
				std::cout << temp << "*";
				else
				{
					std::cout << temp;
				}
				plus = true;
			}
			else
			{
				int zeros = 0;
				std::string temp = std::to_string(mas[i]);
				for (int i = temp.length() - 1; i >= 0; i--) {
					if (temp[i] == '0') {
						temp.erase(i, 1);
					}
					else if(temp[i] == '.')
					{
						temp.erase(i, 1);
						break;
					}
					else if (temp[i]!='0'&&temp[i]!='.')
					{
						break;
					}
				}			
				if (i != length - 1)
				std::cout << "(" << temp << ")" << "*";
				else
				{
					std::cout << "(" << temp << ")";
				}
				plus = true;
			}			
		}		
	}
	std::cout << " <" << "Total " << length << ">\n";
	std::cout << "<" << "Result " << calculate() << ">\n";
}
void CustomExpressionEvaluator::logToFile(const std::string& filename) const{
	std::ofstream log(filename, std::ios_base::app | std::ios_base::out);
	bool plus = true;
	for (size_t i = 0; i < length; i++) {
		if (plus) {
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
					log << temp << "+";
				else
				{
					log << temp;
				}
				plus = false;
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
					log << "(" << temp << ")" << "+";
				else
				{
					log << "(" << temp << ")";
				}
				plus = false;
			}
		}
		else
		{
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
					log << temp << "*";
				else
				{
					log << temp;
				}
				plus = true;
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
					log << "(" << temp << ")" << "*";
				else
				{
					log << "(" << temp << ")";
				}
				plus = true;
			}
		}
	}
	log << " <" << "Total " << length << ">\n";
	log << "<" << "Result " << calculate() << ">\n";
}
void CustomExpressionEvaluator::shuffle(size_t i, size_t j) {
	if (mas[i] - (int)mas[i] != 0 || mas[j] - (int)mas[j] != 0) {
		std::swap(mas[i], mas[j]);
	}
}
void CustomExpressionEvaluator::shuffle() {
	for (int i = 0; i < length - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (mas[j]< mas[min])
			{
				min = j;
			}
		}
		std::swap(mas[min], mas[i]);
	}
}