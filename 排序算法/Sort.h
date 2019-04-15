#pragma once
#ifndef SORT_H_INCLUDE
#define SORT_H_INCLUDE

#include<iostream>
#include<stack>
/*交换*/
void SWAP(int&a, int&b);
/*插入排序*/
void insertSort(int *start, int n);

/*归并*/
void mergeSort(int arr[], int size);

/*快排(迭代)*/
void QuickSort(int*arr, int n);

/*快排递归*/
void QGquicksort(int *arr, int left, int right);

/*桶排序*/
void CountSort(int*a,int a_length);

/*基数计数排序*/
void RadixCountSort(int* a, int size, int digit);
/*找出数组最大位数(辅助函数)*/
int maxbit(int arr[], int size);

/*颜色排序,只包含0，1，2*/
void ColorSort(int*a, int size);
#endif // !SORT_H_INCLUDE

