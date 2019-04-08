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

int getMax(int a, int b) {
	return a > b ? a : b;
}
//求二叉树的高度
int getHeight(Node* root) {
	if (root == NULL) {
		return 0;
	}
	int left = getHeight(root->left);//左子树高度
	int right = getHeight(root->right);//右子树高度
	return getMax(left, right) + 1;//二叉树总高度为左右子树较高者加根的高度
}
//判断是否是平衡二叉树
bool isBlanceTree(Node* root) {
	if (root == NULL) {
		return true;
	}
	if (abs(getHeight(root->left) - getHeight(root->right)) > 1) {
		return false;
	}
	if (isBlanceTree(root->left) && isBlanceTree(root->right)) {
		return true;
	}
	return false;
}

int main()
{
	Node* root = CreateTestTree();
	cout << "二叉树前序遍历如下：" << endl;
	PreOrderNoR(root);
	cout << endl;
	int height = getHeight(root);
	cout << "二叉树的高度为：" << height << endl;
	if (isBlanceTree(root)) {
		cout << "该二叉树是平衡二叉树" << endl;
	}
	else {
		cout << "该二叉树不是平衡二叉树" << endl;
	}
	system("pause");
	return 0;
}