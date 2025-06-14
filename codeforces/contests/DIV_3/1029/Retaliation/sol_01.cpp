/*
D. Retaliation
time limit per test
2 seconds
memory limit per test
256 megabytes

Yousef wants to explode an array a1,a2,…,an

. An array gets exploded when all of its elements become equal to zero.

In one operation, Yousef can do exactly one of the following:

    For every index i

in a, decrease ai by i
.
For every index i
in a, decrease ai by n−i+1

    .

Your task is to help Yousef determine if it is possible to explode the array using any number of operations.
Input

The first line of the input contains an integer t
(1≤t≤104

) — the number of test cases.

The first line of each test case contains an integer n
(2≤n≤2⋅105

) — the size of the array.

The second line of each test case contains n
integers a1,a2,…,an (1≤ai≤109

) — the elements of the array.

It is guaranteed that the sum of n
over all test cases doesn't exceed 2⋅105

.
Output

For each test case, print "YES" if Yousef can explode the array, otherwise output "NO".

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll x_number, y_number, n_number;
    x_number = n * a[n - 1] - a[0];
    y_number = n * a[0] - a[n - 1];
    n_number = n * n - 1;
    if (x_number % n_number != 0 || y_number % n_number != 0)
    {
        cout << "NO\n";
    }
    else
    {
        ll x, y;
        x = x_number / n_number;
        y = y_number / n_number;
        if (x < 0 || y < 0)
        {
            cout << "NO\n";
        }
        else
        {
            bool can_explode = true;
            for (ll i = 0; i < n; i++)
            {
                if (a[i] != x * (i + 1) + y * (n - (i + 1) + 1))
                {
                    can_explode = false;
                    break;
                }
            }
            if (can_explode)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}