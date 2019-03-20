//NULL is not a standard C++ keyword or defined symbol, Therefore the following 3 lines of code
//make your code portable to compilers that do not define NULL by default.
#ifndef NULL
#define NULL 0
#endif
#ifndef _NODE
#define _NODE

//First let's declare a singele node in the list
template<typename T>
class Node
{
private :
	T item;	// A data item (can be any complex sturcture)
	Node<T>* next;	// Pointer to next node
public :
	Node();
	Node( T newItem);
	void setItem(T  newItem);
	void setNext(Node<T>* nextNodePtr);
	T getItem() const ;
	Node<T>* getNext() const ;
}; // end Node

#endif

template<typename T>
Node<T>::Node( )
{
	next= NULL;
}  // end default constructor

template<typename T>
Node<T>::Node( T newItem)
{
	item = newItem;
	next= NULL;

}//end constructor

template<typename T>
void Node<T>::setItem(T newItem)
{
	item = newItem;
} // end setItem

template<typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
next = nextNodePtr;
} // end setNext

template<typename T>
T Node<T>::getItem() const
{
return item;
} // end getItem

template<typename T>
Node<T>* Node<T>::getNext() const
{
return next;
} // end getNext
