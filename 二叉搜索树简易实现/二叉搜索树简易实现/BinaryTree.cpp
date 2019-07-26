//实现简易版的二叉搜索树
//  插入  查找   删除

#include <iostream>

using namespace std;

template <class k,class v>
class BSTreeNode {
public:
	BSTreeNode(const pair<k, v> kv)
		:_kv(kv)
		, left(nullptr)
		, right(nullptr)
	{}
public:
	pair<k, v> _kv;
	BSTreeNode<k, v>* left;
	BSTreeNode<k, v>* right;
};

template<class k,class v>
class BSTree {
public:
	typedef BSTreeNode<k,v> Node;

	BSTree()
		:_root(nullptr)
	{}

	//插入
	bool Insert(const pair<k, v> kv) {
		if (_root == nullptr) {
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;

		while (cur) {
			if (cur->_kv.first < kv.first) {
				parent = cur;
				cur = cur->right;
			}
			else if (cur->_kv.first > kv.first) {
				parent = cur;
				cur = cur->left;
			}
			else {
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first) {
			parent->right = cur;
		}
		else {
			parent->left = cur;
		}
		return true;
	}

	//查找
	Node* Find(const k& key) {
		Node* cur = _root;
		while (cur) {
			if (cur->_kv.first < key) {
				cur = cur->left;
			}
			else if(cur->_kv.first > key){
				cur = cur->right;
			}
			else{
				return cur;
			}
		}
		return nullptr;
	}


	//删除
	bool Remove(const k& key) {
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			if (cur->_kv.first < key) {
				parent = cur;
				cur = cur->right;
			}
			else if(cur->_kv.first > key){
				parent = cur;
				cur = cur->left;
			}
			else {  //找到
				//没有孩子，只有一个孩子，两个孩子都有
				Node* del = cur;
				//只有右孩子
				if (cur->left == nullptr) {
					if (parent == nullptr) {
						_root = cur->right;
					}
					else{
						if (parent->left == cur) {
							parent->left = cur->right;
						}
						else {
							parent->right = cur->right;
						}
					}
				}
				//只有左孩子
				else if (cur->right == nullptr) {
					if (parent->left == cur) {
						parent->left = cur->left;
					}
					else {
						parent->right = cur->left;
					}
				}
				//左右孩子都有
				else {
					Node* reparent = cur;
					Node* replace = cur->right;
					while (replace->left) { //在右子树中找最左节点
						reparent = replace;
						replace = replace->left;
					}

					cur->_kv = replace->_kv; //替换节点值

					del = replace;

					if (reparent->left == replace) {
						reparent->left = replace->right;
					}
					else {
						reparent->right = replace->right;
					}

				}
				delete del;
				return true;
			}
		}
		return false;
	}

	//中序遍历
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->left);
		cout << root->_kv.first << " ";
		_InOrder(root->right);
	}

private:
	Node* _root;
};

void TestBSTree1()
{
	BSTree<int, int> tree;
	tree.Insert(make_pair(1, 1));
	tree.Insert(make_pair(3, 1));
	tree.Insert(make_pair(4, 1));
	tree.Insert(make_pair(6, 1));
	tree.Insert(make_pair(1, 1));
	tree.Insert(make_pair(2, 1));
	tree.InOrder();

	tree.Remove(1);
	tree.Remove(3);
	tree.Remove(2);
	tree.Remove(6);
	tree.Remove(4);
	tree.Remove(1);
	tree.Remove(10);
	tree.InOrder();

}

int main(void) {

	TestBSTree1();
	system("pause");
	return 0;
}