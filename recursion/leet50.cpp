// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
#include <iostream>
using namespace std;
double myPow(double x, int n)
{
    if (x == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    if (n < 0)
    {
        return 1 / myPow(x, -n);
    }

    if (n > 0)
    {
        return myPow(x, n - 1) * x;
    }
}

int main()
{

    int n = -5;
    int x = 2;
    double ans = myPow(x, n);
    cout << ans << endl;
    return 0;
}