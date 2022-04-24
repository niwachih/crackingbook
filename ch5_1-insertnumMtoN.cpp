#include <iostream>
#include <string>
#include <bitset>
using namespace std;

//CHIH: 1. design a function to insert a 32-bit number M to the other number N
//         from bit j to bit i
//      2. use C++ Stack STL library
//      3. suppose N have enough space to accomodate M
//         e.g. N = 10000000000 M = 10011 i = 2 j = 6
//              output = 10001001100
//      4. hint: use mask to clear N from j to i
//how to print if use c language
//#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
//#define BYTE_TO_BINARY(byte) \
	((byte) & 0x80 ? '1' : '0'),\
	((byte) & 0x40 ? '1' : '0'),\
	((byte) & 0x20 ? '1' : '0'),\
	((byte) & 0x10 ? '1' : '0'),\
	((byte) & 0x08 ? '1' : '0'),\
	((byte) & 0x04 ? '1' : '0'),\
	((byte) & 0x02 ? '1' : '0'),\
	((byte) & 0x01 ? '1' : '0') 
int updateBits(int n, int m, int i, int j)
{
	int allones = ~0;
	int left = allones << (j + 1);
	int right = (1 << i) - 1;
	int mask = left | right;
	int n_cleared = n & mask;
	int m_shifted = m << i;
	
	return n_cleared | m_shifted;
}

int main() {
	bitset<32> n("10000000000");
	bitset<32> m("10011");
	bitset<32> allones(~0);
	int merged_num;
	bitset<32> merged_num_bits;

	cout << "n = " << n << endl;
	cout << "m = " << m << endl;
	cout << "allones = " << allones << endl;
	
	merged_num = updateBits((int)n.to_ulong(), (int)m.to_ulong(), 2, 6);
	merged_num_bits = merged_num;
	//convert integer into bitset
	cout << "merged num = " << merged_num_bits << endl;

    return 0;
}
//D:\crackingbook>g++ -o test.exe ch5_1-insertnumMtoN.cpp

//D:\crackingbook>test.exe
//n = 00000000000000000000010000000000
//m = 00000000000000000000000000010011
//allones = 11111111111111111111111111111111
//merged num = 00000000000000000000010001001100