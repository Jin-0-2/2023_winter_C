//21_���ĳ���(1).cpp
#include <iostream>
#include <stack>
using namespace std;

typedef struct _tree
{
	int key;
	struct _tree* left;
	struct _tree* right;
}treeNode;

typedef struct wbtree
{
	treeNode* root;
	int count;
}wbTree;


//�������� ��� true ��ȯ
int is_operator(int k)
{
	return (k == '+' || k == '-' || k == '*' || k == '/');
}

//12  +  3 4  -  *  5  /  6  7  *  +
void make_parse_tree(wbTree *wbtree, const char* data)
{
	stack<treeNode*> stack;
	int size = 0;
	while (*data)
	{
		//���� ���ſ�
		while (*data == ' ')
			data++;							//<-------------------------

		//��� ���� �� �ʱ�ȭ
		treeNode* t = t = (treeNode*)malloc(sizeof(treeNode));
		t->key = *data;
		t->left = NULL;
		t->right = NULL;
		size++;

		//ó��
		if (is_operator(*data))
		{
			t->right = stack.top(); stack.pop();
			t->left = stack.top(); stack.pop();
		}
		stack.push(t);
		data++;							//<---------------------------
	}
	wbtree->root = stack.top();
	wbtree->count = size;
}

void preorder(treeNode* cur)
{
	printf("%3c", cur->key);
	if (cur->left != NULL)
		preorder(cur->left);
	if (cur->right != NULL)
		preorder(cur->right);
}


void inorder(treeNode* cur)
{
	if (cur->left != NULL)
		inorder(cur->left);
	printf("%3c", cur->key);
	if (cur->right != NULL)
		inorder(cur->right);
}

void inorder1(const wbTree* tree)
{
	printf("[���尳�� : %d]\n", tree->count);
	inorder(tree->root);
}


void postorder(treeNode* cur)
{
	if (cur->left != NULL)
		postorder(cur->left);
	if (cur->right != NULL)
		postorder(cur->right);
	printf("%3c", cur->key);
}

void postorder1(treeNode* cur, int count)
{
	printf("[���尳�� : %d]\n", count);
	postorder(cur);
}


int main()
{
	//  ���� ǥ��� ������ ����
	char post[256];

	wbTree wbtree = { NULL, 0 };

	while (true)
	{
		printf("\n\nInput Postfix expresstion()\n");
		printf("ex) 12  +  3 4  -  *  5  /  6  7  *  +)\n");
		gets_s(post);

		// �ƹ� �͵� �Է����� ���� ��� 
		if (*post == NULL)
		{
			printf("\nPrograme end..");
			exit(0);
		}

		make_parse_tree(&wbtree, post);

		printf("\nPreorder traverse -->\n");
		preorder(wbtree.root);	

		printf("\nInorder traverse --->\n");
		inorder1(&wbtree);

		printf("\nPoseorder traverse --->\n");
		postorder1(wbtree.root, wbtree.count);
	}

	return 0;
}