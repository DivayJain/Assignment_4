//Submitted by student id - 1024030294
//Assignment 4 question 5 (a)

#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2; // two queues

public:
    void push(int x) {
        // push to empty q2
        q2.push(x);

        // move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // swap names of q1 and q2
        swap(q1, q2);

        cout << x << " pushed onto stack.\n";
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow (Empty)\n";
            return;
        }
        cout << q1.front() << " popped from stack.\n";
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }

    void display() {
        if (q1.empty()) {
            cout << "Stack is Empty.\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        queue<int> temp = q1;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "\n";
    }
};

int main() {
    Stack s;
    int choice, val;

    while (true) {
        cout << "\n----- Stack Using Two Queues Menu -----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            s.push(val);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            val = s.top();
            if (val != -1)
                cout << "Top element: " << val << "\n";
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << (s.empty() ? "Stack is Empty.\n" : "Stack is NOT Empty.\n");
            break;
        case 6:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
