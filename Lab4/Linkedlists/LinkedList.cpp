#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
	count = 0;
	Head = NULL;
}


//List is being desturcted ==> delete all items in the list
LinkedList::~LinkedList()
{
	DeleteAll();
}


////////////////////////////////////////////////////////////////////////
/*
* UtilFunction: _deleteNode.
* Deletes after a given Node - if it's not the head - and handels different cases of deletion.
*/

void LinkedList::_deleteNodeAfter(Node* n)
{
	if (n->getNext() == nullptr) return; 
	Node* ptrToDelete = n->getNext();
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
void LinkedList::_deleteHead()
{
	Node* delptr = Head;
	Head = Head->getNext();
	delptr->setNext(nullptr);
	delete delptr;
}

////////////////////////////////////////////////////////////////////////
/*
* Function: InsertEnd.
* inserts a new node at end if the list.
*/

Node* LinkedList::getHead()
{
	return Head;
}

void LinkedList::InsertEnd(int data)
{

	if (Head->getNext() == nullptr) {
		Head->setItem(data);		
	}
	else {
		Node* ptr = this->Head;
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
bool LinkedList::Find(int Key)
{
	if (Head == nullptr) return false;
	Node* ptr = Head;
	while (ptr != nullptr) {
		if (ptr->getItem() == Key) return true;
		ptr = ptr->getNext();
	}
	return false;
}

////////////////////////////////////////////////////////////////////////
/*
* Function: DeleteNodes.
* Deletes ALL nodes with the given value and
  returns true. if not found, returns false.
*/
bool LinkedList::DeleteNodes(int value)
{
	if (!Find(value)) return false;
	Node* ptr = Head;
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
void LinkedList::DeleteLarger(int value)
{
	Node* ptr = Head;
	while (ptr->getNext() != nullptr) {
		if (ptr->getNext()->getItem() > value) {
			_deleteNodeAfter(ptr);
		}
		else ptr = ptr->getNext();
	}
	if (Head->getItem() > value) _deleteHead();
}


/*void LinkedList::MergeSorted(LinkedList* L)
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
void LinkedList::PrintList()
{
	cout<<"\nList has "<<count<<" nodes";
	cout<<"\nprinting list contents:\n\n";
	Node *p = Head;
	
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
void LinkedList::InsertBeg(int data)
{
	Node *R = new Node(data);
	R->setNext(Head);
	Head = R;
	count++;

}

bool LinkedList::InsertBefore(int old_val, int new_val)
{
	if (Find(old_val) == false) return false;
	Node* ptr = Head, *prev = nullptr;
	Node* newNode = new Node(new_val);
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
void LinkedList::DeleteAll()
{
	Node *P = Head;
	while (Head != NULL)
	{
		P = Head->getNext();
		delete Head;
		Head = P;
	}
	count = 0;
}

void LinkedList::PrintKth(int k) const
{
	Node * ptr = Head;
	int cnt = 1;
	while (ptr) // ptr != NULL
	{
		if (cnt == k)
		{
			cout << ptr->getItem() << endl;
			return;
		}
		ptr = ptr->getNext();
		cnt++;
	}
	cout << "Beyond List Length\n";
}
void LinkedList::DeleteFirst()
{
	if (!Head)
	{
		return;
	}
	Node* temp = Head;
	Head = Head->getNext();
	delete temp;
	count--;
}
void LinkedList::DeleteKey(int Key)
{
	if (!Head)
	{
		return;
	}
	while (Head && Head->getItem() == Key)
	{
		Node* temp = Head;
		Head = Head->getNext();
		delete temp;
		count--;
	}
	Node* prev = Head;
	while (prev && prev->getNext())
	{
		Node* nxt = prev->getNext();
		if (nxt->getItem() == Key)
		{
			prev->setNext(nxt->getNext());
			delete nxt;
			count--;
		}
		else
		{
			prev = prev->getNext();
		}
	}

}
Node* LinkedList::GetMin()
{
	if (!Head)
	{
		return Head;
	}
	Node* MinElement = Head;
	Node* ptr = Head->getNext();
	while (ptr)
	{
		if (ptr->getItem() < MinElement->getItem())
		{
			MinElement = ptr;
		}
		ptr = ptr->getNext();
	}
	if (Head->getItem() == MinElement->getItem())
	{
		Head = Head->getNext();
		MinElement->setNext(NULL);
		count--;
	}
	else
	{
		ptr = Head;
		while (ptr && ptr->getNext())
		{
			Node* nxt = ptr->getNext();
			if (nxt->getItem() == MinElement->getItem())
			{
				ptr->setNext(nxt->getNext());
				nxt->setNext(NULL);
				count--;
				break;
			}
		}
	}
	return MinElement;
}

void LinkedList::SignSplit(LinkedList& lpos, LinkedList& lneg)
{
	if (!Head)
	{
		return;
	}
	Node* ptr_pos = lpos.Head;
	Node* ptr_neg = lneg.Head;
	while (Head && Head->getItem() != 0)
	{
		if (Head->getItem() > 0)
		{
			if (!ptr_pos)
			{
				lpos.Head = Head;
				ptr_pos = lpos.Head;
			}
			else
			{
				ptr_pos->setNext(Head);
				ptr_pos = ptr_pos->getNext();
			}
			lpos.count++;
			count--;
		}
		else if (Head->getItem() < 0)
		{
			if (!ptr_neg)
			{
				lneg.Head = Head;
				ptr_neg = lneg.Head;
			}
			else
			{
				ptr_neg->setNext(Head);
				ptr_neg = ptr_neg->getNext();
			}
			lneg.count++;
			count--;
		}
		Head = Head->getNext();
	}
	Node* ptr = Head;
	while (ptr && ptr->getNext())
	{
		Node* nxt = ptr->getNext();
		if (ptr_neg && nxt->getItem() < 0)
		{
			ptr_neg->setNext(nxt);
			ptr_neg = nxt;
			ptr->setNext(nxt->getNext());
			count--;
			lneg.count++;
		}
		else if (!ptr_neg && nxt->getItem() < 0)
		{
			lneg.Head = nxt;
			ptr_neg = lneg.Head;
			ptr->setNext(nxt->getNext());
			count--;
			lneg.count++;
		}
		else if (ptr_pos && nxt->getItem() > 0)
		{
			ptr_pos = nxt;
			ptr->setNext(nxt->getNext());
			count--;
			lpos.count++;
		}
		else if (!ptr_pos && nxt->getItem() > 0)
		{
			lpos.Head = nxt;
			ptr_pos = lpos.Head;
			ptr->setNext(nxt->getNext());
			count--;
			lpos.count++;
		}
		else
		{
			ptr = ptr->getNext();
		}
	}
	ptr_neg->setNext(nullptr);
	ptr_pos->setNext(nullptr);
}

void LinkedList::MergeSorted(LinkedList &L)
{
	if (!L.Head)
	{
		return;
	}
	if (!Head)
	{
		Head = L.Head;
		L.Head = NULL;
		count += L.count;
		L.count = 0;
		return;
	}
	if (Head->getItem() > L.Head->getItem())
	{
		Node* temp = Head;
		Head = L.Head;
		L.Head = temp;
	}
	Node* ptr1 = Head;
	Node* ptr2 = L.Head;
	while (ptr1 && ptr1->getNext() && ptr2)
	{
		if (ptr1->getNext()->getItem() <= ptr2->getItem())
		{
			ptr1 = ptr1->getNext();
		}
		else
		{
			Node* temp = ptr1->getNext();
			ptr1->setNext(ptr2);
			ptr2 = ptr2->getNext();
			ptr1->getNext()->setNext(temp);
			ptr1 = ptr1->getNext();
		}
	}
	if (ptr2)
	{
		ptr1->setNext(ptr2);
	}
	count += L.count;
	L.count = 0;
	L.Head = NULL;
}

void LinkedList::Reorder_X(int x)
{
	Node* ptr = Head;
	if (!ptr || !(ptr->getNext()))
	{
		return;
	}

	while (ptr && ptr->getNext()) 
	{
		Node* nxt = ptr->getNext();
		if (nxt->getItem() <= x)
		{
			ptr->setNext(nxt->getNext());
			nxt->setNext(Head);
			Head = nxt;
		}
		else
			ptr = ptr->getNext();
	}

}

void LinkedList::RemoveDuplicates()
{
	if (!Head)
	{
		return;
	}
	Node* ptr = Head;
	LinkedList NonDuplictedElements;
	NonDuplictedElements.Head = new Node(Head->getItem());
	while (ptr && ptr->getNext())
	{
		Node* nxt = ptr->getNext();
		Node* ptr2 = NonDuplictedElements.Head;
		bool found = 0;
		while (ptr2 && !found)
		{
			if (ptr2->getItem() == nxt->getItem())
			{
				found = 1;
			}
			ptr2 = ptr2->getNext();
		}
		if (found)
		{
			_deleteNodeAfter(ptr);
		}
		else
		{
			NonDuplictedElements.InsertBeg(nxt->getItem());
			ptr = ptr->getNext();
		}
	}
	NonDuplictedElements.DeleteAll();
}