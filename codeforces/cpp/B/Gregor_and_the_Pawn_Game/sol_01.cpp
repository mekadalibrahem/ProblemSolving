/*
B. Gregor and the Pawn Game
time limit per test
1 second
memory limit per test
256 megabytes

There is a chessboard of size n
by n. The square in the i-th row from top and j-th column from the left is labelled (i,j)

.

Currently, Gregor has some pawns in the n
-th row. There are also enemy pawns in the 1-st row. On one turn, Gregor moves one of his pawns. A pawn can move one square up (from (i,j) to (i−1,j)) if there is no pawn in the destination square. Additionally, a pawn can move one square diagonally up (from (i,j) to either (i−1,j−1) or (i−1,j+1)

) if and only if there is an enemy pawn in that square. The enemy pawn is also removed.

Gregor wants to know what is the maximum number of his pawns that can reach row 1

?

Note that only Gregor takes turns in this game, and the enemy pawns never move. Also, when Gregor's pawn reaches row 1

, it is stuck and cannot make any further moves.
Input

The first line of the input contains one integer t
(1≤t≤2⋅104) — the number of test cases. Then t

test cases follow.

Each test case consists of three lines. The first line contains a single integer n
(2≤n≤2⋅105

) — the size of the chessboard.

The second line consists of a string of binary digits of length n
, where a 1 in the i-th position corresponds to an enemy pawn in the i-th cell from the left, and 0

corresponds to an empty cell.

The third line consists of a string of binary digits of length n
, where a 1 in the i-th position corresponds to a Gregor's pawn in the i-th cell from the left, and 0

corresponds to an empty cell.

It is guaranteed that the sum of n
across all test cases is less than 2⋅105

.
Output

For each test case, print one integer: the maximum number of Gregor's pawns which can reach the 1
-st row.
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, count = 0;
    cin >> n;
    vector<ll> a(n + 2, 0), b(n + 2, 0);
    char in[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> in[i];
        a[i] = in[i] - 48;
    }
    for (int i =1; i <= n; i++)
    {
        cin >> in[i];
        b[i] = in[i] - 48;
    }
    a[0] = a[n + 1] = b[0] = b[n + 1] = -1;
    vector<bool> captured(n+2, false);
    for (ll i = 1; i <= n; i++)
    {
        if (b[i] == 1)
        {
            ll curn = a[i], prev = a[i - 1], next = a[i + 1];

            if (prev == 1 && !captured[i - 1])
            {
                count++;
                captured[i - 1] = true;
            }
            else if (curn == 0)
            {
                count++;
            }
            else if (next == 1)
            {
                count++;
                captured[i + 1] = true;
            }
        }
    }

    cout << count << "\n";
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