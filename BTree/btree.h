#pragma once
#include <iostream>
#include <string>
#include <vector>
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


//二叉树类
template<class T>
class BinaryTree
{
public:
	BinaryTree() :root(NULL) {}

	void PreOrder()const;
	T PreOrder(int location)const;
	BinaryTree<T> & PreOrderCreaterTree(const string & treestr);

private:
	void PreOrder(BtreeNode<T> *currentNode)const;
	void PreOrder(BtreeNode<T> *currentNode,int location,int &count,T &elem)const;

	BtreeNode<T> *PreOrderCreateNode(const char *& treechar);
	BtreeNode<T> *root;
};

template<class T>
inline BinaryTree<T>& BinaryTree<T>::PreOrderCreaterTree(const string & treestr)
{
	const char * treechar = treestr.c_str();
	if (*treechar != '#')
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
inline void BinaryTree<T>::PreOrder() const
{
	PreOrder(root);
}

template<class T>
inline T BinaryTree<T>::PreOrder(int location) const
{
	int count = 1;
	T elem;
	PreOrder(root, location, count, elem);
	return elem;
}

template<class T>
inline void BinaryTree<T>::PreOrder(BtreeNode<T>* currentNode) const
{
	if (currentNode == NULL)
	{
		//cout << '#' << endl;
	}
	else
	{
		cout << currentNode->data << endl;
		PreOrder(currentNode->plchild);
		PreOrder(currentNode->prchild);
	}
}

template<class T>
inline void BinaryTree<T>::PreOrder(BtreeNode<T>* currentNode, int location, int &count,T & elem) const
{
	if (currentNode == NULL)
	{
		cout << '#' << endl;
	}
	else
	{

		if (count == location)
		{
			elem = currentNode->data;

		}
		count++;
		cout << currentNode->data << endl;
		PreOrder(currentNode->plchild, location, count,elem);
		PreOrder(currentNode->prchild, location, count,elem);

	}
}




template<class T>
inline BtreeNode<T>* BinaryTree<T>::PreOrderCreateNode(const char *& treechar)
{
	if (*treechar == '#' || *treechar == '\n')
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
