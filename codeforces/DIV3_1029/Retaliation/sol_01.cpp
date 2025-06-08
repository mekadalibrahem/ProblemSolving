/*
D. Retaliation
time limit per test
2 seconds
memory limit per test
256 megabytes

Yousef wants to explode an array a1,a2,…,an

. An array gets exploded when all of its elements become equal to zero.

In one operation, Yousef can do exactly one of the following:

    For every index i

in a, decrease ai by i
.
For every index i
in a, decrease ai by n−i+1

    .

Your task is to help Yousef determine if it is possible to explode the array using any number of operations.
Input

The first line of the input contains an integer t
(1≤t≤104

) — the number of test cases.

The first line of each test case contains an integer n
(2≤n≤2⋅105

) — the size of the array.

The second line of each test case contains n
integers a1,a2,…,an (1≤ai≤109

) — the elements of the array.

It is guaranteed that the sum of n
over all test cases doesn't exceed 2⋅105

.
Output

For each test case, print "YES" if Yousef can explode the array, otherwise output "NO".

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
*/