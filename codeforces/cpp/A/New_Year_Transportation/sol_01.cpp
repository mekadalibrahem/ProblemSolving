/*

A. New Year Transportation
time limit per test
2 seconds
memory limit per test
256 megabytes

New Year is coming in Line World! In this world, there are n cells numbered by integers from 1 to n, as a 1 × n board. People live in cells. However, it was hard to move between distinct cells, because of the difficulty of escaping the cell. People wanted to meet people who live in other cells.

So, user tncks0121 has made a transportation system to move between these cells, to celebrate the New Year. First, he thought of n - 1 positive integers a1, a2, ..., an - 1. For every integer i where 1 ≤ i ≤ n - 1 the condition 1 ≤ ai ≤ n - i holds. Next, he made n - 1 portals, numbered by integers from 1 to n - 1. The i-th (1 ≤ i ≤ n - 1) portal connects cell i and cell (i + ai), and one can travel from cell i to cell (i + ai) using the i-th portal. Unfortunately, one cannot use the portal backwards, which means one cannot move from cell (i + ai) to cell i using the i-th portal. It is easy to see that because of condition 1 ≤ ai ≤ n - i one can't leave the Line World using portals.

Currently, I am standing at cell 1, and I want to go to cell t. However, I don't know whether it is possible to go there. Please determine whether I can go to cell t by only using the construted transportation system.
Input

The first line contains two space-separated integers n (3 ≤ n ≤ 3 × 104) and t (2 ≤ t ≤ n) — the number of cells, and the index of the cell which I want to go to.

The second line contains n - 1 space-separated integers a1, a2, ..., an - 1 (1 ≤ ai ≤ n - i). It is guaranteed, that using the given transportation system, one cannot leave the Line World.
Output

If I can go to cell t using the transportation system, print "YES". Otherwise, print "NO".

*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void print(bool r);
bool dfs(ll s, ll t, vector<vector<ll>> &graph);
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, t;
    cin >> n >> t;
    vector<vector<ll>> graph(n+1);

    for (ll i = 1; i < n; i++)
    {
        ll temp;
        cin >> temp;

        graph[i].push_back(i + temp);
    }

    print(dfs(1, t, graph));

    return 0;
}

void print(bool r)
{
    if (r)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

bool dfs(ll s, ll t, vector<vector<ll>> &graph)
{
    if (s == t)
    {
        return true;
    }

    if(s <= graph.size()){
        vector<ll> edges = graph[s];
        for (ll edge : edges)
        {
    
            if (dfs(edge, t, graph))
            {
                return true;
            }
        }
    }
    return false;
}
