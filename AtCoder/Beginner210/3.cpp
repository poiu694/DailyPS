#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <map>
#include <limits.h>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int getCount(vector<int> list)
{
    sort(list.begin(), list.end());
    int past = list[0];
    int ans = 1;
    for (int i = 1; i < list.size(); i++)
    {
        if (past != list[i])
        {
            ans++;
            past = list[i];
        }
    }

    return ans;
}

void solve()
{
    int N, M;
    cin >> N >> M;

    vector<int> list(N);
    for (int i = 0; i < N; i++)
        cin >> list[i];

    map<int, int> m;
    for (int i = 0; i < M; i++)
        m[list[i]]++;
    int mx = (int)m.size();
    for (int i = M; i < N; i++)
    {
        m[list[i - M]]--;
        m[list[i]]++;

        if (m[list[i - M]] == 0)
            m.erase(list[i - M]);
        if (mx < (int)m.size())
            mx = (int)m.size();
    }
    cout << mx << '\n';
}

int main()
{
    fastIO();
    solve();

    return 0;
}
