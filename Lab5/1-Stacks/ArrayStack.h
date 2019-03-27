//	This is an updated version of code originally
//  created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT stack: Array-based implementation.
 @file ArrayStack.h */

#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#include "StackADT.h"


//Unless spesificed by the stack user, the default size is 100
template<typename ItemType, int STACK_SIZE=100> 
class ArrayStack : public StackADT<ItemType>
{
private:
	ItemType items[STACK_SIZE];		// Array of stack items
	int      top;                   // Index to top of stack
	
public:
	 ArrayStack();                 // Default constructor
	 bool isEmpty() const;
	 bool push(const ItemType& newEntry);
	 bool pop(ItemType& TopEntry);
	 bool peek(ItemType& TopEntry) const;
}; // end ArrayStack



template<typename ItemType, int STACK_SIZE>
ArrayStack<ItemType, STACK_SIZE>::ArrayStack() : top(-1)
{
}  // end default constructor

// Copy constructor and destructor are supplied by the compiler

template<typename ItemType, int STACK_SIZE>
bool ArrayStack<ItemType, STACK_SIZE>::isEmpty() const
{
	return top < 0;	
}  // end isEmpty

template<typename ItemType, int STACK_SIZE>
bool ArrayStack<ItemType, STACK_SIZE>::push(const ItemType& newEntry)
{
	if( top == STACK_SIZE-1 ) return false;

	top++;
	items[top] = newEntry;   
	return true;
}  // end push

template<typename ItemType, int STACK_SIZE>
bool ArrayStack<ItemType, STACK_SIZE>::pop(ItemType& TopEntry)
{

	if (isEmpty()) return false;
		
	TopEntry = items[top];		 
	top--;
	return true;

}  // end pop

template<typename ItemType, int STACK_SIZE>
bool ArrayStack<ItemType, STACK_SIZE>::peek(ItemType& TopEntry) const
{
	if (isEmpty()) return false;
		
	TopEntry = items[top];		 
	return true;
}  // end peek


#endif
