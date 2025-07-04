/*
C. Word on the Paper
time limit per test
1 second
memory limit per test
256 megabytes

On an 8×8

grid of dots, a word consisting of lowercase Latin letters is written vertically in one column, from top to bottom. What is it?
Input

The input consists of multiple test cases. The first line of the input contains a single integer t
(1≤t≤1000

) — the number of test cases.

Each test case consists of 8
lines, each containing 8 characters. Each character in the grid is either . (representing a dot) or a lowercase Latin letter (a–z

).

The word lies entirely in a single column and is continuous from the beginning to the ending (without gaps). See the sample input for better understanding.
Output

For each test case, output a single line containing the word made up of lowercase Latin letters (a
–z

) that is written vertically in one column from top to bottom.
Example
Input
Copy

5
........
........
........
........
...i....
........
........
........
........
.l......
.o......
.s......
.t......
........
........
........
........
........
........
........
......t.
......h.
......e.
........
........
........
........
........
.......g
.......a
.......m
.......e
a.......
a.......
a.......
a.......
a.......
a.......
a.......
a.......

Output
Copy

i
lost
the
game
aaaaaaaa

*/

#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int t, n = 8, m = 8;
    scanf("%d", &t);

    while (t--)
    {
        vector<char> word;
        for (int i = 0; i < n; i++)
        {
            char s[m + 1];
            scanf("%s", s);
            for (int j = 0; j < m; j++)
            {
                if (s[j] != '.')
                {
                    word.push_back(s[j]);
                }
            }
        }

        for (char c : word)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}