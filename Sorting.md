![](https://lamfo-unb.github.io/img/Sorting-algorithms/Complexity.png)


<details>
<summary>Code</summary>
<ul>
    
```c++
#include<bits/stdc++.h>
using namespace std;
#define int long long int


void bubbleSort(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (v[j] > v[j + 1]) swap(v[j], v[j + 1]);
        }
    }
    for (auto val: v) cout << val << " ";
        cout << '\n';
}

void selectionSort(vector<int> v) {
    int n = v.size();
    for (int i = 0; i < n - 1; ++i) {
        int mi_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (v[j] < v[mi_idx]) {
                mi_idx = j;
            }
        }
        swap(v[mi_idx], v[i]);
    }
    for (auto val: v) cout << val << " ";
        cout << '\n';
}

void countingSort(vector<int> v) {
    int n = v.size();
    int count[20];
    memset(count, 0, sizeof count);
    for (auto it: v) count[it]++;
    vector<int> sorted;
    for (int i = 0; i < 20; ++i) {
        while (count[i]) {
            sorted.push_back(i);
            count[i]--;
        }
    }
    for(auto val: sorted) cout << val << " ";
        cout << '\n';

}


void malena() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &it: v) cin >> it;
    // bubbleSort(v);
    // selectionSort(v);
    // countingSort(v);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t, c = 0;
    t = 1;
    // cin >> t;
    while(t--) {
        // cout << "Case " << ++c <<": ";
        malena();
    }
    return 0;
}

```

</ul>
</details>

Ref : 
- [Course](https://academy.shahjalalshohag.com/course/a-complete-guideline-to-competitive-programming-phase-1#table-of-contents)
- [article](https://lamfo-unb.github.io/2019/04/21/Sorting-algorithms/)
