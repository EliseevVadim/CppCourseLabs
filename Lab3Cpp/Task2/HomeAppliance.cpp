#include "HomeAppliance.h"
#include "WorkMode.h"
#pragma region Конструкторы и деструктор
HomeAppliance::HomeAppliance() {
	firm_ = "0";
	model_ = "0";
	weight_ = 0;
	temperature_ = 0;
	mode_ = WorkMode::OFF;
	power_ = 0;
	year_ = 1900;
	comfortable_temperature_ = 20;
}
HomeAppliance::HomeAppliance(std::string firm, std::string model, unsigned short weight, int temperature, WorkMode mode, unsigned short power, int year, int comfortable_temperature) {
	firm_ = firm;
	model_ = model;
	weight_ = weight;
	temperature_ = temperature;
	mode_ = mode;
	power_ = power;
	year_ = year;
	comfortable_temperature_ = comfortable_temperature;
}
HomeAppliance::~HomeAppliance() {

}
#pragma endregion
#pragma region Сеттеры
void HomeAppliance::setFirm(std::string firm) {
	firm_ = firm;
}
void HomeAppliance::setModel(std::string model) {
	model_ = model;
}
void HomeAppliance::setWeight(unsigned short weight) {
	weight_ = weight;
}
void HomeAppliance::setTemperature(int temperature) {
	temperature_ = temperature;
}
void HomeAppliance::setWorkMode(WorkMode mode) {
	mode_ = mode;
}
void HomeAppliance::setPower(unsigned short power) {
	power_ = power;
}
void HomeAppliance::setYear(int year) {
	year_ = year;
}
void HomeAppliance::setComfortableTemperature(int comfortable_temperature) {
	comfortable_temperature_ = comfortable_temperature;
}
#pragma endregion
#pragma region Геттеры
std::string HomeAppliance::getFirm() const {
	return firm_;
}
std::string HomeAppliance::getModel () const {
	return model_;
}
unsigned short HomeAppliance::getWeight() const {
	return weight_;
}
int HomeAppliance::getTemperature() const {
	return temperature_;
}
WorkMode HomeAppliance::getWorkMode() const {
	return mode_;
}
unsigned short HomeAppliance::getPower() const {
	return power_;
}
int HomeAppliance::getYear() const {
	return year_;
}
int HomeAppliance::getComfortableTemperature() const {
	return comfortable_temperature_;
}
#pragma endregion
void HomeAppliance::control(int temperature){}