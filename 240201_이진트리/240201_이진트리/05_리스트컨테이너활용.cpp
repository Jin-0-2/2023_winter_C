//80_템플릿클래스적용.cpp
//74_Account.cpp

#include <iostream>
using namespace std;

//1) 데이터 클래스
class Account
{
private:
	const int number;
	string name;
	int balance;

public:
	Account(int _number, string _name) : number(_number), name(_name), balance(0)
	{
	}
	Account(int _number, string _name, int _balance) : number(_number), name(_name), balance(_balance)
	{
	}
	~Account()
	{
	}

public:
	int getNumber() const { return number; }
	string getName() const { return name; }
	int getBalance() const { return balance; }

public:
	void Print() const
	{
		cout << number << "\t";
		cout << name << "\t";
		cout << balance << "원" << endl;
	}
	bool InputMoney(int money)
	{
		if (money <= 0)		//0보다 작거나 같은값 입금해줘...(오류)
			throw "잘못된 금액 전달";

		balance = balance + money;
		return true;
	}
	bool OutputMoney(int money)
	{
		if (money <= 0)			//0보다 작거나 같은값 출금해줘...(오류)
			throw "잘못된 금액 전달";

		if (balance < money)	//잔액이 부족한 상황(오류)
			throw "잔액 부족";

		balance = balance - money;
		return true;
	}
};

template <typename T>
class MyList
{
public:
	class Node
	{
	public:		//-> prive
		T data;				//<-------------------------------------------(수정)
		Node* next;
		Node* prev;

	public:
		Node(T _data) : data(_data), next(NULL), prev(NULL)//<-----------(수정)
		{
		}
	};

private:
	Node* head;  //첫 노드 저장
	Node* tail;  //마지막 노드 저장
	int   size;  //저장 개수

public:
	MyList();
	~MyList();

public:
	int getSize() const { return size; }
	T getData(Node* cur) { return cur->data; }  //<-------------------수정
	Node* getHead() { return head; }
	Node* getTail() { return tail; }

	//배열과 동일하게 사용할 수 있도록 제공
public:
	void Insert(T value)
	{
		Push_Back(value);
	}
	T getData(int idx)
	{
		Node* cur = head;
		for (int i = 0; i < idx; i++)
		{
			cur = cur->next;
		}
		return cur->data;
	}
	bool Delete(int idx)
	{
		Node* cur = head;
		for (int i = 0; i < idx; i++)
		{
			cur = cur->next;
		}
		return Delete_Random(cur);
	}
	
private:
	//insert 
	bool Push_Front(T value);					//<--------------------수정
	bool Push_Back(T value);					//<--------------------수정
	bool Push_Random(Node* cur, T value);		//<--------------------수정

private:
	//Delete
	bool Delete_Front();
	bool Delete_Back();
	bool Delete_Random(Node* del);
};

template <typename T>
MyList<T>::MyList() : head(NULL), tail(NULL), size(0)
{
}

template <typename T>
MyList<T>::~MyList()
{
}

template <typename T>
bool MyList<T>::Push_Front(T value)
{
	Node* newnode = new Node(value);
	if (newnode == NULL)
		throw "메모리 부족";//return false;

	if (head == NULL)
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
	size++;
	return true;
}

template <typename T>
bool MyList<T>::Push_Back(T value)
{
	Node* newnode = new Node(value);
	if (newnode == NULL)
		throw "메모리 부족";//return false;

	if (head == NULL)
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
	}
	size++;
	return true;
}

template <typename T>
bool MyList<T>::Push_Random(Node* cur, T value)
{
	Node* newnode = new Node(value);
	if (newnode == NULL)
		throw "메모리 부족";	//return false;

	if (cur == tail)  //꼬리노드 (push_back의 꼬리연결 코드 복사)
	{
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
	}
	else  //중간 노드
	{
		newnode->prev = cur;
		newnode->next = cur->next;
		cur->next->prev = newnode;
		cur->next = newnode;
	}
	size++;
	return true;
}

template <typename T>
bool MyList<T>::Delete_Front()
{
	if (head == NULL) //비어있다
		throw "비어있는 상태";  //  return false;

	Node* del = head; //첫번째 노드
	if (head->next == NULL) //노드가 한개
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		head = head->next;
		head->prev = NULL;
	}
	delete del;
	size--;

	return true;
}

template <typename T>
bool MyList<T>::Delete_Back()
{
	if (head == NULL) //비어있다
		throw "비어있는 상태";  //  return false;

	Node* del = tail; //마지막 노드
	if (head->next == NULL) //노드가 한개
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		tail = tail->prev;
		tail->next = NULL;
	}
	delete del;
	size--;

	return true;
}

template <typename T>
bool MyList<T>::Delete_Random(Node* del)
{
	if (del == head) //첫번째 노드
	{
		return Delete_Front();
	}
	else if (del == tail) //마지막 노드
	{
		return Delete_Back();
	}
	else //중간 노드 삭제
	{
		del->prev->next = del->next;
		del->next->prev = del->prev;
		delete del;
		size--;
	}
	return true;
}
//------------------------------------------------------------------------------------


