/* 
* Simple, given a string of words, return the length of the shortest word(s).
* 
* String will never be empty and you do not need to account for different data types.

*/
#include <string>
int find_short(std::string str)
{
  int size = str.length();
  int low = size; 
  int count = 0 ; 
  for( int i = 0 ; i <size ; i++ ){
    char l = str[i] ;
      if (isspace(l) ) {
            if(count != 0 && count < low ){
                low = count ; 
               
            }
         count = 0 ;
      }
      else {
        count += 1 ;

      }
  }
  // check last word 
  if (low > count ) low = count ;
  return low;
}