#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

string sortstr(string str)
{
	char content[str.length()+1];
	
	strcpy(content,str.c_str());
	//CHIH: string string轉換成char string
	
	sort(content,content + str.length());
	//CHIH: 對char string做排序!
	
	string result;
	
	result.assign(content);
	//CHIH: 排序後再轉回string string!!
	
	return result;
	
}
bool permutation(string s, string t)
{
	if(s.length()!=t.length())
		return false;
	
	//CHIH: 分別sort兩個string後再比較!!
	if(sortstr(s).compare(sortstr(t))==0)
		return true;
	else
		return false;
}
int main() {
	
	//CHIH: part 1 - string sorting
	string str;
	cout << "Please enter your string..." << endl;
	getline(cin,str);
	
	cout << "original string is: " << str << endl;
	cout << "sorted string is: " << sortstr(str) << endl;
	
	//CHIH: part 2 - permutation
	string s, t;
	cout << "Please enter your first string..." << endl;
	getline(cin,s);
	
	cout << "Please enter your second string..." << endl;
	getline(cin,t);
	
	if(s.compare(t)==0)
		cout << "two strings are identical!!" << endl;
	else if(permutation(s,t))
		cout << s << " is permutation of " << t << endl;
	else
		cout << "two strings are different!!" << endl;
	
    return 0;
}
//
//example test pattern:
//Please enter your string...
//jack
//original string is: jack
//sorted string is: acjk
//
//Please enter your first string...
//hello
//Please enter your second string...
//eholl
//hello is permutation of eholl
//
//Please enter your first string...
//hello
//Please enter your second string...
//hello
//two strings are identical!!
//
//Please enter your first string...
//hello
//Please enter your second string...
//jack
//two strings are different!!