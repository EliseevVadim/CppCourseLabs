#include "ExpressionEvaluator.h"
#include <iostream>
ExpressionEvaluator::ExpressionEvaluator() {
	mas = new double[20];
	for (int i = 0; i < 20; i++) {
		mas[i]=0;
	}
	length = 20;
}
ExpressionEvaluator::ExpressionEvaluator(size_t n) {
	mas = new double[n];
	for (int i = 0; i < n; i++) {
		mas[i] = 0;
	}
	length = n;
}
void ExpressionEvaluator::setOperand(size_t pos, double value) {
	mas[pos] = value;
}
void ExpressionEvaluator::setOperands(double ops[], size_t n) {
	for (int i = 0; i < n; i++) {
		mas[i] = ops[i];
	}

}
double ExpressionEvaluator::calculate() const {
	return 0;
}
void ExpressionEvaluator::logToScreen() const{
	std::cout << "log";
}
void ExpressionEvaluator::logToFile(const std::string& filename) const {

}
ExpressionEvaluator::~ExpressionEvaluator() {
	delete[] mas;
}