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


	string e;
	inputfile >> e;


	BinaryTree<char> btree;
	btree.PreOrderCreaterTree(e);
	outputfile << e;
	
	inputfile.close();
	inputfile.close();
}