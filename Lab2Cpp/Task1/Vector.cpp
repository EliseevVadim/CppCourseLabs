#include "Vector.h"
#include <iostream>
#include <ctime>
#include "Matrix.h"
using namespace std;
Vector::Vector(int length) {
	srand(time(NULL));
	mas = new int[length];
	length_ = length;
	for (int i = 0; i < length_; i++) {
		mas[i] = rand() % 101;
	}
}
void Vector::printVector() {
	for (int i = 0; i < length_; i++) {
		cout << mas[i] << " ";
	}
}
void Vector::getVectorFromMatrix(Matrix m) {
	int pos = 0;
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i % 2 != 0) {
				mas[pos] = m.at(i, j);
				pos++;
			}
		}
	}
}
Vector::~Vector() {
	delete[] mas;
	mas = nullptr;
	cout << "\nThe vector was deleted\n";
}
int& Vector::operator[](int pos) {
	return mas[pos];
}
// префиксный инкремент
Vector& Vector::operator++() {
	for (int i = 0; i < length_; i++) {
		++mas[i];
	}
	return *this;
}
// постфиксный инкремент
Vector& Vector::operator++(int) {
	Vector& v = *this;
	for (int i = 0; i < length_; i++) {
		mas[i]++;
	}
	return v;
}
// префиксный декремент
Vector& Vector::operator--() {
	for (int i = 0; i < length_; i++) {
		--mas[i];
	}
	return *this;
}
// постфиксный декремент
Vector& Vector::operator--(int) {
	Vector& v = *this;
	for (int i = 0; i < length_; i++) {
		mas[i]--;
	}
	return v;
}
