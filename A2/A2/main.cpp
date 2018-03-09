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
	cout << "Initial list" << endl << endl;
	dll->printDLL();

	cout << "List after InsertAfter" << endl << endl;
	dll->InsertAfter(3, 7);
	dll->printDLL();

	cout << "List after InsertBefore" << endl << endl;
	dll->InsertBefore(2, 7);
	dll->printDLL();
	

	cout << "List with deleted element" << endl << endl;
	dll->Delete(7);
	dll->printDLL();

	cout << "Max Value = " << dll->GetMax() << endl;
	cout << "Min Value = " << dll->GetMin() << endl;

	delete dll;

	return 0;
}

