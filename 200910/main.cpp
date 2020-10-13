
#include <iostream>

void Output()
{
	std::cout << "Output Function" << std::endl;
}

void OutputTest()
{
	std::cout << "OutputTest Function" << std::endl;
}

// 인자도 이 함수 내에서 사용하는 지역변수로 인식된다.
int Sum(int a, int b)
{
	return a + b;
}

void SetFunctionPointer(void(*pFunc)())
{
	pFunc();
}

/*
함수의 오버로딩 : C++은 기본적으로 이름이 같을 경우 문제가 발생된다.
하지만 함수의 경우에는 이름이 같더라도 인자의 개수 혹은 타입이 다를경우
다른함수로 인식이 된다.
이를 함수의 오버로딩 이라고 한다.
단, 함수의 반환타입은 오버로딩에 영향을 안준다.
*/
//int Output()
//{
//	return 0;
//}
void Output(int iNumber)
{
	std::cout << iNumber << std::endl;
}
//
//void Output(int iNumber1, int iNumber2 = 50)
//{
//}

// 디폴트 인자 : 함수의 인자에 기본값을 설정해주는것을 말한다.
// 이 함수를 호출할때 인자에 값을 지정할 경우 해당 값으로 iNumber가
// 설정된다. 그런데 인자에 값을 안넣어줄경우 iNumber는 100으로
// 설정된다.
void OutputNumber(int iNumber = 100)
{
	std::cout << iNumber << std::endl;
}

/*
재귀함수 : 함수내에서 자기자신을 호출해주는 함수를 말한다.
마치 반복문처럼 여러번 호출해줄 수 있는 특징을 갖게 되는데
잘못 사용하면 해당 함수에서 무한루프에 빠지게 된다.
*/
void Recursion()
{
	//Recursion();
}

int Factorial(int iNumber)
{
	if (iNumber == 1)
		return 1;

	return iNumber * Factorial(iNumber - 1);
	/*
	컴파일러가 인식하는 코드
	if(iNumber == 1)
		return 1;
	int iResult = Factorial(iNumber - 1);
	return iNumber * iResult;
	*/
}

/*
꼬리재귀 : 재귀 호출이 끝난 후에 현재 함수에서 추가 연산을 안하도록
구현하는 형태이다. 이렇게 해주면 호출이 반복되면서 스택이 쌓일때
컴파일러가 선형으로 처리하도록 알고리즘을 바꿔서 스택을 재사용할 수 있게
해준다.
컴파일러 최적화를 해줘야 한다.
*/
int Factorial1(int iNumber, int iAccumulator)
{
	if (iNumber == 1)
		return iAccumulator;
	return Factorial1(iNumber - 1, iAccumulator * iNumber);

	/*
	int iAcc = 1;

	do
	{
		if(iNumber == 1)
			return;
		iAcc = iAcc * iNumber;
		iNumber = iNumber - 1;
	}while(true);
	*/
}

int FactorialTail(int iNumber)
{
	return Factorial1(iNumber, 1);
}

void ChangeNumber(int iNumber)
{
	iNumber = 3030;
}

void ChangeNumber(int* pNumber)
{
	*pNumber = 3030;
}

/*
map을 많이 썼는데 요즘엔 해쉬맵을 많이 쓴다.
unordered_map
stl : list, vector, unordered_map
C++ 11에서 많이 물어보는 것들
스마트포인터 꼭 공부하기!!
C++ 형변환 4가지 꼭 공부하기.
static_cast, const_cast, dynamic_cast, reinterpret_cast

람다, function객체, 템플릿 가변인자, auto, 정규 표현식
*/
struct FPlayer
{
	char	strName[32];
	int		iAttack;
	int		iArmor;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
};

// 인자를 레퍼런스로 받게되면 참조자로 받기 때문에 무거운 데이터를
// 인자로 넘겨줄때도 손쉽게 받을 수 있다.
void SetPlayer(FPlayer& player)
{
}

