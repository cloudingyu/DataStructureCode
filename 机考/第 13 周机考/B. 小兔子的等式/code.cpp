#include <iostream>
#include <string>
using namespace std;

string s, num1, num2, num3;
int len, maxn;
char op;
long long Num1, Num2, Num3;
const int MOD = 1e9 + 7;

bool isNum(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F');
}

int char2int(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else
        return c - 'A' + 10;
}

void pre()
{
    int t = 0;
    while (isNum(s[t]))
    {
        maxn = max(maxn, char2int(s[t]));
        num1 = num1 + s[t];
        t++;
    }

    op = s[t++];
    while (isNum(s[t]))
    {
        maxn = max(maxn, char2int(s[t]));
        num2 = num2 + s[t];
        t++;
    }
    t++;
    while (isNum(s[t]))
    {
        maxn = max(maxn, char2int(s[t]));
        num3 = num3 + s[t];
        t++;
    }
}

long long trans(string Num, int k)
{
    long long num = 0;
    int len = Num.length();
    for (int i = 0; i < len; i++)
    {
        num *= k;
        num += char2int(Num[i]);
    }
    return num;
}

int main()
{
    cin >> s;

    pre();

    for (int k = max(2,maxn + 1); k <= 16; k++)
    {
        Num1 = trans(num1, k);
        Num2 = trans(num2, k);
        Num3 = trans(num3, k);

        if (op == '+')
        {
            if (Num1 + Num2 == Num3)
            {
                cout << k << endl;
                return 0;
            }
        }
        else if (op == '-')
        {
            if (Num1 - Num2 == Num3)
            {
                cout << k << endl;
                return 0;
            }
        }
        else if (op == '*')
        {
            if (Num1 * Num2 == Num3)
            {
                cout << k << endl;
                return 0;
            }
        }
        else
        {
            if (Num1 % Num2 == 0 && Num1 / Num2 == Num3)
            {
                cout << k << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}