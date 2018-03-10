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

	//#Question 1 and 2. See DLLStructure.h, DLLStructure.cpp, Node.h and Node.cpp for implementations
	DLLStructure *dll = new DLLStructure(list, 3);
	cout << "Initial list" << endl << endl;
	dll->printDLL();

	//#Question 4
	int value2InsertAfter = 3;
	int value2BeInserted = 7;
	cout << "Inserting " << value2BeInserted << " after the first occurence of " << value2InsertAfter << endl << endl;
	dll->InsertAfter(value2InsertAfter, value2BeInserted);
	cout << "New list is now " << endl << endl;
	dll->printDLL();

	//#Question 5
	int value2InsertBefore = 2;
	cout << "Inserting " << value2BeInserted << " before the first occurence of " << value2InsertBefore << endl << endl;
	dll->InsertBefore(value2InsertBefore, value2BeInserted);
	cout << "New List is " << endl << endl;
	dll->printDLL();
	
	//#Question 6
	int value2BeDeleted = 7;
	cout << "Deleting the first occurence of " << value2BeDeleted << endl << endl;
	dll->Delete(value2BeDeleted);
	cout << "New list with deleted element is now " << endl << endl;
	dll->printDLL();


	//#Question 7
	cout << "Creating new DLL " << endl << endl;
	int unsortedList[5] = { 11, 2, 7, 22, 4 };
	DLLStructure *dll2 = new DLLStructure(unsortedList, 5);
	cout << "New Unsorted DLL " << endl << endl;
	dll2->printDLL();
	dll2->Sort();
	cout << "Sorted DLL" << endl << endl;
	dll2->printDLL();

	//#Question 8
	cout << "DLL isEmpty = " << dll->isEmpty() << endl << endl;

	cout << "Creating new DLL containing only the default Node with data = 0 " << endl;
	DLLStructure *defaultDLL = new DLLStructure();
	cout << "Deleting the first occurenceof " << 0 << endl << endl;
	defaultDLL->Delete(0);
	cout << "DLL isEmpty = " << defaultDLL->isEmpty() << endl << endl;

	//#Question 9
	cout << "Value of Head = " << dll->GetHead() << endl << endl;
	cout << "Value of Tail = " << dll->GetTail() << endl << endl;

	//#Question 10
	cout << "Size of DLL is " << dll->GetSize() << endl << endl;

	//#Question 11
	cout << "Max Value of DLL is " << dll->GetMax() << endl;
	cout << "Min Value of DLL is " << dll->GetMin() << endl;


	//#Question 12
	//For the text answer, see the comments written above the implementation of the custom copy constructor in DLLStructure.cpp
	DLLStructure dll_copied(*dll);
	dll->printDLL();
	dll_copied.printDLL();


	return 0;
}

