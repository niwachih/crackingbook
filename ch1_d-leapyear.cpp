#include <iostream>
using namespace std;
//CHIH: 1. implement a function to calculate leap year
//      2. hint: 
//         -2020 is leap year but 1900 is NOT leap year
//         (can be divided by 4, but cannot be divided by 100)
//         -2000 is leap year
//         (can be divided by 400)
//      3. PHISON SSD firmware position interview problem
bool isLeapYear(int);

int main() {
	
	cout << "please enter year: " << endl;
	int year;
	cin >> year;
	if(isLeapYear(year))
		cout << year << " is leap year!!!" << endl;
	else
		cout << year << " is NOT leap year..." << endl;
	
    return 0;
}

bool isLeapYear(int year)
{
	if((year%4==0 && year%100!=0) || year%400==0)
		return true;
	else
		return false;
}
//---test result--- (compiler: g++)
//please enter year:
//2020
//2020 is leap year!!!
//
//please enter year:
//2000
//2000 is leap year!!!
//
//please enter year:
//1900
//1900 is NOT leap year...
//
//please enter year:
//1999
//1999 is NOT leap year...
