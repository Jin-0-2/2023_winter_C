//23_이진탐색트리.cpp
#include <iostream>
#include <conio.h>
using namespace std;

//이진트리 노드
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
	//연결 알고리즘
	if (*root == NULL)  //노드가 비어있을 때
	{
		*root = createnode(k);
		return;
	}
	if ((*root)->key == k)
	{
		printf("중복키\n");
		return;
	}

	if ((*root)->key > k)  //KEY가 큰 경우
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

int deleteNode(treeNode** root, int key)
{
	//1. 삭제할 노드를 찾는다.
	//   p == NULL : key가 존재하지 않는 경우
	//   p != NULL : key를 갖고 있는 노드를 찾은 경우

	treeNode* parent = NULL;	//삭제할 노드를 가리키는 부모
	treeNode* p = *root;		//삭제할 노드
	while ((p != NULL) && (p->key != key)) 
	{
		parent = p;
		if ( p->key > key) //키가 작은 경우
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
			*root = NULL;
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
			*root = child;
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
	inorder(root);	//오름차순
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
				insert(key, &root); break;
			}
		case '2':
			{
				int key;
				scanf_s("%d", &key);
				treeNode* node = searchBST(root, key); 
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
				int ret = deleteNode(&root, key);
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