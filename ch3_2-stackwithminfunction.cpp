#include <iostream>
#include <stack>
//include header for stack operation
#include <climits>
//to use INT_MAX, INT_MIN
using namespace std;

//CHIH: 1. design a function to return the minimum value of stack
//      2. use C++ Stack STL library
//      3. condition: push, pop, min, the three operations
//         must be finished in o(1) time
//      4. use another stack to record minimum values
//         if new node is smaller then smin.top(), push this node to it
class StackwithMin: public stack<int> {
	stack<int> s_min_vlaues;
	//to store minimum values
	public: StackwithMin() {
		cout << "stack created!" << endl;
	}
	public: ~StackwithMin() {
		cout << "stack destroyed..." << endl;
	}
	public: void push(int);
	//push node to stack
	public: int pop();
	//pop out node from stack
	public: int min();
	//return minimum node of stack
};

void StackwithMin::push(int value)
{
	if (value <= min())
		s_min_vlaues.push(value);
	
	stack::push(value);
	//c++ cannot use 'super' to overload parent class
}

int StackwithMin::pop()
{
	int value = stack::top();
	stack::pop();
	//remove the top node
	if (value == min())
		s_min_vlaues.pop();
	return value;
}

int StackwithMin::min()
{
	if (s_min_vlaues.empty())
		return INT_MAX;
	else
		return s_min_vlaues.top();
}

int main() {
	StackwithMin mystack;
	
	mystack.push(1);
	mystack.push(2);
	mystack.push(3);
	mystack.push(4);
	mystack.push(0);
	mystack.push(0);
	mystack.push(0);
	mystack.pop();
	mystack.pop();
	mystack.pop();
	cout << "minimum value of stack is: " << mystack.min() << endl;

    return 0;
}
//D:\crackingbook>g++ -o test.exe ch3_2-stackwithminfunction.cpp

//D:\crackingbook>test.exe
//stack created!
//minimum value of stack is: 1
//stack destroyed...
