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
	DLLStructure();
	~DLLStructure();

	DLLStructure(int list[], int size);

	void printDLL();

	void InsertAfter(int value2InsertAfter, int value2BeInserted);
	void InsertBefore(int value2InsertBefore, int value2BeInserted);

	void Delete(int value);

	bool isEmpty();
	
	int GetMax();
	int GetMin();

};

