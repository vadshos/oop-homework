#pragma once
#include <iostream>
#include"Bus.h"

template<typename T>
class Dlist
{
public:
	Dlist() = default;
	Dlist(const Dlist& obj);
	void pushFront(const T& data);
	void pushTail(const T& data);
	void popFront();
	void popBack();
	void pushAfter(const T& searchData, const T& data);
	void pushBefore(const T& searchData, const T& data);
	auto findNode(const size_t& data);
	auto findAndReturnBusNode(const size_t& data);

	bool replace(const T& SearchData, const T& data);
	void reverse();
	void popSomeElement(const size_t& data);
	bool isEmpty() const;
	Dlist concat(Dlist obj);
	Dlist interseption(Dlist obj);
	size_t getSize() const;
	void print();
	void clear();
	void rPrint();
private:
	struct Node
	{
		Bus data;
		Node* next, * prev;
		Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr)
			:data(data), next(next), prev(prev)
		{

		};
	};
	Node* head = nullptr;
	Node* tail = nullptr;
	size_t size = 0;
};

template<typename T>
inline Dlist<T>::Dlist(const Dlist& obj)
{
	Node* temp = obj.head;
	while (temp != nullptr) {
		pushTail(temp->data);
		temp = temp->next;
	}
}

template<typename T>
inline void Dlist<T>::pushFront(const T& data)
{
	Node* tmp = new Node(data, nullptr, head);
	if (isEmpty())
	{
		tail = tmp;
	}
	else
	{
		head->prev = tmp;
	}
	++size;
	head = tmp;

}

template<typename T>
inline void Dlist<T>::pushTail(const T& data)
{
	Node* add = new Node(data, tail, nullptr);
	if (!isEmpty())
	{
		tail->next = add;
	}
	else {
		head = add;
	}
	size++;
	tail = add;
}

template<typename T>
inline void Dlist<T>::popFront()
{
	if (!isEmpty())
	{
		auto tmp = head;
		head = head->next;
		if (isEmpty())
		{
			tail = nullptr;

		}
		else {
			head->prev = nullptr;
		}
		delete tmp;
		--size;
	}

}

template<typename T>
inline void Dlist<T>::popBack()
{
	if (!isEmpty())
	{
		if (size == 1) {
			clear();
		}
		else {
			Node* temp = tail->prev;
			delete tail;
			tail = temp;
			temp->next = nullptr;
		}
	}
	else {
		head = nullptr;
		tail = nullptr;
	}
}

template<typename T>
inline void Dlist<T>::pushAfter(const T& searchData, const T& data)
{
	Node* find = findNode(searchData);
	if (find != nullptr)
	{
		Node* ins = new Node(data, find->prev, find->next);
		find->next = ins;
		if (find == tail)
		{
			tail = ins;
		}
	}
}

template<typename T>
inline void Dlist<T>::pushBefore(const T& searchData, const T& data)
{
	Node* find = findNode(searchData);
	if (find != nullptr)
	{
		Node* ins = new Node(data, find->prev, find);
		find->prev = ins;
		find->prev->prev->next = ins;

		if (find == tail)
		{
			tail = ins;
		}
	}
}

template<typename T>
inline auto Dlist<T>::findNode(const size_t& data)
{
	Node* tmp = head;
	while (tmp != nullptr && tmp->data.id != data)
	{
		tmp = tmp->next;
	}
	return tmp;
}

template<typename T>
inline auto Dlist<T>::findAndReturnBusNode(const size_t& data)
{
	Node* tmp = findNode(data);
	return tmp->data;
}

template<typename T>
inline bool Dlist<T>::replace(const T& SearchData, const T& data)
{
	Node* find = findNode(SearchData);
	if (find != nullptr)
	{
		find->data = data;
		if (find == tail)
		{
			tail->data = data;
		}
		return true;
	}
	return false;
}

template<typename T>
inline void Dlist<T>::reverse()
{
	Node* temp = head;
	Dlist <T> reversed_list;
	while (temp != nullptr) {
		reversed_list.pushFront(temp->data);
		temp = temp->next;
	}
	this->clear();
	*this = reversed_list;
}


template<typename T>
inline void Dlist<T>::popSomeElement(const size_t& data)
{
	Node* find = findNode(data);
	if (find != nullptr)
	{
		if (find == head) {
			popFront();
		}
		else if (find == tail) {
			popBack();
		}
		else if (find->next != nullptr)
		{
			find->prev->next = find->next;
			find->next->prev = find->prev;
			delete find;
		}
		--size;


	}
}

template<typename T>
inline bool Dlist<T>::isEmpty() const
{
	return head == nullptr;
}

template<typename T>
inline Dlist<T> Dlist<T>::concat(Dlist obj)
{
	Dlist<T>  c;
	Node* temp = head;
	while (temp != tail) {
		c.pushFront(temp->data);
		temp = temp->next;
	}
	temp = obj.head;
	while (temp != obj.tail) {
		c.pushFront(temp->data);
		temp = temp->next;
	}
	return c;
}

template<typename T>
inline Dlist<T> Dlist<T>::interseption(Dlist obj)
{
	Dlist<T>  c;
	Node* temp = head;
	Node* tmp = obj.head;
	while (temp != tail) {
		while (tmp != obj.tail) {
			if (temp->data == tmp->data) {
				c.pushTail(temp->data);
				tmp = tmp->next;
				break;
			}
		}
		temp = temp->next;
	}
	return c;
}

template<typename T>
inline size_t Dlist<T>::getSize() const
{
	return size;
}

template<typename T>
inline void Dlist<T>::print()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
	std::cout << std::endl;
}

template<typename T>
inline void Dlist<T>::clear()
{
	while (!isEmpty())
	{
		popFront();
	}
}

template<typename T>
inline void Dlist<T>::rPrint()
{
	Node* temp = tail;
	while (temp != head)
	{
		std::cout << temp->data << std::endl;
		temp = temp->prev;
	}
	std::cout << std::endl;
}
