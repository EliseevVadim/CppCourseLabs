#include "Vector.h"
#include <iostream>
using namespace std;
Vector::Vector(int length) {
	mas = new int[length];
	length_ = length;
}
void Vector::setElementToIndex(int element, int i) {
	mas[i] = element;
}
void Vector::printVector() {
	for (int i = 0; i < length_; i++) {
		cout << mas[i] << " ";
	}
}
int Vector::getElementFromIndex(int i) {
	if (i >= length_) {
		return NULL;
	}
	else
	{
		return mas[i];
	}
}
Vector::~Vector() {
	delete[] mas;
	mas = nullptr;
	cout << "\nThe vector was deleted\n";
}
void Vector::prefixIncrease() {
	for (int i = 0; i < length_; i++) {
		++mas[i];
	}
}
void Vector::postfixIncrease() {
	for (int i = 0; i < length_; i++) {
		mas[i]++;
	}
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