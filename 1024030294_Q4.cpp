//Submitted by 1024030294
//Assignment 4 Q4

#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(const string &s) {
    queue<char> q;
    int freq[256] = {0}; 
    for (char ch : s) {
        freq[(unsigned char)ch]++;  // increment frequency
        q.push(ch);                 
        // pop chars with frequency > 1
        while (!q.empty() && freq[(unsigned char)q.front()] > 1) {
            q.pop();
        }

        // print first non-repeating char or -1
        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Enter characters separated by space (like 'a a b c'): ";
    getline(cin, s);

  //removing spaces
    string clean;
    for (char c : s) {
        if (c != ' ') clean.push_back(c);
    }

    cout << "Output: ";
    firstNonRepeating(clean);

    return 0;
}
