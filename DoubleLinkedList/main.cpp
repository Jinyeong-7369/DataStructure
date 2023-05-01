#include"listClass.h"
using namespace std;
#include<string>

#include<string>

void showOption()
{
	string option[7] = { "삽입", "삭제", "출력", "검색", "비어있는지 검사", "길이 출력", "종료" };
	cout << "======================================================================" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << i + 1 << ". " + option[i] << endl << endl;
	}
	cout << "======================================================================" << endl;
}




int main(void)
{
	listClass list;
	showOption();
	int position = 0;
	int item = 0;
	while (1)
	{
		cout << "원하는 기능 선택 >>";
		int sel;
		cin >> sel;
		switch (sel)
		{
		case 1:
			cout << "삽입할 데이터와 위치를 입력해 주세요 >>";
			cin >> item >> position;
			list.Insert(position, item);
			continue;
			break;
		case 2:
			cout << "삭제할 위치를 입력해 주세요 >> ";
			cin >> position;
			list.Delete(position);
			break;
		case 3:
			list.PrintAll();
			break;
		case 4:
			cout << "검색할 위치를 입력해 주세요 >> ";
			cin >> position;
			list.Retrieve(position, item);
			cout << "position위치에 있는 값은 " << item << "입니다." << endl;
			break;
		case 5:
			cout << "리스트는 ";
			if (list.IsEmpty()) cout << "비어있습니다." << endl;
			else cout << "비어있지 않습니다." << endl;
			break;
		case 6:
			cout << "리스트의 길이는 " << list.Length() << "입니다." << endl;
			break;
		case 7:
			cout << "프로그램을 종료합니다" << endl;
			return 0;
		default:
			cout << "잘못된 입력입니다." << endl;
		}
	}


}