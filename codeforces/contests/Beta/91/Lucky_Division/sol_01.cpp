/*
A. Lucky Division
time limit per test
2 seconds
memory limit per test
256 megabytes

Petya loves lucky numbers. Everybody knows that lucky numbers are positive integers whose decimal representation contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya calls a number almost lucky if it could be evenly divided by some lucky number. Help him find out if the given number n is almost lucky.
Input

The single line contains an integer n (1 ≤ n ≤ 1000) — the number that needs to be checked.
Output

In the only line print "YES" (without the quotes), if number n is almost lucky. Otherwise, print "NO" (without the quotes).
Examples
Input
Copy

47

Output
Copy

YES

Input
Copy

16

Output
Copy

YES

Input
Copy

78

Output
Copy

NO

Note

Note that all lucky numbers are almost lucky as any number is evenly divisible by itself.

In the first sample 47 is a lucky number. In the second sample 16 is divisible by 4.

*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const string YES = "YES\n";
const string NO = "NO\n";

bool is_lucky(int x)
{
    string s = to_string(x);
    for (char c : s)
    {
        if (c != '4' && c != '7')
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        if (is_lucky(i))
        {
            if (n % i == 0)
            {
                cout << YES;
                return;
            }
        }
    }
    cout << NO;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}