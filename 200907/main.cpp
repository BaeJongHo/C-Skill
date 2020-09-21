#include <iostream>
// time.h : �ð��� ���õ� ����� �������ִ� ��������̴�.
#include <time.h>

/*
����ü : ���ڿ� �̸��� �ο����ִ� ����̴�.
�������� ������ ���ڿ� �̸��� �ٿ��ٶ� ���ϰ� ����� �� �ִ�.
enum ����ü��
{
};
�� ���·� �����ȴ�.
�ڵ�� �ȿ� ���ϴ� �̸����� �����ָ� �ȴ�.

*/

enum class SRP
{
	S = 1,	// ����
	R,		// ����
	P,		// ��
	Exit
};

enum JOB
{
	JOB_KNIGHT = 1,	// 0���� ���� �ο��ȴ�. ����� 1�� �����صξ 1���� ���ʷ� ���� �����Ѵ�.
	JOB_ARCHER,
	JOB_MAGICION
};

enum JOB1
{
	JOB1_KNIGHT = 7,	// 0���� ���� �ο��ȴ�.
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
	// srand�� �̿��ؼ� ���ϴ� ���� ���̺��� ������ �Ѵ�.
	// time(0) �� ���ָ� 1979�� 1�� 1�� ���� �帥 �ʰ� ������
	// �ȴ�.
	srand((unsigned int)time(0));
	rand();

	std::cout << (unsigned int)time(0) << std::endl;

	// rand() �� �̿��ؼ� ������ ���� ���´�.
	std::cout << rand() << std::endl;
	std::cout << rand() << std::endl;

	// 0 ~ 99 ������ ������ ���� ���´�.
	// 19192 % 100 = 92
	// � ���� 100���� ���������� ���� �� �ִ� ��������
	// 0 ~ 99 ���̰� �ȴ�.
	//int	iRand = rand() % 100;
	//std::cout << "Rand : " << iRand << std::endl;
	float	fRand = rand() % 10000 / 100.f;
	std::cout << "Rand : " << fRand << std::endl;

	// 100 ~ 199 ������ ������ ���� ���Ѵ�.
	std::cout << rand() % 100 + 100 << std::endl;

	// �ּҰ��ݷ�, �ִ���ݷ� ������ ���ݷ��� ���Ѵ�.
	int	iMin = 150;
	int	iMax = 1000;

	// 1000 - 150 + 1 = 851
	// 0 ~ 850 ������ ���� ���´�.
	// 0 ~ 850 + 150 = 150 ~ 1000 �� �ȴ�.
	std::cout << rand() % (iMax - iMin + 1) + iMin << std::endl;

	if (fRand < 50.f)
		std::cout << "Gold ȹ��" << std::endl;

	else if (fRand < 50.1f)
		std::cout << "���� ������ ȹ��" << std::endl;

	else if (fRand < 60.1f)
		std::cout << "����ũ ������ ȹ��" << std::endl;

	else if (fRand < 70.1f)
		std::cout << "���� ������ ȹ��" << std::endl;

	else
		std::cout << "�Ϲ� ������ ȹ��" << std::endl;

	/*
	switch �� : �б⹮�� �� �����̴�.
	switch(����)
	{
	case üũ�Ұ�:
	���ϴ��ڵ�;
	break; break�� ������ switch���� ����������.
	case üũ�Ұ�:
	���ϴ��ڵ�;
	break;
	case üũ�Ұ�:
	���ϴ��ڵ�;
	break;
	.
	.
	.
	.
	default:	// case���� üũ ���ϴ� ��������.else�� ���� ����.
	break;
	}
	*/
	int	iNumber = 5;

	switch (iNumber)
	{
	case 0:	// case���� ������ ����� ���´�. ������ �����´�.
		std::cout << "0�� �����Դϴ�." << std::endl;
		break;
	case 1:
		std::cout << "1�� �����Դϴ�." << std::endl;
		break;
	case 2:
		std::cout << "2�� �����Դϴ�." << std::endl;
		break;
	case 3:
		std::cout << "3�� �����Դϴ�." << std::endl;
		break;
	default:
		std::cout << "�� ���� �����Դϴ�." << std::endl;
		break;
	}

	// Player�� ������ ���� �ɷ�ġ�� �����Ѵ�.
	int	iAttack = 0, iArmor = 0, iHP = 0, iMP = 0;
	int	iJob = 0;

	std::cout << "1. ���" << std::endl;
	std::cout << "2. �ü�" << std::endl;
	std::cout << "3. ������" << std::endl;
	std::cout << "������ �����ϼ��� : ";
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
	�ݺ��� : ������ �ڵ带 �ݺ��ؼ� ���۽����ٶ� Ȱ���ϴ� ����̴�.
	for, while, do while 3������ �ִ�.

	for�� : �ݺ����� �� �����̴�.
	for(�ʱⰪ; ���ǽ�; ������)
	{
		���ϴ��ڵ�;
	}
	�� ���·� ������ �ȴ�.
	�ʱⰪ�� �� for���� ���۵ɶ� 1���� ���۵ȴ�.
	���ǽ��� �Ź� �ݺ��Ҷ����� üũ�ϰ� �ǰ� ���ǽ��� true�϶�
	{}(�ڵ��) ���� �ڵ尡 ���۵ǰ� false��� for���� ����������
	�ȴ�.
	�������� �ڵ尡 1�� ����Ǹ� �������� ���۵ǰ� �� �Ŀ� ������
	üũ�ȴ�.

