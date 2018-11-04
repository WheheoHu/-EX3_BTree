#pragma once
template<typename T>
struct BtreeNode
{
	T data;
	BtreeNode *lchild.*rchild;
};

template<class T>
class BTree
{
public:
	BTree();
	~BTree();
	
private:

};
