/*
A. Yet Another Two Integers Problem
time limit per test
1 second
memory limit per test
256 megabytes

You are given two integers a
and b

.

In one move, you can choose some integer k
from 1 to 10 and add it to a or subtract it from a. In other words, you choose an integer k∈[1;10] and perform a:=a+k or a:=a−k. You may use different values of k

in different moves.

Your task is to find the minimum number of moves required to obtain b
from a

.

You have to answer t

independent test cases.
Input

The first line of the input contains one integer t
(1≤t≤2⋅104) — the number of test cases. Then t

test cases follow.

The only line of the test case contains two integers a
and b (1≤a,b≤109

).
Output

For each test case, print the answer: the minimum number of moves required to obtain b
from a

.
Example
Input
Copy

6
5 5
13 42
18 4
1337 420
123456789 1000000000
100500 9000

Output
Copy

0
3
2
92
87654322
9150

Note

In the first test case of the example, you don't need to do anything.

In the second test case of the example, the following sequence of moves can be applied: 13→23→32→42
(add 10, add 9, add 10

).

In the third test case of the example, the following sequence of moves can be applied: 18→10→4
(subtract 8, subtract 6).
*/
// INVALID TAKE LONG TIMR 
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a1, a2, diff, count = 0;
        scanf("%d", &a1);
        scanf("%d", &a2);
        diff = abs(a1 - a2);
        while (diff)
        {
            if (diff > 10)
            {
                diff -= 10;
                count++;
            }
            else
            {
                diff = 0;
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}