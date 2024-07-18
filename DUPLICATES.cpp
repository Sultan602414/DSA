#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void append(int value) {

        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void display1()
    {
        Node *temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }

    void removeDuplicate() {
    Node* current = head;
    Node* index = NULL;
    Node* temp = NULL;

    while (current != NULL) {
        index = current->next;

        while (index != NULL) {
            if (index->data == current->data) {
                temp = index->next;


                if (index->prev != NULL) {
                    index->prev->next = temp;
                } else {

                    head = temp;
                }

                if (temp != NULL) {
                    temp->prev = index->prev;
                }

                delete index;
                index = temp;
            } 
			else
			{
                index = index->next;
            }
        }

        current = current->next;
    }
    }
    void display()
    {
        Node *temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }


};
int main() {
    DoublyLinkedList list;
    list.append(80);
    list.append(40);
    list.append(30);
    list.append(60);
    list.append(80);
    list.append(40);
    list.append(100);
    list.append(100);
    list.append(120);
    cout << "Doubly Linked List" << endl;
    list.display1();
    cout << "Doubly LinkedList Remove Duplicate" << endl;
    list.removeDuplicate();
    list.display();

    return 0;
}
