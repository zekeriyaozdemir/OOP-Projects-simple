#include <iostream>
#include <string>

using namespace std;

//======================================================
//=============== CIRCULAR ARRAY QUEUE =================
//======================================================

template <typename T>
class CircularQueue {
private:
	T* data;
	int front_index;
	int back_index;
	int capacity;

public:
	explicit CircularQueue(int cap = 16)
		: front_index(0), back_index(0), capacity(cap + 1) {
		data = new T[capacity];
		cout << "[CircularQueue] is created, usable capacity=" << cap << "\n";
	}

	~CircularQueue() {
		delete[] data;
		cout << "[CircularQueue] is destroyed.\n";
	}

	bool isEmpty() const { return front_index == back_index; }
	bool isFull() const { return (back_index + 1) % capacity == front_index; }

	int size() const {
		return (back_index - front_index + capacity) & capacity;
	}

	// --- enqueue() -------------------------------
	// add at back. O(1)
	void enqueue(const T& val) {
		if (isFull()) throw overflow_error("Queue is FULL !");
		data[back_index] = val;
		back_index = (back_index + 1) & capacity; //wrap around
	}

	// --- dequeue() ---------------------------------
	// remove at front. O(1)
	T dequeue() {
		if (isEmpty()) throw underflow_error("Queue is EMPTY !");
		T val = data[front_index];
		front_index = (front_index + 1) % capacity;
		return val;
	}

	T front() const {
		if (isEmpty()) throw underflow_error("Queue is EMPTY !");
		return data[front_index];
	}

	void print() const {
		cout << "Queue (front -> back) [size=" << size() << "]: ";
		int i = front_index;
		while (i != back_index) {
			cout << "[" << data[i] << "]";
			i = (i + 1) & capacity;
		}
		cout << "\n";
	}

};

//======================================================
//==================  LINKED QUEUE =====================
//======================================================
template <typename T>
struct QNode {
	T data;
	QNode* next;
	explicit QNode(const T& v) : data(v), next(nullptr) {}
};

template <typename T>
class LinkedQueue {
private:
	QNode<T>* headNode;
	QNode<T>* tailNode;
	int length;

public:
	LinkedQueue() : headNode(nullptr), tailNode(nullptr), length(0) {
		cout << "[LinkedQueue] is created.\n";
	}
	~LinkedQueue() {
		while (!isEmpty()) dequeue();
		cout << "[LinkedQueue] is destroyed.\n";
	}

	bool isEmpty() const { return headNode == nullptr; }
	int size() const { return length; }
	T front() const {
		if (isEmpty()) throw underflow_error("Queue is EMPTY !");
		return headNode->data;
	}

	// enqueue at tail O(1)
	void enqueue(const T& val) {
		QNode<T>* node = new QNode<T>(val);
		if (isEmpty()) {
			headNode = tailNode = node;
		}
		else {
			tailNode->next = node;
			tailNode = node;
		}
		++length;
	}

	// dequeue from head O(1)
	T dequeue() {
		if (isEmpty()) throw underflow_error("Queue is EMPTY !");
		QNode<T>* old = headNode;
		T val = old->data;
		headNode = headNode->next;
		if (headNode == nullptr) tailNode = nullptr;
		delete old;
		--length;
		return val;
	}

	void print() const {
		cout << "Queue (front->back) [size=" << length << "]: ";
		QNode<T>* curr = headNode;
		while (curr) {
			cout << "[" << curr->data << "]";
			curr = curr->next;
		}
		cout << "\n";
	}
};

// ============================================================
//  UART Receive Buffer (Circular Queue)
//
//  A microcontroller UART ISR writes bytes to a circular queue.
//  The application layer reads from the front.
//  If the queue fills up before the app reads, bytes are dropped
//  (common embedded bug — the "buffer overrun").
// ============================================================
void uartDemo() {
	cout << "\n--- UART Receive Buffer (Circular Queue) ---\n";
	CircularQueue<uint8_t> uartFifo(8);

	// Simulate ISR writing bytes (ASCII 'H','e','l','l','o')
	cout << "ISR receives bytes: ";
	for (uint8_t b : {72, 101, 108, 108, 111}) {
		uartFifo.enqueue(b);
		cout << b << " ";
	}
	cout << "\n";
	uartFifo.print();

	// Application read and print characters
	cout << "App reads: ";
	while (!uartFifo.isEmpty())
		cout << (char)uartFifo.dequeue();
	cout << "\n";
}

// ============================================================
//  Round-Robin Task Scheduler
//
//  An RTOS gives each task a time slice.  When a task's
//  slice expires, it is re-enqueued at the back.  The next
//  task is always dequeued from the front.
// ============================================================
void schedulerDemo() {

	cout << "\n--- Round-Robin Task Scheduler ---\n";

	LinkedQueue<string> ready;
	ready.enqueue("Task_ADC");
	ready.enqueue("Task_Filter");
	ready.enqueue("Task_Display");
	ready.enqueue("Task_Comms");
	ready.print();

	cout << "Running 6 scheduling cycles:\n";
	for (int cycle = 1; cycle <= 6; ++cycle) {
		string t = ready.dequeue();
		cout << "  Cycle " << cycle << ": execute [" << t << "]\n";
		ready.enqueue(t);   // re-enqueue at back
	}
	ready.print();
}

// ============================================================
//  MAIN
// ============================================================
int main()
{
	uartDemo();
	schedulerDemo();

	return 0;
}

/*
Output:

--- UART Receive Buffer (Circular Queue) ---
[CircularQueue] is created, usable capacity=8
ISR receives bytes: H e l l o
Queue (front -> back) [size=8]: [o]
App reads: o
[CircularQueue] is destroyed.

--- Round-Robin Task Scheduler ---
[LinkedQueue] is created.
Queue (front->back) [size=4]: [Task_ADC][Task_Filter][Task_Display][Task_Comms]
Running 6 scheduling cycles:
  Cycle 1: execute [Task_ADC]
  Cycle 2: execute [Task_Filter]
  Cycle 3: execute [Task_Display]
  Cycle 4: execute [Task_Comms]
  Cycle 5: execute [Task_ADC]
  Cycle 6: execute [Task_Filter]
Queue (front->back) [size=4]: [Task_Display][Task_Comms][Task_ADC][Task_Filter]
[LinkedQueue] is destroyed.
*/





