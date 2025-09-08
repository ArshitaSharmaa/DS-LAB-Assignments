#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
    stack<int> st;
    int mini;

public:
    MinStack() {
        mini = INT_MAX;
    }

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            mini = value;
        }
        else if (value >= mini) {
            st.push(value);
        }
        else {
            st.push(2 * value - mini);
            mini = value;
        }
    }

    void pop() {
        if (st.empty()) return; 
        int x = st.top();
        st.pop();
        if (x < mini) {
            mini = 2 * mini - x;
        }
        if (st.empty()) mini = INT_MAX; 
    }

    int top() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        int x = st.top();
        if (x >= mini) return x;
        return mini; 
    }

    int getMin() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return mini;
    }
};

int main() {
    MinStack st;
    st.push(4);
    st.push(7);
    st.push(3);
    st.push(2);

    st.pop();
    cout << st.getMin() << endl; // 3
    st.pop();
    cout << st.getMin() << endl; // 4
    st.pop();
    cout << st.getMin() << endl; // 4
    st.pop();
    cout << st.getMin() << endl; // Stack empty

    return 0;
}