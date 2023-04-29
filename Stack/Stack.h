#include"listClass.h"

class Stack :private listClass
{
public:
	Stack();
	~Stack();
	void Push(int item);
	int Pop();
	int GetTop();
};