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
	//size表示栈的大小
	int size;
public:
	/*构造函数*/
	Linkstack();
	/*复制构造函数*/
	Linkstack(const Linkstack &e);
	/*析构函数*/
	~Linkstack();
	/*判断栈是否为空*/
	bool isEmpty();
	/*返回栈顶元素的引用*/
	elemType& getTopstack();
	/*清空栈的数据*/
	bool clearLStack();
	/*返回栈的大小*/
	int length()const;
	/*入栈*/
	bool push(const elemType&e);
	/*出栈*/
	bool pop();
};

/*构造函数*/
template<class elemType>
Linkstack<elemType>::Linkstack()
{
	top = nullptr;
	size = 0;
}
/*复制构造函数*/
template<class elemType>
Linkstack<elemType>::Linkstack(const Linkstack&e)
{
	//p是指向操作栈e的指针
	node*p = e.top;
	//q是这个栈的指针;
	node*q, *last;
	q = last = nullptr;
	//处理size
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

/*判断栈是否为空*/
template<class elemType>
bool Linkstack<elemType>::isEmpty() {
	if (size == 0)
		return true;
	else
		return false;
}

/*返回栈顶元素的引用*/
template<class elemType>
elemType& Linkstack<elemType>::getTopstack() {
	return top->data;
}

/*清空栈的数据*/
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
		std::cout << "空栈" << std::endl;
		return false;
	}
	return true;
}

/*入栈*/
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

/*出栈*/
template<class elemType>
bool Linkstack<elemType>::pop() {
	if (size != 0) {
		node*p = top;
		top = top->next;
		delete p;
		size--;
	}
	else {
		std::cout << "空栈" << std::endl;
		return false;
	}
	return true;
}

/*析构函数*/
template<class elemType>
Linkstack<elemType>::~Linkstack() {
	node*p = top;
	while (top!=nullptr) {
		top = top->next;
		delete p;
		p = top;
	}
}

/*返回栈的大小*/
template<class elemType>
int Linkstack<elemType>::length()const {
	return size;
}
#endif