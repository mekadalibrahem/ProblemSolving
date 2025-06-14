/*

B. Shrink
time limit per test
2 seconds
memory limit per test
256 megabytes

A shrink operation on an array a
of size m

is defined as follows:

    Choose an index i

(2≤i≤m−1) such that ai>ai−1 and ai>ai+1
.
Remove ai

    from the array.

Define the score of a permutation∗
p as the maximum number of times that you can perform the shrink operation on p

.

Yousef has given you a single integer n
. Construct a permutation p of length n

with the maximum possible score. If there are multiple answers, you can output any of them.

∗
A permutation of length n is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array), and [1,3,4] is also not a permutation (n=3 but there is 4

in the array).
Input

The first line of the input contains an integer t
(1≤t≤103

) — the number of test cases.

Each test case contains an integer n
(3≤n≤2⋅105

) — the size of the permutation.

It is guaranteed that the sum of n
over all test cases does not exceed 2⋅105

.
Output

For each test case, output any permutation p1,p2,…,pn

that maximizes the number of shrink operations.
Example
Input
Copy

2
3
6

Output
Copy

1 3 2
2 3 6 4 5 1

Note

In the first test case:

    We choose p=[1,3,2]

.
Choose index 2
, and remove p2 from the array. The array becomes p=[1,2]

    .

It can be shown that the maximum number of operations we can perform is 1
. Another valid answer is p=[2,3,1]

.

In the second test case:

    We choose p=[2,3,6,4,5,1]

.
Choose index 5
, and remove p5 from the array. The array becomes p=[2,3,6,4,1]
.
Choose index 3
, and remove p3 from the array. The array becomes p=[2,3,4,1]
.
Choose index 3
, and remove p3 from the array. The array becomes p=[2,3,1]
.
Choose index 2
, and remove p2 from the array. The array becomes p=[2,1]

    .

The maximum number of operations we can perform is 4
. Any permutation with a score of 4 is valid.

*/

#include <iostream>
#include <vector>

using namespace std;

int main()



{

    int test_case_count = 0;

    cin >> test_case_count;
    vector<vector<int>> result;
    while (test_case_count--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        int low = n/2, high = n;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 1)
                p[i - 1] = low++;
            else
                p[i - 1] = high--;
        }
        result.push_back(p);
    }

    for (int i = 0; i < result.size(); i++)
    {
        for (int j : result[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}