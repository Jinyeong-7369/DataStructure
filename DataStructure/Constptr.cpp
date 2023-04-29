#include<iostream>
using namespace std;
void InOrder(int x, int y)
{
	if (y > x)
	{
		++x;
		--y;
		cout << x << " " << y << endl;
		InOrder(x, y);
		cout << x << " " << y << endl;
	}
}
int main(void)
{
	InOrder(2, 10);
}