/*
E. Lost Soul
time limit per test
2 seconds
memory limit per test
256 megabytes

You are given two integer arrays a
and b, each of length n

.

You may perform the following operation any number of times:

    Choose an index i

(1≤i≤n−1), and set ai:=bi+1, or set bi:=ai+1

    .

Before performing any operations, you are allowed to choose an index i
(1≤i≤n) and remove both ai and bi

from the arrays. This removal can be done at most once.

Let the number of matches between two arrays c
and d of length m be the number of positions j (1≤j≤m) such that cj=dj

.

Your task is to compute the maximum number of matches you can achieve.
Input

The first line of the input contains an integer t
(1≤t≤104)

— the number of test cases. The description of each test case follows.

The first line contains an integer n
(2≤n≤2⋅105) — the length of a and b

.

The second line contains n
integers a1,a2,…,an (1≤ai≤n) — the elements of a

.

The third line contains n
integers b1,b2,…,bn (1≤bi≤n) — the elements of b

.

It is guaranteed that the sum of n
over all test cases does not exceed 2⋅105

.
Output

For each test case, print a single integer — the answer for the test case.
Example
Input
Copy

10
4
1 3 1 4
4 3 2 2
6
2 1 5 3 6 4
3 2 4 5 1 6
2
1 2
2 1
6
2 5 1 3 6 4
3 5 2 3 4 6
4
1 3 2 2
2 1 3 4
8
3 1 4 6 2 2 5 7
4 2 3 7 1 1 6 5
10
5 1 2 7 3 9 4 10 6 8
6 2 3 6 4 10 5 1 7 9
5
3 2 4 1 5
2 4 5 1 3
7
2 2 6 4 1 3 5
3 1 6 5 1 4 2
5
4 1 3 2 5
3 2 1 5 4

Output
Copy

3
3
0
4
3
5
6
4
5
2

Note

In the first test case, we can do the following:

    We will choose not to remove any index.
    Choose index 3

, and set a3:=b4. The arrays become: a=[1,3,2,4], b=[4,3,2,2]
.
Choose index 1
, and set a1:=b2. The arrays become: a=[3,3,2,4], b=[4,3,2,2]
.
Choose index 1
, and set b1:=a2. The arrays become: a=[3,3,2,4], b=[3,3,2,2]. Notice that you can perform ai:=bi+1 and bi:=ai+1 on the same index i

    .

The number of matches is 3

. It can be shown that this is the maximum answer we can achieve.

In the second test case, we can do the following to achieve a maximum of 3

:

    Let's choose to remove index 5

. The arrays become: a=[2,1,5,3,4], b=[3,2,4,5,6]
.
Choose index 4
, and set b4:=a5. The arrays become: a=[2,1,5,3,4], b=[3,2,4,4,6]
.
Choose index 3
, and set a3:=b4. The arrays become: a=[2,1,4,3,4], b=[3,2,4,4,6]
.
Choose index 2
, and set a2:=b3. The arrays become: a=[2,4,4,3,4], b=[3,2,4,4,6]
.
Choose index 1
, and set b1:=a2. The arrays become: a=[2,4,4,3,4], b=[4,2,4,4,6]
.
Choose index 2
, and set b2:=a3. The arrays become: a=[2,4,4,3,4], b=[4,4,4,4,6]
.
Choose index 1
, and set a1:=b2. The arrays become: a=[4,4,4,3,4], b=[4,4,4,4,6]

    .

In the third test case, it can be shown that we can not get any matches. Therefore, the answer is 0
.
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve();

int main()
{

    int t;
    cin >> t;
    vector<ll> r;
    while (t--)
    {
        r.push_back(solve());
    }
    for (ll re : r)
    {
        cout << re << "\n";
    }
    return 0;
}

ll solve()
{
    ll n, count = 0;
    cin >> n;

    vector<ll> a(n, 0), b(n, 0);
    map<ll, bool> w;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    // RULE 1 : if a[i] == b[i]  all item previes index 'i' can be match
    if (a[n - 1] == b[n - 1])
        return n ;
    // we strat from (n-2)  => n is checked in preves step
    // and start from end  becuse rule 1 if i is match so  max number of match is i
    // store whatc state for last number

    for (ll i = n - 2; i >= 0; i--)
    {

        ll ai = a[i], bi = b[i];
        if (ai == bi || w[ai] || w[bi] || a[i] == a[i + 1] || b[i] == b[i + 1])
        {
            return (i + 1);
        }

        w[a[i + 1]] = w[b[i + 1]] = true;
    }
    return 0;
}