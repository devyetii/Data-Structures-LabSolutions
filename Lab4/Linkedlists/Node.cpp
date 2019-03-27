
#include "Node.h"

Node::Node( )
{
	next= NULL;
}  // end default constructor

Node::Node( int newItem)
{
	item = newItem;
	next= NULL;

}//end constructor

void Node::setItem( int newItem)
{
	item = newItem;
} // end setItem

void Node::setNext(Node* nextNodePtr)
{
	next = nextNodePtr;
} // end setNext

int Node::getItem() const
{
return item;
} // end getItem

Node* Node::getNext() const
{
return next;
} // end getNext