/*
A. Shovels and Swords
time limit per test
1 second
memory limit per test
256 megabytes

Polycarp plays a well-known computer game (we won't mention its name). In this game, he can craft tools of two types — shovels and swords. To craft a shovel, Polycarp spends two sticks and one diamond; to craft a sword, Polycarp spends two diamonds and one stick.

Each tool can be sold for exactly one emerald. How many emeralds can Polycarp earn, if he has a
sticks and b

diamonds?
Input

The first line contains one integer t
(1≤t≤1000

) — the number of test cases.

The only line of each test case contains two integers a
and b (0≤a,b≤109

) — the number of sticks and the number of diamonds, respectively.
Output

For each test case print one integer — the maximum number of emeralds Polycarp can earn.
Example
Input
Copy

4
4 4
1000000000 0
7 15
8 7

Output
Copy

2
0
7
5

Note

In the first test case Polycarp can earn two emeralds as follows: craft one sword and one shovel.

In the second test case Polycarp does not have any diamonds, so he cannot craft anything.
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    if (a * 2 < b)
    {
        cout << a << endl;
        return;
    }
    if (b * 2 < a)
    {
        cout << b << endl;
        return;
    }
    while (a > 0 && b > 0 && (a + b) >= 3)
    {

        if (a > b)
        {
            double x = ceil(a / 2);
            double x_2 = ceil(x/ 2);
            a -= 2*x_2;
            b -= x_2;
            ans += x_2;
        }
        else
        {
            double x = ceil(b / 2);
            double x_2 = ceil(x / 2);
            a -= x_2;
            b -= 2*x_2;
            ans += x_2;
        }
    }

    cout << ans << endl;
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