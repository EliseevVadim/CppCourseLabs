#pragma once
class Matrix
{
public:
	Matrix(int rows, int cols);
	~Matrix();
	int at(int i, int j) const;
	void setAt(int i, int j, int val);
	void printMatrix();
	int factorial(int num);
	Matrix operator++();
	Matrix operator--();
	Matrix operator++(int);
	Matrix operator--(int);
private:
	int** mas;
	int rows_;
	int cols_;
};
