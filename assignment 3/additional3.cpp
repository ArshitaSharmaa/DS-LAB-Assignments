#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1); 
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nge[i] = st.top();
        }

        st.push(arr[i]);
    }

    return nge;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> result = nextGreaterElement(arr);

    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
