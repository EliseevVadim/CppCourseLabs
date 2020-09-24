#pragma once
#include <string>
class Stadium
{
public:
	Stadium(std::string location, std::string club, short sectors_num, int complexity);
	~Stadium();
	Stadium();
	void setLoc(std::string location);
	void setClub(std::string club);
	void setSectorsNumber(short sectors_num);
	void setComplexity(int complexity);
	void setAttendance(int attendance);
	void serialize(std::string filename);
	void deserialize(std::string filename);
	void serialize();
	void deserialize();
	void printInfo();
	void setAverageValue(float value);
	float getAverageValue();
	float getPercent();
private:
	std::string location_;
	std::string club_;
	short sectors_num_;
	int complexity_;
	int attendance_ = 0;
	float average;
};

