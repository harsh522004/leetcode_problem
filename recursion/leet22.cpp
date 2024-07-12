// generate parentheses

#include <iostream>
#include <vector>
using namespace std;
void generateParenthesis(int n, int openBracket, int closeBracket, string str)
{
    if (openBracket == 0 && closeBracket == 0)
    {
        cout << str << endl;
    }

    // add open if limit still there
    if (openBracket <= n)
    {
        str.append("(");
    }

    str.

        // add close if limit still there
        if (closeBracket <= n && closeBracket < openBracket)
    {
        str.append(")");
    }
}
int main()
{
}