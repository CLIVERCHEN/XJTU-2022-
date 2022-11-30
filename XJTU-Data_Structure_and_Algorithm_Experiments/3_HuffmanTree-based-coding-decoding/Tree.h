#pragma once
#ifndef TREE_
#define TREE_

#include "Node.h"
#include "My_Vector.h"
#include <string>
using namespace std;

class Tree
{
private:
	Node* Head;
	My_Vector<char> Ans_Code;  // ��ű���Ľ��
	My_Vector<char> Ans_Decode;  // ��Ž���Ľ��

public:
	Tree() {};
	~Tree();

public:
	My_Vector<Node*> ChCoding;  // ���ÿ����ĸ�Ľ���ַ

public:
	Node* Creat_New_Node(int input);
	Node* Creat_New_Node(int input, char ch);
	void Connect_Node(Node& n1, Node& n2, string pos);
	void PreOrder();
	void Create_Tree(char* S);
	void Coding(char* S);
	void Decoding(char* S);

public:
	void Print_Code();
	void Print_Decode();
};

#endif // !TREE_

