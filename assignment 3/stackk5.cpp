#include <iostream>
#include <cstring>
#include <cmath> 
using namespace std;

int stackArr[100];
int top = -1;

// push onto stack
void push(int x) {
    stackArr[++top] = x;
}

// pop from stack
int pop() {
    return stackArr[top--];
}

int evaluatePostfix(char postfix[]) {
    for (int i = 0; i < strlen(postfix); i++) {
        char c = postfix[i];

        
        if (c >= '0' && c <= '9') {
            push(c - '0'); 
        }
   
        else {
            int val2 = pop();
            int val1 = pop();
            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push(pow(val1, val2)); break;
            }
        }
    }
    return pop(); 
}

int main() {
    char postfix[100];
    cout << "Enter postfix expression (single digit operands): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}