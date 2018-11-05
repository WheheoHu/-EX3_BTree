#pragma ones
#include <iostream>
#include <string>
using namespace std;

template<class T> class BtreeNode;
template<class T> class BinaryTree;


template<class T>
class BtreeNode
{
public:
	friend class BinaryTree<T>;
	BtreeNode() :plchild(NULL), prchild(NULL){}
	BtreeNode(T d) :data(d), plchild(NULL), prchild(NULL){}

private:
	BtreeNode<T> *plchild, *prchild;
	T data;
};

template<class T>
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

private:

};
