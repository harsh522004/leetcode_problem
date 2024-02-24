// 1614. Maximum Nesting Depth of the Parentheses
#include <iostream>
#include <vector>
using namespace std;
void maxDepth(string s)
{

    if (s == "()")
    {
        return;
    }
    int currentDepth = 0;
    int maxd = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            currentDepth++;
            maxd = max(maxd, currentDepth);
        }
        else if (s[i] == ')')
        {
            currentDepth--;
        }
    }

    cout << maxd << endl;
}
int main()
{
    maxDepth("+(+(+)+)+");
    return 0;
}