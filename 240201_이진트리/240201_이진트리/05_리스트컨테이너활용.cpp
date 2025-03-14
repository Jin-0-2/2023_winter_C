//80_���ø�Ŭ��������.cpp
//74_Account.cpp

#include <iostream>
using namespace std;

//1) ������ Ŭ����
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
		cout << balance << "��" << endl;
	}
	bool InputMoney(int money)
	{
		if (money <= 0)		//0���� �۰ų� ������ �Ա�����...(����)
			throw "�߸��� �ݾ� ����";

		balance = balance + money;
		return true;
	}
	bool OutputMoney(int money)
	{
		if (money <= 0)			//0���� �۰ų� ������ �������...(����)
			throw "�߸��� �ݾ� ����";

		if (balance < money)	//�ܾ��� ������ ��Ȳ(����)
			throw "�ܾ� ����";

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
		T data;				//<-------------------------------------------(����)
		Node* next;
		Node* prev;

	public:
		Node(T _data) : data(_data), next(NULL), prev(NULL)//<-----------(����)
		{
		}
	};

private:
	Node* head;  //ù ��� ����
	Node* tail;  //������ ��� ����
	int   size;  //���� ����

public:
	MyList();
	~MyList();

public:
	int getSize() const { return size; }
	T getData(Node* cur) { return cur->data; }  //<-------------------����
	Node* getHead() { return head; }
	Node* getTail() { return tail; }

	//�迭�� �����ϰ� ����� �� �ֵ��� ����
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
	bool Push_Front(T value);					//<--------------------����
	bool Push_Back(T value);					//<--------------------����
	bool Push_Random(Node* cur, T value);		//<--------------------����

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
		throw "�޸� ����";//return false;

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
		throw "�޸� ����";//return false;

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
		throw "�޸� ����";	//return false;

	if (cur == tail)  //������� (push_back�� �������� �ڵ� ����)
	{
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
	}
	else  //�߰� ���
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
	if (head == NULL) //����ִ�
		throw "����ִ� ����";  //  return false;

	Node* del = head; //ù��° ���
	if (head->next == NULL) //��尡 �Ѱ�
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
	if (head == NULL) //����ִ�
		throw "����ִ� ����";  //  return false;

	Node* del = tail; //������ ���
	if (head->next == NULL) //��尡 �Ѱ�
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
	if (del == head) //ù��° ���
	{
		return Delete_Front();
	}
	else if (del == tail) //������ ���
	{
		return Delete_Back();
	}
	else //�߰� ��� ����
	{
		del->prev->next = del->next;
		del->next->prev = del->prev;
		delete del;
		size--;
	}
	return true;
}
//------------------------------------------------------------------------------------


//3) ���� Ŭ����
//���� ���������� ���� ��ü�� ����Ǹ� ����
class AccountControl
{
private:
	MyList<Account*> *accounts;				//<------------------------------(1)

public:
	AccountControl()
	{
		//Account*�� �����ϴ� WbArray��ü�� ���� �����ߴ�.
		accounts = new MyList<Account*>;	//<------------------------------(2)
	}
	~AccountControl()
	{
		delete accounts;
	}

private:
	int Select_Number(int number)  //value�� �˻��ؼ� �ִٸ� �ε����� ��ȯ�� ��.
	{
		for (int i = 0; i < accounts->getSize(); i++)	 //max�� �ƴ϶� size������ ��ȸ!
		{
			Account* pacc = accounts->getData(i);
			if (pacc->getNumber() == number)					//<--------------[����]
				return i;
		}
		throw "����";
	}

	int Select_Name(string name)  //value�� �˻��ؼ� �ִٸ� �ε����� ��ȯ�� ��.
	{
		for (int i = 0; i < accounts->getSize(); i++)	 //max�� �ƴ϶� size������ ��ȸ!
		{
			Account* pacc = (Account*)accounts->getData(i);
			if (pacc->getName() == name)					//<--------------[����]
				return i;
		}
		throw "����";
	}

public:
	//���� ���� ����
	void con_insert()
	{
		printf("[�Է�(���� ����)]\n");

		try
		{
			int number;
			string name;
			int balance;
			cout << "���� ��ȣ �Է� : ";   cin >> number;
			cout << "���� �̸� �Է� : ";   cin >> name;
			cout << "�Աݾ� �Է� : ";	  cin >> balance;

			Account* pacc = new Account(number, name, balance); //���� ����------------------------------------------

			accounts->Insert(pacc);
			cout << "����Ǿ����ϴ�." << endl;
		}
		catch (const char* err)
		{
			cout << "[�������] : " << err << endl;
		}
	}

	//���� �˻�(���¹�ȣ)
	void con_select()
	{
		printf("[�˻�(��ȣ)]\n");

		try
		{
			int number;
			printf("���¹�ȣ �Է� : ");   cin >> number;

			int idx = Select_Number(number);			//(�������)	

			Account* pacc = (Account*)accounts->getData(idx);			//---------------------------------------
			pacc->Print();
		}
		catch (const char* err)
		{
			cout << "[�˻�����] : " << err << endl;
		}
	}

	//���� �Ա� / ���
	//��ü�� ���� ���� �� �Ϻθ� ����!
	void con_update_input()
	{
		printf("[����(���¹�ȣ�� �˻� �� �Ա�->�ܾ׺���)]\n");

		try
		{
			int number;
			int money;
			cout << "���� ��ȣ �Է� : ";		cin >> number;
			cout << "�Աݾ� �Է� : ";		cin >> money;

			int idx = Select_Number(number);			//(�������)	

			Account* pacc = (Account*)accounts->getData(idx);
			pacc->InputMoney(money);
			cout << "����" << endl;
		}
		catch (const char* err)
		{
			cout << "[�Աݽ���] : " << err << endl;
		}
	}

	void con_update_output()
	{
		printf("[����(���¹�ȣ�� �˻� �� ���->�ܾ׺���)]\n");

		try
		{
			int number;
			int money;
			cout << "���� ��ȣ �Է� : ";		cin >> number;
			cout << "��ݾ� �Է� : ";		cin >> money;

			int idx = Select_Number(number);			//(�������)	

			Account* pacc = (Account*)accounts->getData(idx);
			pacc->OutputMoney(money);
			cout << "����" << endl;
		}
		catch (const char* err)
		{
			cout << "[��ݽ���] : " << err << endl;
		}
	}

	void con_delete()
	{
		printf("[����(�̸����� �˻��� �� ����)]\n");

		try
		{
			string name;
			printf("�� �̸� �Է� : ");   cin >> name;

			int idx = Select_Name(name);
			accounts->Delete(idx);
			cout << "����" << endl;
		}
		catch (const char* err)
		{
			cout << "[��������] : " << err << endl;
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
	con.con_printall();		//3�� ���

	cout << "\n\n�˻�" << endl;
	con.con_select();	//30, (OK)  
	con.con_select();	//31(FAIL)

	cout << "\n\n����" << endl;
	con.con_update_input();	//30
	con.con_printall();		//3�� ���

	con.con_update_output();	//30
	con.con_printall();		//3�� ���

	cout << "\n\n����" << endl;
	con.con_delete();	//30
	con.con_printall();		//3�� ���

	return 0;
}