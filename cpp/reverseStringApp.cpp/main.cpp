#include <iostream>
#include <string>
using namespace std;
// Complete the solution so that it reverses the string passed into it.

string reverseString(string str);
int main()
{
    cout << reverseString("Hello world!") << endl;
    return 0;
}
string reverseString(string str){
    string reverseText= "";
    for(int i = str.length() -1 ; i>=0 ; i--){
        reverseText += str[i] ;
    }
    return reverseText ;
}
