#pragma once
#include<iostream>
const int MAX = 5;//����Ʈ�� �ִ� ũ��, �׽�Ʈ�� �����ϰ� �ϱ� ���� ���� ������ ���� 

class listClass {
public:
	listClass();
	~listClass();
	void PrintAll();//���
	void Insert(int position, int item);//������ ��ġ�� ����
	void Delete(int position);//������ ��ġ ����
	void Retrieve(int position, int& item);//������ ��ġ ������ ����
	bool IsEmpty();//����Ʈ�� ����ִ��� �˻� 
	int Length();//����Ʈ�� ũ�� ��ȯ 
private:
	int option;
	int count;//����Ʈ�� ũ��
	int data[MAX];//������ ���� �迭 
};