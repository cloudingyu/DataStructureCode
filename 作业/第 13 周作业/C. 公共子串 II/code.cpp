#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

typedef unsigned long long ull;

int main()
{

    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ull char_vals[26];
    for (int i = 0; i < 26; ++i)
    {
        char_vals[i] = rng();
    }

    vector<ull> pref_s(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        pref_s[i + 1] = pref_s[i] + char_vals[s[i] - 'a'];
    }

    vector<ull> pref_t(m + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        pref_t[i + 1] = pref_t[i] + char_vals[t[i] - 'a'];
    }

    long long total_pairs = 0;
    int max_len = min(n, m);

    vector<ull> hashes_s;
    vector<ull> hashes_t;
    hashes_s.reserve(n);
    hashes_t.reserve(m);

    for (int len = 1; len <= max_len; ++len)
    {
        hashes_s.clear();
        hashes_t.clear();

        for (int i = 0; i <= n - len; ++i)
            hashes_s.push_back(pref_s[i + len] - pref_s[i]);

        for (int i = 0; i <= m - len; ++i)
            hashes_t.push_back(pref_t[i + len] - pref_t[i]);

        sort(hashes_s.begin(), hashes_s.end());
        sort(hashes_t.begin(), hashes_t.end());

        int i = 0, j = 0;
        int size_s = hashes_s.size();
        int size_t = hashes_t.size();

        while (i < size_s && j < size_t)
        {
            if (hashes_s[i] < hashes_t[j])
                i++;
            else if (hashes_s[i] > hashes_t[j])
                j++;
            else
            {
                ull current_val = hashes_s[i];

                long long count_s = 0;
                while (i < size_s && hashes_s[i] == current_val)
                {
                    count_s++;
                    i++;
                }

                long long count_t = 0;
                while (j < size_t &&hashes_t[j] == current_val)
                {
                    count_t++;
                    j++;
                }

                total_pairs += count_s * count_t;
            }
        }
    }

    cout << total_pairs << endl;

    return 0;
}