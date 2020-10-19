
#include <iostream>
#include "BinaryTree.h"

int main()
{
	CBinaryTree<int, const char*>	tree;

	int	iArr[8] = { 50, 40, 80, 30, 15, 25, 10, 100 };

	tree.insert(30, "아무무");
	tree.insert(15, "아리");
	tree.insert(10, "노란머리고아");
	tree.insert(25, "가붕이");
	tree.insert(50, "렉붕이");
	tree.insert(40, "우붕이");
	tree.insert(80, "아이번");
	tree.insert(100, "스붕이");

	CBinaryTree<int, const char*>::iterator	iter = tree.begin();
	CBinaryTree<int, const char*>::iterator	iterEnd = tree.end();

	for (; iter != iterEnd; ++iter)
	{
		std::cout << "Key : " << iter->first << 
			" Value : " << iter->second << std::endl;
	}

	iter = tree.find(200);

	if (iter == tree.end())
		std::cout << "찾는 대상이 없습니다." << std::endl;

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
