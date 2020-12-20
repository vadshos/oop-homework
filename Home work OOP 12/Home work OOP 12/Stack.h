#pragma once
#include <iostream>

template<typename MyType>
class Stack
{
public:
	Stack(int capacity = CAPACYTY_DEFAULT);
	void push(const MyType& element);
	bool empty() const;
	void pop();
	bool full() const;
	const MyType& peak() const;
	void clear();
	int size() const;
	template<typename T> friend std::ostream& operator << (std::ostream& os, const Stack<T>& obj);
private:
	static const  int CAPACYTY_DEFAULT = 10;
	static const  int EMPTY = -1;
	size_t capacity;
	MyType* buffer;
	int top = -1;

};

template<typename MyType>
inline Stack<MyType>::Stack(int capacity)
{
	this->capacity = capacity <= 0 ? CAPACYTY_DEFAULT : capacity;
	buffer = new MyType[this->capacity];
	top = EMPTY;
}

template<typename MyType>
inline void Stack<MyType>::push(const MyType& element)
{
	if (!full()) {
		++top;
		buffer[top] = element;
	}
	else
	{
		std::cerr << "Stack is full" << std::endl;
	}
}

template<typename MyType>
inline bool Stack<MyType>::empty() const
{
	return top != EMPTY ? false : true;
}

template<typename MyType>
inline void Stack<MyType>::pop()
{
	if (!empty()) {
		top--;
	}
}

template<typename MyType>
inline bool Stack<MyType>::full() const
{
	return top == capacity - 1;
}

template<typename MyType>
inline const MyType& Stack<MyType>::peak() const
{
	if (empty()) {

		return  MyType();
	}
	return buffer[top];
}

template<typename MyType>
inline void Stack<MyType>::clear()
{
	top = EMPTY;
}

template<typename MyType>
inline int Stack<MyType>::size() const
{
	return top + 1;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const Stack<T>& obj)
{
	for (int i = obj.top; i >= 0; i--)
	{
		os << obj.buffer[i] << " ";
	}
	return os;

}

