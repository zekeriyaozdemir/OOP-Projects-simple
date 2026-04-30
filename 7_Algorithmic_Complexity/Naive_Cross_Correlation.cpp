/*   ------------------ O(n2) - Quadratic -- nested loops over same data ------------------

Naive Cross-Correlation:

'Naive' cross-correlation in EEE refers to the direct, brute-force
calculation of similarity between two signals as a function of the time
shift applied to one of them. While computationally expensive compare 
to frequency-domain methods (FFT), it is frequently used for DSP, radar
ranging, synchronization, and fault diagnosis.
 
 Rxy[m] = SUM{ x[n]*y[n-m] } for 0 -> n

*/

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<double> crossCorelation(const vector<double>& A, const vector<double>& B)
{
	int N = A.size();
	int M = B.size();
	vector<double> result(N - M + 1, 0.0);

	for (int k = 0; k <= (N - M); k++)
	{
		double sum = 0;
		for (int i = 0; i < M; i++)
		{
			sum += A[i + k] * B[i];
		}
		result[k] = sum;
	}
	return result;
}

int main()
{
	auto Start = chrono::high_resolution_clock::now();

	vector<double> first = {16, 12, 2000, 25, 2026};
	vector<double> second = {1, 0, -1};

	vector<double> Result = crossCorelation(first, second);
 
	cout << "[";
	for (int i = 0; i < Result.size(); ++i) 
	{
		cout << Result[i];
		if (i != Result.size() - 1)
			cout << ",";
	}
	cout << "]\n";

	auto End = chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration<double, milli> (End - Start).count();
	cout << "Time Duration: " << elapsed << " ms\n";

	return 0;
}

/*
Output:
[-1984,-13,-26]
Time Duration: 1.1306 ms
*/