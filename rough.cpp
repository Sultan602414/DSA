#include <iostream>
#include <iomanip>
#include <limits>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class node {
public:
    int no_of_courses = 0, student = 0;
    float final_grade[50];
    float grades, grad[50], finalgrade = 0;
    string course_name, corse_nam[50];
    node* next;
    node* prev;

    node(int value) {
        next = NULL;
        prev = NULL;
        student = value;

        cout << "ENTER THE NO OF COURSES of student: " << student + 1 << endl;
        cin >> no_of_courses;
        cout << "ENTER THE NAMES AND THE GRADE OF COURSES: " << endl;
        for (int i = 0; i < no_of_courses; i++) {
            cout << "COURSE " << i + 1 << endl;
            cin >> course_name;
            corse_nam[i] = course_name;
            cout << "GRADE OF its COURSE " << i + 1 << endl;
            cin >> grades;
            grad[i] = grades;
        }

        // Calculate CGPA of all courses by a single student
        for (int i = 0; i < no_of_courses; i++) {
            finalgrade += grad[i];
        }
        final_grade[student] = finalgrade / no_of_courses;
        cout << "CGPA " << final_grade[student] << endl;
    }
};

class TreeNode {
public:
    int student;
    node* studentNode;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int st, node* node) {
        student = st;
        studentNode = node;
        left = NULL;
        right = NULL;
    }
};

class student_management {
public:
    node* head;

    student_management() {
        head = NULL;
    }

    void list_of_student(int value) {
        node* newnode = new node(value);
        if (head == NULL) {
            head = newnode;
        }
        else {
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    void display(string arr[], int& count, int front) {
        int x;
        node* ptr = head;

        cout << "1 for DETAILED INFO of current students: \n2 for just name and roll no of current students\n";
        cin >> x;

        if (x == 1) {
            node* temp = head;
            while (temp != NULL) {
                cout << "ROLL NO " << (temp->student) + 1;
                cout << " " << arr[front];
                cout << " has " << temp->no_of_courses;
                cout << " courses with cgpa " << ptr->final_grade[front] << endl;

                temp = temp->next;
                front++;
            }
        }
        else if (x == 2) {
            for (int i = front; i < count; i++) {
                cout << arr[i] << " roll no " << i + 1 << " WITH FINAL GRADE " << ptr->final_grade[i + 1] << endl;
            }
        }
    }

    node* search(int st) {
        node* temp = head;
        while (temp != NULL) {
            if (temp->student == st) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void insert(int st, node* new_node) {
        node* temp = search(st);
        if (temp == NULL) {
            cout << "Student not found." << endl;
            return;
        }
        if (temp->next == NULL) {
            temp->next = new_node;
        }
        else {
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }

    void my_deque(string arr[], int& count, int& front) {
        front++;
        arr[front] = " ";
    }

    void pass_out(string arr[], int& count, int& front) {
        int x;
        cout << "HOW MANY STUDENTS PASS THIS SEMESTER: \n";
        cin >> x;
        for (int i = 0; i < x; ++i) {
            my_deque(arr, count, front);
        }
    }

    void swap(int& a, int& b) {
        int c;
        c = a;
        a = b;
        b = c;
    }

    void swap2(string& a, string& b) {
        string c;
        c = a;
        a = b;
        b = c;
    }
};

class BST {
public:
    TreeNode* root;

    BST() {
        root = NULL;
    }

    node* searchRecursive(TreeNode* root, int st) {
        if (root == NULL || root->student == st) {
            return (root == NULL) ? NULL : root->studentNode;
        }

        if (st < root->student) {
            return searchRecursive(root->left, st);
        }
        else {
            return searchRecursive(root->right, st);
        }
    }

    node* search(int st) {
        return searchRecursive(root, st);
    }

    TreeNode* insertRecursive(TreeNode* root, int st, node* new_node) {
        if (root == NULL) {
            return new TreeNode(st, new_node);
        }

        if (st < root->student) {
            root->left = insertRecursive(root->left, st, new_node);
        }
        else if (st > root->student) {
            root->right = insertRecursive(root->right, st, new_node);
        }

        return root;
    }

    void insert(int st, node* new_node) {
        root = insertRecursive(root, st, new_node);
    }
};

class MaxHeap {
private:
    vector<float> heap;

    void heapifyUp() {
        int currentIndex = heap.size() - 1;
        while (currentIndex > 0) {
            int parentIndex = (currentIndex - 1) / 2;
            if (heap[currentIndex] > heap[parentIndex]) {
                swap(heap[currentIndex], heap[parentIndex]);
                currentIndex = parentIndex;
            }
            else {
                break;
            }
        }
    }

    void heapifyDown() {
        int currentIndex = 0;
        int heapSize = heap.size();
        while (true) {
            int leftChildIndex = 2 * currentIndex + 1;
            int rightChildIndex = 2 * currentIndex + 2;
            int largestIndex = currentIndex;

            if (leftChildIndex < heapSize && heap[leftChildIndex] > heap[largestIndex]) {
                largestIndex = leftChildIndex;
            }

            if (rightChildIndex < heapSize && heap[rightChildIndex] > heap[largestIndex]) {
                largestIndex = rightChildIndex;
            }

            if (largestIndex != currentIndex) {
                swap(heap[currentIndex], heap[largestIndex]);
                currentIndex = largestIndex;
            }
            else {
                break;
            }
        }
    }

public:
    void insert(float value) {
        heap.push_back(value);
        heapifyUp();
    }

    float extractMax() {
        if (heap.empty()) {
            cout << "Heap is empty." << endl;
            return -1; // Assuming -1 as an invalid value for CGPA
        }

        float maxVal = heap[0];
        int lastIdx = heap.size() - 1;
        heap[0] = heap[lastIdx];
        heap.pop_back();
        heapifyDown();

        return maxVal;
    }
};

int displayMenu() {
    int choice;
    cout << "\nMENU:\n";
    cout << "1. View Max Heap\n";
    cout << "2. Enroll New Student\n";
    cout << "3. Expel Student\n";
    cout << "4. Display All Students\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    student_management std;
    BST bst;
    MaxHeap maxHeap;

    int count = 0, x, z, front = 0;
    string arr[40], y;

    cout << "ENTER THE NO OF STUDENTS who are enrolled in this semester: \n";
    cin >> count;

    cout << "ENTER THE NAMES OF THE STUDENT roll wise: " << endl;
    for (int i = 0; i < count; i++) {
        cout << "student " << i + 1 << " NAME : ";
        cin >> y;
        arr[i] = y;
        std.list_of_student(i);
        bst.insert(i, std.head); // Inserting into BST
        maxHeap.insert(std.head->final_grade[i]); // Inserting into MaxHeap
    }

    do {
        x = displayMenu();
        switch (x) {
            case 1:
                cout << "Max CGPA: " << maxHeap.extractMax() << endl;
                break;
            case 2:
                cout << "Enter details for the new student: " << endl;
                cout << "student " << count + 1 << " NAME : ";
                cin >> y;
                arr[count] = y;
                std.list_of_student(count);
                bst.insert(count, std.head); // Inserting into BST
                maxHeap.insert(std.head->final_grade[count]); // Inserting into MaxHeap
                count++;
                break;
            case 3:
                cout << "Enter the Roll No of the student to be expelled: ";
                cin >> z;
                std.my_deque (arr, count,  front) ;
        
    // Roll No is 1-based, adjust to 0-based
                break;
            case 4:
                std.display(arr, count, front);
                break;
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (x != 0);

    return 0;
}
