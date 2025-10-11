#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

char s[MAXN][MAXN];
int rlen[MAXN][MAXN];
int h[MAXN], prevLessArr[MAXN], nextLessArr[MAXN], st[MAXN];

int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    for (int i = 0; i < n; ++i)
    {
        rlen[i][m - 1] = 1;
        for (int j = m - 2; j >= 0; --j)
        {
            if (s[i][j] == s[i][j + 1])
                rlen[i][j] = rlen[i][j + 1] + 1;
            else
                rlen[i][j] = 1;
        }
    }

    int bestSide = 0;

    for (int col = 0; col < m; ++col)
    {
        for (int i = 0; i < n; ++i)
            h[i] = rlen[i][col];

        int top = -1;
        for (int i = 0; i < n; ++i)
        {
            while (top >= 0 && h[i] <= h[st[top]])
                top--;
            prevLessArr[i] = (top < 0 ? -1 : st[top]);
            st[++top] = i;
        }

        top = -1;
        for (int i = n - 1; i >= 0; --i)
        {
            while (top >= 0 && h[i] < h[st[top]])
                top--;
            nextLessArr[i] = (top < 0 ? n : st[top]);
            st[++top] = i;
        }

        for (int i = 0; i < n; ++i)
        {
            int width = nextLessArr[i] - prevLessArr[i] - 1;
            int side = min(h[i], width);
            if (side > bestSide)
                bestSide = side;
        }
    }

    long long area = 1LL * bestSide * bestSide;
    cout << area << endl;
    return 0;
}