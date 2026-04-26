/*
Here is the ADC Demo that enables the choosing channel, resolution, and reference voltage. 
Calculating 'step size (LSB)' and 'Voltage value'
*/

#include <iostream>
#include <string>
#include <chrono>

using namespace std;

class adcDemo {
private:
    int currentChannel;
    int resolution;
    double vRef;
    int adcValue;


public:
    adcDemo(const int channel, const int res, const double V, const int val)           // Parameterized Constructor
        : currentChannel(channel), resolution(res), vRef(V), adcValue(val) {
        cout << "ADC_channel[" << channel << "] Created.\n";
    }

    ~adcDemo() { cout << "[Channel " << currentChannel << "] Destroyed.\n"; }          // Destructor

    double step_size() {                                                               // LSB calculating [ vRef / (2 over n) - 1].
        return vRef / ((1 << resolution) - 1);
    }

    double Voltage_Value() {
        return adcValue * step_size();
    }

    void print() {
        cout << "[Channel " << currentChannel << "]" << endl;                          //Eg. channel 1 output
        cout << "Reference Voltage:" << vRef << "V\n" << "LSB:" << step_size()         //[Channel 3]
            << "\n" << "Voltage Output:" << Voltage_Value() << "V" << "\n\n";          //Reference Voltage : 3.3V
    }                                                                                  //LSB : 0.0129412
                                                                                       //Voltage Output : 0.582353V
    
};

int main()
{
    auto start = chrono::high_resolution_clock::now();

    adcDemo adc_1(1, 2, 3.3, 2);
    adcDemo adc_2(2, 4, 5.0, 11);
    adcDemo adc_3(3, 8, 3.3, 45);
    adcDemo adc_4(4, 10, 3.3, 510);
    adcDemo adc_5(5, 12, 5.0, 600);
    cout << "\n";
    adc_1.print();
    adc_2.print();
    adc_3.print();
    adc_4.print();
    adc_5.print();
    cout << "\n";

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Creating Time: " << elapsed.count() << " seconds\n\n";

    return 0;
}