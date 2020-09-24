#pragma once
class Vector
{
public:
	Vector(int length);
	~Vector();
	int getElementFromIndex(int i);
	void setElementToIndex(int element, int i);
	void printVector();
	void prefixIncrease();
	void postfixIncrease();
	void prefixDecrease();
	void postfixDecrease();
private:
	int length_;
	int* mas;
};

