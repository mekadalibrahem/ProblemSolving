/*
D. Counting Pairs
time limit per test
2 seconds
memory limit per test
256 megabytes

You are given a sequence a
, consisting of n integers, where the i-th element of the sequence is equal to ai. You are also given two integers x and y (x≤y

).

A pair of integers (i,j)

is considered interesting if the following conditions are met:

    1≤i<j≤n

;
if you simultaneously remove the elements at positions i
and j from the sequence a, the sum of the remaining elements is at least x and at most y

    .

Your task is to determine the number of interesting pairs of integers for the given sequence a

.
Input

The first line contains one integer t
(1≤t≤104

) — the number of test cases.

Each test case consists of two lines:

    The first line contains three integers n,x,y

(3≤n≤2⋅105, 1≤x≤y≤2⋅1014
);
The second line contains n
integers a1,a2,…,an (1≤ai≤109

    ).

Additional constraint on the input: the sum of n
across all test cases does not exceed 2⋅105

.
Output

For each test case, output one integer — the number of interesting pairs of integers for the given sequence a

.
Example
Input
Copy

7
4 8 10
4 6 3 6
6 22 27
4 9 6 3 4 5
3 8 10
3 2 1
3 1 1
2 3 4
3 3 6
3 2 1
4 4 12
3 3 2 1
6 8 8
1 1 2 2 2 3

Output
Copy

4
7
0
0
1
5
6

Note

In the first example, there are 4

interesting pairs of integers:

    (1,2)

;
(1,4)
;
(2,3)
;
(3,4)
.
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll total_sum = 0;
ll n, x, y;


void solve()
{
    ll ans = 0;
    total_sum = 0;

    cin >> n >> x >> y;
    vector<ll> a(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        total_sum += a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n - 1; i++)
    {
        
        ll  lower , upper ;
        lower = total_sum - y - a[i];
        upper = total_sum - x - a[i];
        auto l  = lower_bound(a.begin() + i + 1, a.end(), lower);
        auto r = upper_bound(a.begin() + i + 1, a.end(), upper);
       
   

        ans += abs(r - l);
      
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