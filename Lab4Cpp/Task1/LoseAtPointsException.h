#pragma once
#include <stdexcept>
class LoseAtPointsException: public std::exception
{
public:
	LoseAtPointsException();
};

