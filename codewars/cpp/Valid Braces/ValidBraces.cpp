/**
 * Write a function that takes a string of braces, and determines if the order of the braces is valid. It should return true if the string is valid, and false if it's invalid.

This Kata is similar to the Valid Parentheses Kata, but introduces new characters: brackets [], and curly braces {}. Thanks to @arnedag for the idea!

All input strings will be nonempty, and will only consist of parentheses, brackets and curly braces: ()[]{}.
What is considered Valid?

A string of braces is considered valid if all braces are matched with the correct brace.
Examples

"(){}[]"   =>  True
"([{}])"   =>  True
"(}"       =>  False
"[(])"     =>  False
"[({})](]" =>  False


 */

#include <iostream>
#include <stack>
using namespace std;
bool validBraces(string s);

int main()
{

    cout << validBraces("(){}[]") << "\n";
    cout << validBraces("([{}])") << "\n";
    cout << validBraces("(}") << "\n";
    cout << validBraces("[(])") << "\n";
    cout << validBraces("[({})](]") << "\n";

    return 0;
}

bool validBraces(string s)
{
    stack<char> seq;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        char top;
        switch (c)
        {
        case '[':
            seq.push(c);
            break;
        case '(':
            seq.push(c);
            break;
        case '{':
            seq.push(c);
            break;

        case ')':
            if (seq.empty())
            {
                return false;
            }
            else
            {
                top = seq.top();
                if (top == '(')
                {
                    seq.pop();
                }
                else
                {
                    return false;
                }
            }
            break;
        case '}':
            if (seq.empty())
            {
                return false;
            }
            else
            {
                top = seq.top();
                if (top == '{')
                {
                    seq.pop();
                }
                else
                {
                    return false;
                }
            }
            break;
        case ']':
            if (seq.empty())
            {
                return false;
            }
            else
            {
                top = seq.top();
                if (top == '[')
                {
                    seq.pop();
                }
                else
                {
                    return false;
                }
            }
            break;

        default:
            break;
        }
    }
    if (seq.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
