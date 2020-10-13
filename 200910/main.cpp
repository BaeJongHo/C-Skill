
#include <iostream>

void Output()
{
	std::cout << "Output Function" << std::endl;
}

void OutputTest()
{
	std::cout << "OutputTest Function" << std::endl;
}

// ���ڵ� �� �Լ� ������ ����ϴ� ���������� �νĵȴ�.
int Sum(int a, int b)
{
	return a + b;
}

void SetFunctionPointer(void(*pFunc)())
{
	pFunc();
}

/*
�Լ��� �����ε� : C++�� �⺻������ �̸��� ���� ��� ������ �߻��ȴ�.
������ �Լ��� ��쿡�� �̸��� ������ ������ ���� Ȥ�� Ÿ���� �ٸ����
�ٸ��Լ��� �ν��� �ȴ�.
�̸� �Լ��� �����ε� �̶�� �Ѵ�.
��, �Լ��� ��ȯŸ���� �����ε��� ������ ���ش�.
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

// ����Ʈ ���� : �Լ��� ���ڿ� �⺻���� �������ִ°��� ���Ѵ�.
// �� �Լ��� ȣ���Ҷ� ���ڿ� ���� ������ ��� �ش� ������ iNumber��
// �����ȴ�. �׷��� ���ڿ� ���� �ȳ־��ٰ�� iNumber�� 100����
// �����ȴ�.
void OutputNumber(int iNumber = 100)
{
	std::cout << iNumber << std::endl;
}

/*
����Լ� : �Լ������� �ڱ��ڽ��� ȣ�����ִ� �Լ��� ���Ѵ�.
��ġ �ݺ���ó�� ������ ȣ������ �� �ִ� Ư¡�� ���� �Ǵµ�
�߸� ����ϸ� �ش� �Լ����� ���ѷ����� ������ �ȴ�.
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
	�����Ϸ��� �ν��ϴ� �ڵ�
	if(iNumber == 1)
		return 1;
	int iResult = Factorial(iNumber - 1);
	return iNumber * iResult;
	*/
}

/*
������� : ��� ȣ���� ���� �Ŀ� ���� �Լ����� �߰� ������ ���ϵ���
�����ϴ� �����̴�. �̷��� ���ָ� ȣ���� �ݺ��Ǹ鼭 ������ ���϶�
�����Ϸ��� �������� ó���ϵ��� �˰����� �ٲ㼭 ������ ������ �� �ְ�
���ش�.
�����Ϸ� ����ȭ�� ����� �Ѵ�.
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
map�� ���� ��µ� ���� �ؽ����� ���� ����.
unordered_map
stl : list, vector, unordered_map
C++ 11���� ���� ����� �͵�
����Ʈ������ �� �����ϱ�!!
C++ ����ȯ 4���� �� �����ϱ�.
static_cast, const_cast, dynamic_cast, reinterpret_cast

����, function��ü, ���ø� ��������, auto, ���� ǥ����
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

// ���ڸ� ���۷����� �ްԵǸ� �����ڷ� �ޱ� ������ ���ſ� �����͸�
// ���ڷ� �Ѱ��ٶ��� �ս��� ���� �� �ִ�.
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
	�Լ������� ���� ������
	��ȯŸ�� (*������)(����Ÿ�Ե�);
	�� ���·� �����ȴ�.
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
	���۷��� : C++������ �����Ǵ� �����̴�.
	C������ ������ �ȵȴ�.
	���۷����� �ٸ� ������ �����Ͽ� �ش� ������ ���� ��Ʈ���� �� �ִ�.
	���۷����� �ݵ�� ����� ���ÿ� ��������� �����ؾ� �Ѵ�.
	*/
	int	iNumber = 100;
	int	iNumber1 = 900;
	int& iRef = iNumber;

	// ������ iRef�� iNumber�� �����ϰ� �Ǿ���.
	// �Ʒ����� iNumber1�� �����ϰ� �Ǹ� ������ �ϴ°��� �ƴ϶�
	// �̹� �����ϰ� �ִ� iNumber�� ���� iNumber1�� ������
	// �������ְ� �ȴ�.
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

	// ������ Ÿ�� �տ� const�� ���� ��� �����ϴ� ����� ���� ������ ��
	// ����.
	const int* cpNumber = &iNumber;
	//*cpNumber = 9999;
	cpNumber = &iNumber1;

	// Ÿ�� �ڿ� const�� ���� ��� �����ϴ� ����� ������ �� ����.
	int* const pcNumber = &iNumber;
	*pcNumber = 2929;
	//pcNumber = &iNumber1;

	// ��� ���� Ư���� ��� ������ �ȴ�.
	const int* const cpcNumber = &iNumber;

	// ���� : new�� malloc�� ���̿� ���ؼ� �˾ƺ���.
	// �����Ҵ� : new�� �̿��ؼ� �޸��� �� ������ �Ҵ��� �� �ִ�.
	// new�� �������̴�.
	// new�� �̿��ؼ� ���ϴ� Ÿ��ũ�⸸ŭ ������ �Ҵ��ϰ� �ش� ��������
	// �޸� �ּҸ� ��ȯ�ϰ� �ȴ�. 
	int* pNew = new int;

	delete	pNew;

	// �������� �迭�� ������ �����ϴ�. 800����Ʈ��ŭ ���� ������
	// �Ҵ����ش�.
	int* pArray = new int[200];

	pArray[2] = 3030;

	delete[]	pArray;

	return 0;
}
