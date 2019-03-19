//NULL is not a standard C++ keyword or defined symbol, Therefore the following 3 lines of code
//make your code portable to compilers that do not define NULL by default.
#ifndef NULL
#define NULL 0
#endif
#ifndef _NODE
#define _NODE

//First let's declare a singele node in the list
class Node
{
private :
	int item;	// A data item (can be any complex sturcture)
	Node* next;	// Pointer to next node
public :
	Node();
	Node( int newItem);
	void setItem(int  newItem);
	void setNext(Node* nextNodePtr);
	int getItem() const ;
	Node* getNext() const ;
}; // end Node

#endif	
