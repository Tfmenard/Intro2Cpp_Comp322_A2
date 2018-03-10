#pragma once
#include "Node.h"
#include <stddef.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class DLLStructure
{
private:
	Node *first;
	Node *last;
public:
	//Default constructor
	DLLStructure();

	//Default destructor
	~DLLStructure();

	//Custom constructor
	DLLStructure(int list[], int size);

	//Custom copy constructor
	DLLStructure(const DLLStructure &dll);

	void printDLL();

	void InsertAfter(int value2InsertAfter, int value2BeInserted);
	void InsertBefore(int value2InsertBefore, int value2BeInserted);

	void Delete(int value);

	void QuickSort(Node *first, Node *last);
	void Sort();
	void swap(Node *a, Node *b);
	Node* Partition(Node *start, Node *end);

	bool isEmpty();

	int GetHead();
	int GetTail();

	int GetSize();

	
	int GetMax();
	int GetMin();

};

