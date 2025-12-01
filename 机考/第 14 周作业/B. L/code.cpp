#include <iostream>
#include <string>
using namespace std;

const long long MAXN = 5005;
const long long BASE = 131;
const long long MOD = 1e7 + 7;

int n, m, k, cnt = 0;
int hn[MAXN][MAXN], hm[MAXN][MAXN];
long long hl[2 * MAXN], p[2 * MAXN];
char c[MAXN][MAXN];
string L;

long long get_hash_n(int l, int r, int q)
{
    return (hn[q][r] + MOD - hn[q][l - 1] * p[r - l + 1] % MOD) % MOD;
}

long long get_hash_m(int l, int r, int q)
{
    return (hm[q][r] + MOD - hm[q][l - 1] * p[r - l + 1] % MOD) % MOD;
}

long long get_hash_l(int l, int r)
{
    return (hl[r] + MOD - hl[l - 1] * p[r - l + 1] % MOD) % MOD;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];
    cin >> L;

    p[0] = 1;
    for (int i = 1; i <= 2 * MAXN - 1; i++)
        p[i] = p[i - 1] * BASE % MOD;

    char key = L[k - 1];

    for (int i = 1; i <= 2 * k - 1; i++)
        hl[i] = (hl[i - 1] * BASE + L[i - 1] - 'a' + 1) % MOD;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            hn[i][j] = (hn[i][j - 1] * BASE + c[j][i] - 'a' + 1) % MOD;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            hm[i][j] = (hm[i][j - 1] * BASE + c[i][j] - 'a' + 1) % MOD;

    for (int i = k; i <= n; i++)
        for (int j = 1; j <= m - k + 1; j++)
            if (c[i][j] == key && get_hash_n(i - k + 1, i, j) == get_hash_l(1, k) && get_hash_m(j, j + k - 1, i) == get_hash_l(k, 2 * k - 1))
                cnt++;

    cout << cnt << endl;

    return 0;
}