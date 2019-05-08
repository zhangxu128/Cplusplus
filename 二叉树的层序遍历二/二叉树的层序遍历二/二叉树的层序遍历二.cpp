/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
例如：
给定二叉树[3, 9, 20, null, null, 15, 7],
3
/ \
9  20
/ \
15   7
返回其自底向上的层次遍历为：
[
	[15, 7],
	[9, 20],
	[3]
]
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int> > res;
	if (!root) return res;
	TreeNode* node = NULL;
	queue <TreeNode*> que; 
	que.push(root);  //启动，将头放进队列
	while (!que.empty()) {
		int size = que.size();   //计算队列的有效长度
		vector<int> tmp;
		while (size > 0) {
			node = que.front();  //取出队列首元素
			if (node->val != 0) {
				tmp.push_back(node->val);  //放进容器中
			}
			que.pop();  //取出队列
			if (node->left) que.push(node->left);  //将左子树拉进队列
			if (node->right) que.push(node->right);  //将右子树拉进队列
			size--;
		}
		res.push_back(tmp);
	}
	reverse(res.begin(), res.end());
	return res;
}

//创建节点
TreeNode * CreateNode(char value) {
	TreeNode * node = (TreeNode *)malloc(sizeof(TreeNode));
	node->val = value;
	node->left = node->right = NULL;
	return node;
}

//创建二叉树
TreeNode * CreateTestTree() {
	TreeNode *a = CreateNode(3);
	TreeNode *b = CreateNode(9);
	TreeNode *c = CreateNode(20);
	TreeNode *d = CreateNode(0);
	TreeNode *e = CreateNode(0);
	TreeNode *f = CreateNode(15);
	TreeNode *g = CreateNode(7);

	a->left = b; a->right = c;
	b->left = f;
	b->right = g;
	c->left = d; c->right = e;

	return a;
}
int main(void) {

	int array[] = { 3,9,20,0,0,15,7 };
	int size = sizeof(array) / sizeof(int);
	vector<int> v(array, array + size);
	TreeNode* root = CreateTestTree();
	vector<vector<int>> ret = levelOrderBottom(root);
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}