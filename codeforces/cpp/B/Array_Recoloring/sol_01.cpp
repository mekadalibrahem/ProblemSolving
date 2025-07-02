/*

B. Array Recoloring
time limit per test
2 seconds
memory limit per test
256 megabytes

You are given an integer array a
of size n

. Initially, all elements of the array are colored red.

You have to choose exactly k

elements of the array and paint them blue. Then, while there is at least one red element, you have to select any red element with a blue neighbor and make it blue.

The cost of painting the array is defined as the sum of the first k

chosen elements and the last painted element.

Your task is to calculate the maximum possible cost of painting for the given array.
Input

The first line contains a single integer t
(1≤t≤103

) — the number of test cases.

The first line of each test case contains two integers n
and k (2≤n≤5000; 1≤k<n

).

The second line contains n
integers a1,a2,…,an (1≤ai≤109

).

Additional constraint on the input: the sum of n
over all test cases doesn't exceed 5000

.
Output

For each test case, print a single integer — the maximum possible cost of painting for the given array.
Example
Input
Copy

3
3 1
1 2 3
5 2
4 2 3 1 3
4 3
2 2 2 2

Output
Copy

5
10
8

Note

In the first example, you can initially color the 2
-nd element, and then color the elements in the order 1,3. Then the cost of painting is equal to 2+3=5

.

In the second example, you can initially color the elements 1
and 5, and then color the elements in the order 2,4,3. Then the cost of painting is equal to 4+3+3=10

.

In the third example, you can initially color the elements 2,3,4
, and then color the 1-st element. Then the cost of painting is equal to 2+2+2+2=8

.



*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n, k, ans;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (k > 1)
    {
        sort(a.begin(), a.end(), greater<ll>());
        ans = accumulate(a.begin(), a.begin() + k + 1, 0LL);
    }
    else
    {
        int l = *max_element(a.begin(), a.end() - 1);
        int r = *max_element(a.begin() + 1, a.end());
        ans = max(l + a.back(), r + a[0]);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
