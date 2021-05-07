#pragma once
#define N 5

class Stack
{
	private:
		int top;
		int size;
		int* data;
	public:
		Stack();
		Stack(Stack&);
		Stack& operator=(Stack&);
		~Stack();
		int set(int, int);
		int get(int, int*);
		void push(int);
		int pop(int*);
		int get_size();
		void print();
};

