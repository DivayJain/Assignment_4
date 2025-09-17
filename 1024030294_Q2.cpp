//Submitted by 1024030294
//Assigment 4 Q2
#include <iostream>
using namespace std;

#define MAX 5  // size of circular queue

class CircularQueue {
    int front, rear;
    int arr[MAX];
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow (Full)\n";
            return;
        }
        if (front == -1) { // first element
            front = 0;
            rear = 0;
            arr[rear] = x;
        } else {
            rear = (rear + 1) % MAX;
            arr[rear] = x;
        }
        cout << x << " enqueued successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow (Empty)\n";
            return;
        }
        cout << arr[front] << " dequeued successfully.\n";
        if (front == rear) {
            // only one element was there
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty.\n";
            return;
        }
        cout << "Queue Elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << "\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty.\n";
            return;
        }
        cout << "Front Element: " << arr[front] << "\n";
    }
};

int main() {
    CircularQueue q;
    int choice, val;

    while (true) {
        cout << "\n----- Circular Queue Menu -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << (q.isEmpty() ? "Queue is Empty.\n" : "Queue is NOT Empty.\n");
            break;
        case 6:
            cout << (q.isFull() ? "Queue is Full.\n" : "Queue is NOT Full.\n");
            break;
        case 7:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
