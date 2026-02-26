
#pragma once
#include "aircraft.h"

class Aeroplane : public Aircraft {

public:
    Aeroplane(string name, double maxSpeed);

	void engineStart() override;
	void engineStop() override;
	void takeOff() override;
	void landing() override;
};