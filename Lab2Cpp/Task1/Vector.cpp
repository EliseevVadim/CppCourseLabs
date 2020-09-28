#include "Vector.h"
#include <iostream>
using namespace std;
Vector::Vector(int length) {
	mas = new int[length];
	length_ = length;
}
void Vector::printVector() {
	for (int i = 0; i < length_; i++) {
		cout << mas[i] << " ";
	}
}
Vector::~Vector() {
	delete[] mas;
	mas = nullptr;
	cout << "\nThe vector was deleted\n";
}
void Vector::prefixDecrease() {
	for (int i = 0; i < length_; i++) {
		--mas[i];
	}
}
void Vector::postfixDecrease() {
	for (int i = 0; i < length_; i++) {
		mas[i]--;
	}
}
int& Vector::operator[](int pos) {
	return mas[pos];
}
// префиксный инкремент
Vector Vector::operator++() {
	for (int i = 0; i < length_; i++) {
		++mas[i];
	}
	return *this;
}
// постфиксный инкремент
Vector Vector::operator++(int) {
	Vector& v = *this;
	for (int i = 0; i < length_; i++) {
		mas[i]++;
	}
	return v;
}
// префиксный декремент
Vector Vector::operator--() {
	for (int i = 0; i < length_; i++) {
		--mas[i];
	}
	return *this;
}
// постфиксный декремент
Vector Vector::operator--(int) {
	Vector& v = *this;
	for (int i = 0; i < length_; i++) {
		mas[i]--;
	}
	return v;
}
