#include <iostream>
#include <time.h>
#include "CSelectionSort.h"
#include "CDoubleSelectionSort.h"
#include "CBubbleSort.h"
#include "CInsertionSort.h"
#include "CMergeSort.h"
#include "CQuicksort.h"
using namespace std;

int main()
{
    const int size = 10000; //정렬 개수
    int data[size];
    // 시드 초기화
    //srand((unsigned)time);
    for (int i = 0; i < size; i++) // 내림차순 배열
    {
        //data[i] = rand() % size + 1;
        data[i] = size - i - 1;
    }
    cout << "[정렬되지 않은 배열]" << endl;
    for (int i = 0; i < size; i++)
    {
        if (i % 10 == 0 && i != 0)
            cout << endl;
        cout << data[i] << " ";
    }
    cout << endl;

    // 클래스 명만 바꾸면 정렬 방식이 변경됨.
    // CDoubleSelectionSort sort(size);
    CQuicksort sort(size);
    sort.initData(data);
    clock_t previousTime = clock();
    sort.sorting();
    clock_t laterTime = clock();
    sort.draw();
    cout << "퀵 정렬 알고리즘" << endl;
    cout << "걸린 시간 : " << difftime(laterTime, previousTime)/CLOCKS_PER_SEC << endl;
}