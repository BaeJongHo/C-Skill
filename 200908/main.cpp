
#include <iostream>
#include <time.h>

#define	TEST	110

/*
����
1 ~ 9 ������ ������ ���� 3���� �ߺ� ���� ���´�.
���� �����ϰ� ���� ���ڰ� 8, 3, 9 �� ���

�� �Ŀ� �������� �ݺ��� �Ѵ�.
����ڴ� 3���� ���ڸ� �Է��Ѵ�.
1, 2, 4 �� �Է��ߴٸ� �ߺ��Ǵ� ���ڰ� �ƿ� �����Ƿ�  Out�� ����Ѵ�.
8, 4, 5 �� �Է��ߴٸ� 8�� ���ڵ� ������ �ִµ� �ڸ����� �����Ƿ� strike�� ó���Ѵ�.
�������� �����Ƿ� 1strike 0ball �� ����Ѵ�.
�̷������� ���ڰ� ������ �ڸ����� ���ٸ� strike�߰� �ڸ��� �ٸ��ٸ� ball�� �߰��ؼ�
ǥ�����ش�.
��� ���ڸ� �ڸ����� ����ٸ� ������ ����ȴ�.
*/

/*
����ü : �ٸ�Ÿ���� ���� �������� �����ִ� ����̴�.
struct ����ü��
{
    ���ϴ� �����鼱��;
};
�� ���·� �����ȴ�.
*/
enum class JOB
{
    NONE,
    KNIGHT,
    ARCHER,
    MAGICION
};

// �𸮾󿡼��� ����ü�� �տ� F�� �ٿ��� ����ϴ��󱸿�!
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


/*
���� 1.
���� for���� Ȱ���ؼ� �Ʒ� ������ ����Ѵ�.
1-1.
*
**
***
****
*****

1-2.
*****
****
***
**
*

1-3.
    *
   **
  ***
 ****
*****

1-4.
*****
 ****
  ***
   **
    *

1-5.
   *
  ***
 *****
*******

1-6.
   *
  ***
 *****
*******
 *****
  ***
   *
*/
int main()
{
    /*
    *
    **
    ***
    ****
    *****
    */
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    /*
    *****
    ****
    ***
    **
    *
    */
    for (int i = 4; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    /*
        *
       **
      ***
     ****
    *****
    */
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 4; j > i; --j)
        {
            std::cout << " ";
        }

        for (int j = 0; j <= i; ++j)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    /*
    *****
     ****
      ***
       **
        *
    */
    for (int i = 4; i >= 0; --i)
    {
        for (int j = 4; j > i; --j)
        {
            std::cout << " ";
        }

        for (int j = 0; j <= i; ++j)
        {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    /*
       *
      ***
     *****
    *******
    */
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 3; j > i; --j)
        {
            std::cout << " ";
        }

        for (int j = 0; j < i * 2 + 1; ++j)
        {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    /*
       *
      ***
     *****
    *******
     *****
      ***
       *
    */
    // i �� 0�϶��� 6�϶� ���ƾ� �Ѵ�.
    // i �� 1�϶��� 5�϶� ���ƾ� �Ѵ�.
    // i �� 2�϶��� 4�϶� ���ƾ� �Ѵ�.
    int iStar = 0;
    for (int i = 0; i < 7; ++i)
    {
        if (i > 3)
            iStar = 6 - i;

        else
            iStar = i;

        for (int j = 3; j > iStar; --j)
        {
            std::cout << " ";
        }

        for (int j = 0; j < iStar * 2 + 1; ++j)
        {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    /*
    �迭 : ���� Ÿ���� ���� �������� �ѹ��� ������ �� �ְ� ���ִ� ����̴�.
    ����Ÿ�� �迭��[����];
    �� ���·� �����ȴ�.
    ������ �ݵ�� ����� �����Ǿ�� �Ѵ�.
    int	iNumber[100];

    ��ó�� �ϸ� iNumber�� 100�� �����Ǵ� ���̴�.
    �� ��ҿ� �����ϱ� ���ؼ� ����ϴ°��� �ε����̴�.
    �ε����� 0 ~ ���� - 1 ���� �̴�.
    100�����
    0 ~ 99 ���� �ε����� �����Ѵ�.
    */
    //int	iNumber[10010010001000000100];
    // �Ʒ�ó�� �ʱ�ȭ�ϸ� 0, 1, 2�� �ε����� 1, 2, 3 ���� ���� �ȴ�.
    // �������� ��� 0���� �ʱ�ȭ�ȴ�.
    int	iNumber[10] = { 1, 2, 3 };

    iNumber[0] = 10;
    iNumber[9] = 1;
    //iNumber[10] = 3030;

    for (int i = 0; i < 10; ++i)
    {
        iNumber[i] = i + 1;
    }

    for (int i = 0; i < 10; ++i)
    {
        std::cout << iNumber[i] << std::endl;
    }

    /*
    �ζ� ���α׷��� ������.
    1 ~ 45 ������ ������ ������ 6���� ���ڸ� ������ �Ѵ�.
    ���� �ߺ��Ǹ� �ȵȴ�.
    */
    system("cls");
    srand((unsigned int)time(0));
    rand();

    int	iLotto[45] = {};

    // ���� ���ϴ� ������ �־�д�.
    for (int i = 0; i < 45; ++i)
    {
        iLotto[i] = i + 1;
    }

    int	iTemp, idx1, idx2;
    for (int i = 0; i < 100; ++i)
    {
        idx1 = rand() % 45;
        idx2 = rand() % 45;

        iTemp = iLotto[idx1];
        iLotto[idx1] = iLotto[idx2];
        iLotto[idx2] = iTemp;
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = i + 1; j < 6; ++j)
        {
            if (iLotto[i] < iLotto[j])
            {
                iTemp = iLotto[i];
                iLotto[i] = iLotto[j];
                iLotto[j] = iTemp;
            }
        }
    }

    for (int i = 0; i < 6; ++i)
    {
        std::cout << iLotto[i] << "\t";
    }

    std::cout << std::endl;

    /*
    ������ �迭 : �迭�� �迭�� �����ؼ� ����ϴ°��̴�.
    int iNumber[5][10];
    �� ���·� �����ȴ�.
    �� �迭 ���� 5 * 10 ���� 50���� �ǰ� 200����Ʈ�� �����Ѵ�.
    */
    int iNumber1[5][10];
    iNumber1[0][1] = 10;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            // i�� j�� ���� �̿��ؼ� 0 ~ 49���� ���� ��������� ���� �ۼ��غ���.
            // ���ι�ȣ * ���ΰ��� + ���ι�ȣ
            // i * 10 + j
            iNumber1[i][j] = i * 10 + j;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            std::cout << iNumber1[i][j] << std::endl;
        }
    }

    return 0;
}
