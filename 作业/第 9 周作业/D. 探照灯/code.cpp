#include <iostream>
#include <string>
using namespace std;

int n, left_R, right_L;
string LR;

int main()
{
    cin >> n >> LR;

    left_R = 0, right_L = n - 1;

    while (left_R < n && LR[left_R] == 'L')
        left_R++;
    while (right_L >= 0 && LR[right_L] == 'R')
        right_L--;

    if (left_R == n || right_L == -1)
        cout << -1 << endl;
    else if (left_R < right_L)
        cout << 0 << endl;
    else
        cout << right_L + 1 << endl;
 
    return 0;
}