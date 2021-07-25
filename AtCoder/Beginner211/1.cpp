#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <limits.h>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(5);
    cout << fixed;
}

void solve()
{
    double A, B;
    cin >> A >> B;

    if ((int)(A - B) % 3 == 0)
    {
        int x = A;
        int y = B;
        cout << (x - y) / 3 + y;
    }
    else
        cout << (A - B) / 3 + B;
}

int main()
{
    fastIO();
    solve();
}
