#pragma once

#include <iostream>

using namespace std;

class Motor
{
public:
	
	void start();
	void stop();
	void setSpeed(int speed, double threshold);

private:
	
	int rpm;

};