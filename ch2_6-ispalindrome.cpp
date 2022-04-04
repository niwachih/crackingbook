#include <iostream>
using namespace std;

//CHIH: 1. implement a function to check a linked-list is a palindrome or not
//      2. e.g. 0->1->2->1->0 is palindrome
//      3. extend from basic list:
//         create, append, reverse, destroy, ...
//      4. hint: reverse and compare
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
void destroynodelist(Node_int*);
Node_int* partitionlistfromx(Mylist* , int);
Node_int* addtwolists(Node_int*, Node_int*, int);
void appendtolisttail(Mylist*, int);
Node_int* insertnodetotail(Node_int*, int);
void reverselist(Mylist*);
Node_int* reversenodelistclone(Node_int*);
bool isequallists(Node_int*, Node_int*);
bool ispalindrome(Node_int*);
void deleteitem(Mylist*, int);
bool deletenode(Mylist*, Node_int*);
void printlist(Mylist*);
void printnode(Node_int*);
int printfromkthtolast(Node_int*, int);
void deleteduplicate(Mylist*);

int main() {
	Mylist* list=createlist();
	Node_int* retnode = NULL;
	Node_int* list1 = NULL;
	Node_int* list2 = NULL;
	//Node_int* listsum = NULL;
	int ret = -1;
	int x;
	
	if(list)
	{
		cout << "list created successfully!!!" << endl;
		list1 = insertnodetotail(list1,1);
		list1 = insertnodetotail(list1,2);
		list1 = insertnodetotail(list1,2);
		list1 = insertnodetotail(list1,3);
		list1 = insertnodetotail(list1,2);
		list1 = insertnodetotail(list1,2);
		list1 = insertnodetotail(list1,1);
		cout << "content of list1: " << endl;
		printnode(list1);
		//list2 = reversenodelistclone(list1);
		//cout << "content of list2: " << endl;
		//printnode(list2);
		//if (isequallists(list1, list2))
		//	cout << "list1 and list2 are identical!!" << endl;
		if (ispalindrome(list1))
			cout << "list1 is palindrome!!!" << endl;
		else
			cout << "list1 is not palindrome..." << endl;
		destroynodelist(list1);
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
Node_int* addtwolists(Node_int* l1, Node_int* l2, int carry)
{
	Node_int* result;
	Node_int* more;
	int value;

	if (l1 == NULL && l2 == NULL && carry == 0)
		return NULL;

	result = (Node_int*)malloc(sizeof(Node_int));
	value = carry;
	if (l1 != NULL)
		value += l1->data;
	if (l2 != NULL)
		value += l2->data;
	
	result->data = value % 10;
	
	//recursive part
	if (l1 != NULL || l2 != NULL) {
		more = addtwolists(l1 == NULL ? NULL : l1->next,
						   l2 == NULL ? NULL : l2->next,
						   value >= 10 ? 1 : 0);
		result->next = more;
	}

	return result;
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
void destroynodelist(Node_int* nodep)
{
	Node_int* deletenode;

	if (nodep == NULL)
		return;

	if (nodep->next == NULL) {
		free(nodep);
		nodep = NULL;
	}

	while (nodep->next) {
		deletenode = nodep;
		nodep = nodep->next;
		free(deletenode);
	}
}
void appendtolisttail(Mylist* plist, int item)
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
Node_int* insertnodetotail(Node_int* nodep, int item)
{
	Node_int* itemptr = (Node_int*) malloc(sizeof(Node_int));
	itemptr->data = item;
	itemptr->next = NULL;
	Node_int* rethead = nodep;
	
	if (rethead == NULL)
		rethead = itemptr;
	else {
		while (nodep->next)
			nodep = nodep->next;
		
		nodep->next = itemptr;
	}
	
	return rethead;
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
Node_int* reversenodelistclone(Node_int* nodep)
{
	Node_int* head = NULL;

	while (nodep != NULL) {
		Node_int* n = (Node_int*) malloc(sizeof(Node_int));
		n->data = nodep->data;
		n->next = head;
		head = n;
		nodep = nodep->next;
	}
	return head;
}
bool isequallists(Node_int* l1, Node_int* l2)
{
	while ((l1 != NULL) && (l2 != NULL)) {
		if (l1->data != l2->data)
			return false;
		l1 = l1->next;
		l2 = l2->next;
	}
	return ((l1 == NULL) && (l2 == NULL));
}
bool ispalindrome(Node_int* head)
{
	Node_int* reversed;
	
	reversed = reversenodelistclone(head);

	return isequallists(head, reversed);
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
	if(nodep == NULL)
		return;
	while(nodep != NULL)
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
//D:\crackingbook>g++ -o test.exe ch2_6-ispalindrome.cpp

//D:\crackingbook>test.exe
//list created successfully!!!
//content of list1:
//1 2 2 2 3 6 8
//content of list2:
//list1 is not palindrome...

//D:\crackingbook>g++ -o test.exe ch2_6-ispalindrome.cpp

//D:\crackingbook>test.exe
//list created successfully!!!
//content of list1:
//1 2 2 3 2 2 1
//list1 is palindrome!!!