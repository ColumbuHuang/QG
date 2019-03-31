#pragma once
#ifndef CACULATE_H_
#define CACULATE_H_
#include"LinkStack.h"
#include<string>
class Caculate {

public:
	float toFloat(char a)
	{
		float num = a - 48;
		return num;
	}
	float caculate(char*output)
	{
		Linkstack<float> store;
		int i = 0;
		float a, b;
		while (output[i] != '\0')
		{
			//若是数字 进栈
			if (output[i] >= '0'&&output[i] <= '9')
			{
				store.push(toFloat(output[i]));
			}

			//运算符 取栈顶两个元素运算后 运算结果入栈
			else
			{
				a = (float)store.getTopstack();
				store.pop();
				b = (float)store.getTopstack();
				store.pop();
				switch (output[i])
				{
				case'+':
					store.push(a + b);
					break;
				case'-':
					store.push(b - a);
					break;
				case'*':
					store.push(a*b);
					break;
				case'/':
					store.push(b / a);
					break;
				}
			}
			i++;
		}
		return store.getTopstack();
	}
	//b>a 返回true
	bool priority(char a, char b)
	{
		if ((a == '+' || a == '-') && (b == '*' || b == '/')) return true;
		if ((a == '+' || a == '-') && (b == '+' || b == '-')) return false;
		if ((a == '*' || a == '/') && (b == '*' || b == '/')) return false;
		if ((a == '*' || a == '/') && (b == '+' || b == '-')) return false;
		if (a == '(' || a == ')') return true;
	}
	void changeExpression(std::string input, char*output)
	{
		Linkstack<char> store;
		//std::string input = "6+(4-2)*3+9/3";
		//std::string output=input;
		//char output[1000] = { '\0' };
		unsigned int i = 0;
		int j = 0;
		for (i = 0, j = 0; i < input.length(); i++)
		{
			//数字直接输出
			if (input[i] >= '0'&&input[i] <= '9')
			{
				output[j++] = input[i];
			}
			//遇到左括号 或者空栈 直接入栈 
			else if (input[i] == '(' || store.isEmpty())
			{
				store.push(input[i]);
			}
			//遇到右括号，把栈顶元素出栈，直到左括号弹出
			else if (input[i] == ')')
			{
				while (store.getTopstack() != '(')
				{
					output[j++] = store.getTopstack();
					store.pop();
				}
				store.pop();
			}
			//遇到运算符 先判断优先级 优先级大于栈顶元素 入栈
			else if (priority(store.getTopstack(), input[i]))
			{
				store.push(input[i]);
			}
			//优先级低 出栈
			else
			{
				//当栈顶的元素优先级>=插入元素
				while (!store.isEmpty() && !priority(store.getTopstack(), input[i]))
				{
					output[j++] = store.getTopstack();
					store.pop();
				}
				store.push(input[i]);
			}
		}
		while (!store.isEmpty())
		{
			output[j++] = store.getTopstack();
			store.pop();
		}
	}
	float figure()
	{
		std::string input;
		char output[1000] = { '\0' };
		std::cout << "请输入表达式:";
		std::cin >> input;
		this->changeExpression(input, output);
		float n = this->caculate(output);
		return n;
	}
};

#endif // !CACULATE_H_


