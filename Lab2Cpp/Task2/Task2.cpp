#include <iostream>
#include <string>
#include <cstring>
#include "Fraction.h"
/*Елисеев Вадим, ИВТ-5, Вариант 7
Написать класс Fraction для представления обыкновенных дробей (как отношения двух целых чисел x/y). Перегрузить операторы +, -, *, / для дробей. Реализовать метод void reduce() для сокращения дроби, а также статические методы:
 int gcd(int n, int m)
функция для нахождения наибольшего общего делителя чисел n и m;
 void printAsFraction(double decimal_fraction)
 void printAsFraction(char* decimal_fraction)
перегруженные методы вывода десятичной дроби в виде обыкновенной (например, при значении decimal_fraction = 0.43 на экране должно вывестись 43/100, при 0.25 – 1/4 и т.д.).
Также реализовать в виде статического члена класса счетчик всех созданных на данный момент в программе экземпляров дробей.
Продемонстрировать работу созданного класса. Создать несколько объектов дробей. Произвести операции сложения, вычитания, умножения и деления дробей. Вывести на экран результаты. Показать также результаты работы статических методов класса.*/
int main()
{
	setlocale(0, "Russian");
	Fraction f(1, 2);
	Fraction f1(1, 3);
	Fraction res = res.summarize(f, f1);
	res.reduce();
	res.printFraction();
	Fraction res1 = res.subtract(f, f1);
	res1.reduce();
	res1.printFraction();
	Fraction res2 = res2.multiply(f, f1);
	res2.reduce();
	res2.printFraction();
	Fraction res3 = res3.divide(f, f1);
	res3.reduce();
	res3.printFraction();
	res3.printAsFraction(0.43);
	res3.printAsFraction("0.25");
	std::cout << "Число всех созданных дробей: " << Fraction::counter;
}