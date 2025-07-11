/*

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int max_ = 0;
    int current= 0;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int in, out;
        cin >> out >> in;
        current -= out;
        current += in;
        max_ = max(max_, current);
    }
    cout << max_;
    return 0;
}