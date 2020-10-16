#pragma once

template <typename T>
class CListNode
{
	// friend 는 지정해주는 클래스를 이 클래스의 친구 클래스로 만들어서
	// 지정해주는 클래스 내에서는 이 클래스의 private에 접근할 수 있게 한다.
	// 생성, 소멸자를 private으로 만들어두고 friend를 지정해주면
	// 지정된 클래스 외에는 이 클래스를 생성하거나 메모리를 해제할 수 없다.

	// template 클래스를 friend처리할때는 아래처럼 template 을 붙여주어야
	// 한다.
	template <typename T>
	friend class CList;
	template <typename t>
	friend class CListIterator;
	template <typename t>
	friend class CListReverseIterator;

	// 생성자가 private이면 외부에서는 이 생성자를 호출할수가 없으므로
	// 외부에서 객체 생성이 불가능하다.
private:
	CListNode()
	{
		m_pNext = nullptr;
		m_pPrev = nullptr;
	}

	~CListNode()
	{
	}

private:
	T		m_Data;
	CListNode<T>* m_pNext;
	CListNode<T>* m_pPrev;
};

template <typename T>
class CListIterator
{
	template <typename t>
	friend class CList;

public:
	CListIterator()
	{
		m_pNode = nullptr;
	}

	~CListIterator()
	{
	}

private:
	CListNode<T>* m_pNode;

public:
	bool operator == (const CListIterator<T>& iter)	const
	{
		return m_pNode == iter.m_pNode;
	}

	bool operator != (const CListIterator<T>& iter)	const
	{
		return m_pNode != iter.m_pNode;
	}

	void operator ++ ()
	{
		m_pNode = m_pNode->m_pNext;
	}

	void operator ++ (int)
	{
		m_pNode = m_pNode->m_pNext;
	}

	void operator -- ()
	{
		m_pNode = m_pNode->m_pPrev;
	}

	void operator -- (int)
	{
		m_pNode = m_pNode->m_pPrev;
	}

	CListIterator<T> operator - (int iNumber)
	{
		CListIterator<T> iter;
		iter.m_pNode = m_pNode;
		for (int i = 0; i < iNumber; ++i)
			iter.m_pNode = iter.m_pNode->m_pPrev;

		return iter;
	}

	T& operator * ()	const
	{
		return m_pNode->m_Data;
	}
};

template <typename T>
class CListReverseIterator
{
	template <typename t>
	friend class CList;

public:
	CListReverseIterator()
	{
		m_pNode = nullptr;
	}

	~CListReverseIterator()
	{
	}

private:
	CListNode<T>* m_pNode;

public:
	bool operator == (const CListReverseIterator<T>& iter)	const
	{
		return m_pNode == iter.m_pNode;
	}

	bool operator != (const CListReverseIterator<T>& iter)	const
	{
		return m_pNode != iter.m_pNode;
	}

	void operator ++ ()
	{
		m_pNode = m_pNode->m_pPrev;
	}

	void operator ++ (int)
	{
		m_pNode = m_pNode->m_pPrev;
	}

	void operator -- ()
	{
		m_pNode = m_pNode->m_pNext;
	}

	void operator -- (int)
	{
		m_pNode = m_pNode->m_pNext;
	}

	T& operator * ()	const
	{
		return m_pNode->m_Data;
	}
};

// template 클래스는 헤더파일에 구현까지 모두 해준다.
template <typename T>
class CList
{
public:
	CList()
	{
		m_pBegin = new Node;
		m_pEnd = new Node;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_iSize = 0;
	}

