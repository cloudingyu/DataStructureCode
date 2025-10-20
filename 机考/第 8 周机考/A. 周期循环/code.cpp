#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

int T, z[500005];
string s;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> s;
        memset(z, 0x00, sizeof(z));
        int len = s.length();
        for (int i = 1; i < len; i++)
            while (i + z[i] < len && s[z[i]] == s[i + z[i]])
                z[i]++;

        int ans = len;
        for (int p = 1; p < len; ++p)
        {
            if (p + z[p] >= len)
            {
                int m = max(((len + p - 1) / p) * p, 2 * p);
                ans = min(ans, m - len);
            }
        }
        cout << ans << endl;
    }

    return 0;
}