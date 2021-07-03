#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(9);
}

void solve()
{
    int N, L, W, H;
    cin >> N >> L >> W >> H;

    int mn = L < W ? L : W;
    mn = mn < H ? mn : H;

    long double start = 0;
    long double end = mn;

    while (end - start > 1e-10)
    {
        long double mid = (start + end) / 2;
        long long tot = (long long)(L / mid) * (long long)(W / mid) * (long long)(H / mid);

        if (tot < N)
            end = mid;
        else
            start = mid;
    }

    cout << start;
}

int main()
{
    fastIO();
    solve();
}
