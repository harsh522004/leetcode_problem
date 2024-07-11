#include <iostream>
#include <cmath>
using namespace std;
const int MOD = 1'000'000'007;
long long findPow(long long base, long long exp, long long ans)
{
    if (exp == 0)
    {
        return ans;
    }
    if (exp % 2 == 0)
    {
        // even can
        return findPow((base * base) % MOD, (exp / 2), ans);
    }
    else
    {
        return findPow(base, exp - 1, (ans * base) % MOD);
    }
}
int countGoodNumbers(long long n)
{
    long long ans = findPow(20, n / 2, 1);
    if (n % 2 != 0)
    {
        return (ans * 5) % MOD;
    }
    return (ans) % MOD;
}
int main()
{
    int ans = countGoodNumbers(4);
    cout << ans << endl;
    return 0;
}