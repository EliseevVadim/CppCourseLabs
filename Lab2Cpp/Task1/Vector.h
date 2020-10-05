#pragma once
#include "Matrix.h"
class Vector
{
public:
	Vector(int length);
	~Vector();
	void getVectorFromMatrix(Matrix m);
	void printVector();
	Vector& operator++();
	Vector& operator--();
	Vector& operator++(int);
	Vector& operator--(int);
	int& operator[](int pos);
private:
	int length_;
	int* mas;
};
