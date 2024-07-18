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
	Node *head1;
	Node *tail1;
public:
	DoublyLinkedList()
	{
		head = NULL;
		tail = NULL;
		head1 = NULL;
		tail1 = NULL;
	}

	void insert1(int value)
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

		void insert2(int value)
	{
		Node *NewNode = new Node(value);
		if (head1 == NULL)
		{
			head1 = NewNode;
			tail1 = NewNode;
		}

		else
		{
			NewNode->next=head1;
			head1->previous=NewNode;
			head1 = NewNode;
		}
	}

	void Display1()
	{
		Node *temp = head;
		while(temp != NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
	}

		void Display2()
	{
		Node *temp = head1;
		while(temp != NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
	}

	void Merg()
	{
		Node *temp = head;
		tail->next = head1;
		while (temp != NULL)
		{
				temp = temp->next;
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
};


int main ()
{
	int a = 20;
	DoublyLinkedList DLL;
	for(int i=0; i<4; i++)
	{
		DLL.insert1(a);
		a-=5;
	}

  a=40;
	for(int i=0; i<4; i++)
	{
		DLL.insert2(a);
		a-=5;
	}
	DLL.Display1();
	cout<<endl;
	DLL.Display2();
	DLL.Merg();
	cout<<"\n\nAfter Merging\n";
	DLL.Display();

}