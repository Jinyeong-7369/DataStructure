#include<iostream>
#include<string>
#include "listClass.h"

using namespace std;

listClass::listClass()
{
	count = 0;//count 0으로 초기화
}
listClass::~listClass()
{
	//아무런 기능도 하지 않음
}
void listClass::Insert(int position, int item)
{
	if (count == MAX)//리스트가 가득 찼다면 
	{
		cout << "리스트가 가득 찼습니다." << endl;
	}
	else if (position < 1 || position > count + 1)//1보다 작은 위치, 이격된 위치 불허 
	{
		cout << "잘못된 위치 지정입니다." << endl;
	}
	else
	{
		
		for (int i = count - 1; i >= position - 1; i--)
		{
			//데이터를 뒤로 밀어내 복사함ex)1,2,3,4->1,1,2,3,4
			data[i + 1] = data[i];
		}
		data[position - 1] = item;//원하는 위치에 데이터 삽입ex)1,1,2,3,4->0,1,2,3,4
		count++;//리스트 길이 늘임
		cout <<"리스트의 " << position << " 위치에 " << item << " 삽입 했습니다." << endl;
	}

}
void listClass::Delete(int position)
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
		for (int i = position - 1; i < count - 1; i++)
		{
			//데이터를 덮어 써서 삭제함 ex)1,2,3,4,5 -> 2,3,4,5
			data[i] = data[i + 1];
		}
		count--;//리스트 크기 감소 
		cout << "리스트의 " << position << " 위치의 데이터를 삭제 했습니다." << endl;
	}
}
void listClass::Retrieve(int position, int& item)
{
	if(IsEmpty())//리스트가 비어있으면 오류 발생
	{
		cout << "리스트가 비어 있습니다." << endl;
	}
	else if (position < 1 || position > count)//1보다 작은위치 및 count보다 큰 위치 불허 
	{
		cout << "잘못된 위치 지정입니다." << endl;
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
	return (count == 0);//빈 리스트 라면 true반환 
}
int listClass::Length()
{
	return count;//count 반환 
}
