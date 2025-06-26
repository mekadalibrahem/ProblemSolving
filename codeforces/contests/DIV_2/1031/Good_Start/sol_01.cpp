/*
B. Good Start
time limit per test
1 second
memory limit per test
256 megabytes

The roof is a rectangle of size w×h
with the bottom left corner at the point (0,0) on the plane. Your team needs to completely cover this roof with identical roofing sheets of size a×b

, with the following conditions:

    The sheets cannot be rotated (not even by 90∘

    ).
    The sheets must not overlap (but they can touch at the edges).
    The sheets can extend beyond the boundaries of the rectangular roof.

A novice from your team has already placed two such sheets on the roof in such a way that the sheets do not overlap and each of them partially covers the roof.

Your task is to determine whether it is possible to completely tile the roof without removing either of the two already placed sheets.
Input

Each test contains multiple test cases. The first line contains the number of test cases t
(1≤t≤104

). The description of the test cases follows.

The first line of each test case contains four integers w
, h, a, and b (1≤w,h,a,b≤109

) — the dimensions of the roof and the dimensions of the roofing sheets, respectively.

The second line of each test case contains four integers x1
, y1, x2, and y2 (−a+1≤x1,x2≤w−1,−b+1≤y1,y2≤h−1

) — the coordinates of the bottom left corners of the already placed roofing sheets. It is guaranteed that these sheets do not overlap.
Output

For each test case, output "Yes" (without quotes) if it is possible to completely tile the roof without removing either of the two already placed tiles, and "No" (without quotes) otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    ll w, h, a, b;
    ll x1, y1, x2, y2;
    cin >> w >> h >> a >> b;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2)
    {
        if (abs(y2 - y1) % b == 0)
        {
            cout << "YES\n";
            return;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    else if (y1 == y2)
    {
        if (abs(x2 - x1) % a == 0)
        {
            cout << "YES\n";
            return;
        }
        else
        {
            cout << "No\n";
            return;
        }
    }
    else
    {
        if (abs(x2 - x1) % a == 0 || abs(y2 - y1) % b == 0)
        {
            cout << "YES\n";
            return;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}