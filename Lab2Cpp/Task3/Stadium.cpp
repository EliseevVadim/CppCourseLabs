#include "Stadium.h"
#include <string>
#include <iostream>
#include <fstream>
Stadium::Stadium() {
	club_ = "";
	complexity_ = NULL;
	location_ = "";
	sectors_num_ = NULL;
}
Stadium::Stadium(std::string location, std::string club, short sectors_num, int complexity) {
	club_ = club;
	location_ = location;
	sectors_num_ = sectors_num;
	complexity_ = complexity;
}
Stadium::~Stadium() {	
}
float Stadium::getPercent() {
	return (attendance_*1.0/complexity_)*100.0;
}
void Stadium::setClub(std::string club) {
	club_ = club;
}
void Stadium::setAverageValue(float value) {
	average = value;
}
float Stadium::getAverageValue() {
	return average;
}
void Stadium::setComplexity(int complexity) {
	complexity_ = complexity;
}
void Stadium::setLoc(std::string location) {
	location_ = location;
}
void Stadium::setSectorsNumber(short sectors_num) {
	sectors_num_ = sectors_num;
}
void Stadium::printInfo() {
	std::cout << "Адрес стадиона: " << location_<<std::endl;
	std::cout << "Владеющий клуб: " << club_<<std::endl;
	std::cout << "Число секторов: " << sectors_num_ << std::endl;
	std::cout << "Вместимость: " << complexity_ << std::endl;
	std::cout << "Средний процент посещаемости: " << average << std::endl;
	std::cout << "-------------------------------------------------------"<<std::endl;
}
void::Stadium::setAttendance(int attendance) {
	attendance_ = attendance;
}
void Stadium::serialize(std::string filename) {
	std::ofstream fout(filename);
	fout <<  location_ << std::endl;
	fout <<  club_ << std::endl;
	fout << sectors_num_ << std::endl;
	fout <<  complexity_ << std::endl;
	fout <<  average << std::endl;
	fout << "-------------------------------------------------------" << std::endl;
	fout.close();
}
void Stadium::deserialize(std::string filename) {
	std::ifstream fin(filename);
	char s1[50];
	char s2[50];
	int s3;
	int s4;
	fin.getline(s1, 50);
	location_ = s1;
	fin.getline(s2, 50);
	club_ = s2;
	fin >> s3;
	sectors_num_ = s3;
	fin >> s4;
	complexity_ = s4;
	fin.close();
}
void Stadium::serialize() {
	std::ofstream fout;
	fout.open("file2.txt");
	fout << location_ << std::endl;
	fout <<  club_ << std::endl;
	fout <<  sectors_num_ << std::endl;
	fout <<  complexity_ << std::endl;
	fout <<   average << std::endl;
	fout << "-------------------------------------------------------" << std::endl;
	fout.close();
}
void Stadium::deserialize() {
	std::ifstream fin("file2.txt");
	char s1[50];
	char s2[50];
	int s3;
	int s4;
	fin.getline(s1, 50);
	location_ = s1;
	fin.getline(s2, 50);
	club_ = s2;
	fin >> s3;
	sectors_num_ = s3;
	fin >> s4;
	complexity_ = s4;	
	fin.close();
}