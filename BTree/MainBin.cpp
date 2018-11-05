//6.41��д�ݹ��㷨���ڶ���������λ�����������е�k��λ�õĽ���ֵ��
//6.42��д�ݹ��㷨�������������Ҷ�ӽ�����Ŀ��
//6.43��д�ݹ��㷨���������������нڵ�����������໥������

#include "btree.h"
#include <fstream>
#include <string>

using namespace std;

int main() {
	std::fstream inputfile, outputfile;
	inputfile.open("input", std::ios::in);
	outputfile.open("output", std::ios::out);

	//����������
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