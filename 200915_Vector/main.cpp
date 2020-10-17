
#include <iostream>
#include "Array.h"

using namespace std;

// 숙제 : 배열을 정렬하는 기능을 만들어보자.

int main()
{
	//int	iArray[10] = {};

	//// memset은 메모리를 원하는 값으로 채워줄때 사용한다.
	//// 1번 인자에 값을 채워줄 메모리의 시작 주소를 지정한다.
	//// 2번 인자에 채워줄 값을 지정한다.
	//// 3번 인자에 값을 채워줄 바이트 크기를 지정한다.
	//// 메모리를 채울때 1번인자주소부터 3번인자의 크기만큼을 채우게 되는데
	//// 2번 인자에 들어간 값으로 1바이트 단위로 채워준다.
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
