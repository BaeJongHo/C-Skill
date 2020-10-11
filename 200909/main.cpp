
#include <iostream>

/*
함수 : 원하는 코드를 모아서 기능을 만들어줄 수 있는것을 말한다.
반복되는 코드가 있다면 그것을 함수로 만들어두고 필요한 곳에서
이 함수를 불러서 해당 코드가 동작될 수 있게 만들어줄 수 있다.

반환타입 함수명(인자)
{
}

의 형태로 구성이 된다.

반환타입 : 이 함수가 동작을 수행하고 결과를 반환해줄 변수 타입을
지정한다.

인자는 있을수도 있고 없을수도 있다.
인자는 이 함수를 불러다 사용할때(호출) 이 함수에 넘겨주고자 하는
값이 있다면 변수를 만들어서 사용하게 해준다.

void를 반환타입으로 하면 반환할 값이 없다 라는 의미이다.


*/
/*
C++의 메모리 영역
스택 영역 : 지역변수가 저장되는 공간이다.
데이터 영역 : 전역변수와 정적변수가 저장되는 공간이다.
코드 영역 : 프로그램을 실행하면 실행되는 바이너리 코드가 저장되는
공간이다.
힙 영역 : 동적할당된 메모리가 저장되는 공간이다.
힙은 할당하고 프로그래머가 원할때 해제를 반드시 해주어야 한다.
해제하기 전까지 메모리에 존재하는게 힙영역의 특징이다.
할당하고 해제를 안한상태에서 프로그램을 종료하면 메모리가 그대로 남아서
메모리 릭이 된다.

변수 종류
지역변수 : 특정 코드블럭({}) 안에서 선언된 변수를 말한다.
함수 내부나 혹은 함수의 인자들이 지역변수에 속한다.
지역변수는 해당 코드블럭을 빠져나가면 메모리에서 해제된다.

전역변수 : 코드블럭 외부에 선언하는 변수를 말한다.
전역변수는 선언된 전역변수 아래의 어느 함수에서라도 동일한 변수에
접근이 가능하다.
전역변수는 프로그램이 시작될때 메모리에 할당이 되고 초기화를 안하면
자동으로 0으로 초기화가 된다.
전역변수는 프로그램이 실행되는 동안 메모리에 계속 존재하다가
프로그램이 종료될때 메모리에서 해제된다.

정적변수 : 정적변수는 지역변수처럼 선언을 한다.
지역변수 변수타입 앞에 static을 붙여주면 정적변수가 된다.
static int iNumber;
위처럼 선언을 하게 된다.
정적변수는 코드 실행흐름이 이 변수가 있는곳으로 가게 될 경우 메모리에
생성이 되고 프로그램이 종료될때까지 메모리가 그대로 유지된다.
초기화를 안하면 0으로 초기화가 된다.

함수를 호출하게 되면 해당 함수에서 사용하는 지역변수들이 스택에
만들어지게 되고 함수 호출이 종료되면 사용하던 스택이 정리가 된다.

숙제 : 함수호출규약에 대해서 검색해보고 이론을 외워오세요.


함수 이름은 해당 함수가 올라가있는 코드영역의 메모리 주소이다.
*/
void Output()
{
	std::cout << "Output Function" << std::endl;
}

// 인자도 이 함수 내에서 사용하는 지역변수로 인식된다.
int Sum(int a, int b)
{
	return a + b;
}

enum class TESTFLAG
{
	FLAG1,
	FLAG2,
	FLAG3,
	FLAG4
};

enum class JOB
{
	NONE,
	KNIGHT,
	ARCHER,
	MAGICION
};

struct FPlayer
{
	char	strName[32];
	// enum문 타입으로 변수를 선언하면 4바이트를 차지한다.
	JOB		eJob;
	int		iAttack;
	int		iArmor;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iLevel;
	int		iExp;
	int		iGold;
};

