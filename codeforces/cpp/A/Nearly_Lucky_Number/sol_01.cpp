/*
A. Nearly Lucky Number
time limit per test
2 seconds
memory limit per test
256 megabytes

Petya loves lucky numbers. We all know that lucky numbers are the positive integers whose decimal representations contain only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Unfortunately, not all numbers are lucky. Petya calls a number nearly lucky if the number of lucky digits in it is a lucky number. He wonders whether number n is a nearly lucky number.
Input

The only line contains an integer n (1 ≤ n ≤ 1018).

Please do not use the %lld specificator to read or write 64-bit numbers in С++. It is preferred to use the cin, cout streams or the %I64d specificator.
Output

Print on the single line "YES" if n is a nearly lucky number. Otherwise, print "NO" (without the quotes).

*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;

    ll count = 0;
    while (n > 0)
    {
        ll t;
        t = n % 10;
        if (t == 4|| t == 7)
        {
            count++;
        }

        n -= t;
        n /= 10;
    }

    if (count == 7 || count == 4)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}