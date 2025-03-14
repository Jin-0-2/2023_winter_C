//24_����Ž��Ʈ��.cpp(Ŭ����ȭ)

#include <iostream>
#include <conio.h>
using namespace std;

//����Ʈ�� ���
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

//Ʈ��
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
			if (p->key > value)  // key�� ũ�ٸ�
				p = p->left;
			else if (p->key == value)
				return p;
			else
				p = p->right;
		}
		printf("\n ã�� Ű�� �����ϴ�! \n");
		return p;		//NULL
	}
	
	int deleteNode(int key)
	{
		//1. ������ ��带 ã�´�.
		//   p == NULL : key�� �������� �ʴ� ���
		//   p != NULL : key�� ���� �ִ� ��带 ã�� ���

		treeNode* parent = NULL;	//������ ��带 ����Ű�� �θ�
		treeNode* p = root;		//������ ���
		while ((p != NULL) && (p->key != key))
		{
			parent = p;
			if (p->key > key) //Ű�� ���� ���
				p = p->left;
			else
				p = p->right;
		}
		if (p == NULL)
		{
			printf("\n ã�� Ű�� ����Ʈ���� �����ϴ�!!");
			return 0;
		}

		//2.1 �ܸ������ ����
		//�ټ��� ��尡 ������ ��� or ��Ʈ��常 ���� ���
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

		//2.2 �ڽĳ�尡 �� ���� ����� ����	
		else if ((p->left == NULL) || (p->right == NULL))
		{
			treeNode* child;

			//������ ����� �ڽ� ��带 child�� ����
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

		// �ڽĳ�尡 �� ���� ����� ����
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

			//������ ��� P
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
		inorder(root);	//��������
		printf("\n");
		postorder(root);
		printf("\n");
	}

private:
	void insert(int k, treeNode** cur)
	{
		//���� �˰���
		if (*cur == NULL)  //��尡 ������� ��
		{
			*cur = new treeNode(k);
			return;
		}
		if ((*cur)->key == k)
		{
			printf("�ߺ�Ű\n");
			return;
		}
		else if ((*cur)->key > k)  //KEY�� ū ���
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
		puts("1. ����Ž��Ʈ������");
		puts("2. ����Ž��Ʈ���˻�");
		puts("3. ����Ž��Ʈ������");
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
				printf("����\n");
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
				printf("����\n");
			}
			else
			{
				printf("���� ����\n");
			}
		}
		break;
		}
		system("pause");
	}
	return 0;
}