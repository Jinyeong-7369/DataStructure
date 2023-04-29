#include<iostream>
using namespace std;

#include"listClass.h"

int main(void)
{
	listClass list;//리스트 생성
	int n = 0;
	//Insert
	list.Insert(-1, 0);//1보다 작은 위치 삽입 오류
	list.Insert(1, 3);//첫 번째 위치 삽입(count : 1)
	list.Insert(2, 5);//두 번째 위치 삽입(count : 2)
	list.Insert(3, 6);//세 번째 위치 삽입(count : 3)
	list.Insert(5, 9);//이격된 위치 삽입 오류
	list.Insert(1, 4);//첫 번째 위치 삽입(count : 4)
	list.Insert(5, 2);//다섯번째 위치 삽입(count : 5)
	list.Insert(3, 3);//리스트가 가득 찼을 시 삽입 오류
	//Retrieve
	for (int i = 1; i < list.Length() + 1; i++)
	{//반복문으로 처음 인덱스 부터 마지막 인덱스까지 복사하고 출력하기 
		list.Retrieve(i, n);
		cout << "n : " << n << endl;
	}

	//Delete 및 Retrieve
	list.Delete(1);//첫 번째 위치 삭제(count : 4)
	list.Retrieve(5, n);//비어있는 리스트 지정시 오류 
	list.Delete(4);//마지막 위치 삭제(count : 3)
	list.Delete(2);//두 번째 위치 삭제(count : 2)
	list.Delete(1);//첫 번째 위치 삭제(count : 1)
	list.Delete(2);//비어있는 위치 지정시 오류
	list.Delete(1);//첫 번째 위치 삭제(count : 0)
	list.Retrieve(1, n);//비어있는 리스트 지정시 오류 

	//Insert 및 소멸자 함수
	list.Insert(1, 3);//첫 번째 위치 삽입(count : 1)
	list.Insert(2, 5);//두 번째 위치 삽입(count : 2)
	list.Insert(3, 6);//세 번째 위치 삽입(count : 3)
	list.Insert(1, 4);//첫 번째 위치 삽입(count : 4)
	list.Insert(5, 2);//다섯번째 위치 삽입(count : 5)
}