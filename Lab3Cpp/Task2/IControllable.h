#pragma once
class IControllable
{
public:
	virtual ~IControllable() {};
	virtual void control(int temperature)=0;
};

