//23_����Ž��Ʈ��.cpp
#include <iostream>
#include <conio.h>
using namespace std;

//����Ʈ�� ���
typedef struct _tree
{
	int key;
	struct _tree* left;
	struct _tree* right;
}treeNode;

treeNode* createnode(int k)
{
	treeNode* new1 = (treeNode*)malloc(sizeof(treeNode));
	new1->key = k;
	new1->left = NULL;
	new1->right = NULL;
	return new1;
}

void insert(int k, treeNode** root)
{
	//���� �˰���
	if (*root == NULL)  //��尡 ������� ��
	{
		*root = createnode(k);
		return;
	}
	if ((*root)->key == k)
	{
		printf("�ߺ�Ű\n");
		return;
	}

	if ((*root)->key > k)  //KEY�� ū ���
	{
		if ((*root)->left == NULL)
		{
			(*root)->left = createnode(k);
			return;
		}
		else
		{
			insert(k, &(*root)->left);
		}
	}
	else
	{
		if ((*root)->right == NULL)
		{
			(*root)->right = createnode(k);
			return;
		}
		else
		{
			insert(k, &(*root)->right);
		}
	}
}

treeNode* searchBST(treeNode* p, int value)
{
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

int deleteNode(treeNode** root, int key)
{
	//1. ������ ��带 ã�´�.
	//   p == NULL : key�� �������� �ʴ� ���
	//   p != NULL : key�� ���� �ִ� ��带 ã�� ���

	treeNode* parent = NULL;	//������ ��带 ����Ű�� �θ�
	treeNode* p = *root;		//������ ���
	while ((p != NULL) && (p->key != key)) 
	{
		parent = p;
		if ( p->key > key) //Ű�� ���� ���
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
			*root = NULL;
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
			*root = child;
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

void printall(const treeNode* root)
{
	if (root == NULL)
		return;
	preorder(root); 
	printf("\n");
	inorder(root);	//��������
	printf("\n");
	postorder(root);
	printf("\n");
}

int main()
{
	char ch;	
	treeNode* root = NULL;
	while (1)
	{
		system("cls");
		printall(root);
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
				insert(key, &root); break;
			}
		case '2':
			{
				int key;
				scanf_s("%d", &key);
				treeNode* node = searchBST(root, key); 
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
				int ret = deleteNode(&root, key);
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