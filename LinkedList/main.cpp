#include<iostream>
using namespace std;

#include"listClass.h"

int main(void)
{
	listClass list;//����Ʈ ����
	int n = 0;
	//Insert
	list.Insert(-1, 0);//1���� ���� ��ġ ���� ����
	list.Insert(1, 3);//ù ��° ��ġ ����(count : 1)
	list.Insert(2, 5);//�� ��° ��ġ ����(count : 2)
	list.Insert(3, 6);//�� ��° ��ġ ����(count : 3)
	list.Insert(5, 9);//�̰ݵ� ��ġ ���� ����
	list.Insert(1, 4);//ù ��° ��ġ ����(count : 4)
	list.Insert(5, 2);//�ټ���° ��ġ ����(count : 5)
	list.Insert(3, 3);//����Ʈ�� ���� á�� �� ���� ����
	//Retrieve
	for (int i = 1; i < list.Length() + 1; i++)
	{//�ݺ������� ó�� �ε��� ���� ������ �ε������� �����ϰ� ����ϱ� 
		list.Retrieve(i, n);
		cout << "n : " << n << endl;
	}

	//Delete �� Retrieve
	list.Delete(1);//ù ��° ��ġ ����(count : 4)
	list.Retrieve(5, n);//����ִ� ����Ʈ ������ ���� 
	list.Delete(4);//������ ��ġ ����(count : 3)
	list.Delete(2);//�� ��° ��ġ ����(count : 2)
	list.Delete(1);//ù ��° ��ġ ����(count : 1)
	list.Delete(2);//����ִ� ��ġ ������ ����
	list.Delete(1);//ù ��° ��ġ ����(count : 0)
	list.Retrieve(1, n);//����ִ� ����Ʈ ������ ���� 

	//Insert �� �Ҹ��� �Լ�
	list.Insert(1, 3);//ù ��° ��ġ ����(count : 1)
	list.Insert(2, 5);//�� ��° ��ġ ����(count : 2)
	list.Insert(3, 6);//�� ��° ��ġ ����(count : 3)
	list.Insert(1, 4);//ù ��° ��ġ ����(count : 4)
	list.Insert(5, 2);//�ټ���° ��ġ ����(count : 5)
}