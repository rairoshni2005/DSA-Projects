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

class LinearQueueLinkedList {
private:
    Node* front;
    Node* rear;
    int size;

public:
    // Constructor to initialize an empty queue
    LinearQueueLinkedList() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Destructor to free the memory allocated for nodes
    ~LinearQueueLinkedList() {
        Node* current = front;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        front = nullptr;
        rear = nullptr;
    }

    // Function to enqueue a new element into the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;
        size++;
    }

    // Function to dequeue an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue from an empty queue." << endl;
            return -1;
        }
        int dequeuedValue = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
        if (isEmpty()) {
            rear = nullptr;
        }
        return dequeuedValue;
    }

    // Function to peek at the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek into an empty queue." << endl;
            return -1;
        }
        return front->data;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to get the size of the queue
    int getSize() {
        return size;
    }
};

int main() {
    LinearQueueLinkedList queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Front element of the queue: " << queue.peek() << endl;  // Output: Front element of the queue: 1

    cout << "Dequeued element: " << queue.dequeue() << endl;  // Output: Dequeued element: 1

    cout << "Front element of the queue after dequeue: " << queue.peek() << endl;  // Output: Front element of the queue after dequeue: 2

    return 0;
}
