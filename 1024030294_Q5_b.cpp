//Student ID - 1024030294
//Assignment 4 Question 5 (b) Submitted

#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);  // add new element
        // rotate the queue so new element comes to front
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << x << " pushed onto stack.\n";
    }

//pop function remains same
    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow (Empty)\n";
            return;
        }
        cout << q.front() << " popped from stack.\n";
        q.pop();
    }
//top function behaves like q.front()
    int top() {
        if (q.empty()) {
            cout << "Stack is Empty.\n";
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is Empty.\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        queue<int> temp = q;
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
        cout << "\n----- Stack Using One Queue Menu -----\n";
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
