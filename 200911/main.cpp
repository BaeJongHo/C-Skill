
#include <iostream>
#include <functional>

/*
객체지향 프로그래밍(OOP) : 개발할때 필요한 기능들을 만들어두고 필요할때
기능들을 조립하여 개발을 진행하는 방식을 말한다.
데이터 + 기능을 하나로 묶어서 부품을 만들고 부품들을 조립하여 완성된
프로그램을 만들어 나가는 방식이다.

클래스 : C++에서 객체지향 프로그래밍을 지원하기 위해 사용되는 문법이다.
구조체와 굉장히 흡사한 방식으로 사용이 되는데 구조체에서는 변수들만
모아두고 사용을 했지만 클래스에서는 필요한 함수들도 만들어두고
사용을 할 수 있다.
C++에서는 구조체에도 클래스와 동일하게 함수를 만들어서 사용을 하는것이
가능하다.

클래스의 4가지 속성
캡슐화 : 관련있는 변수 혹은 기능들을 하나로 묶어주는 기능을 말한다.

은닉화 : 클래스의 변수 혹은 기능들을 외부에 공개하는 수준을 설정하는것을
말한다.
클래스의 내부 : 해당 클래스에 만들어진 함수 안을 의미한다.

- public : 클래스의 내부 혹은 외부 어느곳에서든 접근이 가능한 것을 말한다.
- private : 클래스의 내부에서는 접근이 가능하고 외부에서는 접근이 불가능한
것을 말한다.
- protected : 상속 배우고 설명드리겠습니다.

상속성 : 상속 배우고 설명드리겠습니다.
다형성 : 상속 배우고 설명드리겠습니다.

클래스도 사용자정의 변수 타입이 된다.
*/
/*
this : 자기자신의 메모리 주소이다.
*/
class CPlayer
{
	// 아래처럼 public: 해주게 되면 다른 키워드를 만나기 전까지
	// 모두 public으로 인식이 된다.
public:
	char	m_strName[32];
	int		m_iAttack;
	int		m_iArmor;

	// 여기서부터는 private을 적용한다.
private:
	int		m_iHP;
	int		m_iHPMax;
	int* m_pInt;

public:	// 접근자 : 멤버변수의 값을 변경하거나 얻어서 사용할 수 있는 함수들이다.
	int GetHP()
	{
		// 멤버함수 안에서 사용하는 멤버변수들은 this->를 생략할 수 있다.
		return this->m_iHP;
	}

	void SetHP(int iHP)
	{
		this->m_iHP = iHP;
	}

public:
	// 생성자와 소멸자는 클래스의 이름과 동일한 이름의 함수이다.
	// 이 함수들은 반환타입이 없다.
	// 만약 생성, 소멸자를 안만들었다면 내부적으로 기본생성자와
	// 소멸자를 사용하게 되는 것이다.
	// 만들어주면 만들어준 생성자와 소멸자가 동작된다.
	// 생성자 : 이 클래스를 이용해서 객체를 생성할때 호출되는 함수이다.
	// 이런 특징 때문에 이 클래스의 데이터를 초기화하는 역할을 수행할때
	// 효율적이다.
	// 생성자는 오버로딩이 가능하다.
	// 여러가지 인자를 활용해서 여러 생성자를 오버로딩 해놓고
	// 사용하는 것이 가능하다.
	CPlayer()
	{
		std::cout << "CPlayer 생성자" << std::endl;

		m_pInt = new int;
		*m_pInt = 9999;
	}

	CPlayer(const char* pName)
	{
		std::cout << "CPlayer " << pName << " 생성자" << std::endl;

		m_pInt = new int;
		*m_pInt = 9999;
	}

	/*
	복사생성자 : 인자로 들어오는 다른 객체를 복사해서 생성하는 방식을
	말한다.
	얕은복사 : 데이터를 그대로 복사하는 방식이다.
	깊은복사 : 동적할당된 데이터가 있을 경우 해당 공간의 크기와
	동일 크기의 공간을 새로 할당해주고 데이터 값만 복사해주는것을
	말한다.
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

	// 소멸자 : 이 클래스를 이용해서 생성한 객체가 메모리에서 해제될때
	// 호출되는 함수이다.
	// 이런 특징때문에 객체의 정리작업에 유용하다.
	~CPlayer()
	{
		delete	m_pInt;
		std::cout << "CPlayer 소멸자" << std::endl;
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
	CPlayer	player1("철수");

	// main함수는 player클래스의 외부이다.
	// 그렇기 때문에 여기서 private은 접근할 수 없다.
	// 구조체는 아무것도 안해줄 경우 기본으로 public이고
	// 클래스는 아무것도 안해줄 경우 기본으로 private으로 처리가 된다.
	//player.m_iHP = 100;
	// 아래처럼 멤버함수를 호출할때 this설정해주게 되는데 호출해주는 객체로
	// this를 설정해준다. 즉, this는 호출해주는 객체가 무엇이냐에 따라
	// 달라지게 된다.
	player.SetHP(100);
	player1.SetHP(300);

	std::cout << "Player HP : " << player.GetHP() << std::endl;
	std::cout << "Player1 HP : " << player1.GetHP() << std::endl;

	CPoint	pt1, pt2, pt3;
	pt1.x = 10;
	pt1.y = 20;

	pt2.x = 30;
	pt2.y = 40;

	// pt1의 +함수를 호출한다. 인자로 pt2를 넘겨준다.
	pt3 = pt1 + pt2;

	std::cout << "x : " << pt3.x << " y : " << pt3.y << std::endl;

	// pt1의 +함수를 호출한다. 인자로 30을 넘겨준다.
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

	// function 객체는 전역함수, 멤버함수 모두 받아서 가지고 있다가
	// 사용할 수 있다.
	std::function<void()>	func;

	// bind 함수를 이용해서 함수의 주소를 묶어서 function 객체에
	// 넣어줄 수 있다. 전역함수의 경우에는 해당 함수의 주소만 넣어주면된다.
	func = std::bind(Output);
	func();

	// 멤버함수는 함수의 주소와 this에 지정해줄 객체를 넣어주면 묶어서
	// function 객체로 만들어주고 해당 함수를 호출해줄 수 있다.
	func = std::bind(&CFunction::Func1, func1);
	func();

	std::function<int(int, int)>	funcInt;

	// placeholders : 인자 순서를 지정해준다.
	funcInt = std::bind(Minus, std::placeholders::_1,
		std::placeholders::_2);
	std::cout << funcInt(10, 20) << std::endl;

	funcInt = std::bind(&CFunction::Minus1, func1, std::placeholders::_1,
		std::placeholders::_2);
	std::cout << funcInt(10, 20) << std::endl;

	return 0;
}
