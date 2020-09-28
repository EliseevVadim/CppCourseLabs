#pragma once
class Vector
{
public:
	Vector(int length);
	~Vector();
	void printVector();
	void prefixDecrease();
	void postfixDecrease();
	Vector operator++();
	Vector operator--();
	Vector operator++(int);
	Vector operator--(int);
	int& operator[](int pos);
private:
	int length_;
	int* mas;
};
