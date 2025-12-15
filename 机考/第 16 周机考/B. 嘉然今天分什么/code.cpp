#include <iostream>
using namespace std;

const int MAXN = 5e5 + 5;
int n, k, maxn = 0;
long long ans = 0;
long long sum[MAXN];

bool check(long long m)
{
    long long current = 0;
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (current + (sum[i] - sum[i - 1]) > m)
        {
            cnt++;
            current = sum[i] - sum[i - 1];
            if (cnt > k)
                return false;
        }
        else
            current += sum[i] - sum[i - 1];
    }
    return true;
}

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        maxn = max(maxn, x);
        sum[i] = sum[i - 1] + x;
    }

    long long l = maxn, r = sum[n];
    while (l <= r)
    {
        long long mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}