#include <iostream>
#include <vector>
using namespace std;

string A, B;
int C[100010];

int main()
{
    cin >> A >> B;

    int len1 = A.length(), len2 = B.length();

    for (int i = 0; i < len1; i++)
        for (int j = 0; j < len2; j++)
            C[i + j] += (A[len1 - i - 1]-'0') * (B[len2 - j - 1]-'0');

    for (int i = 0; i < len1 + len2+10; i++)
    {
        C[i + 1] += C[i] / 2;
        C[i] %= 2;
    }

    int h = len1 + len2 + 10;

    while (!C[--h])
        ;

    for (int i = h; i >= 0; i--)
        cout << C[i];
    cout << endl;
    return 0;
}