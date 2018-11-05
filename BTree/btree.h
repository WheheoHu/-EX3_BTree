#pragma once
template<typename T>
struct BtreeNode
{
	T data;
	BtreeNode<T> *lchild,*rchild;
};

template<class T>
class BTree
{
public:
	BTree();
	~BTree();
	void InitBtree();
	BtreeNode<T> *FindNode();

private:
	BtreeNode<T> *root;
};
