
/*
C++ 로 작성한 프로그램이 실제 실행파일로 만들어지는 과정
컴파일 : C++ 같은 사람이 알아보기 편한 고수준 언어를 컴퓨터 친화적인
저수준 언어로 번역하는 일을 의미한다.
컴파일러 : 컴파일 작업을 해주는 프로그램을 말한다.

실행파일이 만들어지는과정 : 컴파일 -> 빌드 -> 링크 -> 실행파일생성
컴파일러가 컴파일 작업을 해서 저수준 언어로 번역된 언어를
빌드를 해주면서 .obj 라는 파일을 cpp마다 생성해준다.
그런 후에 각 .obj 파일들끼리 기능을 끌어다 사용하는게 있다면 링크를
걸어서 사용할 수 있게 해준 후에 최종적으로 기계어(0, 1 로 구성된 언어)
로 만들어서 실행파일을 구성해준다.

Ctrl + B를 이용해서 컴파일을 하고 빌드를 해준다.
Ctrl + F5를 이용해서 만들어진 실행파일을 실행시켜준다.
*/

// <== 주석을 달아준다. 이 줄을 주석으로 처리해서 프로그램 실행시
// 이 줄은 실행에 영향을 안준다.
/*
이 범위 전체를 주석처리한다.
include : 원하는 헤더파일을 여기에 포함시켜서 해당 헤더파일에서
제공되는 기능을 사용할 수 있게 해준다.
아래에서 포함한 iostream 헤더파일은 C++의 표준 입.출력 기능을
제공하고 있다.
*/
#include <iostream>

