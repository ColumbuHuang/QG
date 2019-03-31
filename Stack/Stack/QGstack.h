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
	/*���캯��*/
	QGstack();
	/*���ƹ��캯��*/
	QGstack(const QGstack& e);
	/*����ջ��Ԫ�ص�����*/
	elemType& getTopelemt();
	/*���ջ*/
	bool clearStack();
	/*��������*/
	~QGstack();
	/*����ջ�Ĵ�С*/
	int length();
	/*��ջ*/
	bool push(const elemType&e);
	/*��ջ*/
	bool pop();
	/*�ж�ջ�Ƿ�Ϊ��*/
	bool isEmpty();
	/*�ж�ջ�Ƿ�����*/
	bool isFull();
};

/*���캯��*/
template<class elemType, int num>
QGstack<elemType, num>::QGstack()
{
	top = -1;
	size = 0;
}

/*���ƹ��캯��*/
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

/*����ջ��Ԫ�ص�����*/
template<class elemType, int num>
elemType& QGstack<elemType, num>::getTopelemt()
{
	return arr[top];
}

/*���ջ*/
template<class elemType, int num>
bool QGstack<elemType, num>::clearStack()
{
	top = -1;
	size = 0;
}

/*����ջ�Ĵ�С*/
template<class elemType, int num>
int QGstack<elemType, num>::length()
{
	return size;
}

/*��ջ*/
template<class elemType, int num>
bool QGstack<elemType, num>::push(const elemType&e)
{
	arr[++top] = e;
	size++;
	return true;
}

/*��ջ*/
template<class elemType, int num>
bool QGstack<elemType, num>::pop()
{
	if (top != -1)
	{
		top--;
		size--;
	}
	else {
		cout << "��ջ" << endl;
		return false;
	}
	return true;

}

/*��������*/
template<class elemType, int num>
QGstack<elemType, num>::~QGstack()
{
	delete []arr;

}

/*�ж�ջ�Ƿ�Ϊ��*/
template<class elemType, int num>
bool QGstack<elemType, num>::isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

/*�ж�ջ�Ƿ�����*/
template<class elemType, int num>
bool QGstack<elemType, num>::isFull()
{
	if (top == num - 1)
		return true;
	else
		return false;
}
#endif
