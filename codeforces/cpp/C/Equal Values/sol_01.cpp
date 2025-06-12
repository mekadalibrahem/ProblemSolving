/*

*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    ll last, min_cost, count = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x, cost;
        cin >> x;
        if (i == 0)
        {
            // start here

            cost = x * (n - 1);
            min_cost = cost;
        }
        else
        {
            if (last == x)
            {
                count++;
                cost = x * (n - 1) - (x * count);
            }
            else
            {
                count = 0;
                cost = x * (n - 1);
            }
        }
        last = x;
        if (min_cost > cost)
        {
            min_cost = cost;
        }
    }
    cout << min_cost << "\n";
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

    return 0;
}
