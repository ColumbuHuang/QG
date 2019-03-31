#pragma once
#ifndef QGSTACK_H_INCLUDED
#define QGSTACK_H_INCLUDED
#include<iostream>
using namespace std;

template<class elemType, int num>
class QGstack {
protected:
	int top;
	elemType arr[num];
	int size;
public:
	/*构造函数*/
	QGstack();
	/*复制构造函数*/
	QGstack(const QGstack& e);
	/*返回栈顶元素的引用*/
	elemType& getTopelemt();
	/*清空栈*/
	bool clearStack();
	/*析构函数*/
	~QGstack();
	/*返回栈的大小*/
	int length();
	/*入栈*/
	bool push(const elemType&e);
	/*出栈*/
	bool pop();
	/*判断栈是否为空*/
	bool isEmpty();
	/*判断栈是否已满*/
	bool isFull();
};

/*构造函数*/
template<class elemType, int num>
QGstack<elemType, num>::QGstack()
{
	top = -1;
	size = 0;
}

/*复制构造函数*/
template<class elemType, int num>
QGstack<elemType, num>::QGstack(const QGstack& e)
{
	top = e.top;
	size = e.size;
	if (top != -1) {
		for (int i = 0; i <= top; i++)
		{
			arr[i] = e.arr[i];
		}
	}

}

/*返回栈顶元素的引用*/
template<class elemType, int num>
elemType& QGstack<elemType, num>::getTopelemt()
{
	return arr[top];
}

/*清空栈*/
template<class elemType, int num>
bool QGstack<elemType, num>::clearStack()
{
	top = -1;
	size = 0;
}

/*返回栈的大小*/
template<class elemType, int num>
int QGstack<elemType, num>::length()
{
	return size;
}

/*入栈*/
template<class elemType, int num>
bool QGstack<elemType, num>::push(const elemType&e)
{
	arr[++top] = e;
	size++;
	return true;
}

/*出栈*/
template<class elemType, int num>
bool QGstack<elemType, num>::pop()
{
	if (top != -1)
	{
		top--;
		size--;
	}
	else {
		cout << "空栈" << endl;
		return false;
	}
	return true;

}

/*析构函数*/
template<class elemType, int num>
QGstack<elemType, num>::~QGstack()
{
	delete []arr;

}

/*判断栈是否为空*/
template<class elemType, int num>
bool QGstack<elemType, num>::isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

/*判断栈是否已满*/
template<class elemType, int num>
bool QGstack<elemType, num>::isFull()
{
	if (top == num - 1)
		return true;
	else
		return false;
}
#endif
