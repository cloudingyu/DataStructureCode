#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int n, Next[5050], maxmatch = 0;
string s, p, t;

int main()
{
    cin >> n >> s;
    for (int len = 1; len < n; len++)
    {
        p = s.substr(len);
        t = s.substr(0, len);

        Next[0] = -1;
        for (int i = 0, k = -1; i < n - len-1; i++)
            if (k == -1 || p[k] == p[i])
                Next[++i] = ++k;
            else
                k = Next[k];

        int i = 0, j = 0;
        while (i < len && j < n-len)
        {
            if (t[i] == p[j])
                i++, j++;
            else if (Next[j] != -1)
                j=Next[j];
            else 
                j = 0, i++;

            maxmatch = max(maxmatch, j);
        }
    }

    cout << maxmatch << endl;
    
    return 0;
}
