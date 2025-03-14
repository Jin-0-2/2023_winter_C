//19_이진트리순회.cpp
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef struct treeNode
{
	char data;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

// 1. 노드의 생성 및 연결
treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode)
{
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

//------------- 전위 순회(Pre)------------------------------------------------
void preorder_traverse(treeNode* t) 
{
	if (t != NULL) 
	{
		cout << t->data << " ";               // 실제 작업하는 부분
		preorder_traverse(t->left);    // 재귀 1
		preorder_traverse(t->right);  // 재귀 2
	}
}

/* 전위 표기법 비재귀 함수------------------------------------------------------------------
전위순위에서 뿌리를 방문하면 오른쪽 자식 노드와 왼쪽 자식
노드를 차례로 스택에 푸쉬
다음에 방문할 노드는 스택에서 팝한 노드가 된다.
스택의 내용이 완전히 비게 되면 순회 완료
------------------------------------------------------------------------------------------*/
void non_recursive_preorder_traverse(treeNode* t)
{
	stack<treeNode*> stack;
	stack.push(t);
	
	treeNode* cur = t;
	while ( stack.empty() == false ) 
	{
		cur = stack.top();	 
		stack.pop();
		if (cur != NULL) 
		{
			cout << cur->data << " ";	//전위.(먼저 접근)
			stack.push(cur->right);		// 재귀 2  인자 스택이기에 나중에 수행할 right를 먼저 넣는다.
			stack.push(cur->left);		// 재귀 1  인자
		}
	}
}

//------------ 중위 순회(In)---------------------------------------------------
// 중위 표기법
void inorder_traverse(treeNode* t) 
{
	if (t != NULL) {
		inorder_traverse(t->left);     // 재귀 1
		cout << t->data << " ";                                // 실제 작업하는 부분
		inorder_traverse(t->right);  // 재귀 2
	}
}

// 중위 표기법을 비재귀 함수로
void non_recursive_inorder_traverse(treeNode* t) 
{
	stack<treeNode*> stack;

	treeNode* cur = t;
	while (true) 
	{
		//1. 루트 노드의 왼쪽 자식들을 순서대로 stack PUSH
		while (cur != NULL)
		{
			stack.push(cur);             // 재귀 1 스택에 push
			cur = cur->left;
		}

		//2. statck POP
		if ( stack.empty() == false)
		{
			cur = stack.top();  stack.pop();
			cout << cur->data << " ";               // 실제 작업하는 부분
			cur = cur->right;						// 재귀 2   인자 변경
		}
		else 
		{
			break;
		}
	}
}

//------------ 후위 순회(Post)---------------------------------------------------
void postorder_traverse(treeNode* t) 
{
	if (t != NULL)
	{
		postorder_traverse(t->left);       // 재귀 1
		postorder_traverse(t->right);    // 재귀 2
		cout << t->data << " ";                                     // 실제 작업하는 부분
	}
}

// 후위표기법 비재귀 함수로 변환
void non_recursive_postorder_traverse(treeNode* t) 
{
	stack<treeNode*> stack;

	treeNode* s;
	while (true) 
	{
		//왼쪽 자식들 PUSH
		while (t != NULL) 
		{    
			stack.push(t);
			t = t->left;             //  재귀 1 인자리스트 푸쉬
		}

		while (stack.empty() == false)
		{
			s = t;        // 인자리스트 복사
			t = stack.top();  stack.pop();

			//자신을 스택에 PUSH
			//자신의 오른쪽 자식을 PUSH -> 왼쪽자식들을 PUSH
			if (t->right != NULL) 
			{
				if (t->right == s) 
				{
					cout << t->data << " ";           // 실제 작업하는 부분					
				}
				else 
				{
					stack.push(t);
					t = t->right;       // 재귀 2 인자리스트
					break;
				}
			}
			else 
			{
				cout << t->data << " ";            // 실제 작업하는 부분
			}

			if (stack.empty() == true)
			{
				return;// done = 1;
			}
		}
	}
}

//------------ 층별순회(level)--------------------------------------------------
void levelorder_traverse(treeNode* t)
{
	queue<treeNode*> queue;

	queue.push(t);

	while (queue.empty() == false)
	{
		t = queue.front();  queue.pop();
		cout << t->data << " ";
		if (t->left != NULL)
			queue.push(t->left);
		if (t->right != NULL)
			queue.push(t->right);
	}
}

int main()
{
	treeNode* n7 = makeRootNode('D', NULL, NULL);
	treeNode* n6 = makeRootNode('C', NULL, NULL);
	treeNode* n5 = makeRootNode('B', NULL, NULL);
	treeNode* n4 = makeRootNode('A', NULL, NULL);
	treeNode* n3 = makeRootNode('/', n6, n7);
	treeNode* n2 = makeRootNode('*', n4, n5);
	treeNode* n1 = makeRootNode('-', n2, n3);

	//순회 확인
	preorder_traverse(n1);					//- * A B / C D
	cout << endl;
	non_recursive_preorder_traverse(n1);	//- * A B / C D
	cout << endl; 

	inorder_traverse(n1);	//A * B – C / D
	cout << endl;
	non_recursive_inorder_traverse(n1);
	cout << endl; 

	postorder_traverse(n1);	//A * B – C / D
	cout << endl;
	non_recursive_postorder_traverse(n1);
	cout << endl;

	//층별순회
	levelorder_traverse(n1);

	return 0;
}