#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
int Next[5050];
string s, p, t;

int main()
{
    cin >> n >> s;

    int max_match = 0;

    for (int len = 1; len < n; len++)
    {
        p = s.substr(len);
        t = s.substr(0, len);

        Next[0] = -1;
        for (int i = 0, k = -1; i < n - len - 1;)
            if (k == -1 || p[i] == p[k])
                Next[++i] = ++k;
            else
                k = Next[k];

        int i = 0, j = 0;
        while (i < len && j < n - len)
        {
            if (t[i] == p[j])
                i++, j++;
            else if (Next[j] != -1)
                j = Next[j];
            else
                j = 0, i++;
            max_match = max(max_match, j);
        } 
    }

    cout << max_match << endl;

    return 0;
}