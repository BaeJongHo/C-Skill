
#include <iostream>

/*
�Լ� : ���ϴ� �ڵ带 ��Ƽ� ����� ������� �� �ִ°��� ���Ѵ�.
�ݺ��Ǵ� �ڵ尡 �ִٸ� �װ��� �Լ��� �����ΰ� �ʿ��� ������
�� �Լ��� �ҷ��� �ش� �ڵ尡 ���۵� �� �ְ� ������� �� �ִ�.

��ȯŸ�� �Լ���(����)
{
}

�� ���·� ������ �ȴ�.

��ȯŸ�� : �� �Լ��� ������ �����ϰ� ����� ��ȯ���� ���� Ÿ����
�����Ѵ�.

���ڴ� �������� �ְ� �������� �ִ�.
���ڴ� �� �Լ��� �ҷ��� ����Ҷ�(ȣ��) �� �Լ��� �Ѱ��ְ��� �ϴ�
���� �ִٸ� ������ ���� ����ϰ� ���ش�.

void�� ��ȯŸ������ �ϸ� ��ȯ�� ���� ���� ��� �ǹ��̴�.


*/
/*
C++�� �޸� ����
���� ���� : ���������� ����Ǵ� �����̴�.
������ ���� : ���������� ���������� ����Ǵ� �����̴�.
�ڵ� ���� : ���α׷��� �����ϸ� ����Ǵ� ���̳ʸ� �ڵ尡 ����Ǵ�
�����̴�.
�� ���� : �����Ҵ�� �޸𸮰� ����Ǵ� �����̴�.
���� �Ҵ��ϰ� ���α׷��Ӱ� ���Ҷ� ������ �ݵ�� ���־�� �Ѵ�.
�����ϱ� ������ �޸𸮿� �����ϴ°� �������� Ư¡�̴�.
�Ҵ��ϰ� ������ ���ѻ��¿��� ���α׷��� �����ϸ� �޸𸮰� �״�� ���Ƽ�
�޸� ���� �ȴ�.

���� ����
�������� : Ư�� �ڵ��({}) �ȿ��� ����� ������ ���Ѵ�.
�Լ� ���γ� Ȥ�� �Լ��� ���ڵ��� ���������� ���Ѵ�.
���������� �ش� �ڵ���� ���������� �޸𸮿��� �����ȴ�.

�������� : �ڵ�� �ܺο� �����ϴ� ������ ���Ѵ�.
���������� ����� �������� �Ʒ��� ��� �Լ������� ������ ������
������ �����ϴ�.
���������� ���α׷��� ���۵ɶ� �޸𸮿� �Ҵ��� �ǰ� �ʱ�ȭ�� ���ϸ�
�ڵ����� 0���� �ʱ�ȭ�� �ȴ�.
���������� ���α׷��� ����Ǵ� ���� �޸𸮿� ��� �����ϴٰ�
���α׷��� ����ɶ� �޸𸮿��� �����ȴ�.

�������� : ���������� ��������ó�� ������ �Ѵ�.
�������� ����Ÿ�� �տ� static�� �ٿ��ָ� ���������� �ȴ�.
static int iNumber;
��ó�� ������ �ϰ� �ȴ�.
���������� �ڵ� �����帧�� �� ������ �ִ°����� ���� �� ��� �޸𸮿�
������ �ǰ� ���α׷��� ����ɶ����� �޸𸮰� �״�� �����ȴ�.
�ʱ�ȭ�� ���ϸ� 0���� �ʱ�ȭ�� �ȴ�.

�Լ��� ȣ���ϰ� �Ǹ� �ش� �Լ����� ����ϴ� ������������ ���ÿ�
��������� �ǰ� �Լ� ȣ���� ����Ǹ� ����ϴ� ������ ������ �ȴ�.

���� : �Լ�ȣ��Ծ࿡ ���ؼ� �˻��غ��� �̷��� �ܿ�������.


�Լ� �̸��� �ش� �Լ��� �ö��ִ� �ڵ念���� �޸� �ּ��̴�.
*/
void Output()
{
	std::cout << "Output Function" << std::endl;
}

