#pragma once
#include<iostream>
const int MAX = 5;//리스트의 최대 크기, 테스트를 용이하게 하기 위해 작은 사이즈 설정 

class listClass {
public:
	listClass();
	~listClass();
	void PrintAll();//출력
	void Insert(int position, int item);//지정한 위치에 삽입
	void Delete(int position);//지정한 위치 삭제
	void Retrieve(int position, int& item);//지정한 위치 데이터 복사
	bool IsEmpty();//리스트가 비어있는지 검사 
	int Length();//리스트의 크기 반환 
private:
	int option;
	int count;//리스트의 크기
	int data[MAX];//데이터 저장 배열 
};