/*
C++에서는 반드시 진입점 함수가 필요하다. main으로 이름이 정해져있어서
반드시 여기에 main함수를 만들어주어야 한다.
이 진입점 함수 안에 작성된 코드들만 프로그램 실행시 영향을 주게
된다.
*/
int main()
{
	/*
	C++에서 제공되는 표준 기능들은 보통 std라는 namespace 안에
	구현되어 있다.
	C++은 이름이 같을 경우 구분이 불가능하다. 그렇기 때문에 이름이
	충돌되는 상황을 최대한 막아주어야 한다.
	namespace는 이름이 충돌될 경우를 대비하여 소속을 지정해주는
	기능으로 만들어졌다.
	예를 들어 그냥 A와 1그룹에 포함된 A는 구분이 가능한 것처럼
	namespace 안에 원하는 기능들을 구현하면 해당 namespace 안의
	기능과 바깥에 동일한 이름의 기능은 서로 소속으로 구분이
	가능해지게 되는 것이다.
	*/
	// cout : 콘솔창에 출력을 해주는 기능이다.
	// cout은 std namespace 안에 만들어져 있는 기능이기 때문에
	// std:: 을 붙여서 사용해야 한다.
	// :: <== 범위지정연산자 이다.
	// 한 줄의 끝은 ; 으로 한다.
	// \n : 한줄 개행해준다.
	std::cout << "Test Output\n";
	// endl : 한줄 개행해준다.
	std::cout << "Complete" << std::endl;
	std::cout << "Enter" << std::endl;
	std::cout << "Output " << " Test" << std::endl;

	/*
	변수 : 메모리(램)에 공간을 만들고 해당 공간에 값을 저장해서
	사용할 수 있게 해주는 기능이다.
	용량의 최소단위 : bit
	1bit는 0, 1 둘중 하나의 값을 표현할 수 있다.
	1byte = 8bit
	1kbyte = 1024byte
	1mbyte = 1024kbyte

	0은 false, 0이 아닌 모든 수는 true

	만약 short 타입 변수를 사용한다고 가정했을때
	32768 을 저장했다면 이 값은 short의 표현범위를 벗아나게된다.
	이럴 경우 -32768 로 저장이 된다.
	32769 를 저장했다면 이 값은 short의 표현범위를 벗어나게 된다.
	이럴 경우 -32767 로 저장이 된다.

	변수의 타입
	타입		|	크기		|	표현종류	|	표현범위						|	unsigned		|
	char	|	1byte	|	문자		|	-128 ~ 127					|	0 ~ 255			|
	bool	|	1byte	|	참/거짓	|	false(0) ~ true(1)			|	0 ~ 255			|
	short	|	2byte	|	정수		|	-32768 ~ 32767				|	0 ~ 65535		|
	int		|	4byte	|	정수		|	-2147483648 ~ 2147483647	|	0 ~ 4294967295	|
	__int64	|	8byte	|	정수		|	-9223372036854775808 ~ 9223372036854775807
	float	|	4byte	|	실수		|
	double	|	8byte	|	실수		|
	*/
	// 변수의 이름의 첫번째는 무조건 _ 아니면 알파벳으로 해야한다.
	// 숫자는 변수이름의 첫번째에 올 수 없다.
	// = : 대입연산자. 오른쪽의 값을 왼쪽에 대입해준다.
	// 30, 66 이런 식으로 값을 적는것을 상수라 한다.
	// 상수는 변하지 않는 수이다. 한번 정해지면 그 값을 변경할 수
	// 없는 수를 말한다.
	int	iNumber = 30;
	__int64	iNumber64 = 32389075892375897i64;
	short	sNumber = 32769;
	char	cText = 'A';
	cText = 66;
	bool	bTest = true;
	bTest = false;

	float	fNumber = 3.14f;
	// 아래에서는 암시적인 형변환이 일어나게 된다. float타입을
	// int타입으로 자동으로 형변환한다.
	// 이때 실수를 정수에 넣게되면 소수점이 짤리고 정수부분만
	// 남게되어 3이 저장되게 된다.
	int		iNumberTest = 3.14f;
	double	dNumber = 3.14929293891;

	std::cout << "Number : " << iNumber << std::endl;
	std::cout << "sNumber : " << sNumber << std::endl;
	std::cout << "iNumber64 : " << iNumber64 << std::endl;
	std::cout << "cText : " << cText << std::endl;
	// 형변환 : 여기에서 잠깐 다른 타입으로 인식을 시켜주는 것을
	// 말한다.
	std::cout << "cText Value : " << (int)cText << std::endl;
	std::cout << "bTest : " << bTest << std::endl;

	std::cout << "Input Number : ";
	// cin에서 입력받은 값을 iNumber에 넣어준다.
	std::cin >> iNumber;
	std::cout << iNumber << std::endl;

	std::cout << "Input Number : ";
	// cin에서 입력받은 값을 fNumber에 넣어준다.
	std::cin >> fNumber;
	std::cout << fNumber << std::endl;

	std::cout << "Input Number : ";
	// cin에서 입력받은 값을 cText에 넣어준다.
	std::cin >> cText;
	std::cout << cText << std::endl;

	/*
	사칙연산자 : +, -, *, /, %(나머지 연산자)
	나머지연산자는 A를 B로 나누었을때 몫을 제외한 나머지를 구해준다.
	10 % 3 = 1 이 되는 것이다.
	어떤 수를 2로 나누었을때 나머지가 0이면 짝수이다.
	*/
	std::cout << "10 % 3 = " << (10 % 3) << std::endl;

	/*
	관계연산자 : <, >, <=, >=, ==(같다), !=(다르다)
	관계연산자는 값 대 값을 연산하여 참/거짓으로 결과가 나오게된다.
	10 < 20 = true
	10 > 20 = false
	*/
	std::cout << "10 < 20 = " << (10 < 20) << std::endl;
	std::cout << "10 > 20 = " << (10 > 20) << std::endl;
	std::cout << "10 <= 20 = " << (10 <= 20) << std::endl;
	std::cout << "10 >= 20 = " << (10 >= 20) << std::endl;
	std::cout << "10 == 20 = " << (10 == 20) << std::endl;
	std::cout << "10 != 20 = " << (10 != 20) << std::endl;

	/*
	OR는 shift + \ 2개이다.
	논리연산자 : AND(&&), OR(||), NOT(!)
	논리연산자는 참/거짓 대 참/거짓을 연산하여 결과로 참/거짓이
	나오게 된다.
	A		B		AND		OR
	false	false	false	false
	false	true	false	true
	true	false	false	true
	true	true	true	true

	AND는 둘다 true일때 true이고 아니면 false다.
	OR는 둘중 하나라도 true일때 true이고 아니면 false다.
	A		NOT
	false	true
	true	false
	*/
	std::cout << "false && false = " << (false && false) << std::endl;
	std::cout << "true && false = " << (true && false) << std::endl;
	std::cout << "false && true = " << (false && true) << std::endl;
	std::cout << "true && true = " << (true && true) << std::endl;

	std::cout << "false || false = " << (false || false) << std::endl;
	std::cout << "true || false = " << (true || false) << std::endl;
	std::cout << "false || true = " << (false || true) << std::endl;
	std::cout << "true || true = " << (true || true) << std::endl;

	std::cout << "!false = " << !false << std::endl;
	std::cout << "!true = " << !true << std::endl;

	return 0;
}