#include "Reflector.h"
#include <iostream>
Reflector::Reflector() {
	firm_ = "0";
	model_ = "0";
	weight_ = 0;
	temperature_ = 0;
	mode_ = WorkMode::OFF;
	power_ = 0;
	year_ = 1900;
	comfortable_temperature_ = 20;
}
Reflector::Reflector(std::string firm, std::string model, unsigned short weight, int temperature, WorkMode mode, unsigned short power, int year, int comfortable_temperature) {
	firm_ = firm;
	model_ = model;
	weight_ = weight;
	temperature_ = temperature;
	mode_ = mode;
	power_ = power;
	year_ = year;
	comfortable_temperature_ = comfortable_temperature;
}
void Reflector::control(int temperature) {
	if (temperature > 45) {
		std::cout << "Температура выше 45 градусов. Обогреватель выключается.\n";
		mode_ = WorkMode::OFF;
	}
	else if (temperature<comfortable_temperature_)
	{
		std::cout << "Температура ниже удобной. Обогреватель переходит в режим нагревания.\n";
		mode_ = WorkMode::Heating;
	}
	else if (temperature >= comfortable_temperature_) {
		std::cout << "Температура выше либо равна удобной. Оборгеватель переходит в режим поддержания температуры.\n";
		mode_ = WorkMode::Staying;
	}
}