/*
B. Apples in Boxes
time limit per test
1 second
memory limit per test
256 megabytes

Tom and Jerry found some apples in the basement. They decided to play a game to get some apples.

There are n
boxes, and the i-th box has ai

apples inside. Tom and Jerry take turns picking up apples. Tom goes first. On their turn, they have to do the following:

    Choose a box i

(1≤i≤n) with a positive number of apples, i.e. ai>0, and pick 1 apple from this box. Note that this reduces ai by 1
.
If no valid box exists, the current player loses.
If after the move, max(a1,a2,…,an)−min(a1,a2,…,an)>k

    holds, then the current player (who made the last move) also loses.

If both players play optimally, predict the winner of the game.
Input

Each test contains multiple test cases. The first line contains the number of test cases t
(1≤t≤104

). The description of the test cases follows.

The first line of each test case contains two integers n,k
(2≤n≤105,1≤k≤109

).

The second line of each test case contains n
integers a1,a2,…,an (1≤ai≤109

).

It is guaranteed that the sum of n
over all test cases does not exceed 105

.
Output

For each test case, print "Tom" (without quotes) if Tom will win, or "Jerry" (without quotes) otherwise.
Example
Input
Copy

3
3 1
2 1 2
3 1
1 1 3
2 1
1 4

Output
Copy

Tom
Tom
Jerry

Note

Note that neither player is necessarily playing an optimal strategy in the following games, just to give you an idea of how the game is going.

In the first test case of the example, one possible situation is shown as follows.

    Tom takes an apple from the first box. The array a

becomes [1,1,2]. Tom does not lose because max(1,1,2)−min(1,1,2)=1≤k
.
Jerry takes an apple from the first box as well. The array a
becomes [0,1,2]. Jerry loses because max(0,1,2)−min(0,1,2)=2>k.

*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 10e5 + 11;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n, 0);
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];

        count += a[i];
    }

    // try first move

    sort(a.begin(), a.end());
    a[a.size() - 1] -= 1;
    sort(a.begin(), a.end());

    if ((a[n - 1] - a[0]) > k || count % 2 == 0)
    {
        cout << "Jerry\n";
        return;
    }
    else
    {
        cout << "Tom\n";
        return;
    }
}
int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
