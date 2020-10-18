
#include <iostream>
#include "CStack.h"
#include "CQueue.h"

/*
Stack : 선입후출의 자료구조이다.
먼저 들어간 데이터가 나중에 나오는 방식이다.
구현 방법
배열기반, 리스트기반 2가지가 있다.
리스트기반으로 구현할때 싱글 링크드 리스트 기반으로 활용한다.
*/

/*
queue : 선입선출의 자료구조이다.
먼저 들어간 데이터가 먼저 나오는 방식이다.
구현 방법
배열기반, 리스트기반 2가지가 있다.
*/

int main()
{
	CStack<int>	stack;

	for (int i = 0; i < 10; ++i)
	{
		stack.push(i);
	}

	while (!stack.empty())
	{
		std::cout << stack.top() << std::endl;
		stack.pop();
	}

	system("cls");

	CStackArray<int>	stack1;

	for (int i = 0; i < 10; ++i)
	{
		stack1.push(i);
	}

	while (!stack1.empty())
	{
		std::cout << stack1.top() << std::endl;
		stack1.pop();
	}

	system("cls");

	CQueue<int>	queue;

	for (int i = 0; i < 20; ++i)
	{
		queue.push(i);
	}

	while (!queue.empty())
	{
		std::cout << queue.front() << std::endl;
		queue.pop();
	}

	system("cls");

	CQueueArray<int, 300>	queue1;

	for (int i = 0; i < 300; ++i)
	{
		queue1.push(i);
	}

	while (!queue1.empty())
	{
		std::cout << queue1.front() << std::endl;
		queue1.pop();
	}

	system("cls");

	CCircleQueue<int>	CircleQueue;

	for (int i = 0; i < 50; ++i)
	{
		CircleQueue.push(i);
	}

	std::cout << "Pop 30" << std::endl;

	for (int i = 0; i < 30; ++i)
	{
		std::cout << CircleQueue.front() << std::endl;
		CircleQueue.pop();
	}

	for (int i = 0; i < 70; ++i)
	{
		CircleQueue.push(i);
	}

	std::cout << "Pop All" << std::endl;

	while (!CircleQueue.empty())
	{
		std::cout << CircleQueue.front() << std::endl;
		CircleQueue.pop();
	}

	return 0;
}