void OutputPlayer(const FPlayer& player)
{
	//player.iAttack = 303030;
}

struct IntRef
{
	int& iRef;
};

struct CharRef
{
	char& cRef;
};

struct PlayerRef
{
	FPlayer& ref;
};

int main()
{
	/*
	함수포인터 변수 선언방법
	반환타입 (*변수명)(인자타입들);
	의 형태로 구성된다.
	*/
	void (*pFuncOutput)() = Output;
	int (*pFunc)(int, int) = Sum;

	pFuncOutput = Output;
	pFunc = Sum;
	//pFunc = Output;

	pFuncOutput();
	std::cout << pFunc(10, 20) << std::endl;

	pFuncOutput = OutputTest;
	pFuncOutput();

	//std::cout << "Output Address : " << Output << std::endl;
	std::cout << "Sum Address : " << Sum << std::endl;

	std::cout << "pFuncOutput Value : " << pFuncOutput << std::endl;
	std::cout << "pFunc Value : " << pFunc << std::endl;

	std::cout << "pFuncOutput Address : " << &pFuncOutput << std::endl;
	std::cout << "pFunc Address : " << &pFunc << std::endl;

	SetFunctionPointer(Output);

	Output();
	Output(30);

	OutputNumber();
	OutputNumber(101020);

	//void(*)()
	std::cout << "Factorial : " << Factorial(5) << std::endl;
	std::cout << "Factorial : " << FactorialTail(5) << std::endl;

	int	iNumber = 100;
	ChangeNumber(iNumber);
	ChangeNumber(&iNumber);

	std::cout << "Number : " << iNumber << std::endl;

	/*
	레퍼런스 : C++에서만 제공되는 문법이다.
	C언어에서는 제공이 안된다.
	레퍼런스는 다른 변수를 참조하여 해당 변수의 값을 컨트롤할 수 있다.
	레퍼런스는 반드시 선언과 동시에 참조대상을 지정해야 한다.
	*/
	int	iNumber = 100;
	int	iNumber1 = 900;
	int& iRef = iNumber;

	// 위에서 iRef는 iNumber를 참조하게 되었다.
	// 아래에서 iNumber1을 대입하게 되면 참조를 하는것이 아니라
	// 이미 참조하고 있는 iNumber의 값을 iNumber1의 값으로
	// 대입해주게 된다.
	iRef = iNumber1;

	FPlayer	player;

	SetPlayer(player);

	char	c;
	char& cRef = c;

	FPlayer& playerRef = player;

	std::cout << sizeof(IntRef) << std::endl;
	std::cout << sizeof(CharRef) << std::endl;
	std::cout << sizeof(PlayerRef) << std::endl;

	int* pNumber = &iNumber;

	*pNumber = 3030303030;
	int	iNumber1 = 302;

	// 포인터 타입 앞에 const를 붙일 경우 참조하는 대상의 값을 변경할 수
	// 없다.
	const int* cpNumber = &iNumber;
	//*cpNumber = 9999;
	cpNumber = &iNumber1;

	// 타입 뒤에 const를 붙일 경우 참조하는 대상을 변경할 수 없다.
	int* const pcNumber = &iNumber;
	*pcNumber = 2929;
	//pcNumber = &iNumber1;

	// 얘는 둘의 특성을 모두 가지게 된다.
	const int* const cpcNumber = &iNumber;

	// 숙제 : new와 malloc의 차이에 대해서 알아보자.
	// 동적할당 : new를 이용해서 메모리의 힙 공간에 할당할 수 있다.
	// new는 연산자이다.
	// new를 이용해서 원하는 타입크기만큼 공간을 할당하고 해당 힙공간의
	// 메모리 주소를 반환하게 된다. 
	int* pNew = new int;

	delete	pNew;

	// 동적으로 배열도 생성이 가능하다. 800바이트만큼 힙에 공간을
	// 할당해준다.
	int* pArray = new int[200];

	pArray[2] = 3030;

	delete[]	pArray;

	return 0;
}
