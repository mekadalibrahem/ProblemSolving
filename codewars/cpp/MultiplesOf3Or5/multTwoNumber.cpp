/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.

Additionally, if the number is negative, return 0.

Note: If the number is a multiple of both 3 and 5, only count it once.

*/

#include <iostream> 

using namespace std ; 



int solution(int number);



int main(){

    int re = solution(10);
    cout<<re<<"\n";
    return 0 ;
}




int solution(int number) 
{
    const int number1 =  3 ;
    const int number2 =  5 ;
    int sum_number_1 = 0; 
    int sum_number_2 = 0;
    int total = 0 ;

    for (int i = 0; i < number; i+=number1)
    {
        sum_number_1 += i ;
    }
    for (int i = 0; i < number; i+=number2)
    {
        // number can divid by number 1 and number 2  it is calc in first loop so do not need sum agine
        if(i%number1 == 0 ){continue;}
        sum_number_2 += i ;
    }
    

    total = sum_number_1 + sum_number_2 ;

    return total ;
}
