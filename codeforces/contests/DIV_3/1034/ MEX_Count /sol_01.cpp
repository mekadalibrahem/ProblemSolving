#include <bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> freq(n + 2, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= n) {
            freq[a[i]]++;
        }
    }

    int mex = 0;
    while (freq[mex] > 0) {
        mex++;
    }

    vector<int> diff(n + 2, 0);
    for (int m = 0; m <= mex; m++) {
        if (m > n) 
            break;
        int L = freq[m];
        int R = n - m;
        if (L <= R) {
            diff[L]++;
            if (R + 1 <= n) {
                diff[R + 1]--;
            }
        }
    }

    vector<int> ans;
    int cur = 0;
    for (int k = 0; k <= n; k++) {
        cur += diff[k];
        ans.push_back(cur);
    }

    for (int i = 0; i <= n; i++) {
        cout << ans[i];
        if (i < n) 
            cout << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
       solve();
    }
    return 0;
}