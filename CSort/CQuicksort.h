#pragma once
#include "CSort.h"
#include <iostream>
#include <vector>
using namespace std;

class CQuicksort : public CSort
{
public:
	CQuicksort(int size) : CSort(size) {}
	virtual void sorting() override
	{
		int Max = getSize();
		int* Array = getData();

		QuickSort(Array, 0, Max - 1);
	}
	void QuickSort(int* s, int low, int high)
	{
		int pivotpoint;
		if (high > low)
		{
			pivotpoint = partition(s, low, high);
			// pivotpoint �迭 ���� �̹� ���ĵ� �����̹Ƿ� ���ڷ� �������� �ʴ´�.
			QuickSort(s, low, pivotpoint - 1);
			QuickSort(s, pivotpoint + 1, high);
		}
	}
	int partition(int* s, int low, int high)
	{
		int pivotItem = s[low];
		int pivotpoint = low;
		for (int i = low + 1; i <= high; i++)
		{
			if (s[i] < pivotItem)
			{
				pivotpoint++;

				int temp = s[pivotpoint];
				s[pivotpoint] = s[i];
				s[i] = temp;
			}
		}
		int temp = s[pivotpoint];
		s[pivotpoint] = pivotItem;
		s[low] = temp;

		return pivotpoint;
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
