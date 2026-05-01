/* ------------ RTOS Task Queue ------------

Three tasks are queued: Read_ADC, Filter_Signal, Transmit_UART.
A hardware interrupt fires: EMERGENCY_IRQ must be inserted at the front immediately.
With a linked list this is o(1) - no shifting.
The schedular pops and executes the front task.

*/

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* next;		//next points to the next Node created from the same struct.
	
	explicit Node(const T& val) : data(val), next(nullptr) {}	//next is NULL as a default
	//explicit prevents implicit conversions and requires, constructor to be called explicitly
};

template <typename T>
class LinkedLinearList {
private:
	Node<T>* head;		//pointer to first Node (nullptr if empty)
	int length;

	//Walk to the node at position 'pos'.  o(n)
	Node<T>* nodeAt(int pos) const {
		if (pos < 0 || pos >= length)
			throw out_of_range("Index " + to_string(pos) + " out of range !");
		Node<T>* current = head;
		for (int i = 0; i < pos; ++i)
			current = current->next;
		return current;
	}

public:
	LinkedLinearList() : head(nullptr), length(0) {
		cout << "[LinkedLinearList] is created.\n";
	}
	~LinkedLinearList() {
		//Walk the chain and delete every node
		Node<T>* current = head;
		while (current) {
			Node<T>* next = current->next;
			delete current;
			current = next;
		}
		cout << "[LinkedLinearList] is destroyed - All nodes freed.\n";
	}

	int size() const { return  length; }		 //if we call size(), it directly returns length of list.
	bool isEmpty() const { return length == 0; } //if we call isEmpty(), it directly returns true or false.
	
	//get() - must traverse from head O(n).
	T get(int pos) const {
		return nodeAt(pos)->data;
	}

	//find() - traverse until val found or list exhausted. O(n)
	int find(const T& val) const {
		Node<T>* current = head;
		int i = 0;
		while (current) {
			if (current->data == val) return i;
			current = current->next;
			++i;
		}
		return -1;
	}

	//insert() - insert at position 'pos'
	void insert(int pos, const T& val) {
		if (pos < 0 || pos > length)
			throw out_of_range("Insert position is out of range !");
		
		Node<T>* newNode = new Node<T>(val);
		if (pos == 0) {
			newNode->next = head;
			head = newNode;
		}
		else
		{	//walk to node just before insertion point	
			Node<T>* prev = nodeAt(pos - 1);
			newNode->next = prev->next;
			prev->next = newNode;
		}
		++length;
	}

	//remove() - Remove node at position 'pos'
	//firstly record the value then delete the value and return the deleted value. 
	T remove(int pos) {
		if (pos < 0 || pos >= length)
			throw out_of_range("Position is out of range for remove operation !");
		Node<T>* target;
		if (pos == 0) {
			target = head;
			head = head->next;
		}
		else
		{
			Node<T>* prev = nodeAt(pos - 1);
			target = prev->next;
			prev->next = target->next;
		}
		T value = target->data;
		delete target;
		--length;
		return value;
	}

	//print() - giving information
	void print() const {
		cout << "List [size=" << length << "]: ";
		Node<T>* current = head;
		while (current) {
			cout << "[" << current->data << "]";
			if (current->next)
				cout << " -> ";
			current = current->next;
		}
		cout << " -> NULL\n";
	}
};

// --- Main ----------------
int main()
{

	LinkedLinearList<string> lst;
	lst.insert(0, "Read_ADC");
	lst.insert(1, "Filter_Signal");
	lst.insert(2, "Transmit_UART");
	lst.print();

	cout << "\nInsert high-priority interrupt task at FRONT...\n";
	lst.insert(0, "EMERGENCY_IRQ");
	lst.print();

	cout << "\nPop and execute front task: \n" << lst.remove(0) << "\n\n";

	lst.print();

	return 0;
}

/*
Output:

[LinkedLinearList] is created.
List [size=3]: [Read_ADC] -> [Filter_Signal] -> [Transmit_UART] -> NULL

Insert high-priority interrupt task at FRONT...
List [size=4]: [EMERGENCY_IRQ] -> [Read_ADC] -> [Filter_Signal] -> [Transmit_UART] -> NULL

Pop and execute front task:
EMERGENCY_IRQ

List [size=3]: [Read_ADC] -> [Filter_Signal] -> [Transmit_UART] -> NULL
[LinkedLinearList] is destroyed - All nodes freed.

*/