// ���ڵ� �� �Լ� ������ ����ϴ� ���������� �νĵȴ�.
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
	// enum�� Ÿ������ ������ �����ϸ� 4����Ʈ�� �����Ѵ�.
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
	��� �������� �����ϸ� �޸𸮿� ������ �Ҵ�ǰ� �Ҵ�� �ּҰ�
	����� �ȴ�.
	������ : ��� ���� Ÿ�Ե��� ������ Ÿ���� ���� �� �ְ� �ȴ�.
	��������� ����Ÿ�Ե鵵 ������ Ÿ���� ���� �� �ִ�.
	�����͵� �����̴�.
	�Ϲ� �������� ���� �����Ѵٸ� ������Ÿ���� ������ �޸� �ּҸ�
	�����Ѵ�.

	�޸� �ּҴ� 32bit �ý��ۿ����� 4����Ʈ�� �����ϰ� �ȴ�.
	16���� 8�ڸ��� �����Ǵ� ���̴�.

	64bit �ý��ۿ����� 8����Ʈ�� �����ϰ� �ȴ�.
	16���� 16�ڸ��� �����Ǵ� ���̴�.

	��, ������ ������ �޸� �ּҸ� �����ϴ� �����̹Ƿ� Ÿ�Կ�
	������� ������ 32bit������ 4����Ʈ, 64bit������ 8����Ʈ��
	�����ϰ� �ȴ�.

	int������ Ÿ���� ������ intŸ�� ������ �ּҸ� ������ �� �ִ�.
	float������ Ÿ���� ������ floatŸ�� ������ �ּҸ� ������ �� �ִ�.
	�̷��� Ÿ���� ���缭 �޸� �ּҸ� �����ؾ� �ϴµ�
	void* ��� ���� �ִ�.
	void�� Ÿ���� ���ٴ� �ǹ��̴�.

	void*�� ������ Ÿ���� �����Ƿ� �����Ÿ���� �޸� �ּҶ�
	��� ������ �����ϴ�.

	��, �������� �ȵȴ�.

	�������� ������ ������ �ٸ� ������ �޸� �ּҸ� �����ϰ� ������
	�ش� �ּҿ� �����Ͽ� ���� �����ų� �����ϴ� ���� ���Ѵ�.
	*/
	int* pNumber;
	float* pNumber1;

	int	iNumber = 999;
	float	fNumber = 3.14f;

	pNumber1 = &fNumber;

	// &iNumber : iNumber ������ �޸� �ּҸ� �ǹ��Ѵ�.
	pNumber = &iNumber;

	*pNumber = 2020;
	*pNumber1 = 56.234f;

	//pNumber1 = &iNumber;

	void* pVoid = &iNumber;
	pVoid = &fNumber;

	//*pVoid = 20.112f;
	*((float*)pVoid) = 1020.33f;

	/*
	���������� : ������ ������ �޸� �ּҸ� �����ϴ� ������ �����̴�.
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
	// ->�� �ϸ� ������ �����ϴ°Ͱ� ���� �ٷ� �������� ���ش�.
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
	�����Ϳ� �迭 : �迭���� �����ʹ�. �迭���� �ش� �迭�� �����ϴ�
	�޸� �ּ��̴�.

	�׷��� ������ ������ ������ �迭�� ���� �޸� �ּҸ� �����ϰ�
	�ε����� �����ϴ� ���� �����ϴ�.
	*/
	int		iArray[100] = {};
	int* pArray = iArray;

	iArray[1] = 30;
	pArray[1] = 40;

	std::cout << iArray[1] << std::endl;

	std::cout << "Array Address : " << iArray << std::endl;

	/*
	������ ���� : �����ʹ� ������ ���� 2������ �����ȴ�.
	�����Ϳ����� ���� 1�� ���� ��� �޸��ּҰ� 100�����϶�
	�ܼ��ϰ� 101������ �Ǵ°��� �ƴϴ�.
	int������ ��� 100������ 1�� �������� 1 * Ÿ����ũ�� ��ŭ
	�ּҰ� �������� �ȴ�.
	�� 100������ 1�� ���ϸ� 1 * 4����Ʈ�� ���ؼ� 104������
	�Ǵ� ���̴�.
	char������ ��� 100������ 1�� �������� 1 * 1 �� �Ǿ
	101 ������ �ȴ�.
	int������ 100������ 2�� ���ϸ� 2 * 4 �� �Ǿ� 108 ������
	�ȴ�.
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

	// �迭�� �ε��� ������ ������ �����̴�.
	*(pArray + 1) = 1010;
	pArray[1] = 30389;

	std::cout << iArray[1] << std::endl;

	// �Լ��� �Լ���(���ڿ� �Ѱ��� ��); �� ���·� ȣ���ϰ� �ȴ�.
	// ���ڰ� ���� ��� �Լ���(); �� ���·� ȣ���Ѵ�.
	Output();
	int iNumber = Sum(10, 20);

	std::cout << iNumber << std::endl;
	std::cout << Output << std::endl;
	std::cout << Sum << std::endl;

	return 0;
}
