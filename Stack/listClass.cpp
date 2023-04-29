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
	while (!IsEmpty())//리스트가 빌 때 까지 계속
	{
		Delete(1);
	}
}
void listClass::PrintAll()//출력
{
	cout << "count : " << Length() << ' ';//count 출력, Length()대신 count를 써도 무방
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
		if (position == 1)//첫 번째 위치 삽입, 헤드가 바뀜
		{
			p->next = head;
			head = p;
		}
		else//첫 번째 위치가 아닌경우 헤드가 바뀌지 않음 
		{
			Nptr tmp = head;//헤드부터 시작
			for (int i = 1; i < position - 1; i++)//position의 바로 뒤 까지 이동
			{
				tmp = tmp->next;
			}
			p->next = tmp->next;//p의 다음노드 = tmp의 다음 노드
			tmp->next = p;//tmp의 다음노드 = p
		}
		count++;//리스트 길이 늘임
		cout << "리스트의 " << position << " 위치에 " << item << " 삽입 했습니다.";
		PrintAll();//리스트 상태 출력
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
		if (position == 1)//삭제하려는 위치가 맨 앞인경우, 헤드가 바뀜
		{
			p = head;
			head = head->next;
		}
		else
		{
			Nptr tmp = head;//헤드 부터 시작
			for (int i = 1; i < position - 1; i++)//position의 바로 뒤 노드까지 이동
			{
				tmp = tmp->next;
			}
			p = tmp->next;//p가 position위치의 노드를 가리킴
			tmp->next = p->next;
		}
		delete(p);
		count--;//리스트 크기 감소 
		cout << "리스트의 " << position << " 위치의 데이터를 삭제 했습니다.";
		PrintAll();//리스트의 상태 출력
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
		Nptr p = head;//헤드 부터 시작
		for (int i = 1; i < position; i++)//position의 바로 뒤 노드까지 이동
		{
			p = p->next;
		}
		//p가 position위치의 노드를 가리킴 


		item = p->data;//item에 data 복사 
		cout << position << "위치에 있는 값이 복사되었습니다." << endl;
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