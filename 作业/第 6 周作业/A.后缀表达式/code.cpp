#include <iostream>
#include <string>
using namespace std;

string s;

int stackk[1005], top = -1;

int main()
{

    cin >> s;

    int n = s.length();

    int t = 0;

    while (s[t] != '@')
    {
        if (s[t] >= '0' && s[t] <= '9')
        {
            int num = 0;
            while (t < n && s[t] >= '0' && s[t] <= '9')
            {
                num = num * 10 + s[t] - '0';
                t++;
            }
            t++;
            stackk[++top] = num;
        }
        else
        {
            switch (s[t])
            {
            case '+':
            {
                int a = stackk[top--];
                int b = stackk[top--];
                stackk[++top] = a + b;
                break;
            }
            case '-':
            {
                int a = stackk[top--];
                int b = stackk[top--];
                stackk[++top] = b - a;
                break;
            }
            case '*':
            {
                int a = stackk[top--];
                int b = stackk[top--];
                stackk[++top] = a * b;
                break;
            }
            case '/':
            {
                int a = stackk[top--];
                int b = stackk[top--];
                stackk[++top] = b / a;
                break;
            }
            }
            t++;
        }
    }
    cout<<stackk[top]<<endl;
    return 0;
}