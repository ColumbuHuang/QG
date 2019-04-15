#include<iostream>
#include<cstdlib>
#include<stack>
#include<ctime>
#include"Sort.h"
using std::cout;
using std::cin;
using std::endl;
void table() {
	cout << "a.��������(����)" << endl;
	cout << "b.��������(�ݹ�)" << endl;
	cout << "c.�鲢����" << endl;
	cout << "d.��������" << endl;
	cout << "e.��������" << endl;
	cout << "f.��������" << endl;
	cout << "g.����" << endl;
	cout << "ѡ����Ҫִ�еĲ���:";
}
bool isOrderArray(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
		if (arr[i] > arr[i + 1])
		{
			cout << "ilegal" << endl;
			return false;
		}
	//cout << "legal" << endl;
	return true;
}
clock_t start, end;
int main()
{
	table();
	char control = '1';
	while (control!='g')
	{
		std::cin >> control;
		switch (control)
		{
		case'a': 
		{
			start = clock();
			for (int i = 0; i < 100000; i++)
			{
				int* arr = new int[100];
				for (int j = 0; j < 100; j++)
					arr[j] = rand();
				QuickSort(arr, 100);
				isOrderArray(arr,100);
				delete[]arr;
			}
			end = clock();
			double endtime = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "total time:" << endtime * 1000 << "ms" << endl;
		}break;
		case'b': 
		{
			start = clock();
			for (int i = 0; i < 100000; i++)
			{
				int* arr = new int[100];
				for (int j = 0; j < 100; j++)
					arr[j] = rand();
				QGquicksort(arr, 0,99);
				isOrderArray(arr, 100);
				delete[]arr;
			}
			end = clock();
			double endtime = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "total time:" << endtime * 1000 << "ms" << endl;
		}break;
		case'c': 
		{
			start = clock();
			for (int i = 0; i < 100000; i++)
			{
				int* arr = new int[100];
				for (int j = 0; j < 100; j++)
					arr[j] = rand();
				mergeSort(arr, 100);
				isOrderArray(arr, 100);
				delete[]arr;
			}
			end = clock();
			double endtime = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "total time:" << endtime * 1000 << "ms" << endl;
		}break;
		case'd':
		{
			start = clock();
			for (int i = 0; i < 100000; i++)
			{
				int* arr = new int[100];
				for (int j = 0; j < 100; j++)
					arr[j] = rand();
				insertSort(arr, 100);
				isOrderArray(arr, 100);
				delete[]arr;
			}
			end = clock();
			double endtime = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "total time:" << endtime * 1000 << "ms" << endl;
		}break;
		case'e':
		{
			start = clock();
			for (int i = 0; i < 100000; i++)
			{
				int* arr = new int[100];
				for (int j = 0; j < 100; j++)
					arr[j] = rand();
				CountSort(arr, 100);

				/*for (int i = 0; i < 100; i++)
					std::cout << arr[i] << " ";*/
				//std::cout << std::endl;
				isOrderArray(arr, 100);
				delete[]arr;
			}
			end = clock();
			double endtime = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "total time:" << endtime * 1000 << "ms" << endl;
		}break;
		case'f':
		{
			start = clock();
			for (int i = 0; i < 100000; i++)
			{
				int* arr = new int[100];
				for (int j = 0; j < 100; j++)
					arr[j] = rand();
				int digit = 1;
				int radix = 10;
				for (int i = 0; i < 100; i++)
				{
					if (arr[i] >= radix)
					{
						digit++;
						radix *= 10;
					}
				}
				RadixCountSort(arr, 100,digit);
				isOrderArray(arr, 100);
				delete[]arr;
			}
			end = clock();
			double endtime = (double)(end - start) / CLOCKS_PER_SEC;
			cout << "total time:" << endtime * 1000 << "ms" << endl;
		}break;
		case'g':break;

		}
	}
}