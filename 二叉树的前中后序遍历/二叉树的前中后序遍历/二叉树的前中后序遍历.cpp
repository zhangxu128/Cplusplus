#include<iostream>
#include<stack>
using namespace std;


typedef struct Node {
	struct Node *left;
	struct Node *right;
	char value;
}	Node;

//创建节点
Node * CreateNode(char value) {
	Node * node = (Node *)malloc(sizeof(Node));
	node->value = value;
	node->left = node->right = NULL;
	return node;
}

//创建二叉树
Node * CreateTestTree() {
	Node *a = CreateNode('A');
	Node *b = CreateNode('B');
	Node *c = CreateNode('C');
	Node *d = CreateNode('D');
	Node *e = CreateNode('E');
	Node *f = CreateNode('F');
	Node *g = CreateNode('G');
	Node *h = CreateNode('H');

	a->left = b; a->right = c;
	b->left = d;
	b->right = e;
	c->left = f; c->right = g;
	e->right = h;

	return a;
}
//非递归前序遍历
void PreOrderNoR(Node *root) {
	std::stack<Node *> s;
	Node *cur = root;

	while (cur != NULL || !s.empty()) {
		while (cur != NULL) {
			printf("%c ", cur->value);
			s.push(cur);
			cur = cur->left;
		}

		Node *top = s.top();
		s.pop();

		cur = top->right;
	}
}

//非递归中序遍历
void InOrderNoR(Node *root) {
	std::stack<Node *> s;
	Node *cur = root;

	while (cur != NULL || !s.empty()) {
		while (cur != NULL) {
			s.push(cur);
			cur = cur->left;
		}

		Node *top = s.top();
		s.pop();
		printf("%c ", top->value);

		cur = top->right;
	}
}


//非递归后序遍历
void PostOrderNoR(Node *root) {
	stack<Node *> s;
	Node *cur = root;
	Node *last = NULL;		// 上一个被完整后序遍历过的树的根结点

	while (cur != NULL || !s.empty()) {
		while (cur != NULL) {
			s.push(cur);
			cur = cur->left;
		}

		Node *top = s.top();
		if (top->right == NULL) {
			printf("%c ", top->value);
			s.pop();
			last = top;
		}
		else if (top->right == last) {
			printf("%c ", top->value);
			s.pop();
			last = top;
		}
		else {
			cur = top->right;
		}
	}
}


int main()
{
	Node* root = CreateTestTree();
	PreOrderNoR(root);
	cout << endl;
	InOrderNoR(root);
	cout << endl;
	PostOrderNoR(root);
	cout << endl;
	system("pause");
	return 0;
}