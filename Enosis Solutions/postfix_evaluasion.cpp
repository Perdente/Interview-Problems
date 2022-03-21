// https://github.com/doocs/leetcode/blob/main/solution/1600-1699/1628.Design%20an%20Expression%20Tree%20With%20Evaluate%20Function/README_EN.md#1628-design-an-expression-tree-with-evaluate-function
/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
    string val;
    Node* left;
    Node* right;
};

class MyNode : public Node {
public:
    MyNode(string val) {
        this->val = val;
    }

    MyNode(string val, Node* left, Node* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }

    int evaluate() const {
        if (!(val == "+" || val == "-" || val == "*" || val == "/")) return stoi(val);
        auto leftVal = left->evaluate(), rightVal = right->evaluate();
        if (val == "+") return leftVal + rightVal;
        if (val == "-") return leftVal - rightVal;
        if (val == "*") return leftVal * rightVal;
        if (val == "/") return leftVal / rightVal;
        return 0;
    }
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        stack<MyNode*> stk;
        for (auto s : postfix)
        {
            MyNode* node;
            if (s == "+" || s == "-" || s == "*" || s == "/")
            {
                auto right = stk.top();
                stk.pop();
                auto left = stk.top();
                stk.pop();
                node = new MyNode(s, left, right);
            }
            else
            {
                node = new MyNode(s);
            }
            stk.push(node);
        }
        return stk.top();
    }
};

int main() {
    vector<string> postfix ({"3","4","+","2","*","7","/"});
    TreeBuilder* obj = new TreeBuilder();
    Node* expTree = obj->buildTree(postfix);

    int ans = expTree->evaluate();
    cout << ans << '\n';
}
/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
