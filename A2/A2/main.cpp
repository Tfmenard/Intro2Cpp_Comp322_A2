#include "main.h"
#include "Node.h"
#include "DLLStructure.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;



int main()
{
	int list[3] = { 1,2,3 };

	DLLStructure *dll = new DLLStructure(list, 3);
	dll->printDLL();

	dll->InsertAfter(3, 7);
	dll->InsertBefore(2, 7);

	dll->printDLL();

	return 0;
}

