#pragma ones
#include <iostream>
#include <string>
using namespace std;

template<class T> class BtreeNode;
template<class T> class BinaryTree;

//节点类
template<class T>
class BtreeNode
{
public:
	friend class BinaryTree<T>;
	BtreeNode() :plchild(NULL), prchild(NULL) {}
	BtreeNode(T d) :data(d), plchild(NULL), prchild(NULL) {}
	T getData()const;
private:
	BtreeNode<T> *plchild, *prchild;
	T data;
};
template<class T>
inline T BtreeNode<T>::getData() const
{
	return data;
}


//二叉树  
template<class T>
class BinaryTree
{
public:
	BinaryTree():root(NULL){}
	BinaryTree<T> & PreOrderCreaterTree(const string & treestr);
private:
	BtreeNode<T> *PreOrderCreateNode(const char *& treechar);
	BtreeNode<T> *root;
};

template<class T>
inline BinaryTree<T>& BinaryTree<T>::PreOrderCreaterTree(const string & treestr)
{
	const char * treechar = treestr.c_str();
	if (*treechar!='#')
	{
		root = PreOrderCreateNode(treechar);
	}
	else
	{
		cout << "NO PREORDER INOUT!" << endl;
	}
	// TODO: 在此处插入 return 语句
	return *this;
}

template<class T>
inline BtreeNode<T>* BinaryTree<T>::PreOrderCreateNode(const char *& treechar)
{
	if (*treechar=='#'||*treechar=='\n')
	{
		return NULL;
	}
	else
	{
		BtreeNode<T> *pnewNode = new BtreeNode<T>(*treechar);
		pnewNode->plchild = PreOrderCreateNode(++treechar);
		pnewNode->prchild = PreOrderCreateNode(++treechar);
		return pnewNode;
	}
}
