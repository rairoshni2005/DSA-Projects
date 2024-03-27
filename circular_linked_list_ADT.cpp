#include <iostream>
using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;

    // Constructor to initialize a node with data and next pointer
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
    int size;

public:
    // Constructor to initialize an empty linked list
    CircularLinkedList() {
        head = nullptr;
        size = 0;
    }

    // Destructor to free the memory allocated for nodes
    ~CircularLinkedList() {
        if (head == nullptr) return;
        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
        head = nullptr;
    }

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            newNode->next = head;
            last->next = newNode;
            head = newNode;
        }
        size++;
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = newNode;
            newNode->next = head;
        }
        size++;
    }

    // Function to display the elements of the linked list
    void display() {
        if (head == nullptr) {
            cout << "Circular linked list is empty." << endl;
            return;
        }
        Node* current = head;
        cout << "Circular linked list elements: ";
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    // Function to get the size of the linked list
    int getSize() {
        return size;
    }
};

int main() {
    CircularLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtBeginning(0);

    list.display();  // Output: Circular linked list elements: 0 1 2 3
    cout << "Size of the circular linked list: " << list.getSize() << endl;  // Output: Size of the circular linked list: 4

    return 0;
}
