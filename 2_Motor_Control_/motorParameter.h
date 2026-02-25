#pragma once

#include <iostream>

using namespace std;

class Motor
{
public:
	
	int testSpeed;
	double testHeat;

	void start();
	void stop();
	void setSpeed(int speed, double threshold);
	void heatSensor(float heatValue, int size);

	void testMeasurement(int test_speed, double test_heat);

private:
	
	int rpm;	// radian per minute
	
};