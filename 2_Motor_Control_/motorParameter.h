#pragma once

#include <iostream>

using namespace std;

class Motor
{
public:
	
	void start();
	void stop();
	void setSpeed(int speed, double threshold);

	void heatSensor(float heatValue, int size);

private:
	
	int rpm;	// radian per minute
	
};