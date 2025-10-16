#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;
long long n, m;

long long qpow(long long a, long long b)
{
    if (b == 0)
        return 1;

    long long t = (qpow(a, b >> 1) % MOD);
    t = t * t % MOD;

    return (b & 1) ? t * a % MOD : t;
}

int main()
{
    cin >> n >> m;

    cout << qpow(n, m) << endl;

    return 0;
}