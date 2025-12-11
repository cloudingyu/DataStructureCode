#include <iostream>
using namespace std;

const int MAXN = 205;

const long long INTMAX = 1e17;

struct Matrix
{
    long long a[MAXN][MAXN];
};

int n, m;
Matrix A, Ans;

Matrix mul(Matrix AA, Matrix BB)
{
    Matrix C;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            C.a[i][j] = INTMAX;

    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= n; k++)
            for (int j = 1; j <= n; j++)
                C.a[i][j] = min(C.a[i][j], AA.a[i][k] + BB.a[k][j]);

    return C;
}

Matrix qPow(Matrix B, int p)
{
    Matrix C;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            C.a[i][j] = INTMAX;
    for (int i = 1; i <= n; i++)
        C.a[i][i] = 0;

    while (p > 0)
    {
        if (p & 1)
            C = mul(C, B);
        B = mul(B, B);
        p >>= 1;
    }

    return C;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> A.a[i][j];

    for (int i = 1; i <= n; i++)
        A.a[i][i] = INTMAX;

    Ans = qPow(A, m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << Ans.a[i][j] << " ";
        cout << endl;
    }

    cout << endl;
}