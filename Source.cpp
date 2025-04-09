#include <iostream>
using namespace std;

#define SIZE 10

class Queue {
	int* arr;
	int current;
	int front;
	int rear;
	int capacity;
public:
	Queue(int s = SIZE);
	~Queue();

	bool isFull();
	bool isEmpty();
	void enqueue(int value);
	int dequeue();
	int peek();
	int size();
};

Queue::Queue(int s) {
	capacity = s;
	arr = new int[capacity];
	front = 0;
	rear = 0;
	current = 0;
}

Queue::~Queue() {
	delete[] arr;
}

bool Queue::isFull() {
	if (current - 1 == capacity) {
		return true;
	}
	return false;
}

bool Queue::isEmpty() {
	if (current == 0) {
		return true;
	}
	return false;
}

void Queue::enqueue(int value) {
	if (!isFull()) {
		arr[rear++] = value;
		cout << "Added value " << value << " at index " << rear - 1 << endl;
		current++;
	}
	else {
		cout << "The Queue is Full. " << endl;
	}
}

int Queue::dequeue() {
	if (!isEmpty()) {
		int value = arr[front++];
		cout << "Removed value " << value << " from index " << front - 1 << endl;
		current--;
		return value;
	}
	else {
		cout << "The Queue is Empty. " << endl;
	}
}

int Queue::peek() {
	if (!isEmpty()) {
		cout << "The peek of Queue is " << arr[front] << endl;
		return arr[front];
	}
	else {
		cout << "The Queue is Empty. " << endl;
	}
}

int Queue::size() {
	if (!isEmpty()) {
		cout << "The size of Queue is " << current << endl;
		return current;
	}
	else {
		cout << "The Queue is Empty. " << endl;
	}
}

int main() {
	Queue Q;
	Q.enqueue(1);
	Q.enqueue(2);

	Q.size();
	Q.peek();

	Q.dequeue();
	Q.size();
	Q.peek();

	Q.dequeue();
	Q.size();
	Q.peek();

	return 0;
}