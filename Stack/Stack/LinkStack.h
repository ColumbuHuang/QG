#pragma once
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<iostream>
template<class elemType>
class Linkstack {
protected:
	struct node {
		elemType data;
		node*next;
	};
	node*top;
	//size��ʾջ�Ĵ�С
	int size;
public:
	/*���캯��*/
	Linkstack();
	/*���ƹ��캯��*/
	Linkstack(const Linkstack &e);
	/*��������*/
	~Linkstack();
	/*�ж�ջ�Ƿ�Ϊ��*/
	bool isEmpty();
	/*����ջ��Ԫ�ص�����*/
	elemType& getTopstack();
	/*���ջ������*/
	bool clearLStack();
	/*����ջ�Ĵ�С*/
	int length()const;
	/*��ջ*/
	bool push(const elemType&e);
	/*��ջ*/
	bool pop();
};

/*���캯��*/
template<class elemType>
Linkstack<elemType>::Linkstack()
{
	top = nullptr;
	size = 0;
}
/*���ƹ��캯��*/
template<class elemType>
Linkstack<elemType>::Linkstack(const Linkstack&e)
{
	//p��ָ�����ջe��ָ��
	node*p = e.top;
	//q�����ջ��ָ��;
	node*q, *last;
	q = last = nullptr;
	//����size
	size = e.size;
	while (p != nullptr) {
		q = new node;
		q->data = p->data;
		if (top == nullptr)
			top = q;
		else
			last->next = q;
		last = q;
		p = p->next;
	}
	
}

/*�ж�ջ�Ƿ�Ϊ��*/
template<class elemType>
bool Linkstack<elemType>::isEmpty() {
	if (size == 0)
		return true;
	else
		return false;
}

/*����ջ��Ԫ�ص�����*/
template<class elemType>
elemType& Linkstack<elemType>::getTopstack() {
	return top->data;
}

/*���ջ������*/
template<class elemType>
bool Linkstack<elemType>::clearLStack() {
	if (size != 0) {
		while (size > 1) {
			node*p = top;
			top = top->next;
			delete p;
			size--;
		}
		top->data = 0;
	}
	else {
		std::cout << "��ջ" << std::endl;
		return false;
	}
	return true;
}

/*��ջ*/
template<class elemType>
bool Linkstack<elemType>::push(const elemType&e) {
	if (size == 0) {
		node *p = new node;
		p->data = e;
		p->next = nullptr;
		top = p;
		size++;
	}
	else {
		node*p = new node;
		p->data = e;
		p->next = top;
		top = p;
		size++;
	}
	return true;
}

/*��ջ*/
template<class elemType>
bool Linkstack<elemType>::pop() {
	if (size != 0) {
		node*p = top;
		top = top->next;
		delete p;
		size--;
	}
	else {
		std::cout << "��ջ" << std::endl;
		return false;
	}
	return true;
}

/*��������*/
template<class elemType>
Linkstack<elemType>::~Linkstack() {
	node*p = top;
	while (top!=nullptr) {
		top = top->next;
		delete p;
		p = top;
	}
}

/*����ջ�Ĵ�С*/
template<class elemType>
int Linkstack<elemType>::length()const {
	return size;
}
#endif