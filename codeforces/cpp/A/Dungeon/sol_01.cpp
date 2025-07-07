

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    if ((a + b + c) % 9 == 0)
    {
        int k = (a + b + c) / 9;
        if (a >= k && b >= k && c >= k)
        {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
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
        cout << "\n";
    }
    return 0;
}
