#pragma once
#include<iostream>

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
	void InitBtree(T rootdata);
	BtreeNode<T> *FindNode(T data_find);

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
inline void BTree<T>::InitBtree(T rootdata)
{
	root = new BtreeNode(rootdata);

}
