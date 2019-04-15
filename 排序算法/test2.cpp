#include<iostream>
#include<fstream>
#include"Sort.h"
using namespace std;
int main()
{

	ifstream fin("E:\\input.txt", ios::in);
	int num=50;
	int i = 0;
	int *arr = new int[num];
	while (!fin.eof())
		fin >> arr[i++];
	QuickSort(arr, num);
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";

	delete[]arr;
	cin.get();
	cin.get();
}