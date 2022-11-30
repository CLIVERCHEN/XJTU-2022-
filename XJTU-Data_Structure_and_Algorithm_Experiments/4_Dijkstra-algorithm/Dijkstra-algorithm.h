// ����ʵ��Dijkstra�㷨

#pragma once
#ifndef DIJKSTRA_ALGORITHM

#include <iostream>
#include "location_data.h"
using namespace std;

class D_algorithm:public location_data
{
private:
	int path[NUMBER_OF_LOCATION][NUMBER_OF_LOCATION] = { -1 };  // ��¼ÿһ���Ĳ����������������·��

public:
	void complete_distance();
	int input2num(char* input);
	int Dijkstra(int p1, int p2);
	void output_path(int start, int end);
};

#endif // !DIJKSTRA_ALGORITHM
