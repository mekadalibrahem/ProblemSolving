/*
D. Balanced Round
time limit per test
2 seconds
memory limit per test
256 megabytes

You are the author of a Codeforces round and have prepared n
problems you are going to set, problem i having difficulty ai

. You will do the following process:

    remove some (possibly zero) problems from the list;
    rearrange the remaining problems in any order you wish.

A round is considered balanced if and only if the absolute difference between the difficulty of any two consecutive problems is at most k
(less or equal than k

).

What is the minimum number of problems you have to remove so that an arrangement of problems is balanced?
Input

The first line contains a single integer t
(1≤t≤1000

) — the number of test cases.

The first line of each test case contains two positive integers n
(1≤n≤2⋅105) and k (1≤k≤109

) — the number of problems, and the maximum allowed absolute difference between consecutive problems.

The second line of each test case contains n
space-separated integers ai (1≤ai≤109

) — the difficulty of each problem.

Note that the sum of n
over all test cases doesn't exceed 2⋅105

.
Output

For each test case, output a single integer — the minimum number of problems you have to remove so that an arrangement of problems is balanced.

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<ll> res;
    while (t--)
    {
        res.push_back(solve());
    }

    for (ll r : res)
    {
        cout << r << "\n";
    }
    return 0;
}

ll solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll count = 0;
    ll max_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            count++;
            max_count = count;
        }
        else
        {
            if (abs(a[i] - a[i-1]) > k)
            {
                if (max_count < count)
                {
                    max_count = count;
                }
                count = 1;
            }
            else
            {
                count++;
            }
        }
    }
    //  for last loop
    if (max_count < count)
    {
        max_count = count;
    }
    return (n - max_count);
}
