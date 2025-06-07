/*


A. Stones on the Table
time limit per test
2 seconds
memory limit per test
256 megabytes

There are n stones on the table in a row, each of them can be red, green or blue. Count the minimum number of stones to take from the table so that any two neighboring stones had different colors. Stones in a row are considered neighboring if there are no other stones between them.
Input

The first line contains integer n (1 ≤ n ≤ 50) — the number of stones on the table.

The next line contains string s, which represents the colors of the stones. We'll consider the stones in the row numbered from 1 to n from left to right. Then the i-th character s equals "R", if the i-th stone is red, "G", if it's green and "B", if it's blue.
Output

Print a single integer — the answer to the problem.

*/


#include <iostream> 
using namespace std ;

int main() { 

    

    int  count ,out = 0 ;
    char current , last  ;

    cin >> count ;
    for(int i = 1 ; i <= count ; i++){
        cin >> current ;
        if(current == last){
            out++ ;
        }else{
            last = current ;
        }
    }
    cout << out ;

    return 0 ;
}