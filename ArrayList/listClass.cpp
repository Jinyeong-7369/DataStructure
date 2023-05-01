#include<iostream>
#include<string>
#include "listClass.h"

using namespace std;

listClass::listClass()
{
	count = 0;//count 0���� �ʱ�ȭ
}
listClass::~listClass()
{
	//�ƹ��� ��ɵ� ���� ����
}
void listClass::Insert(int position, int item)
{
	if (count == MAX)//����Ʈ�� ���� á�ٸ� 
	{
		cout << "����Ʈ�� ���� á���ϴ�." << endl;
	}
	else if (position < 1 || position > count + 1)//1���� ���� ��ġ, �̰ݵ� ��ġ ���� 
	{
		cout << "�߸��� ��ġ �����Դϴ�." << endl;
	}
	else
	{
		
		for (int i = count - 1; i >= position - 1; i--)
		{
			//�����͸� �ڷ� �о ������ex)1,2,3,4->1,1,2,3,4
			data[i + 1] = data[i];
		}
		data[position - 1] = item;//���ϴ� ��ġ�� ������ ����ex)1,1,2,3,4->0,1,2,3,4
		count++;//����Ʈ ���� ����
		cout <<"����Ʈ�� " << position << " ��ġ�� " << item << " ���� �߽��ϴ�." << endl;
	}

}
void listClass::Delete(int position)
{
	if (IsEmpty())//����Ʈ�� ����ִٸ� ���� �߻�
	{
		cout << "����Ʈ�� ��� �ֽ��ϴ�." << endl;
	}
	else if (position < 1 || position > count)//1���� ���� ��ġ, count���� ū ��ġ ���� 
	{
		cout << "�߸��� ��ġ �����Դϴ�." << endl;
	}
	else
	{
		for (int i = position - 1; i < count - 1; i++)
		{
			//�����͸� ���� �Ἥ ������ ex)1,2,3,4,5 -> 2,3,4,5
			data[i] = data[i + 1];
		}
		count--;//����Ʈ ũ�� ���� 
		cout << "����Ʈ�� " << position << " ��ġ�� �����͸� ���� �߽��ϴ�." << endl;
	}
}
void listClass::Retrieve(int position, int& item)
{
	if(IsEmpty())//����Ʈ�� ��������� ���� �߻�
	{
		cout << "����Ʈ�� ��� �ֽ��ϴ�." << endl;
	}
	else if (position < 1 || position > count)//1���� ������ġ �� count���� ū ��ġ ���� 
	{
		cout << "�߸��� ��ġ �����Դϴ�." << endl;
	}
	else
	{
		item = data[position - 1];
	}
}
void listClass::PrintAll()
{
	for (int i = 0; i < count; i++)
	{
		
		cout << '[' << data[i] << ']';
	}
	cout << endl;
}
bool listClass::IsEmpty()
{
	return (count == 0);//�� ����Ʈ ��� true��ȯ 
}
int listClass::Length()
{
	return count;//count ��ȯ 
}
