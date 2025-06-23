/*
D. Line
time limit per test
2 seconds
memory limit per test
256 megabytes

There are n

people in a horizontal line, each looking either to the left or the right. Each person counts the number of people in the direction they are looking. The value of the line is the sum of each person's count.

For example, in the arrangement LRRLL, where L stands for a person looking left and R stands for a person looking right, the counts for each person are [0,3,2,3,4]
, and the value is 0+3+2+3+4=12

.

You are given the initial arrangement of people in the line. For each k
from 1 to n, determine the maximum value of the line if you can change the direction of at most k

people.
Input

The input consists of multiple test cases. The first line contains an integer t
(1≤t≤100

) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n
(1≤n≤2⋅105

) — the length of the line.

The following line contains a string consisting of n

characters, each of which is either L or R, representing a person facing left or right, respectively — the description of the line.

It is guaranteed that the sum of n
over all test cases does not exceed 2⋅105

.

Please note that the answer for some test cases won't fit into 32-bit integer type, so you should use at least 64-bit integer type in your programming language (like long long for C++).
Output

For each test case, output n
space-separated non-negative integers — the maximum value of the line if you can change the direction of at most k people for each k from 1 to n, inclusive.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<vector<ll>> res;
    while (t--)
    {
        res.push_back(solve());
    }

    for (vector<ll> v : res)
    {
        for (ll r : v)
        {
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}

vector<ll> solve()
{
    ll n;
    cin >> n;
    vector<char> line(n);
    vector<ll> cur(n, 0);
    vector<ll> rev;
    ll init_sum = 0;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        line[i] = c;
        ll flipped_value = 0;
        if (c == 'L')
        {
            cur[i] = i;
            flipped_value = (n - i - 1) - i;
        }
        else
        {
            cur[i] = n - i - 1;
            flipped_value = i - (n - i - 1);
        }
        if (flipped_value > 0)
        {
            rev.push_back(flipped_value);
        }
        init_sum += cur[i];
    }
    sort(rev.begin(), rev.end(), greater<ll>());
    vector<ll> res(n);
    ll sum = init_sum;
    ll m = rev.size();
    for (ll k = 1; k <= n; k++)
    {
        if (k <= m)
        {
            sum += rev[k - 1];
        }
        res[k - 1] = sum;
    }

    return res;
}