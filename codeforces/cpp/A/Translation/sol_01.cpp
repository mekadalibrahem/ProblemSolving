

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s, t;
    cin >> s;
    cin >> t;
    if (s.size() != t.size())
    {
        cout << "NO";
        return;
    }
    else
    {
        int n = s.size() - 1;
        for (int i = 0; i <= n; i++)
        {
            int j = n - i;
            if (s[i] != t[j])
            {
                cout << "NO";
                return;
            }
        }
        cout << "YES";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    cout << "\n";
    return 0;
}