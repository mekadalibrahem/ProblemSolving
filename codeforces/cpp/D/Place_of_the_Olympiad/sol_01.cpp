/*
D. Place of the Olympiad
time limit per test
1 second
memory limit per test
256 megabytes

For the final of the first Olympiad by IT Campus "NEIMARK", a rectangular venue was prepared. You may assume that the venue is divided into n
rows, each containing m spots for participants' desks. A total of k

participants have registered for the final, and each participant will sit at an individual desk. Now, the organizing committee must choose the locations for the desks in the venue.

Each desk occupies one of the m
spots in a row. Moreover, if several desks occupy consecutive spots in the same row, we call such a group of desks a bench, and the number of desks in the group is the bench's length. For example, seating 7 participants on a 3×4 venue (with n=3,m=4

) can be arranged as follows:

In the figure above, the first row has one bench of length 3
, the second row has one bench of length 2, and the third row has two benches of length 1

.

The organizing committee wants to choose the locations so that the length of the longest bench is as small as possible. In particular, the same 7
desks can be arranged in a more optimal way, so that the lengths of all benches do not exceed 2

:

Given the integers n
, m, and k

, determine the minimum possible length of the longest bench.
Input

Each test contains multiple test cases. The first line contains the number of test cases t
(1≤t≤104

). The description of the test cases follows.

A single line of each test case contains three positive integers — n
, m, k (1≤n,m,k≤109, k≤n⋅m

).
Output

For each test case, output a single number — the minimum possible length of the longest bench.
Example
Input
Copy

5
3 4 7
5 5 5
1 13 2
2 4 7
1 5 4

Output
Copy

2
1
1
4
2


*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool check(ll x, ll n, ll m, ll k)
{
    ll p = m / (x+1) ;
    ll a = m % (x+1);
    ll t = (p * x + a)* n ;
    return  t >= k ;
}

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    ll l = 1, r = m, ans = m;

    while (l <= r)
    {
        ll mid = (l + r) / 2;
        bool c =check(mid, n, m, k); 
        if (c)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
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
