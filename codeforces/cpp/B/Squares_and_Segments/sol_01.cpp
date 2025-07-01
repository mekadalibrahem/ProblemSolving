/*

B. Squares and Segments
time limit per test
1 second
memory limit per test
256 megabytes

Little Sofia is in fourth grade. Today in the geometry lesson she learned about segments and squares. On the way home, she decided to draw n
squares in the snow with a side length of 1. For simplicity, we assume that Sofia lives on a plane and can draw only segments of length 1

, parallel to the coordinate axes, with vertices at integer points.

In order to draw a segment, Sofia proceeds as follows. If she wants to draw a vertical segment with the coordinates of the ends (x,y)
and (x,y+1). Then Sofia looks if there is already a drawn segment with the coordinates of the ends (x′,y) and (x′,y+1) for some x′. If such a segment exists, then Sofia quickly draws a new segment, using the old one as a guideline. If there is no such segment, then Sofia has to take a ruler and measure a new segment for a long time. Same thing happens when Sofia wants to draw a horizontal segment, but only now she checks for the existence of a segment with the same coordinates x, x+1 and the differing coordinate y

.

For example, if Sofia needs to draw one square, she will have to draw two segments using a ruler:

After that, she can draw the remaining two segments, using the first two as a guide:

If Sofia needs to draw two squares, she will have to draw three segments using a ruler:

After that, she can draw the remaining four segments, using the first three as a guide:

Sofia is in a hurry, so she wants to minimize the number of segments that she will have to draw with a ruler without a guide. Help her find this minimum number.
Input

The only line of input contains a single integer n
(1≤n≤109

), the number of squares that Sofia wants to draw.
Output

Print single integer, the minimum number of segments that Sofia will have to draw with a ruler without a guide in order to draw n

squares in the manner described above.
Examples
Input
Copy

1

Output
Copy

2

Input
Copy

2

Output
Copy

3

Input
Copy

4

Output
Copy

4


*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    double n;
    cin >> n;

    if (n == 1)
    {
        cout << 2 << endl;
        return;
    }

    ll l = 1, r = n, ans = 0;
    ll s = sqrt(n);
    double a = s, b = a;
    
    for (ll b = a; b < (a + 3); b++)
    {
        if (a * b >= n)
        {
            ans = a + b;
            break;
        }
    }
   
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}