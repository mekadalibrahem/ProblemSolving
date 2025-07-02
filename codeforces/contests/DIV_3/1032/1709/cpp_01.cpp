/*
D. 1709
time limit per test
2 seconds
memory limit per test
256 megabytes

You are given two arrays of integers a1,a2,…,an
and b1,b2,…,bn. It is guaranteed that each integer from 1 to 2⋅n

appears in exactly one of the arrays.

You need to perform a certain number of operations (possibly zero) so that both of the following conditions are satisfied:

    For each 1≤i<n

, it holds that ai<ai+1 and bi<bi+1
.
For each 1≤i≤n
, it holds that ai<bi

    .

During each operation, you can perform exactly one of the following three actions:

    Choose an index 1≤i<n

and swap the values ai and ai+1
.
Choose an index 1≤i<n
and swap the values bi and bi+1
.
Choose an index 1≤i≤n
and swap the values ai and bi

    .

You do not need to minimize the number of operations, but the total number must not exceed 1709

. Find any sequence of operations that satisfies both conditions.
Input

Each test consists of multiple test cases. The first line contains a single integer t
(1≤t≤100

) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer n
(1≤n≤40) — the length of the arrays a and b

.

The second line of each test case contains n
integers a1,a2,…,an (1≤ai≤2⋅n

).

The third line of each test case contains n
integers b1,b2,…,bn (1≤bi≤2⋅n

).

It is guaranteed that each integer from 1
to 2⋅n appears either in array a or in array b

.
Output

For each test case, output the sequence of operations.

In the first line for each test case, output the number of operations k
. Note that 0≤k≤1709

.

In the following k

lines for each test case, output the operations themselves:

    If you want to swap the values ai

and ai+1, output two integers 1 and i. Note that 1≤i<n
.
If you want to swap the values bi
and bi+1, output two integers 2 and i. Note that 1≤i<n
.
If you want to swap the values ai
and bi, output two integers 3 and i. Note that 1≤i≤n

    .

It can be shown that under the given constraints, a solution always exists.
Example
Input
Copy

6
1
1
2
1
2
1
2
1 3
4 2
2
1 4
3 2
3
6 5 4
3 2 1
3
5 3 4
2 6 1

Output
Copy

0
1
3 1
1
2 1
1
3 2
9
3 1
3 2
3 3
1 1
2 1
2 2
1 2
1 1
2 1
6
2 2
1 1
1 2
2 1
3 1
3 2

Note

In the first test case, a1<b1

, so no operations need to be applied.

In the second test case, a1>b1

. After applying the operation, these values will be swapped.

In the third test case, after applying the operation, a=[1,3]
and b=[2,4]

.

In the fourth test case, after applying the operation, a=[1,2]
and b=[3,4]

.


*/

#include <bits/stdc++.h>

using namespace std;

void bubble_sort(vector<int> &v, vector<pair<int, int>> &steps, int type)
{
    for (int i = 0; i < v.size() ; i++)
    {
        for (int j = 1; j < v.size(); j++)
        {
            if (v[j - 1] > v[j])
            {
                swap(v[j - 1], v[j]);
                steps.push_back({type, j });
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<pair<int, int>> steps;
    bubble_sort(a, steps, 1);
    bubble_sort(b, steps, 2);
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            steps.push_back({3, i+1});
        }
    }
    cout << steps.size() << "\n";
    for (pair<int, int> s : steps)
    {
        cout << s.first << " " << s.second << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
