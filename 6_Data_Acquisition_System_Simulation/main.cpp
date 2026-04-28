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
class VoltSensor : public Sensor {
	double m_vref, m_gain;
public:
	VoltSensor(const string& n, double vref, double gain = 1.0)
		: Sensor(n), m_vref(vref), m_gain(gain) { }

	double getValue() const override { return Raw * m_vref * m_gain; }
	string getUnit() const override { return "V"; }
};

// --- Current Sensor -----------------------------------
class CurrentSensor : public Sensor {
	double m_shunt, m_ampGain;
public:
	CurrentSensor(const string& n, double shuntOhm, double ampGain = 1.0)
		:Sensor(n), m_shunt(shuntOhm), m_ampGain(ampGain) { }

	double getValue() const override {
		// Vshunt = raw * Vref (assume 3.3V ref), I = Vshunt / shunt
		return (Raw * 3.3 / m_shunt) / m_ampGain;
	}

	string getUnit() const override { return "A"; }
};

// --- Data Logger (composition) -----------------------------------
class DataLogger {
private:
	Sensor** m_sensors;
	int m_count;
	int m_maxCount;
	int m_sampleNum;

public:
	DataLogger(int maxSensors)
		: m_count(0), m_maxCount(maxSensors), m_sampleNum(0) 
	{
		m_sensors = new Sensor* [maxSensors];
	}
    
	~DataLogger() { delete[] m_sensors; }

	bool addSensor(Sensor* s) {
		if (m_count >= m_maxCount) return false;
		m_sensors[m_count++] = s;
		return true;
	}

	void printHeader() const {
		cout << string(60, '=') << endl;
		cout << " DATA ACQUISITION LOG" << endl;
		cout << string(60, '=') << endl;
		cout << setw(6) << "Sample";
		for (int i = 0; i < m_count; i++)
			cout << setw(14) << m_sensors[i]->getName();
		cout << endl << string(60, '-') << endl;
	}

	void takeSample() {
		cout << setw(6) << m_sampleNum++;
		for (int i = 0; i < m_count; i++)
			cout << fixed << setprecision(3)
			<< setw(13) << m_sensors[i]->getValue()
			<< m_sensors[i]->getUnit()[0];

		cout << endl;
	}

	void printCSV() const {
		cout << "\n--- CSV Log ---" << endl;
		cout << "name,value,unit" << endl;
		for (int i = 0; i < m_count; i++)
			cout << m_sensors[i]->getLogEntry() << endl; // via ILoggable
	}
};

// --- Main -----------------------------------
int main()
{
	TemperatureSensor t1("T_CPU", 0, 100, +1.2);
	TemperatureSensor t2("T_Board", -10, 90, -0.5);
	VoltSensor v1("V_3V3", 3.3);
	VoltSensor v2("V_5V0", 5.0, 1.0);
	CurrentSensor i1("I_Load", 0.05, 1.0);

	DataLogger logger(5);
	logger.addSensor(&t1);
	logger.addSensor(&t2);
	logger.addSensor(&v1);
	logger.addSensor(&v2);
	logger.addSensor(&i1);

	// Simulate three samples
	double raws[3][5] = {
	{ 0.45, 0.50, 0.97, 0.96, 0.72 },
	{ 0.48, 0.52, 0.98, 0.96, 0.75 },
	{ 0.50, 0.55, 0.97, 0.97, 0.80 },
	};

    logger.printHeader();

	for (int s = 0; s < 3; s++) {
		for (int i = 0; i < 5; i++)
			// setRaw() called via base pointer -- runtime dispatch
			((Sensor*)(&t1))[i].setRaw(raws[s][i]); // simplified
		// Direct calls for clarity
		t1.setRaw(raws[s][0]); t2.setRaw(raws[s][1]);
		v1.setRaw(raws[s][2]); v2.setRaw(raws[s][3]);
		i1.setRaw(raws[s][4]);

		logger.takeSample();
	}

	logger.printCSV();
	cout << "\nTotal ADC readings taken: "
		<< Sensor::getTotalReadings() << endl;

	return 0;
}








