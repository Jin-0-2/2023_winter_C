//24_이진탐색트리.cpp(클래스화)

#include <iostream>
#include <conio.h>
using namespace std;

//이진트리 노드
class treeNode
{
public:
	int key;
	treeNode* left;
	treeNode* right;

public:
	treeNode(int key, treeNode* left = NULL, treeNode* right = NULL)
		:key(key), left(left), right(right)
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
	void insert(int k)
	{
		insert(k, &root);
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
		preorder(root);
		printf("\n");
		inorder(root);	//오름차순
		printf("\n");
		postorder(root);
		printf("\n");
	}

private:
	void insert(int k, treeNode** cur)
	{
		//연결 알고리즘
		if (*cur == NULL)  //노드가 비어있을 때
		{
			*cur = new treeNode(k);
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
				(*cur)->left = new treeNode(k);
				return;
			}
			else
			{
				insert(k, &(*cur)->left);
			}
		}
		else
		{
			if ((*cur)->right == NULL)
			{
				(*cur)->right = new treeNode(k);
				return;
			}
			else
			{
				insert(k, &(*cur)->right);
			}
		}
	}

	void preorder(const treeNode* cur)
	{
		printf("%d ", cur->key);
		if (cur->left != NULL)
			preorder(cur->left);
		if (cur->right != NULL)
			preorder(cur->right);
	}

	void inorder(const treeNode* cur)
	{
		if (cur->left != NULL)
			inorder(cur->left);
		printf("%d ", cur->key);
		if (cur->right != NULL)
			inorder(cur->right);
	}

	void postorder(const treeNode* cur)
	{
		if (cur->left != NULL)
			postorder(cur->left);
		if (cur->right != NULL)
			postorder(cur->right);
		printf("%d ", cur->key);
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
			int key;
			scanf_s("%d", &key);
			tree.insert(key); break;
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
				printf("%d\n", node->key);
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