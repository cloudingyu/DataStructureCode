#include <cstdio>
#include <cstring>

const int MAXN = 200000;
const int ALPHA = 26;
const int MOD1 = 1000000007;
const int MOD2 = 1000000009;
const int BASE1 = 911382323;
const int BASE2 = 972663749;

char s[MAXN + 5];
int prevPos[MAXN + 5];
int diffVal[MAXN + 5];
int posList[ALPHA][MAXN + 5];
int cnt[ALPHA];
int pow1[MAXN + 5];
int pow2[MAXN + 5];
int hash1Arr[MAXN + 5];
int hash2Arr[MAXN + 5];

int lower_bound_array(const int *arr, int len, int target)
{
    int left = 0;
    int right = len;
    while (left < right)
    {
        int mid = (left + right) >> 1;
        if (arr[mid] >= target)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

void get_hash(int l, int r, int &out1, int &out2, int &maskOut)
{
    int len = r - l + 1;
    long long res1 = hash1Arr[r] - (long long)hash1Arr[l - 1] * pow1[len] % MOD1;
    if (res1 < 0)
        res1 += MOD1;
    long long res2 = hash2Arr[r] - (long long)hash2Arr[l - 1] * pow2[len] % MOD2;
    if (res2 < 0)
        res2 += MOD2;
    int mask = 0;
    for (int c = 0; c < ALPHA; ++c)
    {
        int idx = lower_bound_array(posList[c], cnt[c], l);
        if (idx < cnt[c])
        {
            int p = posList[c][idx];
            if (p <= r)
            {
                mask |= (1 << c);
                if (prevPos[p] < l)
                {
                    long long sub1 = (long long)diffVal[p] * pow1[r - p] % MOD1;
                    res1 -= sub1;
                    if (res1 < 0)
                        res1 += MOD1;
                    long long sub2 = (long long)diffVal[p] * pow2[r - p] % MOD2;
                    res2 -= sub2;
                    if (res2 < 0)
                        res2 += MOD2;
                }
            }
        }
    }
    out1 = (int)res1;
    out2 = (int)res2;
    maskOut = mask;
}

int main()
{
    if (scanf("%s", s + 1) != 1)
    {
        return 0;
    }
    int n = (int)strlen(s + 1);
    int last[ALPHA];
    for (int i = 0; i < ALPHA; ++i)
    {
        last[i] = 0;
        cnt[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        int c = s[i] - 'a';
        prevPos[i] = last[c];
        last[c] = i;
        diffVal[i] = i - prevPos[i];
        posList[c][cnt[c]++] = i;
    }
    pow1[0] = 1;
    pow2[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        pow1[i] = (long long)pow1[i - 1] * BASE1 % MOD1;
        pow2[i] = (long long)pow2[i - 1] * BASE2 % MOD2;
    }
    hash1Arr[0] = 0;
    hash2Arr[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        hash1Arr[i] = ((long long)hash1Arr[i - 1] * BASE1 + diffVal[i]) % MOD1;
        hash2Arr[i] = ((long long)hash2Arr[i - 1] * BASE2 + diffVal[i]) % MOD2;
    }
    int m;
    if (scanf("%d", &m) != 1)
    {
        return 0;
    }
    while (m--)
    {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (r1 - l1 != r2 - l2)
        {
            puts("No");
            continue;
        }
        int h1a, h2a, h1b, h2b;
        int mask1, mask2;
        get_hash(l1, r1, h1a, h2a, mask1);
        get_hash(l2, r2, h1b, h2b, mask2);
        if (mask1 != mask2)
        {
            puts("No");
        }
        else if (h1a == h1b && h2a == h2b)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    return 0;
}