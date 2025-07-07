/*
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    ll max_a = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        max_a = max(max_a, a[i]);
    }
    if (n <= 2)
    {
        cout << "-1\n";
        return;
    }
    sort(a.begin(), a.end());
    int k = n / 2;
  
    
    cout << max(0LL,a[k]*2*n-sum+1) << '\n';
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
