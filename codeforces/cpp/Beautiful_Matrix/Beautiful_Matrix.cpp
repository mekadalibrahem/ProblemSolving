/*
A. Beautiful Matrix
time limit per test
2 seconds
memory limit per test
256 megabytes

You've got a 5 × 5 matrix, consisting of 24 zeroes and a single number one. Let's index the matrix rows by numbers from 1 to 5 from top to bottom, let's index the matrix columns by numbers from 1 to 5 from left to right. In one move, you are allowed to apply one of the two following transformations to the matrix:

    Swap two neighboring matrix rows, that is, rows with indexes i and i + 1 for some integer i (1 ≤ i < 5).
    Swap two neighboring matrix columns, that is, columns with indexes j and j + 1 for some integer j (1 ≤ j < 5). 

You think that a matrix looks beautiful, if the single number one of the matrix is located in its middle (in the cell that is on the intersection of the third row and the third column). Count the minimum number of moves needed to make the matrix beautiful.
Input

The input consists of five lines, each line contains five integers: the j-th integer in the i-th line of the input represents the element of the matrix that is located on the intersection of the i-th row and the j-th column. It is guaranteed that the matrix consists of 24 zeroes and a single number one.
Output

Print a single integer — the minimum number of moves needed to make the matrix beautiful.
*/

#include <iostream> 
#include <cmath>
using namespace std ;

int main(){
    // get input 
    int c00 ,c01 ,c02 ,c03 ,c04;
    int c10 ,c11 ,c12 ,c13 ,c14;
    int c20 ,c21 ,c22 ,c23 ,c24;
    int c30 ,c31 ,c32 ,c33 ,c34;
    int c40 ,c41 ,c42 ,c43 ,c44;
    cin >> c00  >> c01  >> c02  >>c03  >>c04;
    cin >> c10  >> c11  >> c12  >>c13  >>c14;
    cin >> c20  >> c21  >> c22  >>c23  >>c24;
    cin >> c30  >> c31  >> c32  >>c33  >>c34;
    cin >> c40  >> c41  >> c42  >>c43  >>c44;
    int current_row , current_col ;
    int target_row = 2 , target_col = 2;
    int mat[5][5] = {
        {c00 ,c01 ,c02 ,c03 ,c04},
        {c10 ,c11 ,c12 ,c13 ,c14},
        {c20 ,c21 ,c22 ,c23 ,c24},
        {c30 ,c31 ,c32 ,c33 ,c34},
        {c40 ,c41 ,c42 ,c43 ,c44}
    };

    
    // find current row and col 
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <5; j++)
        {
            if(mat[i][j] == 1){
                current_col = j ;
                current_row = i ;
                break;
            }
        }
    }

    int result ;
    result = abs(target_row - current_row) + abs(target_col - current_col);
    cout << result<<endl ;  
     


}


