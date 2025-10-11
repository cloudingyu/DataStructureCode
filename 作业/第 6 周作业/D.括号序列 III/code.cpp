#include <iostream>
#include <string>
using namespace std;

string s;
int a[1000005];
int stackk[1000005], stacktop = -1;
int ret = 0;

int main()
{
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++)
        switch (s[i])
        {
        case '(':
            a[i] = 1;
            break;
        case '[':
            a[i] = 2;
            break;
        case '{':
            a[i] = 3;
            break;
        case '<':
            a[i] = 4;
            break;
        case ')':
            a[i] = -1;
            break;
        case ']':
            a[i] = -2;
            break;
        case '}':
            a[i] = -3;
            break;
        case '>':
            a[i] = -4;
            break;
        }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            stackk[++stacktop] = a[i];
        else
        {
            if (stacktop == -1)
            {
                cout << "Impossible" << endl;
                return 0;
            }
            if (stackk[stacktop] + a[i] != 0)
                ret++;
            stacktop--;
        }
    }
    if (stacktop != -1)
        cout << "Impossible" << endl;
    else
        cout << ret << endl;

    return 0;
}