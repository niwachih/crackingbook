#include <iostream>
using namespace std;

//CHIH: 1. implement a function to delete duplicate node
//         from singly linked list 
//      2. hint: go through whole list, add node to hash table
//         if duplicate, delete it
//      3. extend from basic list:
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

int main() {
	Mylist* list=createlist();
	if(list)
	{
		cout << "list created successfully!!!" << endl;
		appendtotail(list,1);
		appendtotail(list,2);
		appendtotail(list,3);
		appendtotail(list,4);
		cout << "my original list: " << list->head->data << " "\
		<< list->head->next->data << " "\
		<< list->head->next->next->data << " "\
		<< list->head->next->next->next->data << endl;
		reverselist(list);
		cout << "list after reverse: " << list->head->data << " "\
		<< list->head->next->data << " "\
		<< list->head->next->next->data << " "\
		<< list->head->next->next->next->data << endl;		
		destroylist(list);
	}
	else
		cout << "cannot create list..." << endl;
	
    return 0;
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
//H:\myperl>g++ -o test ch2_1-deletedup.cpp
//H:\myperl>test.exe
//list created successfully!!!
//my original list: 1 2 3 4
//list after reverse: 4 3 2 1
