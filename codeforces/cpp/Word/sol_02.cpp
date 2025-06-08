/*
A. Word
time limit per test
2 seconds
memory limit per test
256 megabytes

Vasya is very upset that many people on the Net mix uppercase and lowercase letters in one word. That's why he decided to invent an extension for his favorite browser that would change the letters' register in every word so that it either only consisted of lowercase letters or, vice versa, only of uppercase ones. At that as little as possible letters should be changed in the word. For example, the word HoUse must be replaced with house, and the word ViP — with VIP. If a word contains an equal number of uppercase and lowercase letters, you should replace all the letters with lowercase ones. For example, maTRIx should be replaced by matrix. Your task is to use the given method on one given word.
Input

The first line contains a word s — it consists of uppercase and lowercase Latin letters and possesses the length from 1 to 100.
Output

Print the corrected word s. If the given word s has strictly more uppercase letters, make the word written in the uppercase register, otherwise - in the lowercase one.

*/

// using ASCII CODE
// ASCII values for lower case alphabets (a-z):97 - 122
// ASCII values for upper case alphabets (A-Z):65 - 92
// ==============================================================

#include <iostream>
#include <string>

using namespace std;

string strtoupper(string word);
string strtolower(string word);
bool isLower(char c);
bool isUpper(char c);
char toUpper(char c);

char toLower(char c);
int main()
{
    string word, output;
    int lower = 0, upper = 0;
    cin >> word;
    for (char c : word)
    {

        if (isLower(c))
        {

            lower++;
        }
        else if (isUpper(c))
        {

            upper++;
        }
    }
    if (lower >= upper)
    {
        output = strtolower(word);
    }
    else
    {
        output = strtoupper(word);
    }
    cout << output;
    return 0;
}

string strtoupper(string word)
{
    string result = "";
    for (char c : word)
    {
        result += toUpper(c);
    }
    return result;
}

string strtolower(string word)
{
    string result = "";
    for (char c : word)
    {
        result += toLower(c);
    }
    return result;
}
bool isLower(char c)
{
    int ascii = int(c);
    if (ascii >= 97 && ascii <= 122)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isUpper(char c)
{
    int ascii = int(c);
    if (ascii >= 65 && ascii <= 92)
    {
        return true;
    }
    else
    {
        return false;
    }
}
char toUpper(char c)
{
    if (isUpper(c))
        return c;
    return (char(int(c) - 32));
}

char toLower(char c)
{
    if (isLower(c))
        return c;
    return (char(int(c) + 32));
}