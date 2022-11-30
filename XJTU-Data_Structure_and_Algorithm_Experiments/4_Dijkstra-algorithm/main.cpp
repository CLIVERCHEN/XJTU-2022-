// ʵ��Dijkstra�㷨�������������������·�������·���ĳ���

#include <iostream>
#include <climits>
#include "location_data.h"
#include "Dijkstra-algorithm.h"
using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "ERROR_01";
		exit(0);
	}

	D_algorithm d_algo;
	d_algo.complete_distance();
	int p1, p2;
	p1 = d_algo.input2num(argv[1]);
	p2 = d_algo.input2num(argv[2]);
	if (p1 == NUMBER_OF_LOCATION || p2 == NUMBER_OF_LOCATION)  // �������λ�ò���loc2num�У����"ERROR_02"
	{
		cout << "ERROR_02";
		exit(0);
	}
	int ans_dis = d_algo.Dijkstra(p1, p2);
	cout << ans_dis;

	// ���·��
	// cout << endl;
	// d_algo.output_path(p1, p2);

}