#include <iostream>
using namespace std;

//CHIH: 1. implement a function to delete duplicate node
//         from singly linked list 
//      2. hint: go through whole list, add node to hash table
//         if duplicate, delete it
typedef struct node {
	int data;
	struct node* next;
} Node_int;

typedef struct
{
	int count;
	Node_int* head;
} Mylist;

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

int main() {
	Mylist* list=createlist();
	if(list)
		cout << "list created successfully!!!" << endl;
	else
		cout << "cannot create list..." << endl;
	appendtotail(list,1);
	appendtotail(list,2);
	appendtotail(list,9);
	cout << "my list: " << list->head->data << " "\
	<< list->head->next->data << " "\
	<< list->head->next->next->data << endl;
	destroylist(list);
    return 0;
}
//H:\myperl>g++ -o test H:\ubuntushare\apue-testprogram\ch2_1-deletedup.cpp
//H:\myperl>test.exe
//list created successfully!!!
//my list: 1 2 9
