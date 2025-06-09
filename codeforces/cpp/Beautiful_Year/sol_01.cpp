/*
A. Beautiful Year
time limit per test
2 seconds
memory limit per test
256 megabytes

It seems like the year of 2013 came only yesterday. Do you know a curious fact? The year of 2013 is the first year after the old 1987 with only distinct digits.

Now you are suggested to solve the following problem: given a year number, find the minimum year number which is strictly larger than the given one and has only distinct digits.
Input

The single line contains integer y (1000 ≤ y ≤ 9000) — the year number.
Output

Print a single integer — the minimum year number that is strictly larger than y and all it's digits are distinct. It is guaranteed that the answer exists.
Examples
Input

1987

Output

2013

Input

2013

Output


2014
*/


#include <iostream> 
#include <map>
#include <string>
using namespace std; 

int main() {
    int year ;
    int next_year , found = 0 ;
    cin >> year ;
    next_year = year +1;
    string s_year = to_string(next_year);
    while (found ==0)
    {
        bool valid = true ;
        map<char,int> count ;
        for(char c : s_year){
            if(count[c]){
                valid = false;
                break ;
            }else{
                count[c]= 1;
            }
        }
        if(valid){
            cout << next_year ;
            found = 1;
            break ;
        }else{
            next_year++;
            s_year = to_string(next_year);
        }
    }
    
    
    return 0 ;
}