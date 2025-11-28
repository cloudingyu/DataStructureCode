#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
const int MAXN = 1000005;

const ll MOD1 = 1000000007;
const ll BASE1 = 233;

const ll MOD2 = 998244353;
const ll BASE2 = 13331;

ll h1[MAXN], p1[MAXN];
ll h2[MAXN], p2[MAXN];
int ans[MAXN];
int n;
string s;

pair<ll, ll> get_hash(int l, int r)
{
    ll res1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % MOD1 + MOD1) % MOD1;
    ll res2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % MOD2 + MOD2) % MOD2;
    return {res1, res2};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;

    p1[0] = 1;
    p2[0] = 1;
    h1[0] = 0;
    h2[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        p1[i + 1] = (p1[i] * BASE1) % MOD1;
        p2[i + 1] = (p2[i] * BASE2) % MOD2;
        h1[i + 1] = (h1[i] * BASE1 + s[i]) % MOD1;
        h2[i + 1] = (h2[i] * BASE2 + s[i]) % MOD2;
    }

    for (int k = (n + 1) / 2; k >= 1; --k)
    {
        int sub_len = n - 2 * k + 2;
        int cand = ans[k + 1] + 2;

        if (cand >= sub_len)
        {
            cand = sub_len;
            if (cand % 2 != 0)
                cand -= 2;
            else
                cand -= 1;
        }
        else
        {
            if (cand % 2 == 0)
                cand--;
        }

        while (cand > 0)
        {
            if (get_hash(k, k + cand - 1) == get_hash(n - k + 2 - cand, n - k + 1))
                break;
            cand -= 2;
        }

        if (cand < 1)
            cand = -1;

        ans[k] = cand;
    }

    for (int k = 1; k <= (n + 1) / 2; ++k)
        cout << ans[k] << " ";

    return 0;
}