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
	int index = 0;
	while (!inputfile.eof())
	{
		
		inputfile >> std::noskipws >> e;
		if (e == '\n')
		{
			break;
		}
		treedata.push_back(e);
		outputfile << treedata[index] << std::endl;
		index++;
	}





	inputfile.close();
	inputfile.close();
	system("pause");
}