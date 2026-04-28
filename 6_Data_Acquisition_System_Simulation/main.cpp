/* 
--------- Data Acquisition System ------------------------
A data acquisition (DAQ) system is a combination of sensors, specilized hardware, and software
that captures physical signals (temperature, voltage, pressure, sound)
and converts them into digital data for computer analysis, visualization, and
storage. It acts as the interface between the physical world and a computer
to improve measurement accuracy and automation.

-> manage the different sensor types with a single interface
-> convert the data (ADC raw) to the real physical value
-> demonstrate and log the data 
 
 */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

// --- Pure Interfaces ---------------------------------
class IReadable {
public:
	virtual ~IReadable() {}
	virtual double getValue() const = 0;
	virtual string getUnit() const = 0;
};
class ILoggable {
public:
	virtual ~ILoggable() {}
	virtual string getLogEntry() const = 0;
};

// --- Abstract Sensor Base -----------------------------
class Sensor : public IReadable, public ILoggable {
protected:
	string Name;
	double Raw;
	static int s_totalReadings;

public:
	Sensor(const string& m_name) : Name(m_name), Raw(0) {}
	virtual ~Sensor() {}

	void setRaw(double r) {
		Raw = (r < 0) ? 0 : (r > 1) ? 1 : r;
		s_totalReadings++;
	}

	// IReadable -- still pure (no default implementation)
	virtual double getValue() const = 0;
	virtual string getUnit() const = 0;

	// ILoggable -- default implementation
	string getLogEntry() const override {
		ostringstream oss;
		oss << fixed << setprecision(3) << Name << "," << getValue()
			<< "," << getUnit();
		return oss.str();
	}

	void printReading() const {
		cout << setw(12) << Name << ": " << fixed << setprecision(3)
			<< setw(10) << getValue() << " " << getUnit() << endl;
	}

	string getName() const { return Name; }
	static int getTotalReadings() { return s_totalReadings; }

};

int Sensor::s_totalReadings = 0;

// --- Temperature Sensor -----------------------------------
class TemperatureSensor : public Sensor {
	double m_minT, m_maxT, m_offset;
public:
	TemperatureSensor(const string& n, double lo, double hi, double off=0)
		: Sensor(n), m_minT(lo), m_maxT(hi), m_offset(off) { }

	double getValue() const override {
		return m_minT + Raw * (m_maxT - m_minT) + m_offset;
	}

	string getUnit() const override { return "degC"; }
};

// --- Voltage Sensor -----------------------------------


// --- Current Sensor -----------------------------------


// --- Data Logger (composition) -----------------------------------

// --- Main -----------------------------------
int main()
{
	TemperatureSensor T1("T_CPU", 0, 100, +1.2);

	return 0;
}








