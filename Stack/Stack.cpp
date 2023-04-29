#include<iostream>
using namespace std;
#include"Stack.h"

Stack::Stack()
{
	
}
Stack::~Stack()
{
	while (!IsEmpty())
	{
		Pop();
	}
}
void Stack::Push(int item)
{
	Insert(Length() + 1, item);
}
int Stack::Pop()
{
	int top =  GetTop();
	Delete(Length());
	return top;
}
int Stack::GetTop()
{
	int top;
	Retrieve(Length(), top);
	return top;
}

int main()
{
	Stack stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
}