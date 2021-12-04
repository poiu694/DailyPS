#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

const int MOD = 1000000007;

void    fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int    bfs(vector<int> list[], int T)
{
    queue<int>  q;
    int         pastCnt[11];
    int         cnt[11];

    q.push(1);
    for (int i=1; i<=10; i++)
    {
        pastCnt[i] = 0;
        cnt[i] = 0;
    }
    cnt[1] = 1;
    int ret = 0;
    while (T--)
    {
        for (int i=1; i<=10; i++)
            pastCnt[i] = 0;
        for (int i=1; i<=10; i++)
        {
            for (int next: list[i])
                pastCnt[next] = (pastCnt[next] + cnt[i]) % MOD;
        }
        for (int i=1; i<=10; i++)
            cnt[i] = pastCnt[i];
    }
    for (int i=1; i<=10; i++)
        ret = (ret + cnt[i]) % MOD;
    return (ret % MOD);
}

void    get_solution(void)
{
    int V, E, T;
    vector<int> list[11];

    cin >> V >> E >> T;
    while (E--)
    {
        int now, next;
        cin >> now >> next;
        list[now].push_back(next);
        list[next].push_back(now);
    }
    cout << bfs(list, T);
}

int main(void)
{
    fast_io();
    get_solution();
}
