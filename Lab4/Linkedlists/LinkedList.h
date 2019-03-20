#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"

template<typename T>
class LinkedList
{
private:
	Node<T> *Head;	//Pointer to the head of the list
		//You can add tail pointer too (depending on your problem)
	int count;	//Number of nodes in the list
	void _deleteNodeAfter(Node<T>*);
	void _deleteHead();
public:
	LinkedList();
	~LinkedList();
	Node<T>* getHead();
	void PrintList();	//prints all items in the list
	void InsertBeg(T data);	//inserts a new node at list head
	bool InsertBefore(T old_val, T new_val);
	void MergeSorted(LinkedList<T>* L);
	void DeleteAll();	//Deletes all nodes in the list

	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(T data);	

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(T Key);

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(T value) const;

	//[4] DeleteFirst
	//Deletes the first node in the list
	void DeleteFirst();
	
	
	//[5] DeleteLast
	//Deletes the last node in the list
	void DeleteLast();

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNode(T value);	

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNodes(T value);	

	void DeleteLarger(T value);

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	void Merge(LinkedList<T> L);

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
	void Reverse();

	void PrintKth(int k) const;

	void DeleteKey(int Key);

	Node* GetMin();

	void SignSplit(LinkedList& lpos, LinkedList& lneg);

	void MergeSorted(LinkedList &L);
	
	void Reorder_X(int x);

	void RemoveDuplicates();
};

#endif	

template<typename T>
LinkedList<T>::LinkedList()
{
	count = 0;
	Head = NULL;
}


//List is being desturcted ==> delete all items in the list
template<typename T>
LinkedList<T>::~LinkedList()
{
	DeleteAll();
}


////////////////////////////////////////////////////////////////////////
/*
* UtilFunction: _deleteNode.
* Deletes after a given Node - if it's not the head - and handels different cases of deletion.
*/
template<typename T>
void LinkedList<T>::_deleteNodeAfter(Node<T>* n)
{
	if (n->getNext() == nullptr) return; 
	Node<T>* ptrToDelete = n->getNext();
	n->setNext(ptrToDelete->getNext());
	ptrToDelete->setNext(nullptr);
	delete ptrToDelete;
	count--;
}

////////////////////////////////////////////////////////////////////////
/*
* UtilFunction: _deleteHead.
* Deletes the head.
*/
template<typename T>
void LinkedList<T>::_deleteHead()
{
	Node<T>* delptr = Head;
	Head = Head->getNext();
	delptr->setNext(nullptr);
	delete delptr;
}

////////////////////////////////////////////////////////////////////////
/*
* Function: InsertEnd.
* inserts a new node at end if the list.
*/
template<typename T>
Node<T>* LinkedList<T>::getHead()
{
	return Head;
}

template<typename T>
void LinkedList<T>::InsertEnd(T data)
{
	if (Head->getNext() == nullptr) {
		Head->setItem(data);		
	}
	else {
		Node<T>* ptr = this->Head;
		while (ptr->getNext() != nullptr) ptr= ptr->getNext();
		ptr->setItem(data);
	}
	count++;
}

////////////////////////////////////////////////////////////////////////
/*
* Function: Find.
* Searches for a given value in the list,
  returns true if found; false otherwise.
*/
template<typename T>
bool LinkedList<T>::Find(T Key)
{
	if (Head == nullptr) return false;
	Node<T>* ptr = Head;
	while (ptr != nullptr) {
		if (ptr->getItem() == Key) return true;
		ptr = ptr->getNext();
	}
	return false;
}

template<typename T>
int LinkedList<T>::CountOccurance(T value) const {
	int cnt = 0;
	Node<T>* p = Head;
	while (p != nullptr) {
		if (p->getItem() == value) cnt++;
		p = p->getNext();
	}
	return cnt;
}

template<typename T>
void LinkedList<T>::DeleteFirst() {
	Node<T>* del_p = Head;
	Head = Head->getNext();
	del_p->setNext(nullptr);
	delete del_p;
	count--;
}

template<typename T>
void LinkedList<T>::DeleteLast() {
	Node<T> *del_p = Head, *prev = nullptr;
	while (del_p->getNext()->getNext() != nullptr) {
		prev = del_p;
		del_p = del_p->getNext();
	}
	prev->setNext(nullptr);
	delete del_p;
	count--;
}

