#include <string>
#include <iostream>
using namespace std;

bool isuniqueChars(string str)
{
	bool *charset = new bool[128]();
	//CHIH: create a bool array and init it to false
	if(str.length() > 128)
		return false;
	for(int i=0;i<str.length();i++)
	{
		int val = str[i];

		if(charset[val])
			return false;

		charset[val] = true;
		//CHIH: 標示為已出現過!!
	}
	delete[] charset;
	return true;
}
int main() {
	
	string str;
	cout << "Please enter your string..." << endl;
	getline(cin,str);
	
	if(isuniqueChars(str))
		cout << "String is unique!" << endl;
	else
		cout << "String is NOT unique..." << endl;
	
    return 0;
}
//test result:
//D:\crackingbook>g++ -o test ch1_1-uniquechars.cpp

//D:\crackingbook>test.exe
//Please enter your string...
//chiaowei
//String is NOT unique...

//D:\crackingbook>
//D:\crackingbook>
//D:\crackingbook>test.exe
//Please enter your string...
//jack
//String is unique!

//D:\crackingbook>
