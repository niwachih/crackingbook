#include <string>
#include <iostream>
using namespace std;

//CHIH: 1. implement a function to compress a string
//         eg: aaabbccccd -> a3b2c4d
//      2. when compressed string is shorter than original
//         return the original string     
string mycompress(string s)
{
	char chr=s[0];
	string ret_str="";
	int count_chr=1;
	
	
	//CHIH: s[length] is "\0" so compare to length+1
	for(int i=1;i<=s.length();i++)
	{
		if(chr==s[i])
			count_chr++;
		else
		{
			ret_str+=chr;
			
			if(count_chr>1)
				ret_str=ret_str+to_string(count_chr);
			
			count_chr=1;
			chr=s[i];
		}
	}
	
	//CHIH: return original string if compressed string is NOT shorter!!
	if (ret_str.length()<s.length())
		return ret_str;
	else
		return s;
}

int main() {
	
	string s;
	cout << "Please enter your string..." << endl;
	getline(cin,s);

	cout << "my compressed string is: " << mycompress(s) << endl;
    return 0;
}
//g++ -o test-compress "..\ubuntushare\apue-testprogram\ch1_6-strcompress.cpp"
//H:\myperl>test-compress.exe
//Please enter your string...
//aaaaaassss ddd
//my compressed string is: a6s4 d3

//H:\myperl>test-compress.exe
//Please enter your string...
//aaaafffheeee
//my compressed string is: a4f3he4

//H:\myperl>
