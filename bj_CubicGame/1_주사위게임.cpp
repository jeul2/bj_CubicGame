/*
1. �Է� ( 1���� Nĭ���� N���� �̷���� ������������, �ֻ��� Ƚ��)

����1: 1�� ĭ�� N�� ĭ�� ���ִ� ���û����� �׻� 0�̴�. 
����2: ��, �׻� �ֻ����� M�� ���Ϸ� ������ ������ �� �ִ�.  
����3: ��, 1���� ���� ĭ���� �̵��϶�� ���ð� �ִ� ��쵵 ����.

2. ��� ( �ֻ��� ����ŭ �̵�, �ش� ĭ�� ���û����� ������ ����. ���Ĵ� ����������)

3. N�� �����ҽ� �ֻ��� Ƚ�� ���.
-------------------------
g_ar [N + 1] �迭 // 0�� ������, wc 1001
g_ar [M] �迭 //wc 1000 -> ť ���

1. �Է��� �� ����(�ֻ��� Ƚ�������鼭�� ���డ��)
2. �ֻ����� ������, �ش� ��ġ�� ����ϴ� �Լ�.
3. �ش� ��ġ�� ���� 0�� �ƴϸ� 2.�� ȣ���ϴ� �ϰ�, ī��Ʈ �ϴ� �Լ�.
	0�̸� ī��Ʈ���ϴ� �Լ�.
4. ���� ��ġ�� ���������� üũ�ϴ� �Լ�.

�ݺ�������
���� : �������� ������. �����Ҵ� ���.new delete �̿�.

���1. ��Ÿ�ӿ��� : ��? M�� �ƽ��� �ʰ��Ҷ� �߸��� ����. X
					��? Nĭ�� �������� ���� �� ĭ�� �Ѵ� ��쵵 ������ ���̴�. ���� �� ���о���? ->wc 999ĭ�� +999�� �������. O

��Ÿ�ӿ����� �����Ҵ��� ��������ν� �߻��� ����.
Q. �����Ҵ� -> ����޸��� ������. �������� -> ����޸��� ���ÿ���.�̶�� �˰��ִ�.
	�׷��ٸ� []�� ����� �ʰ��ϰ� ���������� �����Ҵ��� ������ ���.
	���������� ������������?������ �ȶ��?
	������ζ�� �� �� �Ͱ���. �ȶ�ٸ� �� �̷� ���̰� ����?


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
