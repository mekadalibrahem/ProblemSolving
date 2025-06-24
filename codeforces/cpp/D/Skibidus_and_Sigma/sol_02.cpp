/*
D. Skibidus and Sigma
time limit per test
2 seconds
memory limit per test
256 megabytes

Let's denote the score of an array b
with k elements as ∑ki=1(∑ij=1bj). In other words, let Si denote the sum of the first i elements of b. Then, the score can be denoted as S1+S2+…+Sk

.

Skibidus is given n
arrays a1,a2,…,an, each of which contains m elements. Being the sigma that he is, he would like to concatenate them in any order to form a single array containing n⋅m

elements. Please find the maximum possible score Skibidus can achieve with his concatenated array!

Formally, among all possible permutations∗
p of length n, output the maximum score of ap1+ap2+⋯+apn, where + represents concatenation†

.

∗
A permutation of length n contains all integers from 1 to n

exactly once.

†
The concatenation of two arrays c and d with lengths e and f respectively (i.e. c+d) is c1,c2,…,ce,d1,d2,…df

.
Input

The first line contains an integer t
(1≤t≤104

) — the number of test cases.

The first line of each test case contains two integers n
and m (1≤n⋅m≤2⋅105

) — the number of arrays and the length of each array.

The i
'th of the next n lines contains m integers ai,1,ai,2,…,ai,m (1≤ai,j≤106) — the elements of the i

'th array.

It is guaranteed that the sum of n⋅m
over all test cases does not exceed 2⋅105

.
Output

For each test case, output the maximum score among all possible permutations p

on a new line.
Example
Input
Copy

3
2 2
4 4
6 1
3 4
2 2 2 2
3 2 1 2
4 1 2 1
2 3
3 4 5
1 1 9

Output
Copy

41
162
72

Note

For the first test case, there are two possibilities for p

:

    p=[1,2]

. Then, ap1+ap2=[4,4,6,1]. Its score is 4+(4+4)+(4+4+6)+(4+4+6+1)=41
.
p=[2,1]
. Then, ap1+ap2=[6,1,4,4]. Its score is 6+(6+1)+(6+1+4)+(6+1+4+4)=39

    .

The maximum possible score is 41

.

In the second test case, one optimal arrangement of the final concatenated array is [4,1,2,1,2,2,2,2,3,2,1,2]
. We can calculate that the score is 162.
*/
// Imporve code from 450mx to  93 ms and 12300KB to 1200KB
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> sums(n), accum(n);
    for (ll i = 0; i < n; i++) {
        ll sum = 0, ac = 0;
        for (ll j = 0; j < m; j++) {
            ll x;
            cin >> x;
            sum += x;
            ac += x * (m - j);
        }
        sums[i] = sum;
        accum[i] = ac;
    }
    // Sort sums and get original indices
    vector<ll> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](ll i, ll j) { return sums[i] > sums[j]; });
    ll total = 0, pre = 0;
    for (ll i : idx) {
        total += accum[i] + pre * m;
        pre += sums[i];
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}