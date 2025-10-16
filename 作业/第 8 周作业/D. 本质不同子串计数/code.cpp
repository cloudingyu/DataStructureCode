#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const long long MOD1 = 1000000007, MOD2 = 1000000009;
const long long BASE1 = 31, BASE2 = 131;
const int MAXN = 2005;

long long hash1[MAXN], hash2[MAXN];
long long pow1[MAXN], pow2[MAXN];

int ans = 1;

pair<long long, long long> rep[MAXN * MAXN];
int len = 0;

string s;

long long sub1(int l,int r)
{
    return (hash1[r] + MOD1 - hash1[l] * pow1[r - l] % MOD1) % MOD1;
}

long long sub2(int l,int r)
{
    return (hash2[r] + MOD2 - hash2[l] * pow2[r - l] % MOD2) % MOD2;
}


int main()
{
    cin >> s;
    int n = (int)s.size();

    pow1[0] = 1;
    pow2[0] = 1;
    hash1[0] = 0;
    hash2[0] = 0;

    for (int i = 0; i < n; i++)
    {
        hash1[i + 1] = (hash1[i] * BASE1 + s[i] - 'a' + 1) % MOD1;
        hash2[i + 1] = (hash2[i] * BASE2 + s[i] - 'a' + 1) % MOD2;
        pow1[i + 1] = pow1[i] * BASE1 % MOD1;
        pow2[i + 1] = pow2[i] * BASE2 % MOD2;
    }

    for (int i = 0; i < n; i++)
        for (int j = i+1; j <= n; j++)
            rep[len++] = {sub1(i,j), sub2(i,j)};
    sort(rep, rep + len);

    for (int i = 0; i < len-1; i++)
        if (rep[i] != rep[i + 1])
            ans++;
    cout << ans << endl;
    return 0;
}