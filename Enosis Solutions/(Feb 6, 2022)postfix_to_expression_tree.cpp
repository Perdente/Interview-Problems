/*
Given a postfix notation. Build the expression tree.
*/

// https://www.youtube.com/watch?v=WHs-wSo33MM
/*
Infix  : 2 + 3 (Operator is in the middle of Operands)
Prefix : + 2 3 (Operator is before the Operands)
Postfix: 2 3 + (Operator is after the operands)
*/
/*
Procedure -
. If operator pop out two pointers from stack and put operator between them
. Otherwise create a new pointer and push it in the stack

*/

#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    node *left;
    node *right;
};

node *arr[100];
string postfix;
int top = -1;

bool isOperator (char ch) {
    return ch == '+' or ch == '-' or ch == '*' or ch == '/';
}
void push (node *tree) {
    top++;
    arr[top] = tree;
}

node *pop() {
    top--;
    return arr[top + 1];
}
void create_expr_tree(string &suffix) {
    node *newl, *ptr1, *ptr2;
    for (int i = 0; i < suffix.size(); ++i) {
        char symbol = suffix[i];
        if (isOperator(symbol)) {
            ptr1 = pop();
            ptr2 = pop();
            newl = new node;
            newl -> data = symbol;
            newl -> left = ptr2;
            newl -> right = ptr1;
            push(newl);
        } else {
            newl = new node;
            newl -> data = symbol;
            newl -> left = NULL;
            newl -> right = NULL;
            push(newl);
        }
    }
}

void inorder (node *tree) {
    if (tree != NULL) {
        inorder(tree -> left);
        cout << tree -> data;
        inorder(tree -> right);
    }
}
void preorder (node *tree) {
    if (tree != NULL) {
        cout << tree -> data;
        preorder(tree -> left);
        preorder(tree -> right);
    }
}
void postorder (node *tree) {
    if (tree != NULL) {
        postorder(tree -> left);
        postorder(tree -> right);
        cout << tree -> data;
    }
}
int main() {
    cout << "Enter postfix expression : ";
    cin >> postfix;
    create_expr_tree(postfix);
    cout << "\nInorder Traversal: ";
    inorder(arr[0]);
    cout << "\nPreorder Traversal: ";
    preorder(arr[0]);
    cout << "\nPostorder Traversal: ";
    postorder(arr[0]);

    return 0;
}


// Enter postfix expression : ab*c/ef/g*+k+xy*-
// Inorder Traversal: a*b/c+e/f*g+k-x*y
// Preorder Traversal: -++/*abc*/efgk*xy
// Postorder Traversal: ab*c/ef/g*+k+xy*-
