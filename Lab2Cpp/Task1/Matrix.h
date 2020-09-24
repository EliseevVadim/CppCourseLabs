#pragma once
class Matrix
{
public:
	Matrix(int rows, int cols);
	~Matrix();
	int at(int i, int j) const;
	void setAt(int i, int j, int val);
	void printMatrix();
	void prefixIncrease();
	void postfixIncrease();
	void prefixDecrease();
	void postfixDecrease();
private:
	int** mas;
	int rows_;
	int cols_;
};

