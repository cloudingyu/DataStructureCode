#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 300010;

string s;
int len;
int dele[10], total[10], remain[10], used[10];
char result[MAXN];
int top = 0;

int main()
{
    cin >> s;
    len = s.length();

    for (int d = 1; d <= 9; ++d)
        cin >> dele[d];

    for (int i = 0; i < len; ++i)
        total[s[i] - '0']++;

    for (int d = 1; d <= 9; ++d)
        remain[d] = total[d] - dele[d];

    for (int i = 0; i < len; ++i)
    {
        int digit = s[i] - '0';

        total[digit]--;

        if (used[digit] >= remain[digit])
            continue;

        while (top > 0)
        {
            int top_digit = result[top - 1] - '0';
            if (top_digit < digit && (used[top_digit] + total[top_digit]) - 1 >= remain[top_digit])
            {
                top--;
                used[top_digit]--;
            }
            else
                break;
        }

        result[top++] = s[i];
        used[digit]++;
        
    }

    result[top] = '\0';

    cout << result << endl;

    return 0;
}