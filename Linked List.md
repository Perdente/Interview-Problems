# Linked List 
![singly linked list](https://miro.medium.com/max/700/1*elJncKhH_P9oQglfI1aVQA.png)

- Each node object must hold at least two pieces of information. 
	1. the node must contain the list item itself (i.e. _data_ field). 
	2. each node must hold a reference to the _next_ node.

## Tips and Template

<details>
<summary>Template</summary>
<ul>
    
```c++
#include<bits/stdc++.h>
using namespace std;


class MyLinkedList
{
private:
    struct node
    {
        int val;
        node *next;
        node (int value) {
            val = value;
            next = nullptr;
        }
    };

    node *head, *tail;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void add_node(int n) {
        node *temp = new node(n);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail -> next = temp;
            tail = tail -> next;
        }
        size++;
    }
    void print()  {
        node *temp;
        temp = head;
        while (temp != NULL) {
            cout << temp -> val << "--> ";
            temp = temp -> next;
        }
        cout << "NULL\n";
        cout << size << '\n';
    }
    int get(int index) {
        int i = 0;
        node *temp = head;
        while (temp != NULL) {
            if (i++ == index) return temp -> val;
            temp = temp -> next;
        }
        return -1;
    }
    void addAtHead(int val) {
        node *temp = new node(val);
        temp -> next = head;
        head = temp;
        size++;
    }

    void addAtTail(int val) {
        node *temp = new node(val);
        tail -> next = temp;
        tail = temp;
        size++;
    }
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index == 0) {addAtHead(val); return;}
        else if (index == size) {addAtTail(val); return;}
        else {
            node *temp = new node(val);
            node *cur = head;
            int i = 0;
            while (cur != NULL) {
                if (i++ == index - 1) {
                    temp -> next = cur -> next;
                    cur -> next = temp;
                }
                cur = cur -> next;
            }
        }
        size++;
        // cout << "loser\n";
    }
    void deleteAtIndex(int index) {
        if (!(0 <= index and index < size)) return;
        if (index == 0) {
            node *temp = head;
            head = head -> next;
            delete temp;
        } else if (index == size - 1) {
            node *cur = head;
            node *prev = NULL;
            while (cur -> next != NULL) {
                prev = cur;
                cur = cur -> next;
            }
            delete cur;
            tail = prev;
            tail -> next = NULL;
        }

        else {
            node *cur = head;
            int i = 0;
            while (cur -> next != NULL) {
                if (i++ == index - 1) {
                    node *temp = cur -> next -> next;
                    delete cur -> next;
                    cur -> next = temp;
                }
                cur = cur -> next;
            }
        }
        size--;
    }
};
int main() {
    MyLinkedList a;
    a.add_node(2);
    a.add_node(3);
    a.add_node(5);
    a.print();
    a.addAtIndex(2, 4);
    a.print();
    a.addAtHead(1);
    a.print();
    a.addAtTail(6);
    a.print();
    a.addAtIndex(0,0);
    a.print();
    a.addAtIndex(7,7);
    a.print();
    cout << a.get(3) << '\n';
    a.deleteAtIndex(3);
    a.print();
    a.deleteAtIndex(6);
    a.print();
    a.deleteAtIndex(5);
    a.print();
    return 0;
}
	
output:
/*
2--> 3--> 5--> NULL
3
2--> 3--> 4--> 5--> NULL
4
1--> 2--> 3--> 4--> 5--> NULL
5
1--> 2--> 3--> 4--> 5--> 6--> NULL
6
0--> 1--> 2--> 3--> 4--> 5--> 6--> NULL
7
0--> 1--> 2--> 3--> 4--> 5--> 6--> 7--> NULL
8
3
0--> 1--> 2--> 4--> 5--> 6--> 7--> NULL
7
0--> 1--> 2--> 4--> 5--> 6--> NULL
6
0--> 1--> 2--> 4--> 5--> NULL
5

*/
```

</ul>
</details>

- Adding node to a linked list

```c++
node *temp = new node;
temp -> data = n;
temp -> next = NULL;

if (head == NULL) {
    head = temp;
    tail = temp;
} else {
    tail -> next = temp;
    tail = tail -> next;
}
```

- Printing values from Linked List
```c++
node *temp;
temp = head;
while (temp != NULL) {
    cout << temp -> data << "--> ";
    temp = temp -> next;
}
cout << "NULL";
```

- When we talk about linked list, we are normally talk about singly linked list. There is also a Doubly Linked list defined as follows:

    ![Leetcode Linked List Learn Doubly Linked List](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/17/screen-shot-2018-04-17-at-161130.png)

    ```python
    class Node
        def __init__(self, val):
            self.val = val
            self.prev = None
            self.next = None
    ```

- Linked list in-place operation can be confusing (i.e. insert or delete), its better to ***draw the structure*** and it'll become much more obvious 

    For example when deleting a node in the middle :

    ![Leetcode Linked List Learn Delete Operation](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/26/screen-shot-2018-04-26-at-203640.png)

    ```python
    node = self.get_node(index)
    prev_node = node.prev
    next_node = node.next
    prev_node.next = next_node
    next_node.prev = prev_node
    ```

- Its better to use a ***Dummy head*** most of time, especially when deleting node is required

    For example:

    ```python
    def linked_list(root):
        dummy = Node("x")
        dummy.next = root

        # Do your logic here

        return dummy.next
    ```

- In many cases, you need to track the previous node of the current node.

    ```python
    dummy = Node("x")
    dummy.next = root

    prev = dummy
    node = head

    while node:
        prev = node
        node = node.next
    ```

- ***Two pointer*** approach is widely used in linked list, such as detecting cycle, remove n-th node etc

    For example when detecting cycle:
    ```python
    def hasCycle(self, head: ListNode) -> bool:
        slow = head
        fast = head
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
            if slow == fast:
                return True
            
        return False
    ```

- It is common to use ***Hashmap or hashset*** to store visited nodes, its widely use to find intersection or beginning of cyclic linked list

    ```python
    def detectCycle(self, head: ListNode) -> ListNode:
        visited = set()
        while head:
            if head.next in visited:
                return head.next
            visited.add(head)
            head = head.next
        return
    ```


Here is a great comparison of ***time complexity*** between the linked list and the array from Leetcode.

![Leetcode Linked List Learn Conclusion](https://assets.leetcode.com/uploads/2020/10/02/comparison_of_time_complexity.png)


Reference:

- [Leetcode Introduction to Linked List](https://leetcode.com/explore/learn/card/linked-list/)
- [Singly-Linked list in JavaScript](https://medium.com/@1991dharapatel/singly-linked-list-in-javascript-aafc71e0cf73)
- [Linked Lists for Technical Interviews - Full Course](https://www.youtube.com/watch?v=Hj_rA0dhr2I)


Practice:

- Practice using Stuckty
    - [linked list values](https://structy.net/problems/linked-list-values)
    - [sum list](https://structy.net/problems/sum-list) 
    - [linked list find](https://structy.net/problems/linked-list-find)
    - [get node value](https://structy.net/problems/get-node-value)
    - [reverse list](https://structy.net/problems/reverse-list)
    - [zipper lists](https://structy.net/problems/zipper-lists)

- Basic questions:
    - [707. Design Linked List](https://leetcode.com/problems/design-linked-list/)
    - [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
    - [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
    - [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

- Tricky questions:
    - [142. Linked List Cycle II - Find linked list cycle start point](https://leetcode.com/problems/linked-list-cycle-ii/)
    - [430. Flatten a Multilevel Doubly Linked List](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)
    - [138. Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)
