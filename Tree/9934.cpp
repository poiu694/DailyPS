#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    int K;
    cin >> K;

    int size = pow(2, K);
    vector<int> list(size);
    for (int i = 0; i < pow(2, K) - 1; i++)
    {
        cin >> list[i];
    }

    bool visited[size];
    memset(visited, false, sizeof(visited));
    int cnt = 2;
    queue<int> ans[11];
    for (int i = 0; i < size; i++)
    {
        if (!visited[i])
        {
            for (int j = i; j < size; j += cnt)
            {
                ans[(int)log2(cnt) - 1].push(list[j]);
                visited[j] = true;
            }
            cnt *= 2;
        }
    }

    for (int i = K - 1; i >= 0; i--)
    {
        while (!ans[i].empty())
        {
            cout << ans[i].front() << " ";
            ans[i].pop();
        }
        cout << '\n';
    }
}

int main()
{
    fastIO();
    solve();
}