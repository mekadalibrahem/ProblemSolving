/*
C. Those Who Are With Us
time limit per test
1 second
memory limit per test
256 megabytes

You are given a matrix of integers with n
rows and m columns. The cell at the intersection of the i-th row and the j-th column contains the number aij

.

You can perform the following operation exactly once:

    Choose two numbers 1≤r≤n

and 1≤c≤m
.
For all cells (i,j)
in the matrix such that i=r or j=c, decrease aij

    by one.

You need to find the minimal possible maximum value in the matrix a

after performing exactly one such operation.
Input

Each test consists of multiple test cases. The first line contains a single integer t
(1≤t≤104

) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n
and m (1≤n⋅m≤105

) — the number of rows and columns in the matrix.

The next n
lines of each test case describe the matrix a. The i-th line contains m integers ai1,ai2,…,aim (1≤aij≤100) — the elements in the i

-th row of the matrix.

It is guaranteed that the sum of n⋅m
across all test cases does not exceed 2⋅105

.
Output

For each test case, output the minimum maximum value in the matrix a
after performing exactly one operation.
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    vector<ll> re;
    while (t--)
    {
        re.push_back(solve());
    }

    for (ll r : re)
    {
        cout << r << endl;
    }
    return 0;
}

ll solve()
{
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<vector<ll>> mat(n, vector<ll>(m));
    ll max_item = 0, max_count = 0;

    vector<ll> n_index(n, 0), m_index(m, 0), empty_n(n, 0), empty_m(m, 0);

    for (ll i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] > max_item)
            {
                n_index = empty_n;
                m_index = empty_m;
                n_index[i]++;
                m_index[j]++;
                max_item = mat[i][j];
                max_count = 1;
            }
            else if (mat[i][j] == max_item)
            {
                n_index[i]++;
                m_index[j]++;
                max_count++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // current is max
            if (max_item == mat[i][j])
            {
                if ((n_index[i] + m_index[j] - 1) == max_count)
                {
                    return (max_item - 1);
                }
            }
            else
            {
                if ((n_index[i] + m_index[j]) == max_count)
                {
                    return (max_item -1);
                }
            }
        }
    }

    return max_item;
}
