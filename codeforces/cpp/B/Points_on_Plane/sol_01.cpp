

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 0;
    }
    else
    {
        ll l = -1;
        ll r = 1e9;
        while (r - l > 1)
        {
            ll mid = (l + r) / 2;
            if (mid * mid >= n)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        cout << (r - 1);
    }
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
        cout << "\n";
    }
    return 0;
}
