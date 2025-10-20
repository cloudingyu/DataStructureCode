#include <iostream>
#include <cstdio>
using namespace std;
string S;
int len;

int match[500005];
int stk[500005], top = -1;

void printRev(int l, int r, bool ifRev)
{
    if (ifRev)
    {
        for (int i = r; i >= l; i--)
            if ((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z'))
                cout << S[i];
            else if (S[i] == ']')
            {
                printRev(match[i] + 1, i - 1, 0);
                i = match[i];
            }
    }
    else
    {
        for (int i = l; i <= r; i++)
            if ((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z'))
                cout << S[i];
            else if (S[i] == '[')
            {
                printRev(i + 1, match[i] - 1, 1);
                i = match[i];
            }
    }
        

    return;
}
int main()
{
    cin >> S;
    len = S.length();

    for (int i = 0,cnt = 0 ; i < len; i++)
    {
        if (S[i] == '(')
            cnt++;
        else if (S[i] == ')')
            cnt--;
        else if (S[i] == '[')
            stk[++top] = i;
        else if (S[i] == ']')
        {
            match[stk[top]] = i;
            match[i] = stk[top];
            top--;
        }
        else if (S[i] >= 'A' && S[i] <= 'Z' && (cnt & 1))
            S[i] = S[i] - 'A' + 'a';
        else if (S[i] >= 'a' && S[i] <= 'z' && (cnt & 1))
            S[i] = S[i] - 'a' + 'A';
    }

    printRev(0, len - 1, 0);

    return 0;
}
