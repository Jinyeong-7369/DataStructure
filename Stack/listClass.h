struct node
{
	int data;
	node* next;
};
typedef node* Nptr;
class listClass {
public:
	listClass();
	~listClass();//리스트에 노드가 남아있으면 전부 삭제
	void PrintAll();//출력
	void Insert(int position, int item);//지정한 위치에 삽입
	void Delete(int position);//지정한 위치 삭제
	void Retrieve(int position, int& item);//지정한 위치 데이터 복사
	bool IsEmpty();//리스트가 비어있는지 검사 
	int Length();//리스트의 크기 반환 
private:
	int count;//리스트의 크기
	Nptr head;
};