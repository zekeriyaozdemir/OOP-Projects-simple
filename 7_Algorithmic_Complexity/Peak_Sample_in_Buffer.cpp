/*   ------------------ O(n) - Linear -- one pass through the data ------------------

Find the peak sample in a buffer:

To find the peak (maximum absolute value) sample in a digital buffer,
we need to iterate through the data and compare each sample against
the current maximum.
*/

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;


int Find_Peak(const vector<int>& samples)
{
	int peak = samples[0];

	for (int i = 1; i < samples.size(); i++)
		if (samples[i] > peak) peak = samples[i];
	
	return peak;
}

int main()
{
	auto Start = chrono::high_resolution_clock::now();


	vector<int> bufferSamples = { 45, 55, 120, 32, 89, 95, 41, 29 };
	int peakValue = Find_Peak(bufferSamples);

	auto End = chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration<double, milli> (End - Start).count();

	cout << "Peak Value: " << peakValue << "\n"
		<< "Time Duration: " << elapsed << endl;

	return 0;
}

/*
Output:
Peak Value: 120
Time Duration: 0.0288
*/
