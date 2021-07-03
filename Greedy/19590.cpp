#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    int N;
    cin >> N;

    vector<int> list(N);

    long long sum = 0, mx = -1;
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
        sum += list[i];
        if (mx < list[i])
            mx = list[i];
    }
    if (sum - mx <= mx)
    {
        cout << 2 * mx - sum;
        return;
    }
    else
    {
        if (sum % 2 == 0)
            cout << 0;
        else
            cout << 1;
    }
}

int main()
{
    fastIO();
    solve();
}
