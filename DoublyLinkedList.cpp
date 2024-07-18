#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node *previous;

	Node(int value)
	{
		data = value;
		next = NULL;
		previous = NULL;
	}

};

class DoublyLinkedList
{
	Node *head;
	Node *tail;
public:
	DoublyLinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	void insert(int value)
	{
		Node *NewNode = new Node(value);
		if (head == NULL)
		{
			head = NewNode;
			tail = NewNode;
		}

		else
		{
			NewNode->next=head;
			head->previous=NewNode;
			head = NewNode;
		}
	}

	void Display()
	{
		Node *temp = head;
		while(temp != NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
	}

	void reverse()
	{
		Node *temp;
		temp = head;
		head = tail;
		tail = temp;
	}

		void Displayprevious()
	{
		Node *temp = head;
		while(temp != NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->previous;
		}
	}
};

int main ()
{
	DoublyLinkedList DLL;
	DLL.insert(3);
	DLL.insert(6);
	DLL.insert(9);
	DLL.Display();
	DLL.reverse();
	cout<<"\nAfter reverse function: ";
	DLL.Displayprevious();
}