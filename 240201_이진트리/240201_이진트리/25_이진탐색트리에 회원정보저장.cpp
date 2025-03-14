//25_이진탐색트리에 회원정보 저장.cpp
/*
* 배열 or 연결리스트 : Value [저장]
* 이진탐색트리       : Value [검색] -> 검색KEY : 이진탐색트리 구성 핵심
*									  pair[KEY, Value]
* 회원정보( 회원번호(KEY), 이름, 전화번호 )
*/


#include <iostream>
#include <conio.h>
using namespace std;

//회원 클래스
class Member
{
private:
	int number;		//KEY
	string name;
	string phone;
public:
	Member(int number, string name, string phone)
		:number(number), name(name), phone(phone)
	{
	}
public:
	int getNumber() const { return number;  }

public:
	void Print() const
	{
		cout << number << ", " << name << ", " << phone << endl; 
	}
};

//이진트리 노드
class treeNode
{
public:
	int key;			//number
	Member* value;		//value
	treeNode* left;
	treeNode* right;

public:
	treeNode(Member* member, treeNode* left = NULL, treeNode* right = NULL)
		:key(member->getNumber()), value(member), left(left), right(right)
	{
	}
};

//트리
class wbTree
{
private:
	treeNode* root;
	int count;

public:
	wbTree() : root(NULL), count(0)
	{
	}
	~wbTree()
	{
	}

public:
	void insert(int key, Member *value)
	{
		insert(key, value, &root);
	}

	treeNode* searchBST(int value)
	{
		treeNode* p = root;
		while (p != NULL)
		{
			if (p->key > value)  // key가 크다면
				p = p->left;
			else if (p->key == value)
				return p;
			else
				p = p->right;
		}
		printf("\n 찾는 키가 없습니다! \n");
		return p;		//NULL
	}

	int deleteNode(int key)
	{
		//1. 삭제할 노드를 찾는다.
		//   p == NULL : key가 존재하지 않는 경우
		//   p != NULL : key를 갖고 있는 노드를 찾은 경우

		treeNode* parent = NULL;	//삭제할 노드를 가리키는 부모
		treeNode* p = root;		//삭제할 노드
		while ((p != NULL) && (p->key != key))
		{
			parent = p;
			if (p->key > key) //키가 작은 경우
				p = p->left;
			else
				p = p->right;
		}
		if (p == NULL)
		{
			printf("\n 찾는 키가 이진트리에 없습니다!!");
			return 0;
		}

		//2.1 단말노드의 삭제
		//다수의 노드가 존재할 경우 or 루트노드만 있을 경우
		if ((p->left == NULL) && (p->right == NULL))
		{
			if (parent != NULL)
			{
				if (parent->left == p) parent->left = NULL;
				else parent->right = NULL;
			}
			else
				root = NULL;
		}

		//2.2 자식노드가 한 개인 노드의 삭제	
		else if ((p->left == NULL) || (p->right == NULL))
		{
			treeNode* child;

			//삭제할 노드의 자식 노드를 child에 저장
			if (p->left != NULL)
				child = p->left;
			else child = p->right;

			if (parent != NULL)
			{
				if (parent->left == p)
					parent->left = child;
				else
					parent->right = child;
			}
			else
				root = child;
		}

		// 자식노드가 두 개인 노드의 삭제
		else
		{
			treeNode* succ_parent = p;
			treeNode* succ = p->right;
			while (succ->left != NULL)
			{
				succ_parent = succ;
				succ = succ->left;
			}

			if (succ_parent->left == succ)
				succ_parent->left = succ->right;
			else succ_parent->right = succ->right;
			p->key = succ->key;

			//삭제할 노드 P
			p = succ;
		}
		free(p);
		return 1;
	}

	void printall()
	{
		if (root == NULL)
		{
			cout << "NULL" << endl;
			return;
		}
		//preorder(root);
		//printf("\n");
		inorder(root);	//오름차순
		printf("\n");
		//postorder(root);
		//printf("\n");
	}

private:
	void insert(int k, Member*value, treeNode** cur)
	{
		//연결 알고리즘
		if (*cur == NULL)  //노드가 비어있을 때
		{
			*cur = new treeNode(value);
			return;
		}
		if ((*cur)->key == k)
		{
			printf("중복키\n");
			return;
		}
		else if ((*cur)->key > k)  //KEY가 큰 경우
		{
			if ((*cur)->left == NULL)
			{
				(*cur)->left = new treeNode(value);
				return;
			}
			else
			{
				insert(k, value, &(*cur)->left);
			}
		}
		else
		{
			if ((*cur)->right == NULL)
			{
				(*cur)->right = new treeNode(value);
				return;
			}
			else
			{
				insert(k, value, &(*cur)->right);
			}
		}
	}

	void preorder(const treeNode* cur)
	{
		cur->value->Print();
		if (cur->left != NULL)
			preorder(cur->left);
		if (cur->right != NULL)
			preorder(cur->right);
	}

	void inorder(const treeNode* cur)
	{
		if (cur->left != NULL)
			inorder(cur->left);
		cur->value->Print();
		if (cur->right != NULL)
			inorder(cur->right);
	}

	void postorder(const treeNode* cur)
	{
		if (cur->left != NULL)
			postorder(cur->left);
		if (cur->right != NULL)
			postorder(cur->right);
		cur->value->Print();
	}
};


int main()
{
	char ch;
	wbTree tree;
	while (1)
	{
		system("cls");
		tree.printall();
		puts("... MENU...");
		puts("0. EXIT");
		puts("1. 이진탐색트리저장");
		puts("2. 이진탐색트리검색");
		puts("3. 이진탐색트리삭제");
		printf("choice number : [ ]\b\b");
		switch (ch = _getche())	//#include <conio.h>
		{
		case '0': return 0;
		case '1':
		{
			int number;
			char name[20];
			char phone[20];			
			cout << "\n회원번호 : "; cin >> number;
			cout << "이름 : "; cin >> name;
			cout << "전화번호 : "; cin >> phone;
			
			Member* p = new Member(number, name, phone);

			tree.insert(number, p); break;
		}
		case '2':
		{
			int key;
			scanf_s("%d", &key);
			treeNode* node = tree.searchBST(key);
			if (node == NULL)
			{
				printf("없다\n");
			}
			else
			{
				cout << "[키] : " << node->key << endl;
				cout << "[값] : ";
				node->value->Print();
			}
			break;
		}
		case '3':
		{
			int key;
			scanf_s("%d", &key);
			int ret = tree.deleteNode(key);
			if (ret == 0)
			{
				printf("없다\n");
			}
			else
			{
				printf("삭제 성공\n");
			}
		}
		break;
		}
		system("pause");
	}
	return 0;
}