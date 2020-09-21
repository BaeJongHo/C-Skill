#include <iostream>
// time.h : 시간에 관련된 기능을 제공해주는 헤더파일이다.
#include <time.h>

/*
열거체 : 숫자에 이름을 부여해주는 기능이다.
연속으로 나열된 숫자에 이름을 붙여줄때 편하게 사용할 수 있다.
enum 열거체명
{
};
의 형태로 구성된다.
코드블럭 안에 원하는 이름들을 적어주면 된다.

*/

enum class SRP
{
	S = 1,	// 가위
	R,		// 바위
	P,		// 보
	Exit
};

enum JOB
{
	JOB_KNIGHT = 1,	// 0부터 값이 부여된다. 여기는 1로 지정해두어서 1부터 차례로 값이 증가한다.
	JOB_ARCHER,
	JOB_MAGICION
};

enum JOB1
{
	JOB1_KNIGHT = 7,	// 0부터 값이 부여된다.
	JOB1_ARCHER,
	JOB1_MAGICION = 340
};

enum class JOB2
{
	KNIGHT = 1,
	ARCHER,
	MAGICION
};

int main()
{
	// srand를 이용해서 원하는 난수 테이블을 얻어오게 한다.
	// time(0) 을 해주면 1979년 1월 1일 이후 흐른 초가 나오게
	// 된다.
	srand((unsigned int)time(0));
	rand();

	std::cout << (unsigned int)time(0) << std::endl;

	// rand() 를 이용해서 랜덤한 수를 얻어온다.
	std::cout << rand() << std::endl;
	std::cout << rand() << std::endl;

	// 0 ~ 99 사이의 랜덤한 값을 얻어온다.
	// 19192 % 100 = 92
	// 어떤 수를 100으로 나누었을때 나올 수 있는 나머지는
	// 0 ~ 99 사이가 된다.
	//int	iRand = rand() % 100;
	//std::cout << "Rand : " << iRand << std::endl;
	float	fRand = rand() % 10000 / 100.f;
	std::cout << "Rand : " << fRand << std::endl;

	// 100 ~ 199 사이의 랜덤한 수를 구한다.
	std::cout << rand() % 100 + 100 << std::endl;

	// 최소공격력, 최대공격력 사이의 공격력을 구한다.
	int	iMin = 150;
	int	iMax = 1000;

	// 1000 - 150 + 1 = 851
	// 0 ~ 850 사이의 값이 나온다.
	// 0 ~ 850 + 150 = 150 ~ 1000 이 된다.
	std::cout << rand() % (iMax - iMin + 1) + iMin << std::endl;

	if (fRand < 50.f)
		std::cout << "Gold 획득" << std::endl;

	else if (fRand < 50.1f)
		std::cout << "에픽 아이템 획득" << std::endl;

	else if (fRand < 60.1f)
		std::cout << "유니크 아이템 획득" << std::endl;

	else if (fRand < 70.1f)
		std::cout << "매직 아이템 획득" << std::endl;

	else
		std::cout << "일반 아이템 획득" << std::endl;

	/*
	switch 문 : 분기문의 한 종류이다.
	switch(변수)
	{
	case 체크할값:
	원하는코드;
	break; break를 만나면 switch문을 빠져나간다.
	case 체크할값:
	원하는코드;
	break;
	case 체크할값:
	원하는코드;
	break;
	.
	.
	.
	.
	default:	// case에서 체크 안하는 나머지값.else와 같은 역할.
	break;
	}
	*/
	int	iNumber = 5;

	switch (iNumber)
	{
	case 0:	// case에는 무조건 상수만 들어온다. 변수는 못들어온다.
		std::cout << "0번 섹션입니다." << std::endl;
		break;
	case 1:
		std::cout << "1번 섹션입니다." << std::endl;
		break;
	case 2:
		std::cout << "2번 섹션입니다." << std::endl;
		break;
	case 3:
		std::cout << "3번 섹션입니다." << std::endl;
		break;
	default:
		std::cout << "그 외의 섹션입니다." << std::endl;
		break;
	}

	// Player의 직업에 따라 능력치를 설정한다.
	int	iAttack = 0, iArmor = 0, iHP = 0, iMP = 0;
	int	iJob = 0;

	std::cout << "1. 기사" << std::endl;
	std::cout << "2. 궁수" << std::endl;
	std::cout << "3. 마법사" << std::endl;
	std::cout << "직업을 선택하세요 : ";
	std::cin >> iJob;

	switch (iJob)
	{
	case JOB_KNIGHT:
		iAttack = 20;
		iArmor = 30;
		iHP = 500;
		iMP = 100;
		break;
	case JOB_ARCHER:
		iAttack = 30;
		iArmor = 20;
		iHP = 400;
		iMP = 200;
		break;
	case JOB_MAGICION:
		iAttack = 40;
		iArmor = 10;
		iHP = 300;
		iMP = 300;
		break;
	}

	switch ((JOB2)iJob)
	{
	case JOB2::KNIGHT:
		iAttack = 20;
		iArmor = 30;
		iHP = 500;
		iMP = 100;
		break;
	case JOB2::ARCHER:
		iAttack = 30;
		iArmor = 20;
		iHP = 400;
		iMP = 200;
		break;
	case JOB2::MAGICION:
		iAttack = 40;
		iArmor = 10;
		iHP = 300;
		iMP = 300;
		break;
	}

	iJob = JOB_KNIGHT;
	iJob = (int)JOB2::KNIGHT;

	std::cout << "Attack : " << iAttack << std::endl;
	std::cout << "Armor : " << iArmor << std::endl;
	std::cout << "HP : " << iHP << std::endl;
	std::cout << "MP : " << iMP << std::endl;

	/*
	반복문 : 동일한 코드를 반복해서 동작시켜줄때 활용하는 기능이다.
	for, while, do while 3가지가 있다.

	for문 : 반복문의 한 종류이다.
	for(초기값; 조건식; 증감값)
	{
		원하는코드;
	}
	의 형태로 구성이 된다.
	초기값은 이 for문이 시작될때 1번만 동작된다.
	조건식은 매번 반복할때마다 체크하게 되고 조건식이 true일때
	{}(코드블럭) 안의 코드가 동작되고 false라면 for문을 빠져나가게
	된다.
	증감값은 코드가 1번 실행되면 증감값이 동작되고 그 후에 조건이
	체크된다.

	for문의 실행 순서
	초기값 -> 조건식 -> 코드실행 -> 증감값 -> 조건식 -> 코드실행
	-> 증감값 -> 조건식 -> 코드실행 ........ false일때
	for문 종료.

	모든 반복문 공통
	break를 사용하면 반복문을 빠져나오게 된다.
	continue를 사용하면 반복문의 시작점으로 돌아가게 된다.
	*/
	// 초기값에서 아래처럼 변수를 새로 생성하면서 초기화를 하면
	// 해당 변수는 이 for문 안에서만 사용이 가능하다.
	// 먼저 i를 0으로 초기화한다.
	// 0 < 10 true이므로 0을 출력하고 ++i가 실행되어 i는 1이 된다.
	// 1 < 10 true이므로 1을 출력하고 ++i가 실행되어 i는 2가 된다.
	// .
	// .
	// .
	// 9 < 10 true이므로 9를 출력하고 ++i가 실행되어 i는 10이 된다.
	// 10 < 10 false이므로 for문이 종료된다.
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << std::endl;
	}

	// i는 for문 안에서 선언된 변수이므로 바깥에서 사용이
	// 불가능하다.
	//std::cout << i << std::endl;
	for (int i = 0; i < 100; i += 2)
	{
		std::cout << i << std::endl;
	}

	// 아래 코드는 콘솔창을 지워주는 역할을 한다.
	system("cls");
	for (int i = 0; i < 100; ++i)
	{
		// 0 ~ 99 사이의 숫자중 3의 배수만 출력하는 if문을
		// 작성해보자.
		if (i % 3 == 0)
			std::cout << i << std::endl;
	}

	// for문을 이용해서 구구단 2단을 출력해보자.
	// 2 * 1 = 2
	// 2 * 2 = 4
	// .
	// .
	// .
	// 2 * 9 = 18
	// 이렇게 나오고 종료가 되어야 한다.
	for (int i = 1; i <= 9; ++i)
	{
		std::cout << "2 * " << i << " = " << 2 * i << std::endl;
	}

	/*
	이중for문 : for문 안에 또다른 for문이 들어가는 형태이다.
	for(int i = 0; i < 10; ++i)
	{
		for(int j = 0; j < 10; ++j)
		{
		}
	}
	*/
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			std::cout << "i : " << i << " j : " << j << std::endl;
		}
	}

	/*
	구구단 2 ~ 9단까지 이중for문을 활용해서 출력해보자.
	2 * 1 = 2
	2 * 2 = 4
	.
	.
	.
	9 * 9 = 81
	*/
	for (int i = 2; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			std::cout << i << " * " << j << " = " << i * j << std::endl;
		}
	}

	system("cls");
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			// 자신이 소속되어있는 for문을 빠져나간다.
			// j for문을 빠져나가게 된다.
			if (j == 5)
				break;

			std::cout << "i : " << i << " j : " << j << std::endl;
		}
	}

	system("cls");
	for (int i = 0; i < 10; ++i)
	{
		if (i == 5)
			continue;

		for (int j = 0; j < 10; ++j)
		{
			// 자신이 소속되어있는 for의 시작점으로 가게된다..
			// j for문의 시작점으로 가게된다.
			/*if (j == 5)
				continue;*/

			std::cout << "i : " << i << " j : " << j << std::endl;
		}
	}

	/*
	whiel문 : 반복문의 한 종류이다.
	while(조건식)
	{
	}
	조건식이 true일 경우 계속 반복한다. false가 되면 반복문이
	종료된다.
	주로 무한루프를 돌릴때 많이 활용한다.
	while(true)
	{
	}
	*/

	/*
	do while문 : 반복문의 한 종류이다.
	do
	{
	}while(조건식);
	의 형태로 구성된다.
	처음 한번은 무조건 동작이 되고 그 후에 조건식을 체크하여
	false가 되면 빠져나간다.
	*/
	srand((unsigned int)time(0));
	rand();

	// 가위바위보 게임을 만들어본다.
	while (true)
	{
		system("cls");
		std::cout << "1. 가위" << std::endl;
		std::cout << "2. 바위" << std::endl;
		std::cout << "3. 보" << std::endl;
		std::cout << "4. 종료" << std::endl;
		std::cout << "플레이어 선택 : ";
		int	iPlayer = 0;
		std::cin >> iPlayer;

		// 잘못된 범위의 값을 입력했을 경우
		if (iPlayer < (int)SRP::S || iPlayer >(int)SRP::Exit)
			continue;

		else if (iPlayer == (int)SRP::Exit)
			break;

		// 인공지능이 가위 ~ 보 사이를 랜덤하게 선택한다.
		int	iAI = rand() % 3 + 1;
		// switch자동만들기
		// switch + Tab + enum문이름 + Tab + Enter
		switch ((SRP)iAI)
		{
		case SRP::S:
			std::cout << "AI : 가위" << std::endl;
			break;
		case SRP::R:
			std::cout << "AI : 바위" << std::endl;
			break;
		case SRP::P:
			std::cout << "AI : 보" << std::endl;
			break;
		}

		int	iResult = iPlayer - iAI;

		if (iResult == 1 || iResult == -2)
			std::cout << "플레이어 승리" << std::endl;

		else if (iResult == 0)
			std::cout << "비김" << std::endl;

		else
			std::cout << "AI 승리" << std::endl;

		// 아무키나 누를때까지 일시정지 시켜준다.
		system("pause");
	}

	//std::cout << iPlayer << std::endl;

	return 0;
}
