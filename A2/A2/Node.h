#pragma once
class Node
{	
public:
	int data;
	Node *next;
	Node *previous;
public:
	Node();
	~Node();

	Node(int _data, Node *_next, Node *_previous);
};

