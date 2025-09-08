#include <iostream>
#include <queue>   // for queue
#include <cstring> // for strlen
using namespace std;
int main() {
    char input[100];
    cout << "Enter the string: ";
    cin.getline(input, 100);   // take input (with spaces)
queue<char> q;
    int freq[256] = {0};   // frequency of characters
cout << "Output: ";
    for (int i = 0; i < strlen(input); i++) {
        char ch = input[i];
        if (ch == ' ') continue;   // ignore spaces
freq[(int)ch]++;   // update frequency
        q.push(ch);        // add to queue
// remove characters from queue front if they are repeating
        while (!q.empty() && freq[(int)q.front()] > 1) {
            q.pop();
        }
if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
cout << endl;
    return 0;
}
