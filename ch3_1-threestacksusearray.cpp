#include <iostream>
#include <cstdlib>
using namespace std;

//CHIH: 1. using array to implement three stacks
//      2. extend from basic operation:
//         push, pop, peek, isempty, isfull, ...
//      3. hint: divide this array into three parts
//               e.g. [0, n/3), [n/3, 2n/3), [2n/3, n)

class FixedMultiStack {
	private: int numofstacks = 3;
	private: int stackcapacity;
	private: int* values;
	private: int* sizes;
	
	public: FixedMultiStack(int stacksize) {
		stackcapacity = stacksize;
		values = new int[stacksize * numofstacks];
		sizes = new int[numofstacks];
	}
	public: ~FixedMultiStack() {
		delete []values;
		delete []sizes;
	}
	public: void push(int, int);
	//push node to stack
	public: int pop(int);
	//pop out node from stack
	public: int peek(int);
	//peek top node of stack
	public: bool isEmpty(int);
	//check a stack is empty or not
	public: bool isFull(int);
	//check a stack is full or not
	public: int indexofTop(int);
	//return the index of stack top
};

void FixedMultiStack::push(int stacknum, int value)
{
	if (isFull(stacknum))
		throw length_error("stack is full!");

	sizes[stacknum]++;
	values[indexofTop(stacknum)] = value;
}

int FixedMultiStack::pop(int stacknum)
{
	if (isEmpty(stacknum))
		throw length_error("stack is empty...");

	int top_index = indexofTop(stacknum);
	int value = values[top_index];
	values[top_index] = 0;
	sizes[stacknum]--;

	return value;
}

int FixedMultiStack::peek(int stacknum)
{
	if (isEmpty(stacknum))
		throw length_error("stack is empty...");
	
	return values[indexofTop(stacknum)];
}

int FixedMultiStack::indexofTop(int stacknum)
{
	int offset = stacknum * stackcapacity;
	int size = sizes[stacknum];
	
	return offset + size - 1;
}

bool FixedMultiStack::isFull(int stacknum)
{
	return sizes[stacknum] == stackcapacity;
}

bool FixedMultiStack::isEmpty(int stacknum)
{
	return sizes[stacknum] == 0;
}

int main() {
	FixedMultiStack(100);
	cout << "stack created successfully!!!" << endl;

    return 0;
}
//D:\crackingbook>g++ -o test ch3_1-threestacksusearray.cpp

//D:\crackingbook>test.exe
//stack created successfully!!!