#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

int ans = 987654321;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void findCase(int N, int now, int sum, int isBig, vector<pair<int, int>> &list, int K)
{
    if (now == N)
    {
        ans = ans > sum ? sum : ans;
        return;
    }

    if (now + 1 <= N)
    {
        findCase(N, now + 1, sum + list[now - 1].first, isBig, list, K);
    }
    if (now + 2 <= N)
    {
        findCase(N, now + 2, sum + list[now - 1].second, isBig, list, K);
    }
    if (isBig == 0)
    {
        if (now + 3 <= N)
        {
            findCase(N, now + 3, sum + K, 1, list, K);
        }
    }
}

void solve()
{
    int N, K;
    cin >> N;

    vector<pair<int, int>> JMP(N);
    for (int i = 0; i < N - 1; i++)
        cin >> JMP[i].first >> JMP[i].second;
    cin >> K;

    findCase(N, 1, 0, 0, JMP, K);
    cout << ans;
}

int main()
{
    fastIO();
    solve();
}
