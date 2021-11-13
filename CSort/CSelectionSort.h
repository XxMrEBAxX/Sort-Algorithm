#pragma once
#include "CSort.h"
#include <iostream>
using namespace std;

class CSelectionSort : public CSort
{
public:
	CSelectionSort(int size) : CSort(size) {}
	virtual void sorting() override
	{
		int Max = getSize();
		int* Array = getData();

		for (int i = Max - 1; i >= 1; i--)
		{
			int greatest = 0;
			for (int j = 1; j <= i; j++)
				// j = 1 �� ������ greatest == 0 �̱� ������
			{
				if (Array[j] > Array[greatest])
					greatest = j;
			}
			int temp = Array[i];
			Array[i] = Array[greatest];
			Array[greatest] = temp;
		}
	}
	virtual void draw() override
	{
		int Max = getSize();
		int* Array = getData();

		cout << "[���ĵ� �迭]" << endl;
		for (int i = 0; i < Max; i++)
		{
			if (i % 10 == 0 && i != 0)
				cout << endl;
			cout << Array[i] << " ";
		}
		cout << endl;
	}
};

