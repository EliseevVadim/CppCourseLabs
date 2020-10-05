#include "Matrix.h"
#include <iostream>
using namespace std;
int Matrix::factorial(int num) {
	int fact = 1;
	for (int i = 1; i <= num; i++) {
		fact *= i;
	}
	return fact;
}
Matrix::Matrix(int rows, int cols) {
	mas = new int* [rows];
	for (size_t i = 0; i < rows; i++) {
		*(mas + i) = new int[cols];
	}
	rows_ = rows;
	cols_ = cols;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			*(*(mas + i) + j) = rand()%100;
		}
	}
}
void Matrix::printMatrix() {
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			cout.width(8);
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
}
int Matrix::at(int i, int j) const {
	if (i >= rows_ || j >= cols_) {
		return NULL;
	}
	else
	{
		return mas[i][j];
	}
}
void Matrix::setAt(int i, int j, int val) {
	mas[i][j] = val;
}
Matrix::~Matrix() {
	for (size_t i = 0; i < rows_; i++)
	{
		delete[] mas[i];
	}
	delete[] mas;
	mas = nullptr;
	cout << "\nThe matrix was deleted\n";
}
// префиксный инкремент
Matrix& Matrix::operator++() {
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			++mas[i][j];
		}
	}
	return *this;
}
// постфиксный инкремент
Matrix& Matrix::operator++(int) {
	Matrix& m = *this;
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			mas[i][j]++;
		}
	}
	return m;
}
//префиксный декремент
Matrix& Matrix::operator--() {
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			--mas[i][j];
		}
	}
	return *this;
}
// постфиксный декремент
Matrix& Matrix::operator--(int) {
	Matrix& m = *this;
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			mas[i][j]--;
		}
	}
	return m;
}
