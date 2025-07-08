/*


*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> c(n, vector<ll>(2,0));

    for (ll i = 0; i < n; i++)
    {

        cin >> c[i][0] >> c[i][1];
    }
    sort(c.begin(), c.end(), greater<>());
    sort(c.begin(), c.end(), [](const vector<ll> &a, const vector<ll> &b)
         {
            if(a[0]!= b[0]) {
                return a[0] > b[0];
            }else{
                return a[1] < b[1];
            } }

    );
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i][0] == c[k - 1][0] && c[i][1] == c[k - 1][1])
        {
            count++;
        }
    }
    cout << count << endl;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