	~CList()
	{
		clear();
		delete	m_pBegin;
		delete	m_pEnd;
	}

private:
	// typedef : 타입을 재정해주는 기능이다.
	typedef CListNode<T>	Node;
	typedef CListNode<T>* PNode;

public:
	typedef CListIterator<T>		iterator;
	typedef CListReverseIterator<T>	reverse_iterator;

private:
	PNode	m_pBegin;
	PNode	m_pEnd;
	int		m_iSize;

public:
	// 가장 마지막노드의 다음 노드로 새로운 노드를 만들어서 추가한다.
	void push_back(const T& data)
	{
		// 데이터를 추가할 노드를 새로 만들어준다.
		PNode	pNode = new Node;

		pNode->m_Data = data;

		PNode	pPrev = m_pEnd->m_pPrev;

		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	void push_front(const T& data)
	{
		// 데이터를 추가할 노드를 새로 만들어준다.
		PNode	pNode = new Node;

		pNode->m_Data = data;

		PNode	pNext = m_pBegin->m_pNext;

		pNode->m_pNext = pNext;
		pNext->m_pPrev = pNode;

		pNode->m_pPrev = m_pBegin;
		m_pBegin->m_pNext = pNode;

		++m_iSize;
	}

	void pop_back()
	{
		if (empty())
			return;

		PNode	pDelete = m_pEnd->m_pPrev;
		PNode	pPrev = pDelete->m_pPrev;

		delete	pDelete;

		pPrev->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pPrev;

		--m_iSize;
	}

	void pop_front()
	{
		if (empty())
			return;

		PNode	pDelete = m_pBegin->m_pNext;
		PNode	pNext = pDelete->m_pNext;

		delete	pDelete;

		m_pBegin->m_pNext = pNext;
		pNext->m_pPrev = m_pBegin;

		--m_iSize;
	}

	T front()	const
	{
		return m_pBegin->m_Data;
	}

	T back()	const
	{
		return m_pEnd->m_pPrev->m_Data;
	}

	// 클래스의 멤버함수 뒤에 const를 붙이게 되면 해당 함수에서는
	// 클래스의 멤버변수의 값을 변경할 수 없다.
	// const 객체도 호출가능한 함수가 된다.
	int size()	const
	{
		return m_iSize;
	}

	bool empty()	const
	{
		return m_iSize == 0;
	}

	void clear()
	{
		PNode	pNode = m_pBegin->m_pNext;

		while (pNode != m_pEnd)
		{
			PNode	pNext = pNode->m_pNext;
			delete	pNode;
			pNode = pNext;
		}

		m_iSize = 0;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
	}

	// begin함수는 시작노드를 반환해준다.
	iterator begin()	const
	{
		iterator	iter;
		iter.m_pNode = m_pBegin->m_pNext;
		return iter;
	}

	// end함수는 마지막노드의 다음을 반환한다.
	// 즉, nullptr을 넣어서 반환할것이다.
	iterator end()	const
	{
		iterator	iter;
		iter.m_pNode = m_pEnd;
		return iter;
	}

	// erase함수는 노드를 지워주고 지운 다음노드를 반환해주도록 한다.
	iterator erase(iterator iter)
	{
		if (iter == end())
			return end();

		PNode	pPrev = iter.m_pNode->m_pPrev;
		PNode	pNext = iter.m_pNode->m_pNext;

		if (pPrev)
			pPrev->m_pNext = pNext;

		if (pNext)
			pNext->m_pPrev = pPrev;

		delete	iter.m_pNode;
		--m_iSize;

		iter.m_pNode = pNext;

		return iter;
	}

	iterator erase(const T& data)
	{
		iterator	iter = begin();
		iterator	iterEnd = end();

		for (; iter != iterEnd; ++iter)
		{
			if (*iter == data)
				return erase(iter);
		}

		return end();
	}

	reverse_iterator rbegin()	const
	{
		reverse_iterator	iter;
		iter.m_pNode = m_pEnd->m_pPrev;
		return iter;
	}

	reverse_iterator rend()	const
	{
		reverse_iterator	iter;
		iter.m_pNode = m_pBegin;
		return iter;
	}

	reverse_iterator erase(reverse_iterator iter)
	{
		if (iter == rend())
			return rend();

		PNode	pPrev = iter.m_pNode->m_pPrev;
		PNode	pNext = iter.m_pNode->m_pNext;

		if (pPrev)
			pPrev->m_pNext = pNext;

		if (pNext)
			pNext->m_pPrev = pPrev;

		delete	iter.m_pNode;
		--m_iSize;

		iter.m_pNode = pPrev;

		return iter;
	}

	iterator erase(const iterator& first, const iterator& second)
	{
		iterator	iterStart = first;
		iterator	iterEnd = second;

		if (iterStart.m_pNode == m_pBegin)
			iterStart.m_pNode = m_pBegin->m_pNext;

		if (iterEnd.m_pNode != m_pEnd)
			++iterEnd;

		PNode	pPrev = iterStart.m_pNode->m_pPrev;
		PNode	pNext = iterEnd.m_pNode;

		PNode	pDeleteNode = iterStart.m_pNode;

		while (pDeleteNode != iterEnd.m_pNode)
		{
			PNode	pDeleteNext = pDeleteNode->m_pNext;
			delete	pDeleteNode;

			pDeleteNode = pDeleteNext;

			--m_iSize;
		}

		pPrev->m_pNext = pNext;
		pNext->m_pPrev = pPrev;

		return iterEnd;
	}

	void Sort(const iterator& first, const iterator& second)
	{
		iterator iterStart = first;
		iterator iterEnd = second;

		if (iterEnd != end())
			++iterEnd;

		iterator iter1;
		iterator iter2;

		for (iter1 = iterStart; iter1 != iterEnd; ++iter1)
		{
			for (iter2 = iterStart; iter2 != iterEnd - 1; ++iter2)
			{
				if (iter2.m_pNode->m_Data > iter2.m_pNode->m_pNext->m_Data)
				{
					int temp = iter2.m_pNode->m_Data;
					iter2.m_pNode->m_Data = iter2.m_pNode->m_pNext->m_Data;
					iter2.m_pNode->m_pNext->m_Data = temp;
				}
			}
		}
	}
};