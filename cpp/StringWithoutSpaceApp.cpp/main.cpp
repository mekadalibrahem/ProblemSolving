#include <iostream>;
#include <string.h>
#include <stdio.h>

using namespace std;
string no_space(string x);
int main()
{
    string str = no_space("8 j 8   mBliB8g  imjB8B8  jl  B");
    cout<< str ;
    return 0;
}
string no_space(string x){
    std::string stringWithoutSpace = "";
      string space = " " ;
      for(int i =0 ; i < x.length() ; i++){


        if(isspace(x[i])) continue ;
       // if(strcmp(c, space) == 0 ) continue ;
        else stringWithoutSpace += x[i];
      }
      return stringWithoutSpace ;
}
