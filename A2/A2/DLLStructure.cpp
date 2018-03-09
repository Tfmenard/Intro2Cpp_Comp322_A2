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
			if (node_ptr == this->last)
			{
				this->last->next = new_node_ptr;
				this->last = new_node_ptr;
			}
			else
			{
				node_ptr->next->previous = new_node_ptr;
				node_ptr->next = new_node_ptr;
			}

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

void DLLStructure::Delete(int value2Delete)
{
	bool valueFound = false;
	Node *node_ptr = this->first;

	while (!valueFound)
	{
		if (node_ptr->data == value2Delete)
		{
			//Delete node
			node_ptr->previous->next = node_ptr->next;
			node_ptr->next->previous = node_ptr->previous;

			//Delete Node object being pointed to
			delete node_ptr;
			valueFound = true;
		}
		else
		{	
			//Go to next node
			node_ptr = node_ptr->next;
		}

	}

}

bool DLLStructure::isEmpty()
{
	if (this->first == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int DLLStructure::GetMax()
{
	Node *node_ptr = this->first;
	int maxValue = node_ptr->data;

	while (node_ptr != NULL)
	{
		if (node_ptr->data > maxValue)
		{
			maxValue = node_ptr->data;
		}

		node_ptr = node_ptr->next;
	}

	return maxValue;
}

int DLLStructure::GetMin()
{
	Node *node_ptr = this->first;
	int minValue = node_ptr->data;

	while (node_ptr != NULL)
	{
		if (node_ptr->data < minValue)
		{
			minValue = node_ptr->data;
		}

		node_ptr = node_ptr->next;
	}

	return minValue;
}