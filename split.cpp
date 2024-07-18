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
			tail1=temp;
			temp = temp->next;
		}
	}
void split()
{
	Node *temp = head;
	tail = head;
	int count = 0;
	cout<<endl;
	while(count != 4)
	{
		tail=temp->next;
		tail->previous=temp;
		temp = tail;
		count++;
	}
		tail = temp->previous;
		head1 = temp;
		tail->next = NULL;
}
};


int main ()
{
	int a = 40;
	DoublyLinkedList DLL;
	for(int i=0; i<8; i++)
	{
		DLL.insert(a);
		a-=5;
	}
	DLL.Display();

	DLL.split();
	cout<<"\nAfter Spliting"<<endl;
	DLL.Display1();
	cout<<endl;
	DLL.Display2();
}