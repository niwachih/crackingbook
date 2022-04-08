#include <iostream>
#include <cstdlib>
using namespace std;

//CHIH: 1. implement a function to check two linked-lists have intersections or not (by reference)
//      2. e.g. 3->1->5->9\
//                         7->2->1
//                    4->6/
//      3. extend from basic list:
//         create, append, reverse, destroy, ...
//      4. hint: go through two list from tail and find intersection node
typedef struct node {
	int data;
	struct node* next;
} Node_int;

typedef struct
{
	int count;
	Node_int* head;
} Mylist;

class Result {
	public: Node_int* tail;
	public: int size;
	public: Result(Node_int* tail, int size) {
		//"this" means pointer to itself in c++
		this->tail = tail;
		this->size = size;
	}
};

Mylist* createlist();
Mylist* destroylist(Mylist*);
void destroynodelist(Node_int*);
Result GetTailAndSize(Node_int*);
Node_int* findintersection(Node_int*, Node_int*);
Node_int* GetKthNode(Node_int*, int);
Node_int* partitionlistfromx(Mylist* , int);
Node_int* addtwolists(Node_int*, Node_int*, int);
void appendtolisttail(Mylist*, int);
Node_int* insertnodetotail(Node_int*, int);
Node_int* insertlisttotail(Node_int*, Node_int*);
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
	Node_int* list_intersec = NULL;
	Node_int* node_intersec;
	Result ret1(NULL, 0);
	Result ret2(NULL, 0);
	int ret = -1;
	int x;
	
	if(list)
	{
		cout << "list created successfully!!!" << endl;
		list1 = insertnodetotail(list1,1);
		list1 = insertnodetotail(list1,2);
		list1 = insertnodetotail(list1,2);
		list1 = insertnodetotail(list1,3);
		list1 = insertnodetotail(list1,4);
		list1 = insertnodetotail(list1,5);
		list1 = insertnodetotail(list1,6);
		list2 = insertnodetotail(list2,1);
		list2 = insertnodetotail(list2,2);
		list2 = insertnodetotail(list2,3);
		list2 = insertnodetotail(list2,4);
		list2 = insertnodetotail(list2,5);
		list2 = insertnodetotail(list2,6);
		list2 = insertnodetotail(list2,7);
		list2 = insertnodetotail(list2,8);
		//create intersection here
		list_intersec = insertnodetotail(list_intersec,9);
		list_intersec = insertnodetotail(list_intersec,10);
		list_intersec = insertnodetotail(list_intersec,11);
		list_intersec = insertnodetotail(list_intersec,12);
		list1 = insertlisttotail(list1, list_intersec);
		list2 = insertlisttotail(list2, list_intersec);
		cout << "content of list1: " << endl;
		printnode(list1);
		cout << "content of list2: " << endl;
		printnode(list2);
		ret1 = GetTailAndSize(list1);
		ret2 = GetTailAndSize(list2);
		node_intersec = findintersection(list1, list2);
		cout << "intersec node data: " << node_intersec->data << endl;
		destroynodelist(list1);
		//destroynodelist(list2);
	}
	else
		cout << "cannot create list..." << endl;
	
    return 0;
}
Result GetTailAndSize(Node_int* nodep)
{
	int size = 1;
	Node_int* current = nodep;
	Result ret = Result(NULL, 0);

	if (nodep == NULL) {
		cout << "list is empty (null ptr)" << endl;
		return ret;
	}
	while (current->next != NULL) {
		size++;
		current = current->next;
	}
	ret = Result(current, size);
	//return new Result(current, size);
	return ret;
}
Node_int* findintersection(Node_int* l1, Node_int* l2)
{
	Result ret1(NULL, 0);
	Result ret2(NULL, 0);
	Node_int* shorter;
	Node_int* longer;

	if ((l1 == NULL) || (l2 == NULL))
		return NULL;

	ret1 = GetTailAndSize(l1);
	ret2 = GetTailAndSize(l2);

	//NO intersection when tail node is different
	if (ret1.tail->data != ret2.tail->data)
		return NULL;

	//find shorter and longer list
	shorter = (ret1.size < ret2.size) ? l1 : l2;
	longer = (ret1.size > ret2.size) ? l1 : l2;

	//move longer by length difference of two list
	longer = GetKthNode(longer, abs(ret1.size - ret2.size));

	//move two list forward until collide
	while (shorter != longer) {
		shorter = shorter->next;
		longer = longer->next;
	}

	//return one of them
	return longer;
}
Node_int* GetKthNode(Node_int* listhead, int k)
{
	Node_int* current = listhead;

	while ((k > 0) && (current != NULL)) {
		current = current->next;
		k--;
	}

	return current;
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
Node_int* insertlisttotail(Node_int* l1, Node_int* l2)
{
	Node_int* rethead = l1;

	if (l1 == NULL && l2 == NULL)
		return NULL;

	if (rethead == NULL)
		rethead = l2;
	else {
		while (l1->next)
			l1 = l1->next;
		
		l1->next = l2;
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
//D:\crackingbook>g++ -o test ch2_7-findintersection.cpp

//D:\crackingbook>test.exe
//list created successfully!!!
//content of list1:
//1 2 2 3 4 5 6 9 10 11 12
//content of list2:
//1 2 3 4 5 6 7 8 9 10 11 12
//intersec node data: 9