#include "DLLStructure.h"


//Default constructor
DLLStructure::DLLStructure()
{
	this->first = new Node();
	this->last = this->first;
}

//Constructorof a DLL. 
//This constructor creates a DLL of the same size as its input integer array.
//Note that it creates Node objects on the heap.
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

//Destructor of a DLL. 
//It removes all Nodes on the DLL by simply assigning the first node be the next node and deleting the first node iteratively.
//Note that it removes all the Node objects from the heap.
DLLStructure::~DLLStructure()
{
	while (this->first != NULL)
	{
		Node *temp = this->first->next;
		delete this->first;
		this->first = temp;
	}
}

/*
Question 12 Text Answer:
We cannot rely on the copy constructor of DLLStructure provided by default by the compiler
since only built-in types will be copied, not user defined types.
Ergo, since a DLLStructure contains user defined type Node, we cannot rely on the default copy constructor
The default copy constructor for Node does copy correctly all member variable even though it contains Node pointers as member variables.
However, to be thorough, a custom copy constructor was also implemented in the Node class. See Node.cpp
*/
 DLLStructure::DLLStructure(const DLLStructure &dll)
{

	 //Copy first Node
	 Node *node_ptr = dll.first;
	 
	 //Create new Node on the heap
	 Node *first_node = new Node(*node_ptr);
	 this->first = first_node;

	 //Pointer to iterate over new DLL
	 Node *new_dll_tail_ptr = this->first;

	 //Go to next Node. Should be first->next
	 node_ptr = node_ptr->next;

	 //Iterate until you hit the last node that is already copied.
	 while (node_ptr != dll.last)
	 {
		 //Create new Node on the heap
		 Node *new_node = new Node(*node_ptr);

		 //Wire new node to the tail of the new DLL
		 new_node->previous = new_dll_tail_ptr;

		 //Wire tail of new DLL to the newly created node. (Newly created node becomes the tail)
		 new_dll_tail_ptr->next = new_node;
		 
		 //Point to newly created Node
		 new_dll_tail_ptr = new_node;

		 //Go to Next node in old DLL
		 node_ptr = node_ptr->next;
	 }

	 //Create the last Node and wire it to new DLL
	 Node *new_last_node = new Node(*node_ptr);
	 new_last_node->previous = new_dll_tail_ptr;
	 new_dll_tail_ptr->next = new_last_node;
	 this->last = new_last_node;
}

//Question 3
//This method prints the content of a DLL
void DLLStructure::printDLL()
{
	Node *node_ptr;
	node_ptr = this->first;

	cout << "---------------" << endl;

	//Iterate until the end is reached
	while (node_ptr != NULL)
	{
		cout << node_ptr->data << endl;
		node_ptr = node_ptr->next;
	}
	cout << "---------------" << endl << endl;
}

//This method inserts a given value in a DLL after first occurence of Node containing a target value
void DLLStructure::InsertAfter(int value2InsertAfter, int value2BeInserted)
{
	bool valueFound = false;
	Node *node_ptr = this->first;

	//Iterate over DLL until value is found or until it reaches the end of the DLL
	while (!valueFound && (node_ptr != NULL))
	{
		if (node_ptr->data == value2InsertAfter)
		{
			//Create new Node on the heap. Take note of the rewiring.
			//The new node's next pointer will point to the target node's next pointer. And the new node's previous pointer points to the target node.
			Node *new_node_ptr = new Node(value2BeInserted, node_ptr->next, node_ptr);

			//Check if current is the last Node of the DLL and if true the new Node inserted will become the last Node of the DLL
			if (node_ptr == this->last)
			{
				this->last->next = new_node_ptr;
				this->last = new_node_ptr;
			}
			//Insert the new Node. Take note of the rewiring complementing the wiring of the new node.
			else
			{
				node_ptr->next->previous = new_node_ptr;
				node_ptr->next = new_node_ptr;
			}

			//Set condition to true to brake from while loop
			valueFound = true;
		}

		//Go to next Node
		node_ptr = node_ptr->next;
	}
}

//This method inserts a given value in a DLL after first occurence of Node containing a target value
void DLLStructure::InsertBefore(int value2InsertBefore, int value2BeInserted)
{

	bool valueFound = false;
	Node *node_ptr = this->first;

	//Iterate over DLL until value is found or until it reaches the end of the DLL
	while (!valueFound && (node_ptr != NULL))
	{
		if (node_ptr->data == value2InsertBefore)
		{

			//Check if current is the first Node of the DLL and if true the new Node inserted will become the first Node of the DLL
			if (node_ptr == this->first)
			{
				//Create new Node on the heap. Take note of the rewiring.
				//The new node's next pointer points to the target node and its previous pointer points to the target node's previous pointer.
				Node *new_node_ptr = new Node(value2BeInserted, node_ptr, node_ptr->previous);
				this->first->previous = new_node_ptr;
				this->first = new_node_ptr;
			}
			//Insert node in DLL. Take note of the rewiring complementing the wiring of the new node.
			else
			{
				//Store head
				Node *head_node_ptr = this->first;

				//Call InsertAfter with new head so we don't reiterate on the same nodes, and get the right target node.
				this->first = node_ptr->previous;
				this->InsertAfter(node_ptr->previous->data, value2BeInserted);

				//Restore head
				this->first = head_node_ptr;
			}

			//Set condition to brake from while loop
			valueFound = true;
		}

		//Go to next Node
		node_ptr = node_ptr->next;
	}
	
}


