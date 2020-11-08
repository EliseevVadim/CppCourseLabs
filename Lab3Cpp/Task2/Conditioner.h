#pragma once
#include "HomeAppliance.h"
class Conditioner :public HomeAppliance, public  IControllable
{
public:
	Conditioner();
	Conditioner(std::string firm, std::string model, unsigned short weight, int temperature, WorkMode mode, unsigned short power, int year, int comfortable_temperature);
	~Conditioner() override{}
	void control(int temperature) override;
};

