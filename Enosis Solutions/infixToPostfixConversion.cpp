

#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch) {
    if ('0' <= ch and ch <= '9') return true;
    if ('a' <= ch and ch <= 'z') return true;
    if ('A' <= ch and ch <= 'Z') return true;
    return false;
}

bool isOperator(char ch) {
    return ch == '+' or ch == '-' or ch == '*' or ch == '/' or ch == '^';
}

int operatorWeight(char ch) {
    if (ch == '^') return 3;
    else if (ch == '/' or ch == '*') return 2;
    else if (ch == '+' or ch == '-') return 1;
    return 0;
}

bool isRightAssociative(char ch) {
    return ch == '^';
}

bool highPrecedence(char a, char b) {
    int weightA = operatorWeight(a);
    int weightB = operatorWeight(b);
    if (weightA == weightB) {
        return isRightAssociative(a);
    }
    return weightA > weightB;
}

string infixToPostfix(string expression) {
    stack<char> st;
    string postfix;
    for (int i = 0; i < expression.size(); ++i) {
        if (expression[i] == '(') {
            st.push(expression[i]);
        } else if (expression[i] == ')') {
            while (st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } else if (isOperand(expression[i])) {
            postfix += expression[i];
        } else if (isOperator(expression[i])) {
            while (!st.empty() and !highPrecedence(expression[i], st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(expression[i]);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main() {
    string expression;
    cin >> expression;
    cout << infixToPostfix(expression) << '\n';

    return 0;
}

// input:K+L-M*N+(O^P)*W/U/V*T+Q
// output:KL+MN*-OP^W*U/V/T*+Q+

