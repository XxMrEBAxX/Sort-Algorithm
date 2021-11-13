#pragma once
#include "CSort.h"
#include <iostream>
using namespace std;

class CDoubleSelectionSort : public CSort
{
public:
	CDoubleSelectionSort(int size) : CSort(size) {}
	virtual void sorting() override
	{
		int Max = getSize();
		int* Array = getData();

		int start = 0;
		int end = Max - 1;
		while (start < end)
		{
			int lowest = start;
			int greatest = end;
			
			for (int i = start + 1; i < end; i++)
				// i = 1 �� ������ lowest == 0 �̱� ������
				// i < end �� ������ greatest == end �̱� ������
			{
				if (Array[i] < Array[lowest])
					lowest = i;
				if (Array[i] > Array[greatest])
					greatest = i;
			}
			int temp = Array[start];
			Array[start] = Array[lowest];
			Array[lowest] = temp;

			temp = Array[end];
			Array[end] = Array[greatest];
			Array[greatest] = temp;

			start++;
			end--;
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

