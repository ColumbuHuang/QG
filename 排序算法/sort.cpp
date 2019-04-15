#pragma once

#include<iostream>
#include"Sort.h"
#include<stack>
#include<array>

#define min(a,b) (a>b?b:a)
//	int a[] = { 5,9,56,22,13,6,65,4,32,1 };
/*����*/
void SWAP(int&a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}
/*��������*/
void insertSort(int *arr, int size)
{
	int i = 0, j = 1; //iΪ���򲿷�ĩβ��jΪ���򲿷���λ
	int insert_index = 0;
	for (i = 0, j = 1; j < size; j++,i++)
	{
		if ( arr[j] < arr[i] )
		{	
			//��arr[j]����temp�б���
			int temp = arr[j];
			//�ҵ�Ҫ�����С�꣬��insert_index��ʾ
			for (insert_index = 0; insert_index < i; insert_index++)
			{
				if (temp < arr[0])
				{
					insert_index = -1;
					break;
				}
				else if (arr[insert_index] <= arr[j] && arr[j] <= arr[insert_index + 1])
					break;
			}
			insert_index++;
			//insert_index�������ȫ����һλ
			while (i >= insert_index)
			{
				arr[i + 1] = arr[i];
				i--;
			}
			//����
			arr[insert_index] = temp;
			i = j-1;
		}
	}
}

/*�鲢*/
void mergeSort(int arr[], int size)
{
	int *box1 = arr;
	int *box2 = new int[size];
	for (int i = 1; i < size; i += i) {
		for (int start = 0; start < size; start += 2*i) {
			int left = start, mid = min(start + i, size), high = min(start + 2*i, size);
			int k = left;
			int start1 = left, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				box2[k++] = (box1[start1] < box1[start2] ? box1[start1++] : box1[start2++]);
			while (start1 < end1)
				box2[k++] = box1[start1++];
			while (start2 < end2)
				box2[k++] = box1[start2++];
		}
		int *temp = box1;
		box1 = box2;
		box2 = temp;
	}
	if (box1 != arr) {
		for (int i = 0; i < size; i++)
			box2[i] = box1[i];
		box2 = box1;
	}
	delete[] box2;
}
/*����(�ݹ�)*/
void QGquicksort(int *arr, int left, int right)
{
	int i, j, temp,box;
	i = left, j = right, temp = arr[left];
	//�ݹ��������
	if (left > right)
		return;
	while (j != i)
	{
		while (arr[j] >= temp && j > i)
			j--;
		while (arr[i] <= temp && j > i)
			i++;
		if (j > i)

		{
			box = arr[j];
			arr[j] = arr[i];
			arr[i] = box;
		}
	}
	//���������С���ұߴ�
	arr[left] = arr[j];
	arr[j] = temp;
	QGquicksort(arr,left, j - 1);
	QGquicksort(arr, j + 1, right);

}

/*���ŵ���*/
void QuickSort(int*a, int n)
{
	std::stack<int> s;
	s.push(0); //low
	s.push(n); //high
	while (!s.empty())
	{
		int low;
		int high;
		high = s.top();
		s.pop();
		low = s.top();
		s.pop();

		while (low < high)
		{

			int left = low;
			int right = high;
			int item = a[low];
			while (left < right)
			{
				left++;
				while (a[left] < item)
					left++;
				right--;
				while (a[right] > item)
					right--;
				if (left < right)
					SWAP(a[left], a[right]);
			}
			SWAP(a[low], a[right]);
			//�������
			if (right - low < high - right)  //ǰ���ֽ�С
			{
				//����󲿷�
				s.push(right + 1);
				s.push(high);
				high = right - 1;
			}
			else
			{
				s.push(low);
				s.push(right - 1);
				low = right + 1;
			}
		}
	}
}

/*��������*/
void CountSort(int*a,int a_length)
{
	int arrmax = 0;
	int arrmin = INT32_MAX;
	//�ҵ����ֵ��Сֵ
	for (int i = 0; i < a_length; i++)
	{
		if (a[i] > arrmax)
			arrmax = a[i];
		if (a[i] < arrmin)
			arrmin = a[i];
	}
	//size��box����Ĵ�С
	int size = arrmax - arrmin+1;
	int correct = arrmax - arrmin - 1;
	int* box = new int[size];
	for (int i = 0; i < size; i++)
		box[i] = 0;
	for (int i = 0; i < a_length; i++)
	{
		box[a[i] - arrmin]++;
	}


	//i��ʾbox������±�  iҪ����size
	//a_index ���ڼ�¼����a���±꣬��������
	int a_index = 0;
	for (int i = 0; i < size; i++)
	{
		//k����ͳ��ÿ�����������Ԫ�ظ���
		for (int k = 0; k < box[i]; k++)
		{
			if (box[i] == 0)
				break;
			a[a_index++] = i+arrmin;
		}
	}
	delete[]box;
}

/*���λ��*/
int arrMaxDigit(int *arr, int size)
{
	int len = 1;
	int radix = 10;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= radix)
		{
			len++;
			radix *= 10;
		}
	}
	return len;
}

/*��������*/
//	int a[] = { 5,9,56,22,13,6,65,4,32,1 };
void RadixCountSort(int *arr, int size,int digit)
{
	//��ʱ����
	int *box = new int[size];
	int *count = new int[10];
	int radix = 1; //radix�ǻ���
	int k;
	int index = 0;
	for (int i = 1; i <= digit; i++)
	{
		//ÿһ����ռ�����
		for (int j = 0; j < 10; j++)
			count[j] = 0;
		//��ȡ��Ӧλ�������� K��������count�����¼
		for (int j = 0; j < size; j++)
		{
			k = (arr[j] / radix) % 10; 
			count[k]++;
		}
		//����ÿ��Ͱ
		for (int j = 0; j < 10; j++)
		{
			//std::cout << j << " " << count[j] << std::endl;
			//j��ʾ��ǰλ��������
			if (count[j] != 0)
			{
				//i��arr�±� index��box�±�
				for (int i = 0; i < size; i++)
				{
					if ((arr[i] / radix) % 10 == j)
					{
						//������ʱ����box
						box[index] = arr[i];
						index++;
						//std::cout <<box[index-1] << " " << arr[i] << std::endl;
					}
				}
			}
		}
		index = 0;
		for (int i = 0; i < size; i++)
			arr[i] = box[i];
		radix *= 10;
	}
	delete []box;
	delete []count;
}