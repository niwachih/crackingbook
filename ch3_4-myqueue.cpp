#include <iostream>
#include <stack>
//include header for stack operation
#include <list>
using namespace std;

//CHIH: 1. design a data structure to represent a queue
//      2. use C++ Stack STL library
//      3. use another stack to reverse order
class MyQueue {
	stack<int> *newest;
	stack<int> *oldest;
	
	public: MyQueue() {
		newest = new stack<int>();
		oldest = new stack<int>();
		cout << "two stack created!" << endl;
	}
	public: ~MyQueue() {
		delete newest;
		delete oldest;
		cout << "two stack deleted..." << endl;
	}
	public: int size() {
		return newest->size() + oldest->size();
	}
	public: void add(int value) {
		newest->push(value);
	}
	//move newest to oldest to reverse order
	private: void shiftstacks() {
		if (oldest->empty()) {
			while (!newest->empty()) {
				oldest->push(newest->top());
				newest->pop();
			}
		}
	}
	public: int peek() {
		shiftstacks();
		return oldest->top();
	}
	public: int remove() {
		int ret;

		shiftstacks();
		ret = oldest->top();
		oldest->pop();
		return ret;
	}
};

int main() {
	MyQueue my_queue;

	my_queue.add(1000);
	my_queue.add(2000);
	my_queue.add(3000);
	cout << "peek: " << my_queue.peek() << endl;
	cout << "remove: " << my_queue.remove() << endl;
	cout << "peek: " << my_queue.peek() << endl;

    return 0;
}
//D:\crackingbook>g++ -o test ch3_4-myqueue.cpp

//D:\crackingbook>test.exe
//two stack created!
//peek: 1000
//remove: 1000
//peek: 2000
//two stack deleted...