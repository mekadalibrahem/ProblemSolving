/*
C. Clock Conversion
time limit per test
1 second
memory limit per test
256 megabytes

Given the time in 24-hour format, output the equivalent time in 12-hour format.

    24-hour format divides the day into 24 hours from 00

to 23, each of which has 60 minutes from 00 to 59
.
12-hour format divides the day into two halves: the first half is AM
, and the second half is PM. In each half, the hours are numbered in the order 12,01,02,03,…,11. Each hour has 60 minutes numbered from 00 to 59

    .

Input

The first line contains a single integer t
(1≤t≤1440

) — the number of test cases.

The only line of each test case contains a string s
of length 5 with format hh:mm representing a valid time in the 24-hour format. hh represents the hour from 00 to 23, and mm represents the minute from 00 to 59

.

The input will always be a valid time in 24-hour format.
Output

For each test case, output two strings separated by a space ("hh:mm AM" or "hh:mm PM"), which are the 12-hour equivalent to the time provided in the test case (without quotes).

You should output the time exactly as indicated; in particular, you should not remove leading zeroes.
Example
Input
Copy

11
09:41
18:06
12:14
00:59
00:00
14:34
01:01
19:07
11:59
12:00
21:37

Output
Copy

09:41 AM
06:06 PM
12:14 PM
12:59 AM
12:00 AM
02:34 PM
01:01 AM
07:07 PM
11:59 AM
12:00 PM
09:37 PM


*/

#include <cstdio>
#include <vector>
using namespace std;

int main()
{

    int t;
    scanf("%d", &t);
    // for resoult
    vector<vector<int>> times;

    while (t--)
    {
        int h, m;
        scanf("%d:%d", &h, &m);
        if (h > 23 || h < 0 || m > 59 || m < 0)
        {
            break;
        }
        vector<int> time;
        time.push_back(h);
        time.push_back(m);
        times.push_back(time);
    }
    for (int i = 0; i < times.size(); i++)
    {
        vector<int> time = times.at(i);
        char c = 'A';
        int h1 = time.at(0), m1 = time.at(1);

        if (h1 > 11)
        {
            h1 = h1 - 12;
            c = 'P';
        }

        if (h1 == 0)
        {
            h1 = 12;
        }

        printf("%02d:%02d %cM\n", h1, m1, c);
    }

    return 0;
}