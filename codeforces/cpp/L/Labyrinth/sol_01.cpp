/*
L. Labyrinth
time limit per test
3 seconds
memory limit per test
512 megabytes

Leslie and Leon entered a labyrinth. The labyrinth consists of n
halls and m one-way passages between them. The halls are numbered from 1 to n

.

Leslie and Leon start their journey in the hall s

. Right away, they quarrel and decide to explore the labyrinth separately. However, they want to meet again at the end of their journey.

To help Leslie and Leon, your task is to find two different paths from the given hall s
to some other hall t, such that these two paths do not share halls other than the staring hall s and the ending hall t. The hall t has not been determined yet, so you can choose any of the labyrinth's halls as t except s

.

Leslie's and Leon's paths do not have to be the shortest ones, but their paths must be simple, visiting any hall at most once. Also, they cannot visit any common halls except s
and t

during their journey, even at different times.
Input

The first line contains three integers n
, m, and s, where n (2≤n≤2⋅105) is the number of vertices, m (0≤m≤2⋅105) is the number of edges in the labyrinth, and s (1≤s≤n

) is the starting hall.

Then m
lines with descriptions of passages follow. Each description contains two integers ui, vi (1≤ui,vi≤n; ui≠vi), denoting a passage from the hall ui to the hall vi. The passages are one-way. Each tuple (ui,vi)

is present in the input at most once. The labyrinth can contain cycles and is not necessarily connected in any way.
Output

If it is possible to find the desired two paths, output "Possible", otherwise output "Impossible".

If the answer exists, output two path descriptions. Each description occupies two lines. The first line of the description contains an integer h
(2≤h≤n) — the number of halls in a path, and the second line contains distinct integers w1,w2,…,wh (w1=s; 1≤wj≤n; wh=t) — the halls in the path in the order of passing. Both paths must end at the same vertex t

. The paths must be different, and all intermediate halls in these paths must be distinct.
Examples
Input
Copy

5 5 1
1 2
2 3
1 4
4 3
3 5

Output
Copy

Possible
3
1 2 3
3
1 4 3

Input
Copy

5 5 1
1 2
2 3
3 4
2 5
5 4

Output
Copy

Impossible

Input
Copy

3 3 2
1 2
2 3
3 1

Output
Copy

Impossible

*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 4e5 + 10;
const ll inf = 9223372036854775700;
vector<vector<ll>> edges(N);
vector<bool> vis(N, 0);

void dfs(ll v, vector<ll> &path, bool &end, set<ll> &s)
{
    path.push_back(v);
    if (vis[v] && s.find(v) == s.end())
    {
        // visit all node and return for start point v => this path end here
        end = true;
        return;
    }
    else if (vis[v])
    {
        path.pop_back();
        return;
    }
    s.insert(v);
    vis[v] = 1;
    for (auto e : edges[v])
    {
        dfs(e, path, end, s);
        if (end)
            return;
    }

    path.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, s;
    cin >> n >> m >> s;

    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }
    if (edges[s].size() < 2)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    else
    {
        vector<ll> path1, path2;
        path1.push_back(s);
        path2.push_back(s);
        bool found = false;
        for (auto v : edges[s])
        {
            bool end = false;
            set<ll> se;
            se.insert(s);
            vis[s] = 1;
            dfs(v, path1, end, se);
            se.clear();
            if (end)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            ll t = path1[path1.size() - 1]; // get last item in path1  and find another path end with it

            // reset visit
            for (int i = 0; i <= n; i++)
            {
                vis[i] = 0;
            }
            // target visit from path1
            vis[t] = 1;
            for (auto e : edges[s])
            {
                bool end = false;
                set<ll> se;
                se.insert(s);
                vis[s] = 1;
                dfs(e, path2, end, se);
                se.clear();
                if (end)
                {
                    break;
                }
            }
            if (t == s)
            {
                cout << "Impossible" << endl;
                return 0;
            }
            else
            {
                cout << "Possible\n";
                cout << path1.size() << "\n";
                for (auto i : path1)
                {
                    cout << i << " ";
                }
                cout << "\n";
                cout << path2.size() << "\n";
                for (auto i : path2)
                {
                    cout << i << " ";
                }
                cout << "\n";
            }
        }
        else
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    return 0;
}