/*   ------------------ O(log n) - Logarithmic -- halves the problem each step ------------------

Binary Search in a sorted LUT:

In computing, binary search is the standard algorithm for finding an element
in a sorted Look-Up-Table (LUT) because it provides logarithmic time complexity (O(log n))

*/

#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

int findValue(const vector<int>& searchTable, const int target)
{
	int lo = 0, hi = searchTable.size() - 1;

	while (lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		if (searchTable[mid] == target)
			return mid;
		else if (searchTable[mid] < target)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
}

int main()
{
	auto Start = chrono::high_resolution_clock::now();

	vector<int> lookUpTable = {2, 17, 19, 51, 73, 5, 7, 11, 20, 91, 61};

	auto End = chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration<double, milli>(End - Start).count();

	cout << "The value index is [ " << findValue(lookUpTable, 20) << " ].\n"
		<< "Time Duration: " << elapsed << "\n";

	return 0;
}

/*
Output:
The value index is [ 8 ].
Time Duration: 0.0463
*/