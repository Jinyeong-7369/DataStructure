struct node
{
	int data;
	node* next;
};
typedef node* Nptr;
class listClass {
public:
	listClass();
	~listClass();//����Ʈ�� ��尡 ���������� ���� ����
	void PrintAll();//���
	void Insert(int position, int item);//������ ��ġ�� ����
	void Delete(int position);//������ ��ġ ����
	void Retrieve(int position, int& item);//������ ��ġ ������ ����
	bool IsEmpty();//����Ʈ�� ����ִ��� �˻� 
	int Length();//����Ʈ�� ũ�� ��ȯ 
private:
	int count;//����Ʈ�� ũ��
	Nptr head;
};