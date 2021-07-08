#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair<long, long> pll;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(1);
}

long long CCW(pll a, pll b, pll c)
{
    long long ret = 0;
    ret += a.first * b.second + b.first * c.second + c.first * a.second -
           (a.second * b.first + b.second * c.first + c.second * a.first);
    return ret;
}

void solve()
{
    int N;
    cin >> N;

    vector<pll> location(N);
    long long a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        location[i] = {a, b};
    }
    location.push_back(location[0]);

    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += CCW({0, 0}, location[i], location[i + 1]);
    }
    cout << (double)fabs((double)ans / 2.0);
}

int main()
{
    fastIO();
    solve();
}
