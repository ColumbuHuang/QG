#pragma once

#include<iostream>
#include"Sort.h"
#include<stack>
#include<array>

#define min(a,b) (a>b?b:a)
//	int a[] = { 5,9,56,22,13,6,65,4,32,1 };
/*交换*/
void SWAP(int&a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}
/*插入排序*/
void insertSort(int *arr, int size)
{
	int i = 0, j = 1; //i为有序部分末尾，j为无序部分首位
	int insert_index = 0;
	for (i = 0, j = 1; j < size; j++,i++)
	{
		if ( arr[j] < arr[i] )
		{	
			//把arr[j]存入temp中保存
			int temp = arr[j];
			//找到要插入的小标，用insert_index表示
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
			//insert_index后面的数全后移一位
			while (i >= insert_index)
			{
				arr[i + 1] = arr[i];
				i--;
			}
			//插入
			arr[insert_index] = temp;
			i = j-1;
		}
	}
}

/*归并*/
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
/*快排(递归)*/
void QGquicksort(int *arr, int left, int right)
{
	int i, j, temp,box;
	i = left, j = right, temp = arr[left];
	//递归结束条件
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
	//交换后，左边小，右边大
	arr[left] = arr[j];
	arr[j] = temp;
	QGquicksort(arr,left, j - 1);
	QGquicksort(arr, j + 1, right);

}

/*快排迭代*/
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
			//保存参数
			if (right - low < high - right)  //前部分较小
			{
				//保存后部分
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

/*计数排序*/
void CountSort(int*a,int a_length)
{
	int arrmax = 0;
	int arrmin = INT32_MAX;
	//找到最大值最小值
	for (int i = 0; i < a_length; i++)
	{
		if (a[i] > arrmax)
			arrmax = a[i];
		if (a[i] < arrmin)
			arrmin = a[i];
	}
	//size是box数组的大小
	int size = arrmax - arrmin+1;
	int correct = arrmax - arrmin - 1;
	int* box = new int[size];
	for (int i = 0; i < size; i++)
		box[i] = 0;
	for (int i = 0; i < a_length; i++)
	{
		box[a[i] - arrmin]++;
	}


	//i表示box数组的下标  i要加上size
	//a_index 用于记录数组a的下标，用于排序
	int a_index = 0;
	for (int i = 0; i < size; i++)
	{
		//k用来统计每个箱子里面的元素个数
		for (int k = 0; k < box[i]; k++)
		{
			if (box[i] == 0)
				break;
			a[a_index++] = i+arrmin;
		}
	}
	delete[]box;
}

/*最大位数*/
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

/*基数排序*/
//	int a[] = { 5,9,56,22,13,6,65,4,32,1 };
void RadixCountSort(int *arr, int size,int digit)
{
	//临时数组
	int *box = new int[size];
	int *count = new int[10];
	int radix = 1; //radix是基数
	int k;
	int index = 0;
	for (int i = 1; i <= digit; i++)
	{
		//每一轮清空计数器
		for (int j = 0; j < 10; j++)
			count[j] = 0;
		//获取对应位数的数字 K，并放入count数组记录
		for (int j = 0; j < size; j++)
		{
			k = (arr[j] / radix) % 10; 
			count[k]++;
		}
		//检索每个桶
		for (int j = 0; j < 10; j++)
		{
			//std::cout << j << " " << count[j] << std::endl;
			//j表示当前位数的数字
			if (count[j] != 0)
			{
				//i是arr下标 index是box下标
				for (int i = 0; i < size; i++)
				{
					if ((arr[i] / radix) % 10 == j)
					{
						//放入临时数组box
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