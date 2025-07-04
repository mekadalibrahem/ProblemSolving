/*
D. Distinct Split
time limit per test
2 seconds
memory limit per test
256 megabytes

Let's denote the f(x)
function for a string x as the number of distinct characters that the string contains. For example f(abc)=3, f(bbbbb)=1, and f(babacaba)=3

.

Given a string s
, split it into two non-empty strings a and b such that f(a)+f(b) is the maximum possible. In other words, find the maximum possible value of f(a)+f(b) such that a+b=s (the concatenation of string a and string b is equal to string s

).
Input

The input consists of multiple test cases. The first line contains an integer t
(1≤t≤104

) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n
(2≤n≤2⋅105) — the length of the string s

.

The second line contains the string s

, consisting of lowercase English letters.

It is guaranteed that the sum of n
over all test cases does not exceed 2⋅105

.
Output

For each test case, output a single integer  — the maximum possible value of f(a)+f(b)
such that a+b=s

.
Example
Input
Copy

5
2
aa
7
abcabcd
5
aaaaa
10
paiumoment
4
aazz

Output
Copy

2
7
2
10
3

Note

For the first test case, there is only one valid way to split aa
into two non-empty strings a and a, and f(a)+f(a)=1+1=2

.

For the second test case, by splitting abcabcd
into abc and abcd we can get the answer of f(abc)+f(abcd)=3+4=7

which is maximum possible.

For the third test case, it doesn't matter how we split the string, the answer will always be 2
.
*/
// NOTE:    218ms  , 300KB
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> split_points;
    map<char, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[s[i]]++;
        if (freq[s[i]] > 1)
        {
            split_points.push_back(i);
        }
    }

    if (split_points.size() <= 1)
    {
        cout << n << "\n";
        return;
    }
    vector<int> l(n), r(n);
    set<int> dis;
    for (int i = 0; i < n; i++)
    {
        dis.insert(s[i]);
        l[i] = dis.size();
    }
    dis.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        dis.insert(s[i]);
        r[i] = dis.size();
    }

    int ans = 0;
    for (int i = 0; i < split_points.size(); i++)
    {

        int count = l[split_points[i]] + r[split_points[i]];
        ans = max(ans, count);
    }

    cout << ans << "\n";
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
