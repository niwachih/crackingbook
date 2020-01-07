#include <vector>
#include <iostream>
using namespace std;

//CHIH: 1. implement a function to rotate a matrix 90 degree
//      2. use algorithm described below:
//           for i=1 to n
//				temp = top_row
//				top_row = left_column
//				left_column = bottom_row
//				bottom_row = right_column
//				right_column = temp
//           end
bool isnxnmatrix(vector<vector<int>>);
vector<vector<int>> rotate(vector<vector<int>>);
void printmtx(vector<vector<int>>);
int main() {
	int i, j;
	vector<vector<int>> matrix{	{1,2,3},
								{4,5,6},
								{7,8,9}	};					
	cout << "matrix before rotation:" << endl;
	printmtx(matrix);
	if(!isnxnmatrix(matrix))
		cout << "must be nxn matrix, rotate error!!!" << endl;
	else
	{
		cout << "matrix after rotate:" << endl;
		printmtx(rotate(matrix));
	}
		
    return 0;
}
bool isnxnmatrix(vector<vector<int>> mtx)
{
	//CHIH: input check, must be nxn matrix:)
	if(mtx.size()==0 || mtx.size()!=mtx[0].size())
		return false;
	return true;
}
vector<vector<int>> rotate(vector<vector<int>> mtx)
{
	int n = mtx.size();
	for(int layer=0;layer < n/2;layer++)
	{
		int first=layer;
		int last=n-1-layer;
		for(int i=first;i<last;i++)
		{
			int offset=i-first;
			int temp=mtx[first][i];
			
			mtx[first][i]=mtx[last-offset][first];
			mtx[last-offset][first]=mtx[last][last-offset];
			mtx[last][last-offset]=mtx[i][last];
			mtx[i][last]=temp;
		}
	}
	return mtx;
}
void printmtx(vector<vector<int>> matrix)
{
	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[i].size();j++)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}	
}
//H:\myperl>g++ -o test ch1_7-rotatemtx.cpp
//
//H:\myperl>test.exe
//matrix before rotation:
//1       2       3
//4       5       6
//7       8       9
//matrix after rotate:
//7       4       1
//8       5       2
//9       6       3