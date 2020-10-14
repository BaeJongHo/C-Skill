
#include <iostream>
#include <functional>

/*
��ü���� ���α׷���(OOP) : �����Ҷ� �ʿ��� ��ɵ��� �����ΰ� �ʿ��Ҷ�
��ɵ��� �����Ͽ� ������ �����ϴ� ����� ���Ѵ�.
������ + ����� �ϳ��� ��� ��ǰ�� ����� ��ǰ���� �����Ͽ� �ϼ���
���α׷��� ����� ������ ����̴�.

Ŭ���� : C++���� ��ü���� ���α׷����� �����ϱ� ���� ���Ǵ� �����̴�.
����ü�� ������ ����� ������� ����� �Ǵµ� ����ü������ �����鸸
��Ƶΰ� ����� ������ Ŭ���������� �ʿ��� �Լ��鵵 �����ΰ�
����� �� �� �ִ�.
C++������ ����ü���� Ŭ������ �����ϰ� �Լ��� ���� ����� �ϴ°���
�����ϴ�.

Ŭ������ 4���� �Ӽ�
ĸ��ȭ : �����ִ� ���� Ȥ�� ��ɵ��� �ϳ��� �����ִ� ����� ���Ѵ�.

����ȭ : Ŭ������ ���� Ȥ�� ��ɵ��� �ܺο� �����ϴ� ������ �����ϴ°���
���Ѵ�.
Ŭ������ ���� : �ش� Ŭ������ ������� �Լ� ���� �ǹ��Ѵ�.

- public : Ŭ������ ���� Ȥ�� �ܺ� ����������� ������ ������ ���� ���Ѵ�.
- private : Ŭ������ ���ο����� ������ �����ϰ� �ܺο����� ������ �Ұ�����
���� ���Ѵ�.
- protected : ��� ���� ����帮�ڽ��ϴ�.

��Ӽ� : ��� ���� ����帮�ڽ��ϴ�.
������ : ��� ���� ����帮�ڽ��ϴ�.

Ŭ������ ��������� ���� Ÿ���� �ȴ�.
*/
/*
this : �ڱ��ڽ��� �޸� �ּ��̴�.
*/
class CPlayer
{
	// �Ʒ�ó�� public: ���ְ� �Ǹ� �ٸ� Ű���带 ������ ������
	// ��� public���� �ν��� �ȴ�.
public:
	char	m_strName[32];
	int		m_iAttack;
	int		m_iArmor;

	// ���⼭���ʹ� private�� �����Ѵ�.
private:
	int		m_iHP;
	int		m_iHPMax;
	int* m_pInt;

public:	// ������ : ��������� ���� �����ϰų� �� ����� �� �ִ� �Լ����̴�.
	int GetHP()
	{
		// ����Լ� �ȿ��� ����ϴ� ����������� this->�� ������ �� �ִ�.
		return this->m_iHP;
	}

	void SetHP(int iHP)
	{
		this->m_iHP = iHP;
	}

public:
	// �����ڿ� �Ҹ��ڴ� Ŭ������ �̸��� ������ �̸��� �Լ��̴�.
	// �� �Լ����� ��ȯŸ���� ����.
	// ���� ����, �Ҹ��ڸ� �ȸ�����ٸ� ���������� �⺻�����ڿ�
	// �Ҹ��ڸ� ����ϰ� �Ǵ� ���̴�.
	// ������ָ� ������� �����ڿ� �Ҹ��ڰ� ���۵ȴ�.
	// ������ : �� Ŭ������ �̿��ؼ� ��ü�� �����Ҷ� ȣ��Ǵ� �Լ��̴�.
	// �̷� Ư¡ ������ �� Ŭ������ �����͸� �ʱ�ȭ�ϴ� ������ �����Ҷ�
	// ȿ�����̴�.
	// �����ڴ� �����ε��� �����ϴ�.
	// �������� ���ڸ� Ȱ���ؼ� ���� �����ڸ� �����ε� �س���
	// ����ϴ� ���� �����ϴ�.
	CPlayer()
	{
		std::cout << "CPlayer ������" << std::endl;

		m_pInt = new int;
		*m_pInt = 9999;
	}

	CPlayer(const char* pName)
	{
		std::cout << "CPlayer " << pName << " ������" << std::endl;

		m_pInt = new int;
		*m_pInt = 9999;
	}

	/*
	��������� : ���ڷ� ������ �ٸ� ��ü�� �����ؼ� �����ϴ� �����
	���Ѵ�.
	�������� : �����͸� �״�� �����ϴ� ����̴�.
	�������� : �����Ҵ�� �����Ͱ� ���� ��� �ش� ������ ũ���
	���� ũ���� ������ ���� �Ҵ����ְ� ������ ���� �������ִ°���
	���Ѵ�.
	*/
	CPlayer(const CPlayer& player)
	{
		strcpy_s(m_strName, player.m_strName);
		m_iAttack = player.m_iAttack;
		m_iArmor = player.m_iArmor;

		m_iHP = player.m_iHP;
		m_iHPMax = player.m_iHPMax;
		//m_pInt = player.m_pInt;
		m_pInt = new int;
		*m_pInt = *player.m_pInt;
	}

	// �Ҹ��� : �� Ŭ������ �̿��ؼ� ������ ��ü�� �޸𸮿��� �����ɶ�
	// ȣ��Ǵ� �Լ��̴�.
	// �̷� Ư¡������ ��ü�� �����۾��� �����ϴ�.
	~CPlayer()
	{
		delete	m_pInt;
		std::cout << "CPlayer �Ҹ���" << std::endl;
	}
};

