#include "Node.h"
#include <stddef.h>


Node::Node()
{
	this->data = 0;
	this->next = NULL;
	this->previous = NULL;

}

Node::Node(int _data, Node *_next, Node *_previous)
:data(_data), next(_next), previous(_previous){}

Node::~Node()
{
}

//Custom copy constrcutor
Node::Node(const Node &node)
{
	this->data = node.data;
	this->next = node.next;
	this->previous = node.previous;
}
