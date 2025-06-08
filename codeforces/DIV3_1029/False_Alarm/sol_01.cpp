/*
A. False Alarm
time limit per test
1 second
memory limit per test
256 megabytes

Yousef is at the entrance of a long hallway with n
doors in a row, numbered from 1 to n. He needs to pass through all the doors from 1 to n in order of numbering and reach the exit (past door n

).

Each door can be open or closed. If a door is open, Yousef passes through it in 1

second. If the door is closed, Yousef can't pass through it.

However, Yousef has a special button which he can use at most once at any moment. This button makes all closed doors become open for x

seconds.

Your task is to determine if Yousef can pass through all the doors if he can use the button at most once.
Input

The first line of the input contains an integer t
(1≤t≤1000

) — the number of test cases.

The first line of each test case contains two integers n,x
(1≤n,x≤10

) — the number of doors and the number of seconds of the button, respectively.

The second line of each test case contains n
integers a1,a2,...,an (ai∈{0,1}

) — the state of each door. Open doors are represented by '0', while closed doors are represented by '1'.

It is guaranteed that each test case contains at least one closed door.
Output

For each test case, output "YES" if Yousef can reach the exit, and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
Example
Input
Copy

7
4 2
0 1 1 0
6 3
1 0 1 1 0 0
8 8
1 1 1 0 0 1 1 1
1 2
1
5 1
1 0 1 0 1
7 4
0 0 0 1 1 0 1
10 3
0 1 0 0 1 0 0 1 0 0

Output
Copy

YES
NO
YES
YES
NO
YES
NO

Note

In the first test case, the optimal way is as follows:

    At time 0

, the door is open, so Yousef passes.
At time 1
, the door is closed, Yousef can use the button now and pass through the door.
At time 2
, the button's effect is still on, so Yousef can still pass.
At time 3

    , the button's effect has finished, but the door is open. Yousef passes and reaches the exit.

In the second test case, Yousef has a 3-second button, but he would need at least a 4-second button to reach the exit. Therefore, the answer is NO.

In the third test case, Yousef can turn on the button before starting to move. All the doors will stay open until he reaches the exit.




*/

#include <iostream>

using namespace std;

int main()

{
    int test_case_count = 0;
    int door_number = 0, seccounds = 0;

    // step 1 - 1 get test case  count
    cin >> test_case_count;
    // setp 1 -2 defain array for result in each case
    int result[test_case_count];
    // step 1 - 3 repet test case  (i) time
    for (int i = 0; i < test_case_count; i++)
    {
        // step 2 - 1 get test data
        cin >> door_number >> seccounds;
        // defain door array
        int doors[door_number];
        // step 2 -2 get doors information
        for (int j = 0; j < door_number; j++)
        {
            cin >> doors[j];
        }

        // step 3 - 1 test
        bool isPressButton = false;
        int r = 1 ;
        for (int t : doors)
        {
            if (t == 0)
            {
                if(isPressButton){
                    seccounds -=1 ;
                }
                continue;
            }
            else
            {
                isPressButton = true;
                if (seccounds <= 0)
                {
                    r = 0;
                    break ;
                }
                seccounds -= 1;
                continue;
            }
        }
        result[i] = r;
    }

    // step 4 - 1 print result
    for (int i = 0; i < test_case_count; i++)
    {
         
        if (result[i] == 1)
        {
            cout << "YES" <<endl;
        }
        else
        {
            cout << "NO" <<endl;
        }
    }

    return 0;
}