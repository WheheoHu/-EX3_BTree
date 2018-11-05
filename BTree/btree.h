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
	char PreOrder(const int location)const;
	BinaryTree<T> & PreOrderCreaterTree(const string & treestr);

private:
	void PreOrder(BtreeNode<T> *currentNode)const;
	T PreOrder(BtreeNode<T> *currentNode,const string str)const;
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
inline char BinaryTree<T>::PreOrder( int location) const
{
	const string str;
	PreOrder(root, str);
	const char * temp = str.c_str();
	while (location>0)
	{
		if (*temp=='#')
		{
			++temp;
			continue;
		}
		++temp;
		location++;
	}
	return *temp;
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
inline T BinaryTree<T>::PreOrder(BtreeNode<T>* currentNode, const string str) const
{
	if (currentNode == NULL)
	{
		str.append('#');
	}
	else
	{
		str.append(currentNode->data);
		PreOrder(currentNode->plchild);
		PreOrder(currentNode->prchild);
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
