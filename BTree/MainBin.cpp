//6.41编写递归算法，在二叉树中求位于先序序列中第k个位置的结点的值。
//6.42编写递归算法，计算二叉树中叶子结点的数目。
//6.43编写递归算法，将二叉树中所有节点的左、右子树相互交换。

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