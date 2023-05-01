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
	while (!IsEmpty())//리스트가 빌 때 까지 계속
	{
		Delete(1);
	}
}
void listClass::PrintAll()//출력
{
	Nptr tmp = head;
	for (int i = 0; i < count; i++)
	{
		cout << '[' << tmp->data << ']';
		tmp = tmp->next;
	}
	cout << endl;
}
void listClass::Insert(int position, int item)//지정한 위치에 삽입
{
	if (position < 1 || position > count + 1)//1보다 작은 위치, 이격된 위치 불허 
	{
		cout << "잘못된 위치 지정입니다." << endl;
	}
	else
	{
		Nptr p = new node;
		p->data = item;//p가 가리키는 노드는 item을 저장하고 있다
		if (count == 0)//첫 번째 노드 삽입 헤드 테일이 바뀜
		{
			p->prev = NULL;
			p->next = NULL;
			head = p;
			tail = p;
		}
		else if (position == 1)//첫 번째 위치 삽입, 헤드가 바뀜
		{
			p->prev = NULL;
			p->next = head;
			head = p;
			p->next->prev = p;

		}
		else if (position == count + 1)//맨 끝에 삽입, 테일이 바뀜
		{
			p->next = NULL;
			p->prev = tail;
			tail->next = p;
			tail = p;
		}
		else//첫 번째 위치가 아닌경우 헤드가 바뀌지 않음 
		{
			Nptr tmp;
			if (position <= count / 2)
			{
				tmp = head;
				for (int i = 1; i < position ; i++)//position위치 까지
				{
					tmp = tmp->next;
				}
			}
			else
			{
				tmp = tail;
				for (int i = count; i > position; i--)//position위치에 삽입 
				{
					tmp = tmp->prev;
				}
			}
			p->next = tmp;
			p->prev = tmp->prev;
			tmp->prev->next = p;
			p->next->prev = p;
		}
		count++;//리스트 길이 늘임
		cout << "리스트의 " << position << " 위치에 " << item << " 삽입 했습니다." << endl;
	}
}
void listClass::Delete(int position)//지정한 위치 삭제
{
	if (IsEmpty())//리스트가 비어있다면 오류 발생
	{
		cout << "리스트가 비어 있습니다." << endl;
	}
	else if (position < 1 || position > count)//1보다 작은 위치, count보다 큰 위치 불허 
	{
		cout << "잘못된 위치 지정입니다." << endl;
	}
	else
	{
		Nptr p;//삭제하려는 노드를 가리키는 포인터
		if (count == 1)
		{
			p = head;
			head = NULL;
			tail = NULL;
		}
		else if (position == 1)//삭제하려는 위치가 맨 앞인경우, 헤드가 바뀜
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
		count--;//리스트 크기 감소 
		cout << "리스트의 " << position << " 위치의 데이터를 삭제 했습니다." << endl;
	}
}
void listClass::Retrieve(int position, int& item)//지정한 위치 데이터 복사
{
	if (IsEmpty())//리스트가 비어있으면 오류 발생
	{
		cout << "리스트가 비어 있습니다." << endl;
	}
	else if (position < 1 || position > count)//1보다 작은위치 및 count보다 큰 위치 불허 
	{
		cout << "잘못된 위치 지정입니다." << endl;
	}
	else
	{
		Nptr p;
		if (position <= count / 2)
		{
			p = head;//헤드 부터 시작
			for (int i = 1; i < position; i++)//position의 바로 뒤 노드까지 이동
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
		item = p->data;//item에 data 복사 
	}
}
void listClass::DeleteData(int item)
{
	if(IsEmpty())
	{ 
		cout << "리스트가 비어 있습니다." << endl;
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
			cout << "데이터를 찾을 수 없습니다." << endl;
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
			cout << item << "데이터를 삭제했습니다. " << endl;
		}
	}
}
bool listClass::IsEmpty()//리스트가 비어있는지 검사 
{
	return (count == 0);
}
int listClass::Length()//리스트의 크기 반환 
{
	return count;
}