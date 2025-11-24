#include <iostream>
#include <algorithm>
using namespace std;

string s;
int len,flag,modd;
int num[100005];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> s;
    len = s.length();

    for (int i = 0; i < len; i++)
    {
        num[i + 1] = s[i] - '0';    
        modd = (modd + num[i + 1]) % 3;
        if (num[i + 1] == 0)
            flag = 1;
    }

    if (flag == 0 || modd != 0)
    {
        cout << -1 << endl;
        return 0;
    }

    sort(num + 1, num + len + 1, cmp);

    for (int i = 1; i <= len; i++)
        cout << num[i];
        
    return 0;
}