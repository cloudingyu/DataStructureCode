#include <iostream>
#include <random>
#include <ctime>
using namespace std;


int rd(int l, int r) {
    return rand() % (r - l + 1) + l;
}

#define val(x) treap[x].val
#define size(x) treap[x].size
#define pri(x) treap[x].pri
#define left(x) treap[x].leftson
#define right(x) treap[x].rightson
#define ifRev(x) treap[x].rev

struct node
{
    int val, size, pri, leftson, rightson, rev;
} treap[1000010];

int n, m;
int Root, cnt;

void newnode(int &u, int val)
{
    u = ++cnt;
    pri(u) = rd(1, 1000010);
    size(u) = 1;
    val(u) = val;
}

void push_down(int u)
{
    if (ifRev(u))
    {
        ifRev(left(u)) ^= 1;
        ifRev(right(u)) ^= 1;

        swap(left(left(u)), right(left(u)));
        swap(left(right(u)),right(right(u)));

        ifRev(u) = 0;
    }
    return ;
}

void push_up(int u)
{
    size(u) = size(left(u)) + size(right(u)) + 1;
}

void merge(int &u, int root_l, int root_r)
{
    if (!root_l || !root_r)
        return void(u = root_l | root_r);
    if (pri(root_l) >= pri(root_r))
    {
        u = root_l;
        push_down(root_l);
        merge(right(u), right(root_l), root_r);
    }
    else
    {
        u = root_r;
        push_down(root_r);
        merge(left(u), root_l, left(root_r));
    }
    push_up(u);
}

void split_size(int u, int &root_l, int &root_r, int cri)
{
    if (!u)
        return void(root_l = root_r = 0);
    push_down(u);

    if (size(left(u)) + 1 <= cri)
        root_l = u, split_size(right(u),right(root_l), root_r, cri - size(left(u)) - 1);
    else
        root_r = u, split_size(left(u), root_l, left(root_r), cri);
    push_up(u);
}

void ins(int val, int id)
{
    int root_l, root_r, son;
    split_size(Root, root_l, root_r, id - 1);
    newnode(son, val);
    merge(root_r, son, root_r);
    merge(Root, root_l, root_r);
}

void reverse(int l, int r)
{
    int root_l, root_r, root_l_l, root_l_r;

    split_size(Root, root_l, root_r, r);
    split_size(root_l, root_l_l, root_l_r, l - 1);

    ifRev(root_l_r) ^= 1;

    swap(left(root_l_r), right(root_l_r));

    merge(root_l, root_l_l, root_r);
    merge(Root, root_l, root_l_r);
}

void print(int u)
{
    if (!u)
        return;
    
    push_down(u);

    print(left(u));
    cout << val(u) << " ";
    print(right(u));

    return ;
}

int main()
{
    srand(time(0));

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        ins(i, i);

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        reverse(l, r);
    }

    print(Root);
    return 0;
}
