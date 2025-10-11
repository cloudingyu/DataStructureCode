#include <iostream>
#include <string>
using namespace std;

int m;
int stackk[100005], maxstack[100005];
int top = -1, maxtop = -1;
string s;

int main()
{
    cin >> m;
    while (m--)
    {
        cin >> s;
        
        if (s == "push")
        {
            int num;
            cin >> num;
            stackk[++top] = num;
            
            if (maxtop == -1 || num >= maxstack[maxtop])
                maxstack[++maxtop] = num;
        }
        else if (s == "pop")
        {
            if (stackk[top] == maxstack[maxtop])
                maxtop--;
            top--;
        }
        
        if (top == -1)
            cout << "empty" << endl;
        else
            cout << maxstack[maxtop] << endl;
    }
    return 0;
}