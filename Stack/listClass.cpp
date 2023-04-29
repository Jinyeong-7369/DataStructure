#include<iostream>

using namespace std;

#include"listClass.h"

listClass::listClass()
{
	head = NULL;
	count = 0;
}
listClass::~listClass()
{
	while (!IsEmpty())//����Ʈ�� �� �� ���� ���
	{
		Delete(1);
	}
}
void listClass::PrintAll()//���
{
	cout << "count : " << Length() << ' ';//count ���, Length()��� count�� �ᵵ ����
	Nptr tmp = head;
	for (int i = 0; i < count; i++)
	{
		cout << '[' << tmp->data << ']';
		tmp = tmp->next;
	}
	cout << endl;
}
void listClass::Insert(int position, int item)//������ ��ġ�� ����
{
	if (position < 1 || position > count + 1)//1���� ���� ��ġ, �̰ݵ� ��ġ ���� 
	{
		cout << "�߸��� ��ġ �����Դϴ�." << endl;
	}
	else
	{
		Nptr p = new node;
		p->data = item;//p�� ����Ű�� ���� item�� �����ϰ� �ִ�
		if (position == 1)//ù ��° ��ġ ����, ��尡 �ٲ�
		{
			p->next = head;
			head = p;
		}
		else//ù ��° ��ġ�� �ƴѰ�� ��尡 �ٲ��� ���� 
		{
			Nptr tmp = head;//������ ����
			for (int i = 1; i < position - 1; i++)//position�� �ٷ� �� ���� �̵�
			{
				tmp = tmp->next;
			}
			p->next = tmp->next;//p�� ������� = tmp�� ���� ���
			tmp->next = p;//tmp�� ������� = p
		}
		count++;//����Ʈ ���� ����
		cout << "����Ʈ�� " << position << " ��ġ�� " << item << " ���� �߽��ϴ�.";
		PrintAll();//����Ʈ ���� ���
	}
}
void listClass::Delete(int position)//������ ��ġ ����
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
		Nptr p;//�����Ϸ��� ��带 ����Ű�� ������
		if (position == 1)//�����Ϸ��� ��ġ�� �� ���ΰ��, ��尡 �ٲ�
		{
			p = head;
			head = head->next;
		}
		else
		{
			Nptr tmp = head;//��� ���� ����
			for (int i = 1; i < position - 1; i++)//position�� �ٷ� �� ������ �̵�
			{
				tmp = tmp->next;
			}
			p = tmp->next;//p�� position��ġ�� ��带 ����Ŵ
			tmp->next = p->next;
		}
		delete(p);
		count--;//����Ʈ ũ�� ���� 
		cout << "����Ʈ�� " << position << " ��ġ�� �����͸� ���� �߽��ϴ�.";
		PrintAll();//����Ʈ�� ���� ���
	}
}
void listClass::Retrieve(int position, int& item)//������ ��ġ ������ ����
{
	if (IsEmpty())//����Ʈ�� ��������� ���� �߻�
	{
		cout << "����Ʈ�� ��� �ֽ��ϴ�." << endl;
	}
	else if (position < 1 || position > count)//1���� ������ġ �� count���� ū ��ġ ���� 
	{
		cout << "�߸��� ��ġ �����Դϴ�." << endl;
	}
	else
	{
		Nptr p = head;//��� ���� ����
		for (int i = 1; i < position; i++)//position�� �ٷ� �� ������ �̵�
		{
			p = p->next;
		}
		//p�� position��ġ�� ��带 ����Ŵ 


		item = p->data;//item�� data ���� 
		cout << position << "��ġ�� �ִ� ���� ����Ǿ����ϴ�." << endl;
	}
}
bool listClass::IsEmpty()//����Ʈ�� ����ִ��� �˻� 
{
	return (count == 0);
}
int listClass::Length()//����Ʈ�� ũ�� ��ȯ 
{
	return count;
}