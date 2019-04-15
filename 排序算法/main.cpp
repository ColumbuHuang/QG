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
	cout << "ѡ����Ҫִ�еĲ���:" ;
}
bool isOrderArray(int arr[],int size)
{
	for (int i = 0; i < size - 1; i++)
		if (arr[i] > arr[i + 1])
		{
			cout << "ilegal" << endl;
			return false;
		}
	cout << "legal" << endl;
	return true;
}
clock_t start, end;
int main()
{
	
	char control='1';
	table();
	while (control != 'g')
	{
		cin >> control;
		switch (control) 
		{
			//���ŵ���
			case'a': 
			{
				int num;
				cout << "������Ҫ���Ե����ݹ�ģ:";
				cin >> num;
				int* arr = new int[num];
				for (int i = 0; i < num; i++)
					arr[i] = rand();
				start = clock();
				QuickSort(arr, num);
				end = clock();
				isOrderArray(arr, num);
				double endtime = (double)(end - start) / CLOCKS_PER_SEC;
				cout << "total time:" << endtime * 1000 <<"ms"<< endl;
				break;
			}
			//���ŵݹ�
			case'b': 
			{
				int num;
				cout << "������Ҫ���Ե����ݹ�ģ:";
				cin >> num;
				int* arr = new int[num];
				for (int i = 0; i < num; i++)
					arr[i] = rand();
				start = clock();
				QGquicksort(arr, 0, num - 1);
				end = clock();
				cout << endl;
				isOrderArray(arr, num);
				double endtime = (double)(end - start) / CLOCKS_PER_SEC;
				cout << "total time:" << endtime * 1000 << "ms" << endl;
				break;
			}
			//�鲢
			case'c':
			{
				int num;
				cout << "������Ҫ���Ե����ݹ�ģ:";
				cin >> num;
				int* arr = new int[num];
				for (int i = 0; i < num; i++)
					arr[i] = rand();
				start = clock();
				mergeSort(arr, num);
				end = clock();
				isOrderArray(arr, num);
				double endtime = (double)(end - start) / CLOCKS_PER_SEC;
				cout << "total time:" << endtime * 1000 << "ms" << endl;
				break;
			}
			//����
			case'd':
			{
				int num;
				cout << "������Ҫ���Ե����ݹ�ģ:";
				cin >> num;
				int* arr = new int[num];
				for (int i = 0; i < num; i++)
					arr[i] = rand();
				start = clock();
				insertSort(arr, num);
				end = clock();
				isOrderArray(arr, num);
				double endtime = (double)(end - start) / CLOCKS_PER_SEC;
				cout << "total time:" << endtime * 1000 << "ms" << endl;
				break;
			}
			//����
			case'e': 
			{
				int num;
				cout << "������Ҫ���Ե����ݹ�ģ:";
				cin >> num;
				int* arr = new int[num];
				for (int i = 0; i < num; i++)
					arr[i] = rand();
				start = clock();
				CountSort(arr, num);
				end = clock();
				isOrderArray(arr, num);
				double endtime = (double)(end - start) / CLOCKS_PER_SEC;
				cout << "total time:" << endtime * 1000 << "ms" << endl;
				break;
			}
			//����
			case'f':
			{
				int num;
				int digit = 1;
				int radix = 10;
				cout << "������Ҫ���Ե����ݹ�ģ:";
				cin >> num;
				int* arr = new int[num];
				for (int i = 0; i < num; i++)
					arr[i] = rand();
				for (int i = 0; i < num; i++)
				{
					if (arr[i] >= radix)
					{
						digit++;
						radix *= 10;
					}
				}
				start = clock();
				RadixCountSort(arr, num,digit);
				end = clock();
				isOrderArray(arr, num);
				double endtime = (double)(end - start) / CLOCKS_PER_SEC;
				cout << "total time:" << endtime * 1000 << "ms" << endl;
				break;
			}
			case'g': break;
		}
	}
	cout << "end";

	/*int a[] = { 5,9,56,22,13,6,65,4,32,1 };
	RadixCountSort(a, 10,2);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";*/

	std::cin.get();
	std::cin.get();
	return 0;
}