/*
B. Interesting drink
time limit per test
2 seconds
memory limit per test
256 megabytes

Vasiliy likes to rest after a hard work, so you may often meet him in some bar nearby. As all programmers do, he loves the famous drink "Beecola", which can be bought in n different shops in the city. It's known that the price of one bottle in the shop i is equal to xi coins.

Vasiliy plans to buy his favorite drink for q consecutive days. He knows, that on the i-th day he will be able to spent mi coins. Now, for each of the days he want to know in how many different shops he can buy a bottle of "Beecola".
Input

The first line of the input contains a single integer n (1 ≤ n ≤ 100 000) — the number of shops in the city that sell Vasiliy's favourite drink.

The second line contains n integers xi (1 ≤ xi ≤ 100 000) — prices of the bottles of the drink in the i-th shop.

The third line contains a single integer q (1 ≤ q ≤ 100 000) — the number of days Vasiliy plans to buy the drink.

Then follow q lines each containing one integer mi (1 ≤ mi ≤ 109) — the number of coins Vasiliy can spent on the i-th day.
Output

Print q integers. The i-th of them should be equal to the number of shops where Vasiliy will be able to buy a bottle of the drink on the i-th day.
Example
Input
Copy

5
3 10 8 6 11
4
1
10
3
11

Output
Copy

0
4
1
5

Note

On the first day, Vasiliy won't be able to buy a drink in any of the shops.

On the second day, Vasiliy can buy a drink in the shops 1, 2, 3 and 4.

On the third day, Vasiliy can buy a drink only in the shop number 1.

Finally, on the last day Vasiliy can buy a drink in any shop.


*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> shops(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> shops[i];
    }
    sort(shops.begin(), shops.end());
    ll q;
    cin >> q;
    vector<ll> days(q);
    for (ll i = 0; i < q; i++)
    {
        cin >> days[i];
    }
    for (ll m : days)
    {
        auto r = upper_bound(shops.begin(), shops.end(), m);
        ll ans = r -   shops.begin() ;
        
        cout << ans << endl;
    }

    return 0;
}