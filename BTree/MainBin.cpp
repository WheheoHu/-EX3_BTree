//6.41编写递归算法，在二叉树中求位于先序序列中第k个位置的结点的值。
//6.42编写递归算法，计算二叉树中叶子结点的数目。
//6.43编写递归算法，将二叉树中所有节点的左、右子树相互交换。

#include "btree.h"
#include <fstream>
#include <string>

using namespace std;

int main() {
	std::fstream inputfile, outputfile;
	inputfile.open("input", std::ios::in);
	outputfile.open("output", std::ios::out);

	//建立二叉树
	string treestr;
	inputfile >> treestr;
	BinaryTree<char> btree;
	btree.PreOrderCreaterTree(treestr);

	cout << "PreOrder:" << endl;
	btree.PreOrder();

	outputfile <<"4th Node in PreOrder:"<< btree.PreOrder(4) << endl;
	//outputfile << btree.size() << endl;
	outputfile << "num of leafs:"<<btree.num_leafs() << endl;
	
	btree.SwapChildren();

	cout << "PreOrder:" << endl;
	btree.PreOrder();

	inputfile.close();
	inputfile.close();
	system("pause");
}