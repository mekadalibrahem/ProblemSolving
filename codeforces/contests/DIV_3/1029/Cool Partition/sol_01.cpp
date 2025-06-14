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

//  TAKE LONG TIME
#include <bits/stdc++.h>

using ll = long long;
const ll N = 10e5 + 10;

using namespace std;

bool is_cool(vector<vector<ll>> segments)
{

    for (int i = 0; i < segments.size(); i++)
    {
        vector<ll> cool = segments[i];
        if (cool.empty())
        {
            return false;
        }
        for (int j = i + 1; j < segments.size(); j++)
        {
            vector<ll> part2 = segments[j];
            for (ll num : cool)
            {
                bool found = false;
                for (ll num2 : part2)
                {
                    if (num == num2)
                    {
                        found = true;
                        break;
                    }
                }
                if (found == false)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<vector<ll>> splite_segemnts(ll index, vector<ll> nums)
{
    vector<vector<ll>> segments;
    vector<ll> s1, s2;
    for (int i = 0; i < index; i++)
    {
        s1.push_back(nums[i]);
    }
    for (int i = index; i < nums.size(); i++)
    {
        s2.push_back(nums[i]);
    }
    segments.push_back(s1);
    segments.push_back(s2);
    return segments;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    vector<ll> result;
    while (t--)
    {
        ll n, first, segments = 1;
        ll max_count = 0;
        stack<ll> num_index;
        vector<ll> nums;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            ll m;
            cin >> m;
            if (i == 0)
            {
                first = m;
                max_count++;
                num_index.push(i);
            }
            else
            {
                if (m == first)
                {
                    max_count++;
                    num_index.push(i);
                }
            }

            nums.push_back(m);
        }

        if (n == 1 || n == 0)
        {
            // one element => one segment
            result.push_back(n);
        }
        else
        {
            if (max_count == 1)
            {
                result.push_back(max_count);
            }
            else
            {
                vector<vector<ll>> parts;

                parts.push_back(nums);
                ll cool_index = n + 5;
                while (!num_index.empty())
                {
                    ll index, top = num_index.top();
                    num_index.pop();
                    if (cool_index > top)
                    {
                        index = top;
                    }
                    else
                    {
                        index = cool_index;
                    }
                    vector<ll> part_to_splite = parts[0];

                    bool isCool = false;
                    for (int i = index; i >= 0; i--)
                    {
                        vector<vector<ll>> temp_parts = splite_segemnts(i, part_to_splite);
                        for (int j = 1; j < parts.size(); j++)
                        {
                            temp_parts.push_back(parts[j]);
                        }
                        if (is_cool(temp_parts))
                        {
                            isCool = true;
                            cool_index = i;
                            parts = temp_parts;
                            break;
                        }
                    }
                    if (isCool)
                    {
                        segments++;
                    }
                }

                result.push_back(segments);
            }
        }
    }
    for (auto r : result)
    {
        cout << r << "\n";
    }

    return 0;
}