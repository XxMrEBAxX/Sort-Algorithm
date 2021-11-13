#pragma once
#include "CSort.h"
#include <iostream>
using namespace std;

class CInsertionSort : public CSort
{
public:
	CInsertionSort(int size) : CSort(size) {}
	virtual void sorting() override
	{
		int Max = getSize();
		int* Array = getData();

		for (int i = 1; i < Max; i++)
		{
			int temp = Array[i];
			int j = i - 1;
			for (; j >= 0 && Array[j] > temp; j--)
			{
				Array[j + 1] = Array[j];
			}
			//j 가 0까지 가면 최종 값은 j == -1 이 되므로 +1을 해준다.
			Array[j + 1] = temp;
		}
	}
	virtual void draw() override
	{
		int Max = getSize();
		int* Array = getData();

		cout << "[정렬된 배열]" << endl;
		for (int i = 0; i < Max; i++)
		{
			if (i % 10 == 0 && i != 0)
				cout << endl;
			cout << Array[i] << " ";
		}
		cout << endl;
	}
};

