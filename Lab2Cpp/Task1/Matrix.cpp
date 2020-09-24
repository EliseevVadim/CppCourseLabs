#include "Matrix.h"
#include <iostream>
using namespace std;
Matrix::Matrix(int rows, int cols) {
	mas = new int* [rows];
	for (size_t i = 0; i < rows; i++) {
		*(mas + i) = new int[cols];
	}
	rows_ = rows;
	cols_ = cols;
}
void Matrix::printMatrix() {
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
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
void Matrix::postfixIncrease() {
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			mas[i][j]++;
		}
	}
}
void Matrix::prefixIncrease() {
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			++mas[i][j];
		}
	}
}
void Matrix::postfixDecrease() {
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			mas[i][j]--;
		}
	}
}
void Matrix::prefixDecrease() {
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			--mas[i][j];
		}
	}
}
