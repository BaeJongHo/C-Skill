
#include <iostream>

int main()
{
	/*
	진수 : 2진수, 8진수, 10진수, 16진수 4가지가 있다.
	2진수 : 0, 1 둘중 하나로 표현되는 수이다.
	8진수 : 0 ~ 7 중 하나로 표현되는 수이다.
	10진수 : 0 ~ 9 중 하나로 표현되는 수이다.
	16진수 : 0 ~ 15 중 하나로 표현되는 수이다.
	16진수는 10 ~ 15를 a ~ f로 표현한다.
	110 은 1 10 인지 11 0 인지 아니면 1 1 0 인지 구분이 애매하다.
	그러므로 10 ~ 15는 알파벳으로 표현하여 확실하게 처리해주어야 한다.
	16진수는 앞에 0x를 붙여서 표현한다.
	0x110	1 1 0 이다.
	0x1a	1 10
	0xb0	11 0

	10진수 87을 2진수, 16진수로 변환해보자.
	2진수로 변환할때는 더이상 나눌 수 없을때까지 2로 계속 나누어준다.
	그러면서 나머지 값들을 적어둔다.
	87 / 2 = 43 -- 1
	43 / 2 = 21 -- 1
	21 / 2 = 10 -- 1
	10 / 2 = 5 --- 0
	5 / 2 = 2 ---- 1
	2 / 2 = 1 ---- 0

	몫이 1이 나오면 더이상 2로 나눌 수 없으므로 멈춰준다.
	마지막 몫 1부터 반대로 읽어준다.
	1010111 이 된다.

	2진수를 10진수로 변환할때는 가장 오른쪽부터 1, 2, 4, 8... 이런식으로 2의 배수로 증가하여
	값을 부여해둔다.
	1  0  1  0 1 1 1
	64 32 16 8 4 2 1
	1인 부분의 값을 모두 더해준다.
	64 + 16 + 4 + 2 + 1 = 87

	16진수로 변환을 할때는 2진수로 변환을 한 상태에서 변환하는것이 편하다.
	1010111 을 16진수로 변환해보자.
	먼저 오른쪽 끝부터 4자리씩 끊어준다.
	2진수 4자리가 16진수 1자리가 된다.
	101 / 0111 이 된다.
	오른쪽 끝부터 1, 2, 4, 8 의 값을 부여해준다.
	1 0 1 / 0 1 1 1
	4 2 1 / 8 4 2 1

	1인 부분의 값을 모두 더해준다.
	0x57 이 된다.

	16진수를 2진수로 바꿀때는 16진수 각 자리별로 2로 나누어서 더이상 나눌 수 없을때까지 나눈다.
	5 / 2 = 2 -- 1
	2 / 2 = 1 -- 0
	101

	7 / 2 = 3 -- 1
	3 / 2 = 1 -- 1
	0111이 된다.

	1010111 이 된다.

	115를 2진수, 16진수로 변환해보자.
	1110011
	0x73

	비트단위 논리연산자 : AND(&), OR(|), NOT(~), XOR(^)
	값 대 값을 연산하여 결과로 값이 나오게 된다.
	연산을할때 먼저 값을 2진수로 변환한 후에 연산을 진행하게 된다.
	2진수 각 자리별로 논리연산을 수행한다.
	87 & 115 =
	  1010111
	& 1110011
	  1010011

	  83이 된다.

	  1010111
	| 1110011
	  1110111
	  64 + 32 + 16 + 4 + 2 + 1 = 119

	A		B		XOR
	false	false	false
	false	true	true
	true	false	true
	true	true	false

	XOR는 두개가 같으면 false 다르면 true가 나온다.

	  1010111
	^ 1110011
	  0100100
	  36이 된다.
	*/
	std::cout << "87 & 115 = " << (87 & 115) << std::endl;
	std::cout << "87 | 115 = " << (87 | 115) << std::endl;
	std::cout << "87 ^ 115 = " << (87 ^ 115) << std::endl;

	// 변수 타입 앞에 const를 붙이면 상수가 된다.
	// 상수는 변하지 않는 수이다.
	// 상수는 선언과 동시에 값을 무조건 지정해주어야 하고 그 이후에는 값을 변경할 수 없다.
	const int	iAttack = 0x1;		//     1
	const int	iArmor = 0x2;		//    10
	const int	iHP = 0x4;			//   100
	const int	iMP = 0x8;			//  1000
	const int	iCritical = 0x10;	// 10000

	int	iBuf = 0;

	// 0 | 1 = 1
	iBuf = iBuf | iAttack;

	// 001 | 100 = 101
	iBuf = iBuf | iHP;

	// 00101 | 10000 = 10101
	iBuf = iBuf | iCritical;

	// 10101 ^ 00100 = 10001
	iBuf = iBuf ^ iHP;

	// 10001 ^ 00100 = 10101
	iBuf = iBuf ^ iHP;

	std::cout << "Attack = " << (iBuf & iAttack) << std::endl;
	std::cout << "Armor = " << (iBuf & iArmor) << std::endl;
	std::cout << "HP = " << (iBuf & iHP) << std::endl;
	std::cout << "MP = " << (iBuf & iMP) << std::endl;
	std::cout << "Critical = " << (iBuf & iCritical) << std::endl;

	// 결론 : OR연산으로 추가하고 AND연산으로 확인한다.
	// XOR연산으로 버프가 없을경우 추가하고 있을 경우 제거할수도 있다.

	/*
	쉬프트연산자 : <<, >> 2가지가 있다.
	값 대 값을 연산하여 결과로 값이 나오게 된다.
	30 << 2 =
	먼저 20을 2진수로 변환한다.
	11110
	위 연산은 뒤에 0을 2개 붙이라는 것이다.
	1111000 이 된다.
	120이 된다.

	30 << 3 =
	11110000 이 된다.
	16 + 32 + 64 + 128 = 240

	30 << 2 를 했을때 결과는 120이 나오는데 이는 30 * 2의 2승의 결과와 같다.
	30 << 3 을 했을때 결과는 240이 나오는데 이는 30 * 2의 3승의 결과와 같다.
	<< 방향의 쉬프트 연산자는 2의 n승을 곱해주는 결과가 된다.
	그래서 빠른 곱하기 라고도 부른다.

	30 >> 2
	11110
	오른쪽 2개를 지우는것과 같다.
	111 이 된다.
	7이다.

	30 >> 3
	오른쪽 3개를 지우는것과 같다.
	11 이 된다.
	3이다.

	30 / 4 = 7 이 된다. 2의 2승으로 나눈것과 같다.
	30 / 8 = 3 이 된다. 2의 3승으로 나눈것과 같다.
	그래서 빠른 나누기라고도 부른다.
	*/
	std::cout << "30 << 2 = " << (30 << 2) << std::endl;
	std::cout << "30 << 3 = " << (30 << 3) << std::endl;
	std::cout << "30 >> 2 = " << (30 >> 2) << std::endl;
	std::cout << "30 >> 3 = " << (30 >> 3) << std::endl;

	// 32bit Color를 사용하면 a, r, g, b 로 구성이 된다.
	// a, r, g, b는 각각 1byte를 차지하게 되며 0 ~ 255 사이의 값으로 표현이 된다.
	// a, r, g, b를 합쳐서 4바이트 변수 하나에 픽셀의 색상을 표현하게 된다.
	// 변수 타입 앞에 unsigned를 붙여주면 부호가 없는 변수가 된다.
	// 즉, -값을 +값으로 변환하게 되는것이다.
	unsigned int	iColor = 0;
	unsigned char	a = 200;
	unsigned char	r = 150;
	unsigned char	g = 97;
	unsigned char	b = 210;

	iColor = a;
	//iColor = iColor << 8;
	iColor <<= 8;

	iColor = iColor | r;
	iColor = iColor << 8;

	iColor = iColor | g;
	iColor = iColor << 8;

	iColor = iColor | b;

	std::cout << "Color : " << iColor << std::endl;

	// f : 15기 때문에 2진수로 1111 이 나오게된다. 11111111과 & 연산을 하는것이다.
	std::cout << "b : " << (iColor & 0x000000ff) << std::endl;
	std::cout << "g : " << (iColor >> 8 & 0x000000ff) << std::endl;
	std::cout << "r : " << (iColor >> 16 & 0x000000ff) << std::endl;
	std::cout << "a : " << (iColor >> 24 & 0x000000ff) << std::endl;

	/*
	증감연산자 : ++, -- 2가지가 있다.
	++는 1 증가시켜준다.
	--는 1 감소시켜준다.

	증감연산자는 연산자를 변수의 앞에 붙여주느냐 뒤에 붙여주느냐에 따라 전치, 후치 연산으로
	나뉘게 된다.
	*/
	int	iNumber = 100;
	++iNumber;

	std::cout << iNumber << std::endl;
	std::cout << ++iNumber << std::endl;

	// 아래에서 후치연산을 하게되면 먼저 iNumber의 값을 출력한 후에 값을 증가시킨다.
	std::cout << iNumber++ << std::endl;
	std::cout << iNumber << std::endl;

	--iNumber;
	std::cout << iNumber << std::endl;
	std::cout << --iNumber << std::endl;
	std::cout << iNumber-- << std::endl;
	std::cout << iNumber << std::endl;

	/*
	연산자 축약형 : +=, -= 등 모든 연산자들은 줄여서 사용이 가능하다.
	int		iNumber = 100;
	iNumber += 10; 을 하게 될 경우
	iNumber = iNumber + 10; 이 된다.
	즉, iNumber의 값을 10 증가시켜주는 것이다.
	*/

	/*
	if문 : 조건을 체크할때 사용하는 기능이다.
	if(조건식)
	{
	}(코드블럭) 의 형태로 구성이 된다.

	조건식이 true일 경우 코드블럭 사이의 코드가 동작이 되고 false일 경우 무시된다.
	*/
	if (false)
	{
		std::cout << "if문의 조건이 true입니다." << std::endl;
	}

	// if문 안의 코드가 1줄일 경우 코드블럭을 생략할 수 있다.
	if ((iBuf & iAttack) == iAttack)
		std::cout << "Attack 버프 활성화" << std::endl;

	if (iBuf & iArmor)
		std::cout << "Armor 버프 활성화" << std::endl;

	if (iBuf & iHP)
		std::cout << "HP 버프 활성화" << std::endl;

	if (iBuf & iMP)
		std::cout << "MP 버프 활성화" << std::endl;

	if (iBuf & iCritical)
		std::cout << "Critical 버프 활성화" << std::endl;

	/*
	else : if문과 쌍으로 사용할 수 있다.
	if문 1개당 1개의 else문이 올 수 있다.
	else는 독립적으로 사용이 불가능하다.
	else
	{
	} 의 형태로 구성이 된다.
	조건식이 없다. 그 말은 조건식을 체크할 필요가 없다는 것이다.
	else는 if문의 조건이 false일 경우 동작되는 구문이다.
	*/
	if (true)
		std::cout << "if  true" << std::endl;

	else
		std::cout << "if  false" << std::endl;

	/*
	else if : if문 아래에 올 수 있다. else와는 다르게 몇개든 만들어서 사용이 가능하다.
	else if도 독립적으로 사용이 불가능하다.
	else if(조건식)
	{
	} 의 형태로 구성된다.
	*/
	int	iKor = 0, iEng = 0, iMath = 0, iTotal = 0;
	// 소수점자리가 없는 float일 경우 .f 로 소수점 자리에 0을 생략할 수 있다.
	float	fAvg = 0.f;

	std::cout << "국어 : ";
	std::cin >> iKor;

	std::cout << "영어 : ";
	std::cin >> iEng;

	std::cout << "수학 : ";
	std::cin >> iMath;

	iTotal = iKor + iEng + iMath;
	// 나눗셈 연산시에 정수 / 정수를 하게 되면 소수점자리가 짤리고 정수만 나오게된다.
	// 실수로 결과를 얻고싶다면 둘중 하나는 반드시 실수로 만들어서 연산해야 한다.
	fAvg = iTotal / 3.f;

	std::cout << "평균 : " << fAvg << std::endl;

	// 90이상 A, 80 ~ 90 B, 70 ~ 80 C, 그 이하는 F
	if (fAvg >= 90.f)
		std::cout << "학점 : A" << std::endl;

	else if (fAvg >= 80.f && fAvg < 90.f)
		std::cout << "학점 : B" << std::endl;

	else if (fAvg >= 70.f)
		std::cout << "학점 : C" << std::endl;

	else
		std::cout << "학점 : F" << std::endl;

	return 0;
}
