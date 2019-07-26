//ʵ�ּ��װ�Ķ���������
//  ����  ����   ɾ��

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

	//����
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

	//����
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


	//ɾ��
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
			else {  //�ҵ�
				//û�к��ӣ�ֻ��һ�����ӣ��������Ӷ���
				Node* del = cur;
				//ֻ���Һ���
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
				//ֻ������
				else if (cur->right == nullptr) {
					if (parent->left == cur) {
						parent->left = cur->left;
					}
					else {
						parent->right = cur->left;
					}
				}
				//���Һ��Ӷ���
				else {
					Node* reparent = cur;
					Node* replace = cur->right;
					while (replace->left) { //����������������ڵ�
						reparent = replace;
						replace = replace->left;
					}

					cur->_kv = replace->_kv; //�滻�ڵ�ֵ

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

	//�������
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