/*

A. Elephant
time limit per test
1 second
memory limit per test
256 megabytes

An elephant decided to visit his friend. It turned out that the elephant's house is located at point 0 and his friend's house is located at point x(x > 0) of the coordinate line. In one step the elephant can move 1, 2, 3, 4 or 5 positions forward. Determine, what is the minimum number of steps he need to make in order to get to his friend's house.
Input

The first line of the input contains an integer x (1 ≤ x ≤ 1 000 000) — The coordinate of the friend's house.
Output

Print the minimum number of steps that elephant needs to make to get from point 0 to point x.

*/

#include <iostream>

using namespace std;

int main()
{
    int start = 0, end = 0, current = 0, steps = 0;
    cin >> end;

    while (current != end)
    {
        int temp = end - current;
        if (temp >= 5)
        {
            current += 5;
            steps++;
        }
        else if (temp >= 4)
        {
            current += 4;
            steps++;
        }
        else if (temp >= 3)
        {
            current += 3;
            steps++;
        }
        else if (temp >= 2)
        {
            current += 2;
            steps++;
        }
        else if (temp >= 1)
        {
            current += 1;
            steps++;
        }
    }
    cout << steps;

    return 0;
}