#pragma once
#include "CSort.h"
#include <iostream>
#include <vector>
using namespace std;

class CMergeSort : public CSort
{
public:
	CMergeSort(int size) : CSort(size) {}
	virtual void sorting() override
	{
		int Max = getSize();
		int* Array = getData();

		MergeSort(Array, 0, Max - 1);
	}
	void MergeSort(int* s, int f, int l)
	{
		if (f < l)
		{
			int m = (f + l) / 2;
			MergeSort(s, f, m);
			MergeSort(s, m + 1, l);
			Merge(s, f, m, l);
		}
	}
	void Merge(int* s, int f, int m, int l)
	{
		int* sorting = new int[getSize()];
		//vector<int> sorting(getSize());
		int First, Last, First2, Last2, index;
		First = f;
		Last = m;
		First2 = m + 1;
		Last2 = l;
		index = First;

		while (First <= Last && First2 <= Last2)
		{
			if (s[First] < s[First2])
				sorting[index++] = s[First++];
			else
				sorting[index++] = s[First2++];
		}
		for (; First <= Last; First++, index++)
			sorting[index] = s[First];
		for (; First2 <= Last2; First2++, index++)
			sorting[index] = s[First2];

		for (index = f; index <= l; index++)
			s[index] = sorting[index];

		delete[] sorting;
		//sorting.clear();
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

