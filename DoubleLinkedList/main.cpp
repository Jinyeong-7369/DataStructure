#include"listClass.h"
using namespace std;
#include<string>

#include<string>

void showOption()
{
	string option[7] = { "����", "����", "���", "�˻�", "����ִ��� �˻�", "���� ���", "����" };
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
		cout << "���ϴ� ��� ���� >>";
		int sel;
		cin >> sel;
		switch (sel)
		{
		case 1:
			cout << "������ �����Ϳ� ��ġ�� �Է��� �ּ��� >>";
			cin >> item >> position;
			list.Insert(position, item);
			continue;
			break;
		case 2:
			cout << "������ ��ġ�� �Է��� �ּ��� >> ";
			cin >> position;
			list.Delete(position);
			break;
		case 3:
			list.PrintAll();
			break;
		case 4:
			cout << "�˻��� ��ġ�� �Է��� �ּ��� >> ";
			cin >> position;
			list.Retrieve(position, item);
			cout << "position��ġ�� �ִ� ���� " << item << "�Դϴ�." << endl;
			break;
		case 5:
			cout << "����Ʈ�� ";
			if (list.IsEmpty()) cout << "����ֽ��ϴ�." << endl;
			else cout << "������� �ʽ��ϴ�." << endl;
			break;
		case 6:
			cout << "����Ʈ�� ���̴� " << list.Length() << "�Դϴ�." << endl;
			break;
		case 7:
			cout << "���α׷��� �����մϴ�" << endl;
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
	}


}