class CTest
{
public:
	CTest()
	{
		m_iTest = 0;
	}

	~CTest()
	{
	}

public:
	int	m_iTest;
};

class CConversion
{
public:
	CConversion()
	{
		test.m_iTest = 3000;
	}

	~CConversion()
	{
	}

public:
	CTest	test;

public:
	operator CTest ()
	{
		return test;
	}

	operator int()
	{
		return test.m_iTest;
	}
};

class CConversion1
{
public:
	CConversion1()
	{
		test.m_iTest = 9999;
	}

	~CConversion1()
	{
	}

public:
	CTest	test;

public:
	CTest* operator -> ()
	{
		return &test;
	}

	int operator * ()
	{
		return test.m_iTest;
	}
};

class CPoint
{
public:
	CPoint()
	{
		x = 0;
		y = 0;
	}

	~CPoint()
	{
	}

public:
	int	x, y;

public:
	CPoint operator + (const CPoint& pt)
	{
		CPoint	result;
		result.x = x + pt.x;
		result.y = y + pt.y;
		return result;
	}

	CPoint operator + (int iNumber)
	{
		CPoint	result;
		result.x = x + iNumber;
		result.y = y + iNumber;
		return result;
	}

	/*
	void* operator new (size_t iSize)
	{
		return nullptr;
	}
	*/
};

class CFunction
{
public:
	CFunction()
	{
	}

	~CFunction()
	{
	}

public:
	void Func1()
	{
		std::cout << "Func1" << std::endl;
	}

	void Func2()
	{
		std::cout << "Func2" << std::endl;
	}

	void Func3()
	{
		std::cout << "Func3" << std::endl;
	}

	int Minus1(int a, int b)
	{
		std::cout << "Test Minus" << std::endl;
		return a - b;
	}
};

void Output()
{
	std::cout << "Output" << std::endl;
}

int Minus(int a, int b)
{
	return a - b;
}

int main()
{
	CPlayer	player;
	CPlayer	player1("ö��");

	// main�Լ��� playerŬ������ �ܺ��̴�.
	// �׷��� ������ ���⼭ private�� ������ �� ����.
	// ����ü�� �ƹ��͵� ������ ��� �⺻���� public�̰�
	// Ŭ������ �ƹ��͵� ������ ��� �⺻���� private���� ó���� �ȴ�.
	//player.m_iHP = 100;
	// �Ʒ�ó�� ����Լ��� ȣ���Ҷ� this�������ְ� �Ǵµ� ȣ�����ִ� ��ü��
	// this�� �������ش�. ��, this�� ȣ�����ִ� ��ü�� �����̳Ŀ� ����
	// �޶����� �ȴ�.
	player.SetHP(100);
	player1.SetHP(300);

	std::cout << "Player HP : " << player.GetHP() << std::endl;
	std::cout << "Player1 HP : " << player1.GetHP() << std::endl;

	CPoint	pt1, pt2, pt3;
	pt1.x = 10;
	pt1.y = 20;

	pt2.x = 30;
	pt2.y = 40;

	// pt1�� +�Լ��� ȣ���Ѵ�. ���ڷ� pt2�� �Ѱ��ش�.
	pt3 = pt1 + pt2;

	std::cout << "x : " << pt3.x << " y : " << pt3.y << std::endl;

	// pt1�� +�Լ��� ȣ���Ѵ�. ���ڷ� 30�� �Ѱ��ش�.
	pt3 = pt1 + 30;

	std::cout << "x : " << pt3.x << " y : " << pt3.y << std::endl;

	CConversion	conversion;

	CTest	test1 = conversion;

	std::cout << test1.m_iTest << std::endl;

	int	iTestNumber = conversion;

	std::cout << iTestNumber << std::endl;

	CConversion1	conversion1;

	std::cout << *conversion1 << std::endl;
	std::cout << conversion1->m_iTest << std::endl;
	//conversion1->

	//CPoint	ptTest = conversion;

	void(*pFunc)() = Output;

	pFunc();

	void(CFunction:: * pFunc1)();

	pFunc1 = &CFunction::Func1;

	CFunction	func1, func2, func3;

	(func1.*pFunc1)();

	void(CFunction:: * pFuncArray[10])();

	pFuncArray[0] = &CFunction::Func1;
	pFuncArray[1] = &CFunction::Func2;
	pFuncArray[2] = &CFunction::Func3;

	(func1.*pFuncArray[0])();
	(func1.*pFuncArray[1])();
	(func1.*pFuncArray[2])();

	// function ��ü�� �����Լ�, ����Լ� ��� �޾Ƽ� ������ �ִٰ�
	// ����� �� �ִ�.
	std::function<void()>	func;

	// bind �Լ��� �̿��ؼ� �Լ��� �ּҸ� ��� function ��ü��
	// �־��� �� �ִ�. �����Լ��� ��쿡�� �ش� �Լ��� �ּҸ� �־��ָ�ȴ�.
	func = std::bind(Output);
	func();

	// ����Լ��� �Լ��� �ּҿ� this�� �������� ��ü�� �־��ָ� ���
	// function ��ü�� ������ְ� �ش� �Լ��� ȣ������ �� �ִ�.
	func = std::bind(&CFunction::Func1, func1);
	func();

	std::function<int(int, int)>	funcInt;

	// placeholders : ���� ������ �������ش�.
	funcInt = std::bind(Minus, std::placeholders::_1,
		std::placeholders::_2);
	std::cout << funcInt(10, 20) << std::endl;

	funcInt = std::bind(&CFunction::Minus1, func1, std::placeholders::_1,
		std::placeholders::_2);
	std::cout << funcInt(10, 20) << std::endl;

	return 0;
}
