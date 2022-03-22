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

bool isLeftAssociative(char ch) {
    return ch != '^';
}

bool lowPrecedence(char a, char b) {
    int weightA = operatorWeight(a);
    int weightB = operatorWeight(b);
    if (weightA == weightB) {
        return isLeftAssociative(a);
    }
    return weightA > weightB;
}

string infixToPrefix(string expression) {
    stack<char> st;
    string prefix;
    for (int i = 0; i < expression.size(); ++i) {
        if (expression[i] == ')') {
            st.push(expression[i]);
        } else if (expression[i] == '(') {
            while (st.top() != ')') {
                prefix += st.top();
                st.pop();
            }
            st.pop();
        } else if (isOperand(expression[i])) {
            prefix += expression[i];
        } else if (isOperator(expression[i])) {
            while (!st.empty() and !lowPrecedence(expression[i], st.top())) {
                prefix += st.top();
                st.pop();
            }
            st.push(expression[i]);
        }
    }
    while (!st.empty()) {
        prefix += st.top();
        st.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string expression;
    cin >> expression;
    reverse(expression.begin(), expression.end());
    string prefix = infixToPrefix(expression);
    reverse(prefix.begin(), prefix.end());
    cout << prefix << '\n';
    return 0;
}
/*
Input: K+L-M*N+(O^P)*W/U/V*T+Q
Output: QTVUWPO^*//*NM*LK+-++

*/

