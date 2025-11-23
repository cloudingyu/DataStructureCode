#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;
struct Student
{
    long long a, t, p, w;
    long long l, r, c;
} s[MAXN];

int n;
int idx1[MAXN], idx2[MAXN], ans[MAXN];
long long v1, v2;
long long group1_c[MAXN], group2_c[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> v1 >> v2;

    int size1 = 0;
    int size2 = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> s[i].a >> s[i].t >> s[i].p >> s[i].w;
        if (s[i].a == 1)
        {
            s[i].c = s[i].p * v1 - s[i].t * v1 * v2;
            s[i].l = s[i].c;
            s[i].r = s[i].c + s[i].w * v2;
            group1_c[size1] = s[i].c;
            idx1[size1] = i;
            size1++;
        }
        else if (s[i].a == 2)
        {
            s[i].c = s[i].p * v2 - s[i].t * v1 * v2;
            s[i].l = s[i].c;
            s[i].r = s[i].c + s[i].w * v1;
            group2_c[size2] = s[i].c;
            idx2[size2] = i;
            size2++;
        }
    }

    sort(group1_c, group1_c + size1);
    sort(group2_c, group2_c + size2);

    for (int k = 0; k < size1; ++k)
    {
        int i = idx1[k];
        long long L = s[i].l;
        long long R = s[i].r;
        int left_idx = lower_bound(group2_c, group2_c + size2, L) - group2_c;
        int right_idx = upper_bound(group2_c, group2_c + size2, R) - group2_c;
        ans[i] = right_idx - left_idx;
    }

    for (int k = 0; k < size2; ++k)
    {
        int i = idx2[k];
        long long L = s[i].l;
        long long R = s[i].r;
        int left_idx = lower_bound(group1_c, group1_c + size1, L) - group1_c;
        int right_idx = upper_bound(group1_c, group1_c + size1, R) - group1_c;
        ans[i] = right_idx - left_idx;
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << endl;

    return 0;
}