//20_���ĳ���.cpp
#include <iostream>
#include <stack>
using namespace std;


typedef struct _tree
{
	int key;
	struct _tree* left;
	struct _tree* right;
}treeNode;


//�������� ��� true ��ȯ
int is_operator(int k)
{
	return (k == '+' || k == '-' || k == '*' || k == '/');
}

//12  +  3 4  -  *  5  /  6  7  *  +
treeNode* make_parse_tree(const char* data)
{
	stack<treeNode*> stack;

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

		//ó��
		if (is_operator(*data))
		{
			t->right = stack.top(); stack.pop();
			t->left  = stack.top(); stack.pop();
		}
		stack.push(t);
		data++;							//<---------------------------
	}
	return stack.top();
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

void postorder(treeNode* cur)
{
	if (cur->left != NULL)
		postorder(cur->left);
	if (cur->right != NULL)
		postorder(cur->right);
	printf("%3c", cur->key);
}

int main()
{
	//  ���� ǥ��� ������ ����
	char post[256];
	treeNode* root = NULL;

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

		root = make_parse_tree(post);

		printf("\nPreorder traverse -->\n");
		preorder(root);

		printf("\nInorder traverse --->\n");
		inorder(root);

		printf("\nPoseorder traverse --->\n");
		postorder(root);
	}

	return 0;
}