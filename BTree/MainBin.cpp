//6.41��д�ݹ��㷨���ڶ���������λ�����������е�k��λ�õĽ���ֵ��
//6.42��д�ݹ��㷨�������������Ҷ�ӽ�����Ŀ��
//6.43��д�ݹ��㷨���������������нڵ�����������໥������

#include "btree.h"
#include <fstream>
#include <vector>

int main() {
	std::fstream inputfile, outputfile;
	inputfile.open("input", std::ios::in);
	outputfile.open("output", std::ios::out);

	std::vector<char> treedata;
	char e;
	while (!inputfile.eof())
	{

		inputfile >> std::noskipws >> e;
		if (e == '\n')
		{
			break;
		}
		treedata.push_back(e);
	}
	for (int i = 0; i < treedata.size(); i++)
	{
		if (treedata[i] == ' ')
		{
			outputfile << i + 1 << " empty" << std::endl;
		}
	}

	BTree<char> btree;






	inputfile.close();
	inputfile.close();
}