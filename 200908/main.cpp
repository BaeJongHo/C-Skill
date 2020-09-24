
#include <iostream>
#include <time.h>

#define	TEST	110

/*
숙제
1 ~ 9 사이의 랜덤한 숫자 3개를 중복 없이 얻어온다.
만약 랜덤하게 얻어온 숫자가 8, 3, 9 일 경우

그 후에 무한으로 반복을 한다.
사용자는 3개의 숫자를 입력한다.
1, 2, 4 를 입력했다면 중복되는 숫자가 아예 없으므로  Out을 출력한다.
8, 4, 5 를 입력했다면 8은 숫자도 같은게 있는데 자리까지 같으므로 strike로 처리한다.
나머지는 없으므로 1strike 0ball 을 출력한다.
이런식으로 숫자가 같은데 자리까지 같다면 strike추가 자리가 다르다면 ball로 추가해서
표시해준다.
모든 숫자를 자리까지 맞췄다면 게임이 종료된다.
*/

/*
구조체 : 다른타입의 변수 여러개를 묶어주는 기능이다.
struct 구조체명
{
    원하는 변수들선언;
};
의 형태로 구성된다.
*/
enum class JOB
{
    NONE,
    KNIGHT,
    ARCHER,
    MAGICION
};

// 언리얼에서는 구조체를 앞에 F를 붙여서 사용하더라구요!
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


/*
숙제 1.
이중 for문을 활용해서 아래 모양들을 출력한다.
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
    // i 가 0일때와 6일때 같아야 한다.
    // i 가 1일때와 5일때 같아야 한다.
    // i 가 2일때와 4일때 같아야 한다.
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
    배열 : 같은 타입의 변수 여러개를 한번에 선언할 수 있게 해주는 기능이다.
    변수타입 배열명[개수];
    의 형태로 구성된다.
    개수는 반드시 상수로 지정되어야 한다.
    int	iNumber[100];

    위처럼 하면 iNumber가 100개 생성되는 것이다.
    각 요소에 접근하기 위해서 사용하는것이 인덱스이다.
    인덱스는 0 ~ 개수 - 1 까지 이다.
    100개라면
    0 ~ 99 까지 인덱스가 존재한다.
    */
    //int	iNumber[10010010001000000100];
    // 아래처럼 초기화하면 0, 1, 2번 인덱스에 1, 2, 3 값이 들어가게 된다.
    // 나머지는 모두 0으로 초기화된다.
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
    로또 프로그램을 만들어보자.
    1 ~ 45 사이의 숫자중 랜덤한 6개의 숫자를 얻어오게 한다.
    값이 중복되면 안된다.
    */
    system("cls");
    srand((unsigned int)time(0));
    rand();

    int	iLotto[45] = {};

    // 먼저 원하는 값들을 넣어둔다.
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
    이차원 배열 : 배열에 배열을 선언해서 사용하는것이다.
    int iNumber[5][10];
    의 형태로 구성된다.
    총 배열 수는 5 * 10 으로 50개가 되고 200바이트를 차지한다.
    */
    int iNumber1[5][10];
    iNumber1[0][1] = 10;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            // i와 j의 값을 이용해서 0 ~ 49까지 값이 만들어지게 식을 작성해보자.
            // 세로번호 * 가로개수 + 가로번호
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
