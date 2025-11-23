#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 100005;
const int P = 131;

string s;
unsigned long long h[MAXN], p[MAXN];
unsigned long long v[MAXN];

unsigned long long get_hash(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    cin >> s;
    int n = s.length();

    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + s[i - 1];
    }

    long long ans = 0;
    int len = 1;
    int limit = min(n, 100);

    for (; len <= limit; len++)
    {
        int cnt = 0;
        for (int i = 1; i + len - 1 <= n; i++)
        {
            v[cnt++] = get_hash(i, i + len - 1);
        }
        sort(v, v + cnt);
        int unique_cnt = unique(v, v + cnt) - v;
        ans += unique_cnt;

        if (unique_cnt == n - len + 1)
        {
            long long rem = n - len;
            ans += rem * (rem + 1) / 2;
            len = n + 1;
            break;
        }
    }

    if (len <= n)
    {
        long long rem = n - (len - 1);
        ans += rem * (rem + 1) / 2;
    }

    cout << ans << endl;

    return 0;
}