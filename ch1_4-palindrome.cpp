#include <string>
#include <iostream>
#include <vector>
using namespace std;
unsigned const int num_alphabets = 'z'-'a'+1;
//CHIH: there's 26 alphabets from a to z

int* buildCharFreqTable(string phrase)
{
	static int table[num_alphabets] = {};
	//initialize all elements to zero
	
	for (int i=0;i<phrase.length();i++)
	{
		int index = phrase[i] -'a';
		table[index]++;
	}
	
	return table;
}
bool checkMaxOneOdd(int* array)
{
	bool odd_found = false;
	for (int i=0;i<num_alphabets;i++)
	{
		if (array[i] % 2 == 1)
		{
			if (odd_found)
				return false;
			
			odd_found = true;
		}
	}
	return true;
}
bool isPermutationofPalindrome(string phrase)
{
	int* array_p; 
	array_p = buildCharFreqTable(phrase);
	return checkMaxOneOdd(array_p);
}
int main() {
	
	string phrase;
	cout << "Please enter your phrase..." << endl;
	getline(cin,phrase);
	
	if(isPermutationofPalindrome(phrase))
		cout << "Phrase is Palindrome!" << endl;
	else
		cout << "Phrase is NOT Palindrome..." << endl;
	
    return 0;
}