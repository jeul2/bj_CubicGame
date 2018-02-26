/*
1. 입력 ( 1부터 N칸까지 N개로 이루어진 직선형보드판, 주사위 횟수)

조건1: 1번 칸과 N번 칸에 써있는 지시사항은 항상 0이다. 
조건2: 또, 항상 주사위를 M번 이하로 던져서 도착할 수 있다.  
조건3: 또, 1보다 작은 칸으로 이동하라는 지시가 있는 경우도 없다.

2. 명령 ( 주사위 수만큼 이동, 해당 칸에 지시사항이 있으면 따름. 이후는 따르지않음)

3. N에 도착할시 주사위 횟수 출력.
-------------------------
g_ar [N + 1] 배열 // 0은 사용안함, wc 1001
g_ar [M] 배열 //wc 1000 -> 큐 사용

1. 입력을 다 받음(주사위 횟수받으면서도 진행가능)
2. 주사위를 던지면, 해당 위치를 출력하는 함수.
3. 해당 위치의 값이 0이 아니면 2.를 호출하는 하고, 카운트 하는 함수.
	0이면 카운트만하는 함수.
4. 현재 위치가 도착점인지 체크하는 함수.

반복문으로
제한 : 전역변수 사용금지. 동적할당 사용.new delete 이용.

결과1. 런타임에러 : 왜? M이 맥스를 초과할때 잘못된 접근. X
					왜? N칸에 도착했을 때와 그 칸을 넘는 경우도 도착한 것이다. 문제 잘 안읽었음? ->wc 999칸에 +999가 적힌경우. O

런타임에러는 동적할당을 사용함으로써 발생된 문제.
Q. 동적할당 -> 가상메모리의 힙영역. 지역변수 -> 가상메모리의 스택영역.이라고 알고있다.
	그렇다면 []로 사이즈를 초과하게 접근했으니 동적할당은 오류가 뜬다.
	지역변수로 선언했을때는?오류가 안뜰까?
	생각대로라면 안 뜰 것같다. 안뜬다면 왜 이런 차이가 날까?


*/
#include <stdio.h>

void fnRollCubic(const int *pSrcBoard, int nCurPosition, int nValue, int *pResPosition);
int fnIsOrderChk(const int *pSrcBoard, int nCurPosition);
int fnIsNotEndPoint(int nCurPosition, int nBoardSize);

int main()
{
	int nData(0);
	int nBoardSize(0); int nCubicMaxCount(0);
	int *parBoard(nullptr);
	int *parCubic(nullptr);

	int nCurrentIndex(0);
	int nCurrentCubicValue(0);
	int nCountOfCubic(0);
	
	//
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &nBoardSize, &nCubicMaxCount);

	parBoard = new int[nBoardSize + 1 + 999]{};
	parCubic = new int[nCubicMaxCount] {};

	for (int i = 1; i <= nBoardSize; ++i)
	{
		scanf("%d", &nData);
		parBoard[i] = nData;
	}
	for (int i = 0; i < nCubicMaxCount; ++i)
	{
		scanf("%d", &nData);
		parCubic[i] = nData;
	}
	////

	nCurrentIndex = 1; nCountOfCubic = 0;
	nCurrentCubicValue = parCubic[nCountOfCubic];
	while (fnIsNotEndPoint(nCurrentIndex, nBoardSize))
	{
		fnRollCubic(parBoard, nCurrentIndex, nCurrentCubicValue, &nCurrentIndex);

		++nCountOfCubic;
		if (nCountOfCubic < nCubicMaxCount)//
			nCurrentCubicValue = parCubic[nCountOfCubic];
	}

	printf("%d\n", nCountOfCubic);

	////
	delete[] parBoard;
	parBoard = nullptr;
	delete[] parCubic;
	parCubic = nullptr;
	return 0;
}

void fnRollCubic(const int * pSrcBoard, int nCurPosition, int nValue, int * pResPosition)
{
	int nIndex(0);
	int nTempValue(0);

	nIndex = nCurPosition + nValue;
	if (fnIsOrderChk(pSrcBoard, nIndex))
	{
		nTempValue = pSrcBoard[nIndex];
		nIndex += nTempValue;
	}

	*pResPosition = nIndex;
}

int fnIsOrderChk(const int * pSrcBoard, int nCurPosition)
{
	if (pSrcBoard[nCurPosition] == 0)
		return 0;
	else
		return 1;
}

int fnIsNotEndPoint(int nCurPosition, int nBoardSize)
{
	if (nCurPosition < nBoardSize)
		return 1;
	else
		return 0;
}
