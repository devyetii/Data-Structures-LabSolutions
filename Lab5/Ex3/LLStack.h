#pragma once
#include"Node.h"
#include "StackADT.h"

template<typename T>
class LLStack :
	public StackADT<T>
{
	Node<T>* Head;
public:
	LLStack();
	bool isEmpty() const;
	bool push(const T& newEntry);
	bool pop(T& TopEntry);
	bool peek(T& TopEntry) const;
	~LLStack();
};

template<typename T>
inline LLStack<T>::LLStack()
{
	Head = nullptr;
}

template<typename T>
inline bool LLStack<T>::isEmpty() const
{
	return Head == nullptr;
}

template<typename T>
inline bool LLStack<T>::push(const T & newEntry)
{
	Node<T>* new_nd = new Node<T>(newEntry);
	new_nd->setNext(Head);
	Head = new_nd;
	return true;
}

template<typename T>
inline bool LLStack<T>::pop(T & TopEntry)
{
	if (Head == nullptr) return false;
	TopEntry = Head->getItem();
	Node<T>* del_ptr = Head;
	Head = Head->getNext();
	del_ptr->setNext(nullptr);
	delete del_ptr;
	return true;
}

template<typename T>
inline bool LLStack<T>::peek(T & TopEntry) const
{
	if (Head == nullptr) return false;
	TopEntry = Head->getItem();
	return true;
}

template<typename T>
inline LLStack<T>::~LLStack()
{
	Node<T>* del_ptr = Head, *nxt_ptr = nullptr;
	while (del_ptr != nullptr) {
		nxt_ptr = del_ptr->getNext();
		del_ptr->setNext(nullptr);
		delete del_ptr;
		del_ptr = nxt_ptr;
	}
}
