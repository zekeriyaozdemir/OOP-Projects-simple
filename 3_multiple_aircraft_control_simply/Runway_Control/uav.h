#pragma once
#include "aircraft.h"

class UAV : public Aircraft {

public:
	UAV(string name, double maxSpeed);

	void engineStart() override;
	void engineStop() override;
	void takeOff() override;
	void landing() override;
};