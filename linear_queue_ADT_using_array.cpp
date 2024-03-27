#include <iostream>
using namespace std;

class LinearQueue {
private:
    int *queue;
    int capacity;
    int front;
    int rear;
    int size;

public:
    LinearQueue(int cap) {
        capacity = cap;
        queue = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~LinearQueue() {
        delete[] queue;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue more items." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = item;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue from an empty queue." << endl;
            return -1;
        }
        int item = queue[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot peek into an empty queue." << endl;
            return -1;
        }
        return queue[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue contents: ";
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << queue[rear] << endl;
    }
};

int main() {
    LinearQueue queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.display();  // Output: Queue contents: 1 2 3 4 5

    cout << "Dequeue: " << queue.dequeue() << endl;  // Output: Dequeue: 1

    queue.display();  // Output: Queue contents: 2 3 4 5

    cout << "Peek: " << queue.peek() << endl;  // Output: Peek: 2

    queue.enqueue(6);
    queue.enqueue(7);

    queue.display();  // Output: Queue contents: 2 3 4 5 6 7

    return 0;
}
