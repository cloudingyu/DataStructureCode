#include <iostream>
using namespace std;

const int MAXN = 500005;
int n;
long long c[MAXN], sum[MAXN], temp[MAXN];

long long inv(int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) >> 1;

    long long ret = inv(l, mid) + inv(mid + 1, r);

    int i = l, j = mid + 1, p = l;
    while (i <= mid && j <= r)
    {
        if (sum[i] < sum[j])
            temp[p++] = sum[i++];
        else
        {
            temp[p++] = sum[j++];
            ret += (mid - i + 1);
        }
    }
    while (i <= mid)
        temp[p++] = sum[i++];
    while (j <= r)
        temp[p++] = sum[j++];

    for (int k = l; k <= r; k++)
        sum[k] = temp[k];

    return ret;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + c[i];

    cout << (long long)n * (n + 1) / 2 - inv(0, n) << endl;

    return 0;
}