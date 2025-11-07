#include <iostream>
using namespace std;

const int MAXN = 1e6 + 5;
int n, m, k, maxn;
int p[MAXN], bitCnt[MAXN];
long long bitSum[MAXN];

void update(int value, int k)
{
    int idx = value;
    while (idx <= maxn)
    {
        bitCnt[idx] += k;
        bitSum[idx] += (long long)k * value;
        idx += idx & -idx;
    }
}

int queryCount(int idx)
{
    int res = 0;
    while (idx > 0)
    {
        res += bitCnt[idx];
        idx -= idx & -idx;
    }
    return res;
}

long long querySum(int idx)
{
    long long res = 0;
    while (idx > 0)
    {
        res += bitSum[idx];
        idx -= idx & -idx;
    }
    return res;
}

int findKth(int target)
{
    int idx = 0;
    int bit = 1;
    while ((bit << 1) <= maxn)
        bit <<= 1;
    while (bit > 0)
    {
        int next = idx + bit;
        if (next <= maxn && bitCnt[next] < target)
        {
            target -= bitCnt[next];
            idx = next;
        }
        bit >>= 1;
    }
    return idx + 1;
}

long long getSumK()
{
    int kth = findKth(k);
    int cntLess = queryCount(kth - 1);
    long long sumLess = querySum(kth - 1);
    return sumLess + (long long)(k - cntLess) * kth;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];

    maxn = n;

    for (int i = 1; i <= m; ++i)
        update(p[i], 1);

    cout << getSumK() << " ";

    for (int i = m + 1; i <= n; ++i)
    {
        update(p[i - m], -1);
        update(p[i], 1);
        cout << getSumK() << " ";
    }
    return 0;
}