//3) 관리 클래스
//구조 유사하지만 저장 객체가 변경되면 수정
class AccountControl
{
private:
	MyList<Account*> *accounts;				//<------------------------------(1)

public:
	AccountControl()
	{
		//Account*를 저장하는 WbArray객체를 힙에 생성했다.
		accounts = new MyList<Account*>;	//<------------------------------(2)
	}
	~AccountControl()
	{
		delete accounts;
	}

private:
	int Select_Number(int number)  //value를 검색해서 있다면 인덱스를 반환해 줘.
	{
		for (int i = 0; i < accounts->getSize(); i++)	 //max가 아니라 size까지만 순회!
		{
			Account* pacc = accounts->getData(i);
			if (pacc->getNumber() == number)					//<--------------[내부]
				return i;
		}
		throw "없다";
	}

	int Select_Name(string name)  //value를 검색해서 있다면 인덱스를 반환해 줘.
	{
		for (int i = 0; i < accounts->getSize(); i++)	 //max가 아니라 size까지만 순회!
		{
			Account* pacc = (Account*)accounts->getData(i);
			if (pacc->getName() == name)					//<--------------[내부]
				return i;
		}
		throw "없다";
	}

public:
	//계좌 생성 저장
	void con_insert()
	{
		printf("[입력(계좌 생성)]\n");

		try
		{
			int number;
			string name;
			int balance;
			cout << "계좌 번호 입력 : ";   cin >> number;
			cout << "계좌 이름 입력 : ";   cin >> name;
			cout << "입금액 입력 : ";	  cin >> balance;

			Account* pacc = new Account(number, name, balance); //힙에 보관------------------------------------------

			accounts->Insert(pacc);
			cout << "저장되었습니다." << endl;
		}
		catch (const char* err)
		{
			cout << "[저장실패] : " << err << endl;
		}
	}

	//계좌 검색(계좌번호)
	void con_select()
	{
		printf("[검색(번호)]\n");

		try
		{
			int number;
			printf("계좌번호 입력 : ");   cin >> number;

			int idx = Select_Number(number);			//(변경없음)	

			Account* pacc = (Account*)accounts->getData(idx);			//---------------------------------------
			pacc->Print();
		}
		catch (const char* err)
		{
			cout << "[검색실패] : " << err << endl;
		}
	}

	//계좌 입금 / 출금
	//객체의 저장 정부 중 일부를 변경!
	void con_update_input()
	{
		printf("[수정(계좌번호로 검색 후 입금->잔액변경)]\n");

		try
		{
			int number;
			int money;
			cout << "계좌 번호 입력 : ";		cin >> number;
			cout << "입금액 입력 : ";		cin >> money;

			int idx = Select_Number(number);			//(변경없음)	

			Account* pacc = (Account*)accounts->getData(idx);
			pacc->InputMoney(money);
			cout << "성공" << endl;
		}
		catch (const char* err)
		{
			cout << "[입금실패] : " << err << endl;
		}
	}

	void con_update_output()
	{
		printf("[수정(계좌번호로 검색 후 출금->잔액변경)]\n");

		try
		{
			int number;
			int money;
			cout << "계좌 번호 입력 : ";		cin >> number;
			cout << "출금액 입력 : ";		cin >> money;

			int idx = Select_Number(number);			//(변경없음)	

			Account* pacc = (Account*)accounts->getData(idx);
			pacc->OutputMoney(money);
			cout << "성공" << endl;
		}
		catch (const char* err)
		{
			cout << "[출금실패] : " << err << endl;
		}
	}

	void con_delete()
	{
		printf("[삭제(이름으로 검색한 후 삭제)]\n");

		try
		{
			string name;
			printf("고객 이름 입력 : ");   cin >> name;

			int idx = Select_Name(name);
			accounts->Delete(idx);
			cout << "성공" << endl;
		}
		catch (const char* err)
		{
			cout << "[삭제실패] : " << err << endl;
		}
	}

	void con_printall()
	{
		for (int i = 0; i < accounts->getSize(); i++)
		{
			Account* pacc = (Account*)accounts->getData(i);
			pacc->Print();
		}
	}
};

int main()
{
	AccountControl con;

	con.con_insert();	//10
	con.con_insert();	//20
	con.con_insert();	//30
	con.con_printall();		//3개 출력

	cout << "\n\n검색" << endl;
	con.con_select();	//30, (OK)  
	con.con_select();	//31(FAIL)

	cout << "\n\n수정" << endl;
	con.con_update_input();	//30
	con.con_printall();		//3개 출력

	con.con_update_output();	//30
	con.con_printall();		//3개 출력

	cout << "\n\n삭제" << endl;
	con.con_delete();	//30
	con.con_printall();		//3개 출력

	return 0;
}