

#include <bits/stdtr1c++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n;
    cin >> s;
    int d = 0, a = 0;
    for (char c : s)
    {
        if (c == 'D')
        {
            d++;
        }
        if (c == 'A')
            a++;
    }

    if(a>d){
        cout<<"Anton";

    }else if(a<d){
        cout<<"Danik";

    }else{
        cout<<"Friendship";
        
    }
    cout<<"\n";
    return 0 ;
}