template<typename T>
bool LinkedList<T>::DeleteNode(T value) {
	Node<T> *prev = nullptr, *del_p = Head;
	while (del_p->getNext() != nullptr) {
		if (del_p->getItem() == value) {
			if (del_p == Head) DeleteFirst();
			else {
				count--;
				prev->setNext(del_p->getNext());
				del_p->setNext(nullptr);
				delete del_p;
			}
			return true;
		}
		prev = del_p; del_p = del_p->getNext();
	}
	return false;
}

template<typename T>
void LinkedList<T>::Merge(LinkedList<T> L)
{
	Node<T> *p1 = Head, *p2 = L.getHead();
	while (p1->getNext() != nullptr) p1 = p1->getNext();
	while (p2 != nullptr) {
		p1->setNext(new Node<T>(p2->getItem()));
		p1 = p1->getNext(); p2 = p2->getNext();
		count++;
	}
}

template<typename T>
void LinkedList<T>::Reverse()
{
	Node<T> *pre = nullptr, *p = Head, *after = nullptr;
	while (p != nullptr) {
		after = p->getNext();
		p->setNext(pre);
		pre = p;
		p = after;
	}
	Head = pre;
}


////////////////////////////////////////////////////////////////////////
/*
* Function: DeleteNodes.
* Deletes ALL nodes with the given value and
  returns true. if not found, returns false.
*/
template<typename T>
bool LinkedList<T>::DeleteNodes(T value)
{
	if (!Find(value)) return false;
	Node<T>* ptr = Head;
	while (ptr->getNext() != nullptr) {
		if (ptr->getNext()->getItem() == value) {
			_deleteNodeAfter(ptr);
		}
		else ptr = ptr->getNext();
	}
	if (Head->getItem() == value) _deleteHead();
	return true;
}

////////////////////////////////////////////////////////////////////////
/*
* Function: DeleteLarger.
* Deletes ALL nodes with the given value and
  returns true. if not found, returns false.
*/
template<typename T>
void LinkedList<T>::DeleteLarger(T value)
{
	Node<T>* ptr = Head;
	while (ptr->getNext() != nullptr) {
		if (ptr->getNext()->getItem() > value) {
			_deleteNodeAfter(ptr);
			count--;
		}
		else ptr = ptr->getNext();
	}
	if (Head->getItem() > value) _deleteHead();
}


/*void LinkedList<T>::MergeSorted(LinkedList* L)
{
	Node* p1 = Head,  *p2 = L->getHead();
	while (p2 == nullptr)
	{
		if (p1 == nullptr) {
			this->InsertEnd(p2->getItem());
			p2 = p2->getNext();
		}
		else if (p2->getItem() == p1->getItem()) {
			p2 = p2->getNext();
		}
		else if (p2->getItem() < p1->getItem()) {
			if (p1 == Head) {
				p2.setNext(p1)
			}
		}
	}
}*/
////////////////////////////////////////////////////////////////////////
/*
* Function: PrintList.
* prints the values of all nodes in a linked list.
*/
template<typename T>
void LinkedList<T>::PrintList()
{
	cout<<"\nList has "<<count<<" nodes";
	cout<<"\nprinting list contents:\n\n";
	Node<T> *p = Head;
	
	while(p != NULL)
	{
		cout << "[ " << p->getItem() << " ]";
		cout << "--->";
		p = p->getNext();
	}
	cout << "*\n";
}
////////////////////////////////////////////////////////////////////////
/*
* Function: InsertBeg.
* Creates a new node and adds it to the beginning of a linked list.
* 
* Parameters:
*	- data : The value to be stored in the new node.
*/
template<typename T>
void LinkedList<T>::InsertBeg(T data)
{
	Node<T> *R = new Node<T>(data);
	R->setNext(Head);
	Head = R;
	count++;
}

template<typename T>
bool LinkedList<T>::InsertBefore(T old_val, T new_val)
{
	if (Find(old_val) == false) return false;
	Node<T>* ptr = Head, *prev = nullptr;
	Node<T>* newNode = new Node(new_val);
	while (ptr != nullptr)
	{
		if (ptr->getItem() == old_val) {
			if (ptr == Head) {
				newNode->setNext(Head);
				Head = newNode;
			}
			else {
				newNode->setNext(ptr);
				prev->setNext(newNode);
			}
			count++;
			return true;
		}
		prev = ptr;
		ptr = ptr->getNext();
	}
}

////////////////////////////////////////////////////////////////////////
/*
* Function: DeleteAll.
* Deletes all nodes of the list.
*/
template<typename T>
void LinkedList<T>::DeleteAll()
{
	Node<T> *P = Head;
	while (Head != NULL)
	{
		P = Head->getNext();
		delete Head;
		Head = P;
	}
	count = 0;
}