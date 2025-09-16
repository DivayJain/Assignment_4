//student_id 1024030294
//Assignment 4 Q1 solution
#include <iostream>
using namespace std;

#define MAX 5  // size of queue

class Queue {
    int front, rear;
    int arr[MAX];
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow (Full)\n";
            return;
        }
        if (front == -1) front = 0;  // first element
        arr[++rear] = x;
        cout << x << " enqueued successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow (Empty)\n";
            return;
        }
        cout << arr[front] << " dequeued successfully.\n";
        front++;
        if (front > rear) {  // reset queue if empty
            front = rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty.\n";
            return;
        }
        cout << "Queue Elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
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
    Queue q;
    int choice, val;

    while (true) {
        cout << "\n----- Queue Menu -----\n";
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
}
