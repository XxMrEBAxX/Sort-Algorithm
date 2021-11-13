#pragma once
class CSort
{
	int* m_iData;
	int m_dataSize;
public:
	CSort(int Max = 100) : m_dataSize(Max)
	{
		m_iData = new int[Max];
	}
	~CSort(void)
	{
		if (m_iData)
			delete[] m_iData;
	}
	virtual void initData(int *data)
	{
		for (int i = 0; i < m_dataSize; i++)
			m_iData[i] = data[i];
	}
	virtual void sorting() = 0;
	virtual void draw() = 0;
	int getSize() { return m_dataSize; }
	int* getData() { return m_iData; }
};