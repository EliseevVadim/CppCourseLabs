#pragma once
#include "HomeAppliance.h"
class Reflector: public HomeAppliance, public IControllable
{
public:
	Reflector();
	Reflector(std::string firm, std::string model, unsigned short weight, int temperature, WorkMode mode, unsigned short power, int year, int comfortable_temperature);
	~Reflector() override {}
	void control(int temperature) override;
};

