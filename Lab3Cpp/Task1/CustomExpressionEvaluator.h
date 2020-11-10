#pragma once
#include "ILoggable.h"
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
class CustomExpressionEvaluator:public ExpressionEvaluator, public ILoggable, public IShuffle
{
public:
	CustomExpressionEvaluator();
	CustomExpressionEvaluator(size_t n);
	~CustomExpressionEvaluator() override {};
	void logToScreen() const override;
	void logToFile(const std::string& filename) const override;
	double calculate() const override;
	void shuffle() override;
	void shuffle(size_t i, size_t j) override;
};