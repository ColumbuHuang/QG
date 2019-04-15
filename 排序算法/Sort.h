#pragma once
#ifndef SORT_H_INCLUDE
#define SORT_H_INCLUDE

#include<iostream>
#include<stack>
/*����*/
void SWAP(int&a, int&b);
/*��������*/
void insertSort(int *start, int n);

/*�鲢*/
void mergeSort(int arr[], int size);

/*����(����)*/
void QuickSort(int*arr, int n);

/*���ŵݹ�*/
void QGquicksort(int *arr, int left, int right);

/*Ͱ����*/
void CountSort(int*a,int a_length);

/*������������*/
void RadixCountSort(int* a, int size, int digit);
/*�ҳ��������λ��(��������)*/
int maxbit(int arr[], int size);

/*��ɫ����,ֻ����0��1��2*/
void ColorSort(int*a, int size);
#endif // !SORT_H_INCLUDE

