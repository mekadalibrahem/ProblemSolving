/*
C. Longest Good Array
time limit per test
2 seconds
memory limit per test
256 megabytes

Today, Sakurako was studying arrays. An array a
of length n

is considered good if and only if:

    the array a

is increasing, meaning ai−1<ai for all 2≤i≤n
;
the differences between adjacent elements are increasing, meaning ai−ai−1<ai+1−ai
for all 2≤i<n

    .

Sakurako has come up with boundaries l
and r and wants to construct a good array of maximum length, where l≤ai≤r for all ai

.

Help Sakurako find the maximum length of a good array for the given l
and r

.
Input

The first line contains a single integer t
(1≤t≤104

)  — the number of test cases.

The only line of each test case contains two integers l
and r (1≤l≤r≤109

).
Output

For each test case, output a single integer  — the length of the longest good array Sakurako can form given l
and r

.
Example
Input
Copy

5
1 2
1 5
2 2
10 20
1 1000000000

Output
Copy

2
3
1
5
44721

Note

For l=1
and r=5, one possible array could be (1,2,5). It can be proven that an array of length 4 does not exist for the given l and r

.

For l=2
and r=2, the only possible array is (2)

.

For l=10
and r=20, the only possible array is (10,11,13,16,20).

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll n, ll r, ll l) {
    return (n - 1) * n / 2 <= r - l;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    if (l == r) {
        cout << 1 << endl;
        return;
    }
    ll l1 = 1, r1 = 1e5; 
    ll ans = 1;
    while (l1 <= r1) {
        ll mid = (l1 + r1) / 2;
        if (check(mid, r, l)) {
            ans = mid;
            l1 = mid + 1;
        } else {
            r1 = mid - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}