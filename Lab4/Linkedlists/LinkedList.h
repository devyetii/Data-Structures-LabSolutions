#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"

class LinkedList
{
private:
	Node *Head;	//Pointer to the head of the list
		//You can add tail pointer too (depending on your problem)
	int count;	//Number of nodes in the list
	void _deleteNodeAfter(Node*);
	void _deleteHead();
public:
	LinkedList();
	~LinkedList();
	Node* getHead();
	void PrintList();	//prints all items in the list
	void InsertBeg(int data);	//inserts a new node at list head
	bool InsertBefore(int old_val, int new_val);
	void MergeSorted(LinkedList* L);
	void DeleteAll();	//Deletes all nodes in the list

	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(int data);	

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(int Key);

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(int value);

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
	bool DeleteNode(int value);	

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNodes(int value);	

	void DeleteLarger(int value);

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	void Merge(LinkedList L);

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
	void Reverse();

	void PrintKth(int k) const;

	void DeleteKey(int Key);

	Node* GetMin();
	
};

#endif	
