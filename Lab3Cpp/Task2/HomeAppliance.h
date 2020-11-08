#pragma once
#include <string>
#include "WorkMode.h"
#include "IControllable.h"
class HomeAppliance:public IControllable
{
public:
	HomeAppliance();
	HomeAppliance(std::string firm, std::string model, unsigned short weight, int temperature, WorkMode mode, unsigned short power, int year, int comfortable_temperature);
	virtual ~HomeAppliance();
	void setFirm(std::string firm);
	void setModel(std::string model);
	void setWeight(unsigned short weight);
	void setTemperature(int temperature);
	void setWorkMode(WorkMode mode);
	void setPower(unsigned short power);
	void setYear(int year);
	void setComfortableTemperature(int comfortable_temperature);
	void control(int temperature) override;
	std::string getFirm() const;
	std::string getModel() const;
	unsigned short getWeight() const;
	int getTemperature() const;
	WorkMode getWorkMode() const;
	unsigned short getPower() const;
	int getYear() const;
	int getComfortableTemperature() const;
protected:
	std::string firm_;
	std::string model_;
	unsigned short weight_;
	int temperature_;
	WorkMode mode_;
	unsigned short power_;
	int year_;
	int comfortable_temperature_;
};