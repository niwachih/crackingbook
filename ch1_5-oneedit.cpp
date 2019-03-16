#include <string>
#include <iostream>
using namespace std;

bool oneeditreplace(string, string);
bool oneeditinsert(string, string);

bool oneeditaway(string first, string second)
{
	if(first.length()==second.length())
		return oneeditreplace(first,second);
	else if(first.length()+1==second.length())
		return oneeditinsert(first,second);
	else if(first.length()-1==second.length())
		return oneeditinsert(first,second);
	else
		return false;
}

bool oneeditreplace(string s1, string s2)
{
	bool founddifference=false;
	
	for (int i=0;i<s1.length();i++)
	{
		if(s1[i] != s2[i])
		{
			if(founddifference)
				return false;
			
			return true;
		}
	}
	
	return true;
}
//CHIH: 檢查是否可以插入一個字元讓s1和s2相同
bool oneeditinsert(string s1, string s2)
{
	int index1=0;
	int index2=0;
	while(index1 < s1.length() && index2 < s2.length())
	{
		if(s1[index1] != s2[index2])
		{
			if(index1 != index2)
				return false;
			
			index2++;
		}
		else
		{
			index1++;
			index2++;
		}
	}
	
	return true;
}

int main() {
	
	string s, t;
	cout << "Please enter your first string..." << endl;
	getline(cin,s);
	
	cout << "Please enter your second string..." << endl;
	getline(cin,t);
	
	if(oneeditaway(s,t))
		cout << "two strings are the same OR one edit away!!" << endl;
	else
		cout << "two strings are different!!" << endl;
	
    return 0;
}
//---test result---
//H:\myperl>test-onedit.exe
//Please enter your first string...
//chih
//Please enter your second string...
//ichih
//two strings are the same OR one edit away!!

//H:\myperl>test-onedit.exe
//Please enter your first string...
//fukuoka
//Please enter your second string...
//fukuoka
//two strings are the same OR one edit away!!