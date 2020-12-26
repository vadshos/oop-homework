#pragma once
#include <iostream>
#include"Bus.h"

using namespace std;

class DList
{
	struct Node
	{
		Bus data;
		Node* next, * prev;
		Node(const Bus data = Bus(), Node* prev = nullptr, Node* next = nullptr)
			: data(data), next(next), prev(prev)
		{}
	};
public:
	DList() = default;
	void pushFront(const Bus data);
	void pushBack(const Bus data);
	bool isEmpty() const;
	size_t getSize() const;
	auto popSomeElement(Bus* data);
	void print() const;
	void printR() const;
	void popBack();
	//~DList();
private:
	Node* head = nullptr, * tail = nullptr;
	size_t size = 0;
};




inline auto DList::pushFront(const Bus data)
{
	Node* tmp = new Node(data, nullptr, head); // data prev   next
	if (isEmpty())
	{
		tail = tmp;
	}
	else
	{
		head->prev = tmp;
	}
	head = tmp;
	++size;
}


inline void DList::pushBack(const Bus data)
{
	Node* tmp = new Node(data, tail, nullptr);
	if (isEmpty())
	{
		head = tmp;
	}
	else
	{
		tail->next = tmp;
	}

	tail = tmp;
	++size;
}


inline bool DList::isEmpty() const
{
	return head == nullptr;
}


inline size_t DList::getSize() const
{
	return size;
}






inline void DList::print() const
{
	// from left to right
	Node* tmp = head;
	cout << "List directly : ";
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}

inline void DList::printR() const
{
	cout << "List in reverse : ";
	Node* tmp = tail;
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->prev;
	}
	cout << endl;
}

inline void DList::popBack()
{
	if (!isEmpty())
	{
		Node* tmp = head;
		if (tmp->next == nullptr)
		{
			tail = nullptr;
			head = nullptr;
			return;
		}
		while (tmp->next != tail)
		{
			tmp = tmp->next;
		}
		delete tmp->next;
		tail = tmp;
		tmp->next = nullptr;
		

	}
}
