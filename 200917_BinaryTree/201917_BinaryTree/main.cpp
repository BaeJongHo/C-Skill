
#include <iostream>
#include "BinaryTree.h"

int main()
{
	CBinaryTree<int, const char*>	tree;

	int	iArr[8] = { 50, 40, 80, 30, 15, 25, 10, 100 };

	tree.insert(30, "�ƹ���");
	tree.insert(15, "�Ƹ�");
	tree.insert(10, "����Ӹ����");
	tree.insert(25, "������");
	tree.insert(50, "������");
	tree.insert(40, "�����");
	tree.insert(80, "���̹�");
	tree.insert(100, "������");

	CBinaryTree<int, const char*>::iterator	iter = tree.begin();
	CBinaryTree<int, const char*>::iterator	iterEnd = tree.end();

	for (; iter != iterEnd; ++iter)
	{
		std::cout << "Key : " << iter->first << 
			" Value : " << iter->second << std::endl;
	}

	iter = tree.find(200);

	if (iter == tree.end())
		std::cout << "ã�� ����� �����ϴ�." << std::endl;

	iter = tree.find(10);

	std::cout << "Find Key : " << iter->first <<
		" Value : " << iter->second << std::endl;

	//iter = tree.erase(50);
	//std::cout << "Next : " << iter->first << std::endl;

	for (int i = 0; i < 8; ++i)
	{
		std::cout << "Delete : " << iArr[i] << std::endl;
		iter = tree.erase(iArr[i]);

		if (iter != tree.end())
			std::cout << "Next : " << iter->first << std::endl;
	}

	iter = tree.begin();
	iterEnd = tree.end();

	for (; iter != iterEnd; ++iter)
	{
		std::cout << "Key : " << iter->first <<
			" Value : " << iter->second << std::endl;
	}

	return 0;
}
