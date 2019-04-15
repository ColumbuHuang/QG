#include<iostream>
#include<fstream>
#include"Sort.h"
using namespace std;
int main()
{
	
	ifstream fin("E:\\input.txt", ios::in);
	ofstream fout("E:\\output.txt", ios::out);
	
	int num;
	cout << "请输入数据规模:";
	cin >> num;
	int *arr = new int[num];
	for (int i = 0; i < num; i++)
		arr[i] = rand();
	QuickSort(arr, num);
	for (int i = 0; i < num; i++)
		fout << arr[i] << " ";
	delete[]arr;
	cin.get();
	cin.get();
}