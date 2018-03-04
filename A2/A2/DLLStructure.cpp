#include "DLLStructure.h"



DLLStructure::DLLStructure()
{
	this->first = new Node();
	this->last = new Node();
}

DLLStructure::DLLStructure(int list[], int size)
{
	Node *node_ptr;

	this->first = new Node(list[0], NULL, NULL);
	this->last = this->first;
	this->first->next = this->last;
	for (int i = 1; i < size; i++)
	{
		node_ptr = this->last;
		node_ptr->next = new Node(list[i], NULL, this->last->previous);
		this->last = node_ptr->next;
		this->last->previous = node_ptr;
	}
}


DLLStructure::~DLLStructure()
{
	while (this->first != NULL)
	{
		Node *temp = this->first->next;
		delete this->first;
		this->first = temp;
	}
}

void DLLStructure::printDLL()
{
	Node *node_ptr;
	node_ptr = this->first;

	while (node_ptr != NULL)
	{
		cout << node_ptr->data << endl;
		node_ptr = node_ptr->next;
	}
}

void DLLStructure::InsertAfter(int value2InsertAfter, int value2BeInserted)
{
	bool valueFound = false;
	Node *node_ptr = this->first;

	while (!valueFound && (node_ptr != NULL))
	{
		if (node_ptr->data == value2InsertAfter)
		{
			Node *new_node_ptr = new Node(value2BeInserted, node_ptr->next, node_ptr);
			node_ptr->next->previous = new_node_ptr;
			node_ptr->next = new_node_ptr;

			valueFound = true;
		}

		node_ptr = node_ptr->next;
	}
}

void DLLStructure::InsertBefore(int value2InsertBefore, int value2BeInserted)
{
	bool valueFound = false;
	Node *node_ptr = this->first;

	while (!valueFound && (node_ptr != NULL))
	{
		if (node_ptr->data == value2InsertBefore)
		{
			Node *new_node_ptr = new Node(value2BeInserted, node_ptr, node_ptr->previous);
			node_ptr->previous->next = new_node_ptr;
			node_ptr->previous = new_node_ptr;

			valueFound = true;
		}

		node_ptr = node_ptr->next;
	}
}