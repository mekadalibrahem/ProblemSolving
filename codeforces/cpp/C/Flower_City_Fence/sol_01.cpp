/*
C. Flower City Fence
time limit per test
2 seconds
memory limit per test
256 megabytes

Anya lives in the Flower City. By order of the city mayor, she has to build a fence for herself.

The fence consists of n
planks, each with a height of ai meters. According to the order, the heights of the planks must not increase. In other words, it is true that ai≥aj for all i<j

.

Anya became curious whether her fence is symmetrical with respect to the diagonal. In other words, will she get the same fence if she lays all the planks horizontally in the same order.

For example, for n=5
, a=[5,4,3,2,1], the fence is symmetrical. Because if all the planks are laid horizontally, the fence will be [5,4,3,2,1]

, as shown in the diagram.

On the left is the fence [5,4,3,2,1]

, on the right is the same fence laid horizontally

But for n=3
, a=[4,2,1], the fence is not symmetrical. Because if all the planks are laid horizontally, the fence will be [3,2,1,1]

, as shown in the diagram.

On the left is the fence [4,2,1]

, on the right is the same fence laid horizontally

Help Anya and determine whether her fence is symmetrical.
Input

The first line of the input contains an integer t
(1≤t≤104

) — the number of test cases.

The description of the test cases follows.

The first line of a test case contains a single integer n
(1≤n≤2⋅105

) — the length of the fence.

The second line of a test case contains n
integers a1≥a2≥a3≥⋯≥an (1≤ai≤109

) — the heights of the planks.

The sum of the values of n
for all test cases does not exceed 2⋅105

.
Output

For each test case, output "YES" if the fence is symmetrical, otherwise output "NO".

You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes" and "YES" will be accepted as a positive answer.
Example
Input
Copy

7
5
5 4 3 2 1
3
3 1 1
3
4 2 1
1
2
5
5 3 3 1 1
5
5 5 5 3 3
2
6 1

Output
Copy

YES
YES
NO
NO
YES
YES
NO

Note

In the first and second test cases of the example, the fence is symmetrical.

In the third test case of the example, the fence is not symmetrical. If the planks are laid horizontally, the fence will be [3,2,1,1]

.

In the fourth test case of the example, the fence is not symmetrical. If the planks are laid horizontally, the fence will be [1,1]

.

In the fifth and sixth test cases of the example, the fence is symmetrical.

In the seventh test case of the example, the fence is not symmetrical. If the planks are laid horizontally, the fence will be [2,1,1,1,1,1]
.

*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[i] = x;
    }

    if (a[0] != n)
    {
        cout << "NO\n";
        return;
    }
    
    for (ll i = n; i > 0; i--)
    {
        while (b.size() < a[i-1])
        {
            b.push_back(i);
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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