int main()
{
	/*
	모든 변수들은 선언하면 메모리에 공간이 할당되고 할당된 주소가
	생기게 된다.
	포인터 : 모든 변수 타입들은 포인터 타입을 가질 수 있게 된다.
	사용자정의 변수타입들도 포인터 타입을 가질 수 있다.
	포인터도 변수이다.
	일반 변수들이 값을 저장한다면 포인터타입의 변수는 메모리 주소를
	저장한다.

	메모리 주소는 32bit 시스템에서는 4바이트를 차지하게 된다.
	16진수 8자리로 구성되는 것이다.

	64bit 시스템에서는 8바이트를 차지하게 된다.
	16진수 16자리로 구성되는 것이다.

	즉, 포인터 변수는 메모리 주소를 저장하는 변수이므로 타입에
	관계없이 무조건 32bit에서는 4바이트, 64bit에서는 8바이트를
	차지하게 된다.

	int포인터 타입의 변수는 int타입 변수의 주소를 저장할 수 있다.
	float포인터 타입의 변수는 float타입 변수의 주소를 저장할 수 있다.
	이렇게 타입을 맞춰서 메모리 주소를 저장해야 하는데
	void* 라는 것이 있다.
	void는 타입이 없다는 의미이다.

	void*는 지정된 타입이 없으므로 어떤변수타입의 메모리 주소라도
	모두 저장이 가능하다.

	단, 역참조가 안된다.

	역참조란 포인터 변수가 다른 변수의 메모리 주소를 저장하고 있을때
	해당 주소에 접근하여 값을 얻어오거나 변경하는 것을 말한다.
	*/
	int* pNumber;
	float* pNumber1;

	int	iNumber = 999;
	float	fNumber = 3.14f;

	pNumber1 = &fNumber;

	// &iNumber : iNumber 변수의 메모리 주소를 의미한다.
	pNumber = &iNumber;

	*pNumber = 2020;
	*pNumber1 = 56.234f;

	//pNumber1 = &iNumber;

	void* pVoid = &iNumber;
	pVoid = &fNumber;

	//*pVoid = 20.112f;
	*((float*)pVoid) = 1020.33f;

	/*
	이중포인터 : 포인터 변수의 메모리 주소를 저장하는 포인터 변수이다.
	*/
	int** ppNumber = &pNumber;
	**ppNumber = 3030;

	TESTFLAG	eFlag = TESTFLAG::FLAG1;
	TESTFLAG* pFlag = &eFlag;

	*pFlag = TESTFLAG::FLAG4;

	FPlayer	tPlayer = {};

	tPlayer.eJob = JOB::KNIGHT;

	FPlayer* pPlayer = &tPlayer;

	(*pPlayer).eJob = JOB::ARCHER;
	// ->를 하면 위에서 접근하는것과 같이 바로 역참조를 해준다.
	pPlayer->eJob = JOB::MAGICION;

	std::cout << "iNumber Address : " << &iNumber << std::endl;
	std::cout << "fNumber Address : " << &fNumber << std::endl;
	std::cout << "iNumber Value : " << iNumber << std::endl;
	std::cout << "fNumber Value : " << fNumber << std::endl;
	std::cout << "pNumber Value : " << pNumber << std::endl;
	std::cout << "pNumber1 Value : " << pNumber1 << std::endl;
	std::cout << "pNumber Address : " << &pNumber << std::endl;
	std::cout << "pNumber1 Address : " << &pNumber1 << std::endl;

	/*
	포인터와 배열 : 배열명은 포인터다. 배열명은 해당 배열이 시작하는
	메모리 주소이다.

	그렇기 때문에 포인터 변수에 배열의 시작 메모리 주소를 저장하고
	인덱스로 접근하는 것이 가능하다.
	*/
	int		iArray[100] = {};
	int* pArray = iArray;

	iArray[1] = 30;
	pArray[1] = 40;

	std::cout << iArray[1] << std::endl;

	std::cout << "Array Address : " << iArray << std::endl;

	/*
	포인터 연산 : 포인터는 덧셈과 뺄셈 2가지가 제공된다.
	포인터연산은 만약 1을 더할 경우 메모리주소가 100번지일때
	단순하게 101번지가 되는것이 아니다.
	int포인터 라면 100번지에 1을 더했을때 1 * 타입의크기 만큼
	주소가 더해지게 된다.
	즉 100번지에 1을 더하면 1 * 4바이트를 더해서 104번지가
	되는 것이다.
	char포인터 라면 100번지에 1을 더했을때 1 * 1 이 되어서
	101 번지가 된다.
	int포인터 100번지에 2를 더하면 2 * 4 가 되어 108 번지가
	된다.
	*/

	std::cout << "pArray Value : " << pArray << std::endl;
	std::cout << "pArray + 1 Value : " << pArray + 1 << std::endl;
	std::cout << "pArray + 2 Value : " << pArray + 2 << std::endl;

	char	cArray[100] = {};
	char* pCharArr = cArray;

	std::cout << "pCharArr Value : " << (int*)pCharArr << std::endl;
	std::cout << "pCharArr + 1 Value : " << (int*)(pCharArr + 1) << std::endl;
	std::cout << "pCharArr + 2 Value : " << (int*)(pCharArr + 2) << std::endl;

	FPlayer	tPlayerArray[10] = {};
	FPlayer* pPlayerArray = tPlayerArray;

	std::cout << "pPlayerArray Value : " << pPlayerArray << std::endl;
	std::cout << "pPlayerArray + 1 Value : " << pPlayerArray + 1 << std::endl;
	std::cout << "pPlayerArray + 2 Value : " << pPlayerArray + 2 << std::endl;

	// 배열의 인덱스 접근은 포인터 연산이다.
	*(pArray + 1) = 1010;
	pArray[1] = 30389;

	std::cout << iArray[1] << std::endl;

	// 함수는 함수명(인자에 넘겨줄 값); 의 형태로 호출하게 된다.
	// 인자가 없을 경우 함수명(); 의 형태로 호출한다.
	Output();
	int iNumber = Sum(10, 20);

	std::cout << iNumber << std::endl;
	std::cout << Output << std::endl;
	std::cout << Sum << std::endl;

	return 0;
}
