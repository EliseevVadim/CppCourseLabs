#pragma once
#include <string>
class SymbolsComparer
{
public:
	SymbolsComparer(std::string tester){
		tester_ = tester;
	}
	bool operator()(std::string for_test) {
		return tester_[0] == for_test[0];
	}
private:
	std::string tester_;
};