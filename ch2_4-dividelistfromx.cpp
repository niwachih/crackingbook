#include <iostream>
using namespace std;

//CHIH: 1. implement a function to delete inner node in a linked list, except head and tail node
//      2. input is node to be deleted only (not key!!!)
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
Node_int* partitionlistfromx(Mylist* , int);
void appendtotail(Mylist*, int);
void reverselist(Mylist*);
void deleteitem(Mylist*, int);
bool deletenode(Mylist*, Node_int*);
void printlist(Mylist*);
void printnode(Node_int*);
int printfromkthtolast(Node_int*, int);
void deleteduplicate(Mylist*);

int main() {
	Mylist* list=createlist();
	Node_int* retnode = NULL;
	int ret = -1;
	int x;
	
	if(list)
	{
		cout << "list created successfully!!!" << endl;
		appendtotail(list,8);
		appendtotail(list,2);
		appendtotail(list,14);
		appendtotail(list,2);
		appendtotail(list,3);
		appendtotail(list,4);
		appendtotail(list,5);
		appendtotail(list,5);
		appendtotail(list,6);
		appendtotail(list,7);
		cout << "my original list: " << endl;
		printlist(list);
		cout << "please enter your divider x: " << endl;
		cin >> x;
		retnode = partitionlistfromx(list, x);
		cout << "list after divided by x: " << endl;
		printnode(retnode);
		destroylist(list);
	}
	else
		cout << "cannot create list..." << endl;
	
    return 0;
}
Node_int* partitionlistfromx(Mylist* plist, int x)
{
	Node_int* nodep = NULL;
	Node_int* beforestart = NULL;
	Node_int* beforeend = NULL;
	Node_int* afterstart = NULL;
	Node_int* afterend = NULL;
	int node_count = 0;
	
	//partition a list from position x
	//insert node to two list and merge them
	if(!plist) {
		cout << "list is empty..." << endl;
		return NULL;
	}
	nodep = plist->head;
	while (nodep != NULL) {
		if (nodep->data < x) {
			if (beforestart == NULL) {
				beforestart = nodep;
				beforeend = beforestart;
			} else {
				beforeend->next = nodep;
				beforeend = nodep;
			} 
		} else {
			if (afterstart == NULL) {
				afterstart = nodep;
				afterend = afterstart;
			} else {
				afterend->next = nodep;
				afterend = nodep;
			}
		}
		nodep = nodep->next;
		node_count++;
	}
	cout << "total node: " << node_count << endl;
	beforeend->next = afterstart;
	afterend->next = NULL;

	return beforestart;
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
		list->head = NULL;
		list->count = 0;
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
bool deletenode(Mylist* plist, Node_int* n)
{
	//delete inner node without head or list
	Node_int* nextnode;

	if ((n == NULL) || (n->next == NULL)) {
		return false;
	}
	nextnode = n->next;
	n->data = nextnode->data;
	n->next = nextnode->next;
	plist->count--;
	return true;
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
void printnode(Node_int* nodep)
{
	if(!nodep)
		return;
	while(nodep)
	{
		cout << nodep->data << " ";
		nodep = nodep->next;
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
//D:\crackingbook>g++ -o test ch2_4-dividelistfromx.cpp

//D:\crackingbook>test.exe
//list created successfully!!!
//my original list:
//8 2 14 2 3 4 5 5 6 7
//please enter your divider x:
//3
//total node: 10
//list after divided by x:
//2 2 8 14 3 4 5 5 6 7

//D:\crackingbook>test.exe
//list created successfully!!!
//my original list:
//8 2 14 2 3 4 5 5 6 7
//please enter your divider x:
//5
//total node: 10
//list after divided by x:
//2 2 3 4 8 14 5 5 6 7

//D:\crackingbook>test.exe
//list created successfully!!!
//my original list:
//8 2 14 2 3 4 5 5 6 7
//please enter your divider x:
//10
//total node: 10
//list after divided by x:
//8 2 2 3 4 5 5 6 7 14

//D:\crackingbook>
