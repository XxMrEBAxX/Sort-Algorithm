#pragma once
#include "CSort.h"
#include <iostream>
using namespace std;

class CBubbleSort : public CSort
{
public:
	CBubbleSort(int size) : CSort(size) {}
	virtual void sorting() override
	{
		int Max = getSize();
		int* Array = getData();

		bool Sorted = false;
		for (int pass = 1; (pass < Max) && (!Sorted); pass++)
		{
			Sorted = true;
			for (int i = 0; i < Max - pass; i++)
			{
				if (Array[i] > Array[i + 1])
				{
					int temp = Array[i];
					Array[i] = Array[i + 1];
					Array[i + 1] = temp;
					Sorted = false;
				}
			}
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

