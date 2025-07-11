/*

D. Lucky Transformation
time limit per test
2 seconds
memory limit per test
256 megabytes

Petya loves lucky numbers. Everybody knows that lucky numbers are positive integers whose decimal representation contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya has a number consisting of n digits without leading zeroes. He represented it as an array of digits without leading zeroes. Let's call it d. The numeration starts with 1, starting from the most significant digit. Petya wants to perform the following operation k times: find the minimum x (1 ≤ x < n) such that dx = 4 and dx + 1 = 7, if x is odd, then to assign dx = dx + 1 = 4, otherwise to assign dx = dx + 1 = 7. Note that if no x was found, then the operation counts as completed and the array doesn't change at all.

You are given the initial number as an array of digits and the number k. Help Petya find the result of completing k operations.
Input

The first line contains two integers n and k (1 ≤ n ≤ 105, 0 ≤ k ≤ 109) — the number of digits in the number and the number of completed operations. The second line contains n digits without spaces representing the array of digits d, starting with d1. It is guaranteed that the first digit of the number does not equal zero.
Output

In the single line print the result without spaces — the number after the k operations are fulfilled.
Examples
Input
Copy

7 4
4727447

Output
Copy

4427477

Input
Copy

4 2
4478

Output
Copy

4478

Note

In the first sample the number changes in the following sequence: 4727447 → 4427447 → 4427477 → 4427447 → 4427477.

In the second sample: 4478 → 4778 → 4478.

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    queue<ll> o;
    for (ll i = 0; i < n - 1; i++)
    {
        if (s[i] == '4' && s[i + 1] == '7')
        {
            o.push(i);
        }
    }
    while (!o.empty() && k > 0)
    {
        ll i = o.front();
        o.pop();
        if (i % 2 == 0 && s[i - 1] == '4' && s[i] == '4' && s[i + 1] == '7')
        {
            if (k % 2 != 0)
            {
                s[i] = '7';
            }
            break;
        }
        if (i % 2 == 0)
        {
            s[i] = s[i + 1] = '4';
        }
        else
        {
            s[i] = s[i + 1] = '7';
        }
        if (s[i] == '7' && s[i - 1] == '4')
        {
            o.push(i - 1);
        }
        if (s[i + 1] == '4' && s[i + 2] == '7')
        {
            o.push(i + 1);
        }
        k--;
    }
    cout << s << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
