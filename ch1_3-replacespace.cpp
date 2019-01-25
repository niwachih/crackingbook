#include <string>
#include <iostream>
using namespace std;

int countspace(const char* str)
{
	int num=0;
	while(*str)
	{
		if(*str==' ')
			num++;
		str++;
	}
	return num;
}

int main() {
	
	//CHIH: part 1 - count num of space in string
	string str;
	cout << "Please enter your string..." << endl;
	getline(cin,str);
	
	cout << "num of space in string is: " << countspace(str.c_str()) << endl;
	//CHIH: convert string string to char string by c_str()
	
	//CHIH: part 2 - replace each space by "%20"
	int str_length = str.length();
	//CHIH: store string length before resize it
	
	int index = str_length + countspace(str.c_str()) * 2;
	str.resize(index);
	for(int i=str_length-1;i>=0;i--)
	{
		if(str[i]==' ')
		{
			str[index-1] = '0';
			str[index-2] = '2';
			str[index-3] = '%';
			index = index - 3;
		}
		else
		{
			str[index-1] = str[i];
			index--;
		}
	}
	
	cout << "replace space in string by %20: " << str << endl;
	
    return 0;
}
//H:\myperl>replacespace.exe
//Please enter your string...
//le petit prince
//num of space in string is: 2
//replace space in string by %20: le%20petit%20prince

//H:\myperl>
//