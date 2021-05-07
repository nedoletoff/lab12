#include "pr.hpp"
#include <iostream>

Stack::Stack()
{
	size = N;
	top = -1;
	data = new int [size];
}

Stack::~Stack()
{
	delete [] data;
}

Stack& Stack::operator=(Stack& a)
{
	if (&a == this)
		return *this;
	delete [] data;
	top = a.top;
	size = a.size;
	data = new int [size];
	for (int i = 0; i <= top; ++i)
		data[i] = a.data[i];
	return *this;
}

Stack::Stack(Stack& a)
{
	size = a.size;
	top = a.top;
	data = new int [size];
	for (int i = 0; i <= top; ++i)
		data[i] = a.data[i];
}

int Stack::set(int index, int value)
{
	if (index > top || index < 0)
	{
		std::cout << "Index out of scope" << std::endl;
		return 1;
	}
	data[index] = value;
	return 0;
}

int Stack::get(int index, int* rv)
{
	if (index > top || index < 0)
	{
		std::cout << "Index out of scope" << std::endl;
		return 1;
	}
	*rv = data[index];
	return 0;
}

void Stack::push(int value)
{
	if (size == top + 1)
	{
//		std::cout << "resize push\n";
		int* cur = new int [size];
		for (int i = 0; i <= top; ++i)
			cur[i] = data[i];
		delete [] data;
		size += N;
		data = new int [size];
		for (int i = 0; i <= top; ++i)
			data[i] = cur[i];
		delete [] cur;
	}
	data[++top] = value;
}

int Stack::pop(int* rv)
{
	if (top < 0)
	{
		std::cout << "Stack is empty" << std::endl;
		return 1;
	}

	if (size > top + N*2)
	{
//		std::cout << "resize pop\n";
		int* cur = new int [size];
		for (int i = 0; i <= top; ++i)
			cur[i] = data[i];
		delete [] data;
		size -= N;
		data = new int [size];
		for (int i = 0; i <= top; ++i)
			data[i] = cur[i];
		delete [] cur;
	}
	*rv = data[top--];
	return 0;
}

int Stack::get_size()
{
	return top;
}

void Stack::print()
{
	for (int i = 0; i <= top; ++i)
		std::cout << data[i] << " - Stack [" << i << "]\n";
}
