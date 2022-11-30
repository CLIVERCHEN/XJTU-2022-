#include "My_Stack.h"
#include "solving.h"
#include <iostream>
using namespace std;

int solving::pri(char c1, char c2)  // c1Ϊ*(op.top - 1)��c2Ϊ*(op.top- 2)��
// ����1��ʾc2���ȼ�����c1��c2Ϊ*��c1Ϊ+����Ҫ����c2������-1��ʾc2���ȼ�����c1��Ҫ���������������
// Ҳ�����ö�ά���������ȼ�
{
	if (c1 == '!')
		return 1;
	switch (c2)
	{
	case '+':
	{
		if ((c1 == '*') || (c1 == '/') || (c1 == '^') || (c1 == '('))
			return -1;
		else
			return 1;
	}
	case '-':
	{
		if ((c1 == '*') || (c1 == '/') || (c1 == '^') || (c1 == '('))
			return -1;
		else
			return 1;
	}
	case '*':
	{
		if ((c1 == '^') || (c1 == '('))
			return -1;
		else
			return 1;
	}
	case '/':
	{
		if ((c1 == '^') || (c1 == '('))
			return -1;
		else
			return 1;
	}
	case '^':
	{
		if (c1 == '(')
			return -1;
		else
			return 1;
	}
	case ')':
		return -1;
	case '(':
		return -1;
	}
}

double solving::calculate(char c, double a, double b)  // a b c
{
	switch (c)
	{
	case '+':
	{
		return (a + b);
		break;
	}
	case '-':
	{
		return (a - b);
		break;
	}
	case '*':
	{
		return (a * b);
		break;
	}
	case '/':
	{
		if (b == 0)
		{
			cout << "ERROR_03";
			exit(0);
		}
		else
		{
			return (a / b);
			break;
		}
	}
	case '^':
	{
		return pow(a, b);
		break;
	}
	default:
	{
		cout << "ERROR_02";  // c���������������Ϊ���ʽ���ڸ�ʽ����
		exit(0);
	}
	}
}

double solving::solving_m_exp(char* input)
{
	my_stack<double> num;
	my_stack<char> op;

	int flag;  // �ж϶�ȡ�����Ƿ�Ϊ�����
	int i = 0;  // ѭ��
	int fix = 0;  // �Ƿ����'!'
	while (input[i] != '\0' || ((op.top - op.base) != fix || *(op.top - 1) != '!')) // ���϶�ȡ���ֺ�����������ڶ�ȡ����֮�����ѭ�����Լ�����ʽ��ֵ
	{						// ((op.top - op.base) != fix || *(op.top - 1) != '!') ��ȡ����֮��Operator������ֻ��'!'ʱ����
		flag = 1;  // �ж϶�ȡ�����Ƿ�Ϊ�������ÿ��ȡ��һ����������������ж����ȼ��������Ƿ����Ļ���
		if (input[i] != '\0')
		{
			if (input[i] >= '0' && input[i] <= '9')  // ��ȡһλ��
			{
				if ((input[i + 1] < '0' || input[i + 1] > '9') && input[i + 1] != '.')
				{
					num.Push((double)(input[i] - 48));  // һλ����ȡ����
					flag = 0;
					i++;
				}
				else  // ��ȡ��λ��
				{
					double temp = (double)(input[i] - 48);
					for (int m = 0; ; m++)
					{
						if (input[i + m + 1] >= '0' && input[i + m + 1] <= '9')
						{
							temp = temp * 10 + (input[i + m + 1] - 48);  // ��ȡ��λ��
							if ((input[i + m + 2] < '0' || input[i + m + 2] > '9') && input[i + m + 2] != '.')  // ��λ������С������
							{
								i += (m + 2);
								break;
							}
						}
						else if (input[i + m + 1] == '.')  // ��ȡС������
						{
							int k;
							for (k = 1; input[i + m + k + 1] >= '0' && input[i + m + k + 1] <= '9'; k++)
							{
								temp += (pow(10, -k) * (input[i + m + k + 1] - 48));
							}
							i += (m + k + 1);
							break;
						}
					}
					num.Push(temp);  // ��λ����ȡ����
					flag = 0;
				}
			}
			else
			{
				if (input[i] == '[' || input[i] == '{') input[i] = '(';  // ��ȡ����ʱ�������ִ�/��/С����
				else if (input[i] == ']' || input[i] == '}') input[i] = ')';
				op.Push(input[i]);
				i++;
			}
		}
		else
		{
			if (!fix)  // ��ӹ�'!'�������
			{
				op.Push('!');  // ͨ���������ȼ���ʹ"!"������������������ɼ������һ��������������
				fix = 1;
			}
		}
		if (flag)  // ��ȡ����������ȡ����ʱ����
		{
			switch (pri(*(op.top - 1), *(op.top - 2)))
			{
			case -1:
				break;
			case 1:
			{
				char tempOp, tempOp_;
				double tempNum;
				op.Pop(tempOp);
				num.Pop(tempNum);
				*(num.top - 1) = calculate(*(op.top - 1), *(num.top - 1), tempNum);
				op.Pop(tempOp_);
				op.Push(tempOp);
				if (tempOp == ')' && *(op.top - 2) == '(')  // ������'('��')'���򽫶���Pop
				{
					op.Pop(tempOp);
					op.Pop(tempOp);
				}
				break;
			}
			}
		}
	}
	return  *(num.top - 1);
}