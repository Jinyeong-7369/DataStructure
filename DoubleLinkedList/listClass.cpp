#include<iostream>

using namespace std;

#include"listClass.h"

listClass::listClass()
{
	head = NULL;
	tail = NULL;
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
		if (count == 0)//ù ��° ��� ���� ��� ������ �ٲ�
		{
			p->prev = NULL;
			p->next = NULL;
			head = p;
			tail = p;
		}
		else if (position == 1)//ù ��° ��ġ ����, ��尡 �ٲ�
		{
			p->prev = NULL;
			p->next = head;
			head = p;
			p->next->prev = p;

		}
		else if (position == count + 1)//�� ���� ����, ������ �ٲ�
		{
			p->next = NULL;
			p->prev = tail;
			tail->next = p;
			tail = p;
		}
		else//ù ��° ��ġ�� �ƴѰ�� ��尡 �ٲ��� ���� 
		{
			Nptr tmp;
			if (position <= count / 2)
			{
				tmp = head;
				for (int i = 1; i < position ; i++)//position��ġ ����
				{
					tmp = tmp->next;
				}
			}
			else
			{
				tmp = tail;
				for (int i = count; i > position; i--)//position��ġ�� ���� 
				{
					tmp = tmp->prev;
				}
			}
			p->next = tmp;
			p->prev = tmp->prev;
			tmp->prev->next = p;
			p->next->prev = p;
		}
		count++;//����Ʈ ���� ����
		cout << "����Ʈ�� " << position << " ��ġ�� " << item << " ���� �߽��ϴ�." << endl;
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
		if (count == 1)
		{
			p = head;
			head = NULL;
			tail = NULL;
		}
		else if (position == 1)//�����Ϸ��� ��ġ�� �� ���ΰ��, ��尡 �ٲ�
		{
			p = head;
			head = head->next;
			head->prev = NULL;
		}
		else if (position == count)
		{
			p = tail;
			tail = tail->prev;
			tail->next = NULL;
		}
		else
		{
			if (position >= count / 2)
			{
				p = head;
				for (int i = 1; i < position; i++)
				{
					p = p->next;
				}
			}
			else
			{
				p = tail;
				for (int i = count; i > position; i--)
				{
					p = p->prev;
				}
			}
			p->next->prev = p->prev;
			p->prev->next = p->next;
		}
		delete(p);
		count--;//����Ʈ ũ�� ���� 
		cout << "����Ʈ�� " << position << " ��ġ�� �����͸� ���� �߽��ϴ�." << endl;
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
		Nptr p;
		if (position <= count / 2)
		{
			p = head;//��� ���� ����
			for (int i = 1; i < position; i++)//position�� �ٷ� �� ������ �̵�
			{
				p = p->next;
			}
		}
		else
		{
			p = tail;
			for (int i = count; i > position; i--)
			{
				p = p->prev;
			}
		}
		item = p->data;//item�� data ���� 
	}
}
void listClass::DeleteData(int item)
{
	if(IsEmpty())
	{ 
		cout << "����Ʈ�� ��� �ֽ��ϴ�." << endl;
	}
	else
	{
		Nptr p = head;
		for (int i = 1; i < count + 1; i++)
		{
			p = p->next;
			if (p->data == item)
			{
				break;
			}
		}
		if (p->data == NULL)
		{
			cout << "�����͸� ã�� �� �����ϴ�." << endl;
		}
		else
		{
			if (count == 1)
			{
				head = NULL;
				tail = NULL;
			}
			else if (p == head)
			{
				head = p->next;
				head->prev = NULL;
			}
			else if (p == tail)
			{
				tail = p->prev;
				tail->next == NULL;
			}
			else
			{
				p->prev->next = p->next;
				p->next->prev = p->prev;
			}
			free(p);
			count--;
			cout << item << "�����͸� �����߽��ϴ�. " << endl;
		}
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