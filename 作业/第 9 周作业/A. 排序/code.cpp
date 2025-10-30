#include <cstdio>
const int MAXN = 3e7 + 5;

unsigned int n, ans = 0;
unsigned int x[MAXN], temp[MAXN];

unsigned int xorshift(unsigned int x)
{
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

void radixSort(int k)
{
    int len = 0;
    unsigned int bit = 1U << k;
    for (int i = 1; i <= n; i++)
        if (!(x[i] & bit))
            temp[++len] = x[i];

    for (int i = 1; i <= n; i++)
        if (x[i] & bit)
            temp[++len] = x[i];

    for (int i = 1; i <= n; i++)
        x[i] = temp[i];

    return;
}

int main()
{
    scanf("%u%u", &n, x[0]);

    for (int i = 1; i <= n; i++)
        x[i] = xorshift(x[i - 1]);

    for (int i = 0; i < 32; i++)
        radixSort(i);

    for (int i = 1; i <= n; i++)
        ans += x[i] * i;

    printf("%u\n", ans);

    return 0;
}