#include <iostream>
#include <list>
using namespace std;
//CHIH: 1.implement a program to demo hash with chaining
//      using linked list STL
//      2.e.g. hash table with 7 buckets (0,1,2,3,4,5,6)
//      key arrives in order (15,11,27,8,...)
//      Hash Index = key % (num of buckets)
class Hash
{
	int bucket;
	list<int> *table;
public:
	Hash(int var);
	void insertitem(int item);
	void deleteitem(int key);
	int hashfunction(int x)
	{
		return (x % bucket);
	}
	void displayhash();
};
Hash::Hash(int var)
{
	this->bucket = var;
	table = new list<int>[bucket];
}
void Hash::insertitem(int key)
{
	int index = hashfunction(key);
	table[index].push_back(key);
}
void Hash::deleteitem(int key)
{
	int index = hashfunction(key);
	//declaring iterator to a int list
	list<int>::iterator i;
	for(i=table[index].begin();i!=table[index].end();i++)
	{
		if(*i == key)
		{
			table[index].erase(i);
			break;
		}
	}
}
void Hash::displayhash()
{
	int i;
	for(i=0;i<bucket;i++)
	{
		cout << i;
		for(auto x:table[i])
			cout << " --> " << x;
		//range-based loop iterate over whole linked list 
		cout << endl;
	}
}
int main() {
	int a[] = {15,11,27,8,12,60};
	int n = sizeof(a) / sizeof(a[0]);
	Hash h(7);
	
	for(int i=0;i<n;i++)
		h.insertitem(a[i]);
	
	h.deleteitem(12);
	h.displayhash();
    return 0;
}
//H:\myperl>g++ -o test ch1_b-hashtable.cpp
//H:\myperl>test.exe
//0
//1 --> 15 --> 8
//2
//3
//4 --> 11 --> 60
//5
//6 --> 27