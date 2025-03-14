//21_���ĳ���(1).cpp
#include <iostream>
#include <stack>
using namespace std;

class treeNode
{
private:
	int key;
	treeNode* left;
	treeNode* right;
public:
	treeNode(int _key, treeNode* left = NULL, treeNode* right = NULL)
		:key(_key), left(left), right(right)
	{
	}

public:
	void setLeft(treeNode* value)	{ left = value; }
	void setRight(treeNode* value)	{ right = value; }

	int getKey()			const { return key; }
	treeNode* getLeft()		const { return left;  }
	treeNode* getRight()	const { return right; }
};

class wbTree
{
private:
	treeNode* root;
	int count;

public:
	wbTree():root(NULL), count(0)
	{
	}

public:
	void setRoot(treeNode* value)	{ root = value;  }
	void setCount(int value)		{ count = value; }
	treeNode* getRoot() const		{ return root;  }
	int getCount() const			{ return count;  }

private:
	//�������� ��� true ��ȯ
	int is_operator(int k)
	{
		return (k == '+' || k == '-' || k == '*' || k == '/');
	}

public:
	//12  +  3 4  -  *  5  /  6  7  *  +
	void make_parse_tree(const char* data)
	{
		stack<treeNode*> stack;
		int size = 0;
		while (*data)
		{
			//���� ���ſ�
			while (*data == ' ')
				data++;							//<-------------------------

			//��� ���� �� �ʱ�ȭ
			treeNode* t = new treeNode(*data);	
			size++;

			//ó��
			if (is_operator(*data))
			{
				t->setRight(stack.top());	stack.pop();
				t->setLeft(stack.top());	stack.pop();
			}
			stack.push(t);
			data++;							//<---------------------------
		}
		setRoot(stack.top());
		setCount(size);
	}

	//��ȸ
	void preorder(treeNode* cur)
	{
		printf("%3c", cur->getKey());
		if (cur->getLeft() != NULL)
			preorder(cur->getLeft());
		if (cur->getRight() != NULL)
			preorder(cur->getRight());
	}

private:
	void inorder(treeNode* cur)
	{		
		if (cur->getLeft() != NULL)
			inorder(cur->getLeft());
		printf("%3c", cur->getKey());
		if (cur->getRight() != NULL)
			inorder(cur->getRight());
	}
	
	void postorder(treeNode* cur)
	{
		if (cur->getLeft() != NULL)
			postorder(cur->getLeft());
		if (cur->getRight() != NULL)
			postorder(cur->getRight());
		printf("%3c", cur->getKey());
	}

public:
	void inorder()
	{
		printf("[���尳�� : %d]\n", count);
		inorder(root);
	}
	
	void postorder(treeNode*cur, int count)
	{
		printf("[���尳�� : %d]\n", count);
		postorder(cur);
	}
};

int main()
{
	//  ���� ǥ��� ������ ����
	char post[256];

	wbTree wbtree;

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

		wbtree.make_parse_tree(post);

		printf("\nPreorder traverse -->\n");
		wbtree.preorder(wbtree.getRoot());

		printf("\nInorder traverse --->\n");
		wbtree.inorder();

		printf("\nPoseorder traverse --->\n");
		wbtree.postorder(wbtree.getRoot(), wbtree.getCount());
	}

	return 0;
}