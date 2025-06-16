/*
K. King's Task
time limit per test
3 seconds
memory limit per test
512 megabytes

The brave Knight came to the King and asked permission to marry the princess. The King knew that the Knight was brave, but he also wanted to know if he was smart enough. So he asked him to solve the following task.

There is a permutation pi
of numbers from 1 to 2n

. You can make two types of operations.

    Swap p1

and p2, p3 and p4, ..., p2n−1 and p2n
.
Swap p1
and pn+1, p2 and pn+2, ..., pn and p2n

    .

The task is to find the minimal number of operations required to sort the given permutation.

The Knight was not that smart actually, but quite charming, so the princess asks you to help him to solve the King's task.
Input

The first line contains the integer n
(1≤n≤1000). The second line contains 2n integers pi — the permutation of numbers from 1 to 2n

.
Output

Print one integer — the minimal number of operations required to sort the permutation. If it is impossible to sort the permutation using these operations, print −1
.

*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n;
vector<ll> arr;

vector<ll> swap_neighbours(vector<ll> a);
vector<ll> swap_half(vector<ll> a);
ll solve(ll max_times , ll option_start ,vector<ll> arr2);
int main()
{
    cin >> n;
    for (int i = 0; i < (2 * n); i++)
    {
        ll t;
        cin >> t;

        arr.push_back(t);
    }
    ll c = 0;
    if (n % 2 == 0)
    {
        c = min(solve(4 , 0 ,arr) , solve(4 , 1 ,arr));
    }
    else
    {
        c = min(solve((2 * n) , 0,  arr), solve((2 * n) , 1,  arr));
    }
    cout << c << "\n";

    return 0;
}
vector<ll> swap_neighbours(vector<ll> a)
{
    for (int i = 0; i <(2 * n); i+=2)
    {
        swap(a[i], a[i + 1]);
    }
    return a;
}
vector<ll> swap_half(vector<ll> a)
{
    for (int i = 0; i < n; i++)
    {
        swap(a[i], a[n + i]);
    }
    return a;
}

ll solve(ll max_times , ll option_start , vector<ll> arr2)
{
    ll count = 0;
    ll option = option_start;
    for (int i = 0; i < max_times; i++)
    {
        if (is_sorted(arr2.begin(), arr2.end()))
        {
            return count;
        }
        else
        {
            count++;
            if (option % 2 == 0)
            {
                arr2 = swap_half(arr2);
            }
            else
            {
                arr2 = swap_neighbours(arr2);
            }
            option++;
        }
    }
    return -1;
}
