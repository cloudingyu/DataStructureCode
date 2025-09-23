#include <iostream>
#include <algorithm>
using namespace std;

struct student
{
    int ini, p, h, l, r;
} A[1000005];

int n;

long long result[1000005];

long long counter;

bool cmp1(student A, student B)
{
    return A.p < B.p;
}

bool cmp2(student A, student B)
{
    return A.ini < B.ini;
}

long long square(int a)
{
    return (long long)a * a;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        A[i].ini = i;
    for (int i = 1; i <= n; i++)
        cin >> A[i].p;
    for (int i = 1; i <= n; i++)
        cin >> A[i].h;

    sort(A + 1, A + n + 1, cmp1);

    A[0].ini = -1;
    A[n + 1].ini = -1;
    for (int i = 1; i <= n; i++)
    {
        A[i].l = A[i - 1].ini;
        A[i].r = A[i + 1].ini;
    }

    for (int i = 1; i <= n - 1; i++)
        counter += square(A[i].h - A[i + 1].h);

    sort(A + 1, A + n + 1, cmp2);

    result[n] = counter;

    for (int i = n ; i >= 2; i--)
    {
        if (A[i].l == -1)
        {
            counter -= square(A[i].h - A[A[i].r].h);
            A[A[i].r].l = -1;
        }
        else if (A[i].r == -1)
        {
            counter -= square(A[i].h - A[A[i].l].h);
            A[A[i].l].r = -1;
        }
        else
        {
            counter = counter - square(A[i].h - A[A[i].l].h) - square(A[i].h - A[A[i].r].h) + square(A[A[i].r].h - A[A[i].l].h);
            A[A[i].l].r = A[i].r;
            A[A[i].r].l = A[i].l;
        }
        result[i-1] = counter;
    }
    for (int i = 1; i <= n; i++)
        cout << result[i] << endl;
    return 0;
}
