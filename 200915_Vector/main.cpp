
#include <iostream>
#include "Array.h"

using namespace std;

// ���� : �迭�� �����ϴ� ����� ������.

int main()
{
	//int	iArray[10] = {};

	//// memset�� �޸𸮸� ���ϴ� ������ ä���ٶ� ����Ѵ�.
	//// 1�� ���ڿ� ���� ä���� �޸��� ���� �ּҸ� �����Ѵ�.
	//// 2�� ���ڿ� ä���� ���� �����Ѵ�.
	//// 3�� ���ڿ� ���� ä���� ����Ʈ ũ�⸦ �����Ѵ�.
	//// �޸𸮸� ä�ﶧ 1�������ּҺ��� 3�������� ũ�⸸ŭ�� ä��� �Ǵµ�
	//// 2�� ���ڿ� �� ������ 1����Ʈ ������ ä���ش�.
	//memset(iArray, 1, sizeof(int) * 10);

	//std::cout << iArray[0] << std::endl;

	CArray<int>	arrInt;

	for (int i = 0; i < 100; ++i)
	{
		arrInt.push_back(i);
	}

	for (int i = 0; i < arrInt.size(); ++i)
	{
		std::cout << arrInt[i] << std::endl;
	}

	CArray<int>::iterator	iter = arrInt.begin();
	CArray<int>::iterator	iterEnd = arrInt.end();

	for (; iter != iterEnd; ++iter)
	{
		std::cout << *iter << std::endl;
	}

	iter = arrInt.begin() + 30;

	std::cout << *iter << std::endl;

	iter = arrInt.erase(iter);

	std::cout << "erase Next : " << *iter << std::endl;

	for (int i = 0; i < arrInt.size(); ++i)
	{
		std::cout << arrInt[i] << std::endl;
	}

	system("cls");
	iter = arrInt.begin() + 10;
	iterEnd = arrInt.begin() + 50;

	iter = arrInt.erase(iter, iterEnd);

	std::cout << "erase Next : " << *iter << std::endl;

	for (int i = 0; i < arrInt.size(); ++i)
	{
		std::cout << arrInt[i] << std::endl;
	}


	//iter -= 40;

	//arrInt[100] = 100;

	system("cls");

	CArray<int>	arrInt2;

	arrInt2.push_back(2);
	arrInt2.push_back(9);
	arrInt2.push_back(1);
	arrInt2.push_back(11);
	arrInt2.push_back(20);
	arrInt2.push_back(15);
	arrInt2.push_back(50);
	arrInt2.push_back(25);
	arrInt2.push_back(21);
	arrInt2.push_back(4);
	arrInt2.push_back(6);

	arrInt2.Sort(arrInt2.begin(), arrInt2.end());

	for (int i = 0; i < arrInt2.size(); ++i)
	{
		cout << arrInt2[i] << endl;
	}

	return 0;
}
