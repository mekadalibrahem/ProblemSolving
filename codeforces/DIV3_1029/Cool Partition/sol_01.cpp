/*
C. Cool Partition
time limit per test
2 seconds
memory limit per test
256 megabytes

Yousef has an array a
of size n. He wants to partition the array into one or more contiguous segments such that each element ai

belongs to exactly one segment.

A partition is called cool if, for every segment bj
, all elements in bj also appear in bj+1

(if it exists). That is, every element in a segment must also be present in the segment following it.

For example, if a=[1,2,2,3,1,5]
, a cool partition Yousef can make is b1=[1,2], b2=[2,3,1,5]. This is a cool partition because every element in b1 (which are 1 and 2) also appears in b2. In contrast, b1=[1,2,2], b2=[3,1,5] is not a cool partition, since 2 appears in b1 but not in b2

.

Note that after partitioning the array, you do not change the order of the segments. Also, note that if an element appears several times in some segment bj
, it only needs to appear at least once in bj+1

.

Your task is to help Yousef by finding the maximum number of segments that make a cool partition.
Input

The first line of the input contains integer t
(1≤t≤104

) — the number of test cases.

The first line of each test case contains an integer n
(1≤n≤2⋅105

) — the size of the array.

The second line of each test case contains n
integers a1,a2,…,an (1≤ai≤n

) — the elements of the array.

It is guaranteed that the sum of n
over all test cases doesn't exceed 2⋅105

.
Output

For each test case, print one integer — the maximum number of segments that make a cool partition.

*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> splitVector(vector<int> v , int start , int end);


int main()
{
    int test_case = 0;
    cin >> test_case;
    int res[test_case];
    for (int i = 0; i < test_case; i++)
    {
        int n;
        cin >> n;
        vector<int> arr ;
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        
    
    }
    for (int i : res)
    {
        cout << i << endl;
    }

    return 0;
}

vector<vector<int>> splitVector(vector<int> v , int start , int end){
    for (int i = 0; i < v.size(); i++)
    {
        // if
    }
    
}