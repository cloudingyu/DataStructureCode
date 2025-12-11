#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point
{
    long long x, y;
};

bool cmpx(Point a, Point b)
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

bool cmpy(Point a, Point b)
{
    if (a.y != b.y)
        return a.y < b.y;
    return a.x < b.x;
}

int n, c;
double min_val = 1e18;
vector<Point> p;

void update(Point p1, Point p2)
{
    double A = (double)p1.y - p2.y;
    double B = (double)p2.x - p1.x;
    double C = -A * p1.x - B * p1.y;

    min_val = min(min_val, 2.0 * hypot(C, c * B) / hypot(A, B));
};

int main()
{
    cin >> n >> c;

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }

    sort(p.begin(), p.end(), cmpx);
    for (int i = 0; i < n - 1; ++i)
        update(p[i], p[i + 1]);

    sort(p.begin(), p.end(), cmpy);
    for (int i = 0; i < n - 1; ++i)
        update(p[i], p[i + 1]);
    
    printf("%.10f\n", min_val);

    return 0;
}