/*
#code wars
Write a function that takes an integer as input, and returns the number of bits that are equal to one in the binary representation of that number. You can guarantee that input is non-negative.

Example: The binary representation of 1234 is 10011010010, so the function should return 5 in this case



*/

#include <iostream>

using namespace std;

unsigned int countBits(unsigned long long n);

int main()
{
    cout << countBits(0) << "\n";
    cout << countBits(4) << "\n";
    cout << countBits(3811) << "\n";
    cout << countBits(77231418) << "\n";
    cout << countBits(12525589) << "\n";
    cout << countBits(392902058) << "\n";
    return 0;
}

unsigned int countBits(unsigned long long n)
{
    int count = 0;

    while (n)
    {
        short bit = n % 2;
        n = n / 2;
        count += bit;
    }

    return count;
}
