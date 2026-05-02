/* ------------- Hardware Call Stack -------------
A hardware call stack is a dedicated, finite memory region managed by CPU hardware
(LIFO - Last In First Out) that stores active subroutine information, specifically
return addresses, local variables, and function parameters. It enables the CPU to 
track function calls resume execution correctly after subroutines finish.
*/

#include <iostream>
#include <string>

using namespace std;


// ==============================================================
// ================      ARRAY BASED STACK      =================
// ==============================================================
template <typename T>
class ArrayStack {
private:
	T* data;
	int topIndex;		//Index of the top element (-1 if empty)
	int capacity;

public:
	explicit ArrayStack(int cap = 16)		//explicit constructor with default identification that 
		: topIndex(-1), capacity(cap) {     // top index is (-1) and capacity is 16.
		data = new T[capacity];
		cout << "[ArrayStack] is created. [Capacity=" << capacity << "]\n";
	}

	~ArrayStack() {
		delete[] data;
		cout << "[ArrayStack] is destroyed.\n\n";
	}

	// --- isEmpty(), size(), isFull() -----------------------------
	// isEmpty() return true if no element into
	// isFull() return true if all capacity is full
	// size() return current element size
	bool isEmpty() const { return topIndex == -1; }
	int size() const { return topIndex + 1; }
	bool isFull() const { return topIndex == capacity - 1; }

	// --- push() -----------------------------------------
	// add element on top, and rearrange topIndex
	void push(const T& val) {
		if (isFull()) throw underflow_error("Stack is FULL !");
		data[++topIndex] = val;		//same time increment index and add element
	}

	// --- pop() -------------------------------------------
	// remove and return top element
	T pop() {
		if (isEmpty()) throw underflow_error("Stack is EMPTY !");
		return data[topIndex--];		//same time return and decrement index
	}

	// --- peek() -----------------------------------------
	// return value on topIndex but not removing
	T peek() const {
		if (isEmpty()) throw underflow_error("Stack is EMPTY !");
		return data[topIndex];
	}

	// --- print() -----------------------------------------
	// print top to bottom
	void print() const {
		cout << "Stack [top -> bottom]	[size=" << size() << "]: ";
		for (int i = topIndex; i >= 0; --i)
			cout << "[" << data[i] << "]";
		cout << "\n";
	}
};

// ==============================================================
// =================     LINKED BASED STACK     =================
// ==============================================================
template <typename T>
struct sNode {
	T data;
	sNode* next;
	explicit sNode(const T& v) : data(v), next(nullptr) {}
};

template <typename T>
class LinkedStack {
private:
	sNode<T>* topNode;
	int length;

public:
	LinkedStack() : topNode(nullptr), length(0) {
		cout << "[LinkedStack] is created.\n";
	}

	~LinkedStack() {
		while (!isEmpty()) pop();
		cout << "[LinkedStack] is destroyed.\n\n";
	}

	bool isEmpty() const { return topNode == nullptr; }
	int size() const { return length; }

	T peek() const {
		if (isEmpty()) throw underflow_error("Stack is EMPTY !");
		return topNode->data;
	}

	void push(const T& val) {
		sNode<T>* node = new sNode<T>(val);
		node->next = topNode;
		topNode = node;
		++length;
	}

	T pop() {
		if (isEmpty()) throw underflow_error("Stack is EMPTY !");
		sNode<T>* old = topNode;
		T val = old->data;
		topNode = topNode->next;
		delete old;
		--length;
		return val;
	}

	void print() const {
		cout << "Stack (top -> bottom) [size=" << length << "]: ";
		sNode<T>* current = topNode;
		while (current) {
			cout << "[" << current->data << "]";
			current = current->next;
		}
		cout << "\n";
	}
};

// ============================================================
//  ====================      MAIN      =======================
// ============================================================
int main()
{

	cout << " =========== STACK ADT ===========\n\n";

	cout << " ----------- Array Stack -----------\n";
	{
		ArrayStack<int> s(6);
		s.push(10); s.push(100); s.push(1000); s.push(10000);
		s.print();
		cout << "Peek: " << s.peek() << "\n";
		cout << "Pop:  " << s.pop() << "\n";
		s.print();
	}

	cout << " ----------- Linked Stack -----------\n";
	{
		LinkedStack<string> s;
		s.push("ISR_UART");
		s.push("ISR_ADC");
		s.push("ISR_TIMER");
		s.print();
		cout << "Return from: " << s.pop() << "\n";
		cout << "Return from: " << s.pop() << "\n";
		s.print();
	}

	return 0;
}

/*
Output:

 =========== STACK ADT ===========

 ----------- Array Stack -----------
[ArrayStack] is created. [Capacity=6]
Stack [top -> bottom]   [size=4]: [10000][1000][100][10]
Peek: 10000
Pop:  10000
Stack [top -> bottom]   [size=3]: [1000][100][10]
[ArrayStack] is destroyed.

 ----------- Linked Stack -----------
[LinkedStack] is created.
Stack (top -> bottom) [size=3]: [ISR_TIMER][ISR_ADC][ISR_UART]
Return from: ISR_TIMER
Return from: ISR_ADC
Stack (top -> bottom) [size=1]: [ISR_UART]
[LinkedStack] is destroyed.

*/