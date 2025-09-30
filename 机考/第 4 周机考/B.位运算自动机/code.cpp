#include <iostream>
#include <string>
using namespace std;

unsigned int Ab[27], len, nodeCount;
string s;

struct CalcNode
{
    unsigned int num = 0;
    int next = -1;
    char op = ' ';
} nodes[200005];

int main()
{
    for (int i = 1; i <= 26; i++)
        cin >> Ab[i];
    cin >> s;
    len = s.length();
    nodeCount = (len + 1) / 2;

    for (int i = 0; i < nodeCount; i++)
    {
        nodes[i].num = Ab[s[i * 2] - 'a' + 1];
        if (i < nodeCount - 1)
        {
            nodes[i].op = s[i * 2 + 1];
            nodes[i].next = i + 1;
        }
    }

    int t = 0;
    while (t != -1)
    {
        if (nodes[t].op == '&')
        {
            nodes[t].num &= nodes[nodes[t].next].num;
            nodes[t].op = nodes[nodes[t].next].op;
            nodes[t].next = nodes[nodes[t].next].next;
        }
        else
        {
            t = nodes[t].next;
        }
    }

    t = 0;
    while (t != -1)
    {
        if (nodes[t].op == '^')
        {
            nodes[t].num ^= nodes[nodes[t].next].num;
            nodes[t].op = nodes[nodes[t].next].op;
            nodes[t].next = nodes[nodes[t].next].next;
        }
        else
        {
            t = nodes[t].next;
        }
    }

    t = 0;
    while (t != -1)
    {
        if (nodes[t].op == '|')
        {
            nodes[t].num |= nodes[nodes[t].next].num;
            nodes[t].op = nodes[nodes[t].next].op;
            nodes[t].next = nodes[nodes[t].next].next;
        }
        else
        {
            t = nodes[t].next;
        }
    }

    cout << nodes[0].num << endl;
    return 0;
}