	for���� ���� ����
	�ʱⰪ -> ���ǽ� -> �ڵ���� -> ������ -> ���ǽ� -> �ڵ����
	-> ������ -> ���ǽ� -> �ڵ���� ........ false�϶�
	for�� ����.

	��� �ݺ��� ����
	break�� ����ϸ� �ݺ����� ���������� �ȴ�.
	continue�� ����ϸ� �ݺ����� ���������� ���ư��� �ȴ�.
	*/
	// �ʱⰪ���� �Ʒ�ó�� ������ ���� �����ϸ鼭 �ʱ�ȭ�� �ϸ�
	// �ش� ������ �� for�� �ȿ����� ����� �����ϴ�.
	// ���� i�� 0���� �ʱ�ȭ�Ѵ�.
	// 0 < 10 true�̹Ƿ� 0�� ����ϰ� ++i�� ����Ǿ� i�� 1�� �ȴ�.
	// 1 < 10 true�̹Ƿ� 1�� ����ϰ� ++i�� ����Ǿ� i�� 2�� �ȴ�.
	// .
	// .
	// .
	// 9 < 10 true�̹Ƿ� 9�� ����ϰ� ++i�� ����Ǿ� i�� 10�� �ȴ�.
	// 10 < 10 false�̹Ƿ� for���� ����ȴ�.
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << std::endl;
	}

	// i�� for�� �ȿ��� ����� �����̹Ƿ� �ٱ����� �����
	// �Ұ����ϴ�.
	//std::cout << i << std::endl;
	for (int i = 0; i < 100; i += 2)
	{
		std::cout << i << std::endl;
	}

	// �Ʒ� �ڵ�� �ܼ�â�� �����ִ� ������ �Ѵ�.
	system("cls");
	for (int i = 0; i < 100; ++i)
	{
		// 0 ~ 99 ������ ������ 3�� ����� ����ϴ� if����
		// �ۼ��غ���.
		if (i % 3 == 0)
			std::cout << i << std::endl;
	}

	// for���� �̿��ؼ� ������ 2���� ����غ���.
	// 2 * 1 = 2
	// 2 * 2 = 4
	// .
	// .
	// .
	// 2 * 9 = 18
	// �̷��� ������ ���ᰡ �Ǿ�� �Ѵ�.
	for (int i = 1; i <= 9; ++i)
	{
		std::cout << "2 * " << i << " = " << 2 * i << std::endl;
	}

	/*
	����for�� : for�� �ȿ� �Ǵٸ� for���� ���� �����̴�.
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
	������ 2 ~ 9�ܱ��� ����for���� Ȱ���ؼ� ����غ���.
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
			// �ڽ��� �ҼӵǾ��ִ� for���� ����������.
			// j for���� ���������� �ȴ�.
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
			// �ڽ��� �ҼӵǾ��ִ� for�� ���������� ���Եȴ�..
			// j for���� ���������� ���Եȴ�.
			/*if (j == 5)
				continue;*/

			std::cout << "i : " << i << " j : " << j << std::endl;
		}
	}

	/*
	whiel�� : �ݺ����� �� �����̴�.
	while(���ǽ�)
	{
	}
	���ǽ��� true�� ��� ��� �ݺ��Ѵ�. false�� �Ǹ� �ݺ�����
	����ȴ�.
	�ַ� ���ѷ����� ������ ���� Ȱ���Ѵ�.
	while(true)
	{
	}
	*/

	/*
	do while�� : �ݺ����� �� �����̴�.
	do
	{
	}while(���ǽ�);
	�� ���·� �����ȴ�.
	ó�� �ѹ��� ������ ������ �ǰ� �� �Ŀ� ���ǽ��� üũ�Ͽ�
	false�� �Ǹ� ����������.
	*/
	srand((unsigned int)time(0));
	rand();

	// ���������� ������ ������.
	while (true)
	{
		system("cls");
		std::cout << "1. ����" << std::endl;
		std::cout << "2. ����" << std::endl;
		std::cout << "3. ��" << std::endl;
		std::cout << "4. ����" << std::endl;
		std::cout << "�÷��̾� ���� : ";
		int	iPlayer = 0;
		std::cin >> iPlayer;

		// �߸��� ������ ���� �Է����� ���
		if (iPlayer < (int)SRP::S || iPlayer >(int)SRP::Exit)
			continue;

		else if (iPlayer == (int)SRP::Exit)
			break;

		// �ΰ������� ���� ~ �� ���̸� �����ϰ� �����Ѵ�.
		int	iAI = rand() % 3 + 1;
		// switch�ڵ������
		// switch + Tab + enum���̸� + Tab + Enter
		switch ((SRP)iAI)
		{
		case SRP::S:
			std::cout << "AI : ����" << std::endl;
			break;
		case SRP::R:
			std::cout << "AI : ����" << std::endl;
			break;
		case SRP::P:
			std::cout << "AI : ��" << std::endl;
			break;
		}

		int	iResult = iPlayer - iAI;

		if (iResult == 1 || iResult == -2)
			std::cout << "�÷��̾� �¸�" << std::endl;

		else if (iResult == 0)
			std::cout << "���" << std::endl;

		else
			std::cout << "AI �¸�" << std::endl;

		// �ƹ�Ű�� ���������� �Ͻ����� �����ش�.
		system("pause");
	}

	//std::cout << iPlayer << std::endl;

	return 0;
}
