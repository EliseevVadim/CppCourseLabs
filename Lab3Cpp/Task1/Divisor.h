#pragma once
#include "ExpressionEvaluator.h"
#include "ILoggable.h"
class Divisor:public ExpressionEvaluator, public ILoggable
{
public:
	Divisor();
	Divisor(size_t n);
	~Divisor() override {};
	void logToScreen() const override;
	void logToFile(const std::string& filename) const override;
	double calculate() const override;
};

