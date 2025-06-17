/*
A. Letter Home
time limit per test
1 second
memory limit per test
256 megabytes

You are given an array of distinct llegers x1,x2,…,xn
and an lleger s

.

Initially, you are at position pos=s
on the X

axis. In one step, you can perform exactly one of the following two actions:

    Move from position pos

to position pos+1
.
Move from position pos
to position pos−1

    .

A sequence of steps will be considered successful if, during the entire journey, you visit each position xi
on the X axis at least once. Note that the initial position pos=s

is also considered visited.

Your task is to determine the minimum number of steps in any successful sequence of steps.
Input

Each test consists of multiple test cases. The first line contains a single lleger t
(1≤t≤1000

) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two llegers n
and s (1≤n≤10, 1≤s≤100

) — the number of positions to visit and the starting position.

The second line of each test case contains n
llegers x1,x2,…,xn (1≤xi≤100). It is guaranteed that for all 1≤i<n, it holds that xi<xi+1

.
Output

For each test case, output the minimum number of steps in any successful sequence of steps.

*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >>t ;
    while (t--)
    {
        solve();
    }

    return 0;
}

void solve()
{
    ll n, s;
    cin >> n >> s;
    vector<ll> nums(n, -1);
    
    for(ll i = 0 ; i < n ; i++){
        cin>> nums[i];
        
    }
    ll min_x = nums[0];
    ll max_x = nums[n - 1];
    ll min_val = min(s, min_x);
    ll max_val = max(s, max_x);
    ll d1 = s - min_val;
    ll d2 = max_val - s;
    ll ans = (max_val - min_val) + min(d1, d2);
    cout << ans << endl;
}