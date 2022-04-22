/*
    Description

    We need a function that can transform a string into a number. What ways of achieving this do you know?

    Note: Don't worry, all inputs will be strings, and every string is a perfectly valid representation of an integral number.
    Examples
    "1234" --> 1234
    "605"  --> 605
    "1405" --> 1405
    "-7" --> -7
    
*/
#include <string>;
#include <iostream>;

using namespace std ;

int string_to_number(const std::string& s); 

int main(){
   int number =  string_to_number("123456");
   cout << number ;
}


int string_to_number(const std::string& s) {
  //your code here
  bool isNegative = false ;
  int number = 0 ;
  for(int i = 0 ; i < s.length() ; i++){
    char c = s[i];
    if( c == '-'){
      isNegative = true; 
      
    }else{
      int num = c - '0';
      number *= 10 ;
      number += num ;
    }
  }
  if(isNegative){
    number = number * -1 ;
  }
  return  number ;
}