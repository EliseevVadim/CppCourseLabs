#include "Conditioner.h"
#include <iostream>
Conditioner::Conditioner() {
	firm_ = "0";
	model_ = "0";
	weight_ = 0;
	temperature_ = 0;
	mode_ = WorkMode::OFF;
	power_ = 0;
	year_ = 1900;
	comfortable_temperature_ = 20;
}
Conditioner::Conditioner(std::string firm, std::string model, unsigned short weight, int temperature, WorkMode mode, unsigned short power, int year, int comfortable_temperature) {
	firm_ = firm;
	model_ = model;
	weight_ = weight;
	temperature_ = temperature;
	mode_ = mode;
	power_ = power;
	year_ = year;
	comfortable_temperature_ = comfortable_temperature;
}
void Conditioner::control(int temperature) {
	setlocale(0, "Russian");
	if (temperature < 10) {
		std::cout << "����������� ���� 10 ��������. ����������� �����������.\n";
		mode_ = WorkMode::OFF;
	}
	else if (temperature > comfortable_temperature_&& temperature >= 10) {
		std::cout << "����������� ���� �������. ����������� ��������� � ����� ����������.\n";
		mode_ = WorkMode::Freezing;
	}
	else if (temperature == comfortable_temperature_ && temperature >= 10) {
		std::cout << "����������� ������������� ������� ������������. ����������� ��������� � ����� �����������.\n";
		mode_ = WorkMode::Staying;
	}
	else
	{
		std::cout << "����������� ���� ����������. ����������� ��������� � ����� ����������.\n";
		mode_ = WorkMode::Heating;
	}
}	