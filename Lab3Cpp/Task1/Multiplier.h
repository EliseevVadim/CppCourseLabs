#pragma once
#include "ExpressionEvaluator.h"
#include "ILoggable.h"
class Multiplier: public ExpressionEvaluator, public ILoggable
{
public:
	Multiplier();
	Multiplier(size_t n);
	~Multiplier() override;
	void logToScreen() const override;
	void logToFile(const std::string& filename) const override;
	double calculate() const override;
};

