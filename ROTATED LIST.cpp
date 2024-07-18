#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void addNode(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    void display() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void rotate(int k) {
        if (head == nullptr || k == 0) {
            return;
        }

        int length = 0;
        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
            length++;
        }
        length++;

        k = k % length;

        if (k == 0) {
            return;
        }

        current = head;
        for (int i = 1; i < length - k; i++) {
            current = current->next;
        }

        Node* newHead = current->next;
        Node* newTail = current;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = head;
        head->prev = current;

        newHead->prev = nullptr;
        newTail->next = nullptr;

        head = newHead;
    }
};

int main() {
    DoublyLinkedList list;

    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    cout << "Original list: ";
    list.display();

    int k = 2;
    list.rotate(k);

    cout << "Rotated list by " << k << " positions: ";
    list.display();

    return 0;
}