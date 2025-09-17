//Submitted by 1024030294
//Assignment 4 question 3

#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even to interleave.\n";
        return;
    }

    int halfSize = n / 2;
    queue<int> firstHalf;

    // Move first half into another queue
    for (int i = 0; i < halfSize; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Now interleave: one from firstHalf, one from remaining (second half in q)
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n, val;

    cout << "Enter number of elements (even): ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
