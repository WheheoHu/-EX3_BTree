#pragma once
#include<iostream>
#include<vector>


template<typename T>
struct BtreeNode
{
	T data;
	BtreeNode<T> *lchild, *rchild;
	BtreeNode(const T &d) :data(d), lchild(NULL), rchild(NULL) {}
};

template<class T>
class BTree
{
public:
	BTree();
	BTree(T rootdata);
	~BTree();
	void InitBtree();
	void InitBtree(T rootdata);
	BtreeNode<T> *FindNode(T data_find);
	bool isEmpty();

private:
	BtreeNode<T> *root;
};

template<class T>
inline BTree<T>::BTree()
{
	std::cout << "please use InitBtree to Init" << std::endl;
}

template<class T>
inline BTree<T>::BTree(T rootdata)
{
	InitBtree(rootdata);
}

template<class T>
inline void BTree<T>::InitBtree()
{
	root = new   BtreeNode;
}

template<class T>
inline void BTree<T>::InitBtree(T rootdata)
{
	root = new BtreeNode(rootdata);
}

template<class T>
inline BtreeNode<T>* BTree<T>::FindNode(T data_find)
{
	if (isEmpty())
	{
		return NULL;
	}
	else
	{
		BtreeNode<T> *p = root;
		if (p->data == data_find)
		{
			return p
		}
		FindNode(p->lchild);
		FindNode(p->rchild);
	}

}

template<class T>
inline bool BTree<T>::isEmpty()
{
	if (root == NULL)
	{
		return true;
	}
	return false;
}
