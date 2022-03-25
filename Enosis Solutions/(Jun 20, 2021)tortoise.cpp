/*
1. Reverse an array
2. Find duplicate
*/
1.
void malena() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int i = 0, j = n - 1;
    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++, j--;
    }
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
        cout << '\n';
}


2.
/*
https://leetcode.com/problems/find-the-duplicate-number/
https://www.youtube.com/watch?v=wjYnzkAhcNk
1. Linklist cycle detection
2. Floyed Tortoise algorithm
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (fast == slow) break;
        }
        int slow2 = 0;
        while (true) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) break;
        }
        return slow;
    }
};

/*
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
using System;
class HelloWorld {
  static void Main() {
    int[] arr = {1, 2, 5, 3, 4, 2};
    int slow = 0, fast = 0;
    while (true) {
        slow = arr[slow];
        fast = arr[arr[fast]];
        if (slow == fast) break;
    }
    int slow2 = 0;
    while (true) {
        slow = arr[slow];
        slow2 = arr[slow2];
        if (slow == slow2) break;
    }
    Console.WriteLine(slow);
  }
}
*/
