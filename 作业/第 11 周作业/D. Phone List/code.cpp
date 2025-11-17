#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 100000;
int trie[MAXN][10];
bool is_end[MAXN];
int cnt, n, T;

bool cmp(string a, string b)
{
    return a.size() < b.size();
}

bool insert(const string &s)
{
    int p = 0;
    for (char c : s)
    {
        int u = c - '0';
        if (!trie[p][u])
        {
            trie[p][u] = ++cnt;
        }
        p = trie[p][u];
        if (is_end[p])
            return false;
    }
    is_end[p] = true;
    return true;
}

int main()
{
    cin >> T;
    while (T--)
    {
        memset(trie, 0, sizeof(trie));
        memset(is_end, 0, sizeof(is_end));
        cnt = 0;
        cin >> n;

        vector<string> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a.begin(), a.end(), cmp);

        bool ok = true;
        for (int i = 0; i < n; i++)
            if (!insert(a[i]))
                ok = false;

        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}