#include <iostream>
#define mysizeof(type) (char*)(&type+1)-(char*)(&type)
using namespace std;
//CHIH: implement a program to calculate size of any variable
//      without using standard sizeof() function
//      hint: 
//      use address to calculate memory amount of variable
int main() {
	
	double x=10.99;
	int y=20;
	short z=6;
	char str[] = "Hello Jack!!";
	char* ptr = str;
	cout << "size of double variable: " << mysizeof(x) << endl;
	cout << "size of integer variable: " << mysizeof(y) << endl;
	cout << "size of short variable: " << mysizeof(z) << endl;
	cout << "size of a char string \"Hello Jack!!\": " << mysizeof(str) << endl;
	cout << "size of a pointer to char string: " << mysizeof(ptr) << endl;
	//CHIH: pointers should be 8-Byte wide to address
	//      DDR memory more than 4GB on 64bit computer
    return 0;
}
//H:\myperl>g++ -o test ch1_a-mysizeof.cpp
//H:\myperl>test.exe
//size of double variable: 8
//size of integer variable: 4
//size of short variable: 2
//size of a char string "Hello Jack!!": 13
//size of a pointer to char string: 8