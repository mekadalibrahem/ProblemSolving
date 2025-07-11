/*
D. Binary String Battle
time limit per test
2 seconds
memory limit per test
256 megabytes

Alice and Bob are given a binary string s
of length n, and an integer k (1≤k<n

).

Alice wins if she is able to transform all characters of s

into zeroes. If Alice is unable to win in a finite number of moves, then Bob wins.

Alice and Bob take turns, with Alice going first.

    On Alice's turn, she may choose any subsequence∗

of length k in s
, then set all characters in that subsequence to zero.
On Bob's turn, he may choose any substring†
of length k in s

    , then set all characters in that substring to one.

Note that Alice wins if the string consists of all zeros at any point during the game, including in between Alice's and Bob's turns.

Determine who wins with optimal play.

∗
A subsequence of a string s is a set of characters in s

. Note that these characters do not have to be adjacent.

†
A substring of a string s is a contiguous group of characters in s

. Note that these characters must be adjacent.
Input

The first line contains an integer t
(1≤t≤104

)  — the number of test cases.

The first line of each test case contains two integers n
and k (2≤n≤2⋅105, 1≤k<n

).

The second line of each test case contains a binary string s
of length n

.

It is guaranteed that the sum of n
over all test cases does not exceed 2⋅105

.
Output

For each test case, output on a single line "Alice" if Alice wins with optimal play, and "Bob" if Bob wins with optimal play.

You can output the answer in any case (upper or lower). For example, the strings "aLiCe", "alice", "ALICE", and "alICE" will be recognized as "Alice".
Example
Input
Copy

6
5 2
11011
7 4
1011011
6 1
010000
4 1
1111
8 3
10110110
6 4
111111

Output
Copy

Bob
Alice
Alice
Bob
Bob
Alice

Note

In the third sample, Alice can choose the subsequence consisting of s2
, turning s into 000000

. Then she wins immediately.

In the fourth sample, it can be shown that there is no way for Alice to guarantee that she can turn s
into 0000

within a finite number of moves.



*/

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int count_ones = 0;
    for (char c : s)
    {
        if (c == '1')
        {
            count_ones++;
        }
    }

    if (count_ones <= k || n < 2 * k)
    {
        cout << "Alice\n";
    }
    else
    {
        cout << "Bob\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}