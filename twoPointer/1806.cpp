#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    int N, S;
    cin >> N >> S;

    vector<int> list(N);
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
    }

    int ans = 1e5 + 1;
    int r = 0, sum = 0;
    for (int l = 0; l < N; l++)
    {
        while (sum < S && r < N)
        {
            sum += list[r++];
        }

        if (sum >= S)
        {
            ans = min(ans, r - l);
        }

        sum -= list[l];
    }
    ans = ans == 1e5 + 1 ? 0 : ans;
    cout << ans;
}

int main()
{
    fastIO();
    solve();
}
