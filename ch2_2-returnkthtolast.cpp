#include <iostream>
using namespace std;

//CHIH: 1. implement a function to return kth element to last in a linked list
//      2. extend from basic list:
//         create, append, reverse, destroy, ...
typedef struct node {
	int data;
	struct node* next;
} Node_int;

typedef struct
{
	int count;
	Node_int* head;
} Mylist;

Mylist* createlist();
Mylist* destroylist(Mylist*);
void appendtotail(Mylist*, int);
void reverselist(Mylist*);
void deleteitem(Mylist*, int);
void printlist(Mylist*);
int printfromkthtolast(Node_int*, int);
void deleteduplicate(Mylist*);

int main() {
	Mylist* list=createlist();
	int ret = -1;
	int k;
	
	if(list)
	{
		cout << "list created successfully!!!" << endl;
		appendtotail(list,1);
		appendtotail(list,2);
		appendtotail(list,2);
		appendtotail(list,2);
		appendtotail(list,3);
		appendtotail(list,4);
		appendtotail(list,5);
		appendtotail(list,5);
		appendtotail(list,6);
		cout << "my original list: ";
		printlist(list);
		cout << "give number to last k: ";
		cin >> k;
		
		cout << "print element of kth to last: ";
		ret = printfromkthtolast(list->head, k);
		destroylist(list);
	}
	else
		cout << "cannot create list..." << endl;
	
    return 0;
}
int printfromkthtolast(Node_int* head, int k)
{
	int index;

	if(!head)
		return 0;
	index = printfromkthtolast(head->next, k) + 1;
	if (index == k)
		cout << k << "th to last node is " << head->data;
	cout << endl;
	return index;
}
Mylist* createlist()
{
	Mylist* list = (Mylist*) malloc(sizeof(Mylist));
	if(list)
	{
		list->head=NULL;
		list->count=0;
	}
	return list;
}
Mylist* destroylist(Mylist* plist)
{
	Node_int* deleteptr;
	if(plist)
	{
		while(plist->count > 0)
		{
			deleteptr=plist->head;
			plist->head=plist->head->next;
			plist->count--;
			free(deleteptr);
		}
		free(plist);
	}
	return NULL;
}
void appendtotail(Mylist* plist, int item)
{
	Node_int* itemptr = (Node_int*) malloc(sizeof(Node_int));
	itemptr->data = item;
	itemptr->next = NULL;
	if(plist->count==0)
	{
		plist->head = itemptr;
	}
	else
	{
		Node_int* startptr = plist->head;
		while(plist->head->next)
			plist->head = plist->head->next;
		
		plist->head->next = itemptr;
		plist->head = startptr;
	}
	plist->count++;
}
void reverselist(Mylist* plist)
{
	Node_int* prevptr = NULL;
	Node_int* currptr = plist->head;
	Node_int* nextptr = NULL;
	while(currptr)
	{
		nextptr = currptr->next;
		//store next position
		currptr->next = prevptr;
		//reverse pointer
		prevptr = currptr;
		currptr = nextptr;
		//move pointers one position forward
	}
	plist->head = prevptr;
}
void deleteitem(Mylist* plist, int key)
{
	Node_int* temp = plist->head;
	Node_int* prev = NULL;
	
	if(temp != NULL && temp->data == key)
	{
		plist->head = temp->next;
		free(temp);
		plist->count--;
		return;
	}
	//key item is at list head
	while(temp != NULL && temp->data != key)
	{
		prev = temp;
		//store pointer to prev node
		temp = temp->next;
		//move one position forward
	}
	if(!temp)
		return;
	//key item NOT found in this list
	prev->next = temp->next;
	//prev node next point to the next of key item
	free(temp);
	plist->count--;
}
void printlist(Mylist* plist)
{
	Node_int* temp = plist->head;
	if(!temp)
		return;
	while(temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
void deleteduplicate(Mylist* plist)
{
	Node_int* curr = plist->head;

	while(curr)
	{
		Node_int* runner = curr;
		while(runner->next)
		{
			if(curr->data == runner->next->data)
			{
				Node_int* temp = runner->next;
				runner->next = runner->next->next;
				free(temp);
				plist->count--;
			}
			else
				runner = runner->next;
		}
		curr = curr->next;
	}
	//algorithm complexity is O(n^2)
}
//D:\crackingbook>g++ -o test ch2_2-returnkthtolast.cpp

//D:\crackingbook>test.exe
//list created successfully!!!
//my original list: 1 2 2 2 3 4 5 5 6
//give number to last k: 2
//print element of kth to last:
//2th to last node is 5
//D:\crackingbook>g++ -o test ch2_2-returnkthtolast.cpp

//D:\crackingbook>test.exe
//list created successfully!!!
//my original list: 1 2 2 2 3 4 5 5 6
//give number to last k: 6
//print element of kth to last:
//6th to last node is 2