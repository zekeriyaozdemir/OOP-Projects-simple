#pragma once
#include "aircraft.h"

class fighterjet : public Aircraft {

public:
	fighterjet(string name, double maxSpeed);

	void engineStart() override;
	void engineStop() override;
	void takeOff() override;
	void landing() override;
};