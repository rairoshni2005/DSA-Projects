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

class SinglyLinkedList {
private:
    Node* head;
    int size;

public:
    // Constructor to initialize an empty linked list
    SinglyLinkedList() {
        head = nullptr;
        size = 0;
    }

    // Destructor to free the memory allocated for nodes
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    // Function to display the elements of the linked list
    void display() {
        if (head == nullptr) {
            cout << "Linked list is empty." << endl;
            return;
        }
        Node* current = head;
        cout << "Linked list elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to get the size of the linked list
    int getSize() {
        return size;
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtBeginning(0);

    list.display();  // Output: Linked list elements: 0 1 2 3
    cout << "Size of the linked list: " << list.getSize() << endl;  // Output: Size of the linked list: 4

    return 0;
}