//This method removes the first occurence of a Node in a DLL with data equal to a target value.
//Then it deletes the floating Node from the heap to not have memory leak, since the DLL destructor would not delete be able to delete it.
void DLLStructure::Delete(int value2Delete)
{
	bool valueFound = false;
	Node *node_ptr = this->first;

	//Iterate over DLL structure until the target value is found
	while (!valueFound)
	{
		if (node_ptr->data == value2Delete)
		{
			if (node_ptr == this->first)
			{
				if (node_ptr->next != NULL)
				{
					node_ptr->next->previous = NULL;
					this->first = node_ptr->next;
				}
				else
				{
					//There is only one Node in the DLL so set first and last to NULL
					this->first = NULL;
					this->last = NULL;
				}
			}
			else if (node_ptr == this->last)
			{
				if (node_ptr->previous != NULL)
				{
					node_ptr->previous->next = NULL;
					this->last = node_ptr->previous;
				}
				else
				{
					//There is only one Node in the DLL so set first and last to NULL
					this->first = NULL;
					this->last = NULL;
				}
			}
			else
			{
				//Rewire nodes
				node_ptr->previous->next = node_ptr->next;
				node_ptr->next->previous = node_ptr->previous;
			}

			//Delete Node object being pointed to from the heap
			delete node_ptr;

			//Set condition to break loop
			valueFound = true;
		}
		else
		{	
			//Go to next node
			node_ptr = node_ptr->next;
		}

	}

}

//Check if DLL structure is empty by simply checking if the first Node is empty
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

int DLLStructure::GetHead()
{
	return this->first->data;
}

int DLLStructure::GetTail()
{
	return this->last->data;
}


/*
Question 10 Text Answer:
This implementation is inefficient since we have to iterate over the whole DLL every time.
The best implementation for this function would be a simple Getter function which returns a member variable "int size"
Though, to have such implementation, one would need to make sure that "size", is updated each time a node is inserted or deleted.
*/
//This method iterates over the whole DLL structure and returns its size
int DLLStructure::GetSize()
{
	Node *node_ptr = this->first;
	int size = 0;

	while (node_ptr != NULL)
	{
		size++;
		node_ptr = node_ptr->next;
	}

	return size;
}

/*
Question 11 Text Answer:
This implementation is inefficient as it has to iterate over the whole structure each time.
The best implementation for this function would be same best solution as for GetSize(). 
The function should be a simple getter function that returns a member variable "int max".
One would have to update max every time a node is inserted or deleted.
However, one must be careful when deleting the node contaning the max.
If that would be the case, one could sort the list to find the new max after deleting the node.
*/

//This method iterates through the whole DLL to find the first occurence of the maximum value in it.
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

/*
The answer for GetMin() is the same as GetMax(), but the member variable would be "int min"
*/
//This method iterates through the whole DLL to find the first occurence of the minimum value in it.
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



//Method calling QuickSort
void DLLStructure::Sort()
{
	this->QuickSort(this->first, this->last);
}


//Implementing QuickSort with DLL. Average case O(N*log(N)), Worst case O(N^2). Space complexity is In-Place
void DLLStructure::QuickSort(Node *start, Node *end)
{
	//check if the Sub DLL is either a sing Node or if it has non valid bounds.
	if (start != end && start->previous != end)
	{
		//get partition index
		Node *part_index_ptr = Partition(start, end);

		//Recursive call on left and right sub DLL
		QuickSort(start, part_index_ptr->previous);
		QuickSort(part_index_ptr->next, end);
	}
}

//This method swaps data members in Node objects. 
/**Note that if there were additional requirements on the sorting method,
one should swap the Node elements in the DLL according to their data member. This way one could sort a DLL without
mixing information between its Nodes.*/
void DLLStructure::swap(Node *a, Node *b)
{
	int tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}


/*
This method partitions data members in the sub-DLL such that every Node with data member <= pivot are positioned to the left of the pivot
And the rest of the noes are positioned to the right of the pivot.
Then it returns a pointer to the Node containing the chosen pivot.
The pivot is chosen to be the last element in sub DLL.
The sub DLL is defined as the elements from start to end inclusively.
*/
Node* DLLStructure::Partition(Node *start, Node *end)
{
	//Select pivot
	int pivot = end->data;

	//Partition index pointer
	Node *part_index_ptr = start;

	//Node iterator pointer
	Node *node_iterator_ptr = start;

	//Loop until the before last node of the sub DLL
	while (node_iterator_ptr != end->previous)
	{
		//Swap elements and increase partition index
		if (node_iterator_ptr->data <= pivot)
		{
			swap(node_iterator_ptr, part_index_ptr);
			part_index_ptr = part_index_ptr->next;
		}

		//Iterate on next Node in sub DLL
		node_iterator_ptr = node_iterator_ptr->next;
	}

	//Swap the partition index data with the data of the Node containing the pivot
	swap(part_index_ptr, end);

	//Return Node containing the pivot
	return part_index_ptr;

}

