#include<iostream>
#include<stack>
using namespace std;


typedef struct Node {
	struct Node *left;
	struct Node *right;
	char value;
}	Node;

//�����ڵ�
Node * CreateNode(char value) {
	Node * node = (Node *)malloc(sizeof(Node));
	node->value = value;
	node->left = node->right = NULL;
	return node;
}

//����������
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
//�ǵݹ�ǰ�����
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
//��������ĸ߶�
int getHeight(Node* root) {
	if (root == NULL) {
		return 0;
	}
	int left = getHeight(root->left);//�������߶�
	int right = getHeight(root->right);//�������߶�
	return getMax(left, right) + 1;//�������ܸ߶�Ϊ���������ϸ��߼Ӹ��ĸ߶�
}
//�ж��Ƿ���ƽ�������
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
	cout << "������ǰ��������£�" << endl;
	PreOrderNoR(root);
	cout << endl;
	int height = getHeight(root);
	cout << "�������ĸ߶�Ϊ��" << height << endl;
	if (isBlanceTree(root)) {
		cout << "�ö�������ƽ�������" << endl;
	}
	else {
		cout << "�ö���������ƽ�������" << endl;
	}
	system("pause");
	return 0;
}