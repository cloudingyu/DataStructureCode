#include <iostream>
#include <string>
using namespace std;

struct BigBinNum
{
    int num[10005];
    int len;
};

void printBigBinNum(BigBinNum k)
{
    for (int i = k.len; i >= 1; i--)
    {
        cout << k.num[i];
    }
    cout << endl;
}

BigBinNum multiplyBigBioNum(BigBinNum A, BigBinNum B)
{
    BigBinNum C;
    for (int i = 0; i <= 10004; i++)
        C.num[i] = 0;
    C.len = A.len + B.len;

    for (int i = 1; i <= A.len; i++)
        for (int j = 1; j <= B.len; j++)
            C.num[i + j - 1] += A.num[i] * B.num[j];

    for (int i = 1; i <= C.len; i++)
        if (C.num[i] >= 2)
        {
            C.num[i + 1] += C.num[i] / 2;
            C.num[i] %= 2;
        }

        while (C.len > 1 && C.num[C.len] == 0)
        C.len--;

    return C;
}

BigBinNum string2BigBinNum(string s)
{
    BigBinNum result;
    result.len = s.length();
    for (int i = 0; i < result.len; i++)
        result.num[result.len - i] = s[i] - '0';
    return result;
}

string Sa, Sb;

int main()
{
    cin >> Sa >> Sb;

    BigBinNum A = string2BigBinNum(Sa);

    BigBinNum B = string2BigBinNum(Sb);

    BigBinNum C = multiplyBigBioNum(A, B);

    printBigBinNum(C);

    return 0;
}
