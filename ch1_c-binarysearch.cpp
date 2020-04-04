#include <iostream>
#include <ctime>
using namespace std;

void insertionSort(int[], int);
void printarray(int[], int);
int binary_search(int[], int, int);
int main(int argc,char* argv[])
{
	int mylist[20];
	int array_size=sizeof(mylist) / sizeof(int);
	
	srand(time(NULL));
	for(int i=0;i<array_size;i++)
	{
		mylist[i] = rand() % 100;
	}
	//CHIH: generate random number for sorting
	
	cout << "before sorting: " << endl;
	printarray(mylist,array_size);
	insertionSort(mylist,array_size-1);
	cout << "after sorting: " << endl;
	printarray(mylist,array_size);
	cout << "Enter item to find index in this array!!" << endl;
	int item, index;
	cin >> item;
	index = binary_search(mylist,array_size,item);
	if(index == -1)
		cout << "item NOT found......" << endl;
	else
		cout << "item (" << item << ") index is: " << index << endl;
	return 0;
}
void insertionSort(int list[], int last)
{
	int hold;
	int walker;
	int current;
	for (current=1;current<=last;current++)
	{
		hold=list[current];
        /*CHIH: set walker to the end of sorted...*/
		for (walker = current-1;walker >= 0 && hold < list[walker];walker--)
		{
			/*CHIH: walker is bigger than hold, so move right*/
			list[walker+1]=list[walker];		
		}
		list[walker+1]=hold;
	}
}
void printarray(int list[], int lsize)
{
	for (int i=0;i<lsize;i++)
	{
		printf("%d ",list[i]);
	}
	printf("\n");
}
int binary_search(int array[], int arrsize, int key)
{
	int ret = -1;//CHIH: return -1 if NOT found
	int start = 0, end = arrsize -1, mid;
	while(start<=end)
	{
		mid = start + (end - start) / 2;
		if(array[mid] < key)
			start = mid + 1;
		else if(array[mid] > key)
			end = mid - 1;
		else //CHIH: array[mid] = key
		{
			ret = mid;
			break;
		}
	}
	return ret;
}
//test result: 
//before sorting:
//71 99 40 11 78 85 79 38 91 1 3 55 12 98 24 93 38 46 93 5
//after sorting:
//1 3 5 11 12 24 38 38 40 46 55 71 78 79 85 91 93 93 98 99
//Enter item to find index in this array!!
//91
//item (91) index is: 15

//before sorting:
//10 8 34 27 81 38 61 79 22 60 28 83 35 46 86 74 42 73 94 57
//after sorting:
//8 10 22 27 28 34 35 38 42 46 57 60 61 73 74 79 81 83 86 94
//Enter item to find index in this array!!
//12
//item NOT found......