/*

A. Destroying Bridges
time limit per test
1 second
memory limit per test
256 megabytes

There are n
islands, numbered 1,2,…,n. Initially, every pair of islands is connected by a bridge. Hence, there are a total of n(n−1)2

bridges.

Everule lives on island 1
and enjoys visiting the other islands using bridges. Dominater has the power to destroy at most k

bridges to minimize the number of islands that Everule can reach using (possibly multiple) bridges.

Find the minimum number of islands (including island 1

) that Everule can visit if Dominater destroys bridges optimally.
Input

Each test contains multiple test cases. The first line contains a single integer t
(1≤t≤103

) — the number of test cases. The description of the test cases follows.

The first and only line of each test case contains two integers n
and k (1≤n≤100, 0≤k≤n⋅(n−1)2

).
Output

For each test case, output the minimum number of islands that Everule can visit if Dominater destroys bridges optimally.

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, k, r;
    cin >> t;
    while (t--)
    {

        cin >> n >> k;
        r = (n - 1) - k;
        if (r >= 1)
        {
            cout << n << "\n";
        }
        else
        {
            cout << 1 << "\n";
        }
    }

    return 0;
}