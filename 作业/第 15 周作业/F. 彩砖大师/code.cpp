#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 5005;

struct Gap
{
    int len, u, v;
};

int n;
int p[MAXN];
long long ans;
long long block_size[MAXN];
string s;

vector<long long> blocks;
vector<Gap> gaps;

bool cmp(Gap a, Gap b)
{
    if (a.len != b.len)
        return a.len < b.len;
    
    long long max_a = max(block_size[a.u], block_size[a.v]);
    long long min_a = min(block_size[a.u], block_size[a.v]);
    
    long long max_b = max(block_size[b.u], block_size[b.v]);
    long long min_b = min(block_size[b.u], block_size[b.v]);
    
    if (max_a != max_b)
        return max_a > max_b;

    return min_a > min_b;
}
int find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}

int main()
{
    cin >> n >> s;

    blocks.push_back(0);

    int t = 0;

    if (t < n && s[t] == '.')
    {
        int len = 0;
        while (t < n && s[t] == '.')
            len++, t++;
        gaps.push_back({len, 0, 1});
    }

    while (t < n)
    {
        int len = 0;
        while (t < n && s[t] == '#')
            len++, t++;
        if (len > 0)
            blocks.push_back(len);
        while (t < n && s[t] == '.')
        {
            len = 0;
            while (t < n && s[t] == '.')
                len++, t++;
            gaps.push_back({len, (int)blocks.size() - 1, (int)blocks.size()});
        }
    }

    int max_idx = 0;
    for (auto g : gaps)
        max_idx = max(max_idx, g.v);
    while (blocks.size() <= max_idx)
        blocks.push_back(0);
    for (int i = 0; i < blocks.size(); i++)
    {
        block_size[i] = blocks[i];
        p[i] = i;
    }

    sort(gaps.begin(), gaps.end(), cmp);

    for (auto g : gaps)
    {
        int fu = find(g.u), fv = find(g.v);
        if (fu != fv)
        {
            long long L = block_size[fu];
            long long R = block_size[fv];
            long long k = g.len;

            ans += k * max(L, R) + min(L, R) + k * (k + 1) / 2;

            p[fv] = fu;
            block_size[fu] += block_size[fv] + k;
        }
    }
    cout << ans << endl;

    return 0;
}
