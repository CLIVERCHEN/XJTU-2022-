#include "Dijkstra-algorithm.h"

void D_algorithm::complete_distance()  // ��ȫ�ڽӾ�������ͼΪ����ͼ�������ɵ��ǶԳƾ���
{
	for (int i = 0; i < NUMBER_OF_LOCATION; i++)
	{
		for (int j = i; j < NUMBER_OF_LOCATION; j++) _distance[j][i] = _distance[i][j];
	}
}

int D_algorithm::input2num(char* input)  // �������λ��ת��Ϊ����
{
	for (int i = 0; i < NUMBER_OF_LOCATION; i++)
	{
		if (strcmp(input, loc2num[i]) == 0) return i;
	}
}

int D_algorithm::Dijkstra(int p1, int p2)  // Dijkstra�㷨
{
	int start, end;
	start = p1;
	end = p2;
	if (start > end)  // �����������Ӧ�ı���С���յ��Ӧ�ı��룬�򽻻�����λ�ã���Ϊ����˳������·��û��Ӱ��
	{
		int tmp = start;
		start = end;
		end = tmp;
	}

	if (start == NUMBER_OF_LOCATION || end == NUMBER_OF_LOCATION)
	{
		cout << "ERROR_02";
		exit(0);
	}

	int path_count = 0;
	int ans[NUMBER_OF_LOCATION];
	int if_min[NUMBER_OF_LOCATION] = { 0 };  // ����ѡ��һ�����ݵ���Сֵ
	memcpy(&ans, &_distance[start], NUMBER_OF_LOCATION * sizeof(int));  // ����Ӧ�ľ����һ������

	for (int i = 0; i < NUMBER_OF_LOCATION - 1; i++)  // ���������ÿһ��
	{
		int min = INT_MAX;  // ��ʼ��minΪ���޴�
		int min_loc = -1;

		for (int j = 0; j < NUMBER_OF_LOCATION; j++)  // ѡ��ans�е���Сֵ
		{
			if (ans[j] < min && ans[j] != -1 && if_min[j] == 0 && j != start)
			{
				min = ans[j];
				min_loc = j;
			}
		}
		if_min[min_loc] = 1;  // ÿ��λ��ֻ�ܱ�ѡΪһ����Сֵ

		for (int k = 0; k < NUMBER_OF_LOCATION; k++)  // ����ans
		{
			if ((ans[k] == -1 || (_distance[min_loc][k] + min < ans[k])) && _distance[min_loc][k] != -1)
			{
				ans[k] = _distance[min_loc][k] + min;
				path[k][path_count] = min_loc;
				path_count++;
			}
		}
	}
	return ans[end];
}

void D_algorithm::output_path(int start, int end)  // �����㵽�յ�����·��
{
	if (start < end)
	{
		int tmp_max = -1;
		int i;
		for (i = 12; i >= 0; i--)
		{
			if (path[end][i] > tmp_max) tmp_max = path[end][i];
		}
		output_path(start, tmp_max);
		cout << " " << "->" << " " << loc2num[end];
	}

	else if (start == end) cout << loc2num[end];

	else  // ��������С���յ����ʱ���򻥻����ߣ������ݹ����������λ�ã���ʵ���������·��
	{
		int tmp_max = -1;
		int i;
		for (i = 12; i >= 0; i--)
		{
			if (path[start][i] > tmp_max) tmp_max = path[start][i];
		}
		cout << loc2num[start] << " " << "->" << " ";
		output_path(tmp_max, end);
	}
}