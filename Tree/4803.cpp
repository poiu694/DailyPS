#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

vector<int> graph[501];
bool visited[501];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool dfs(int node, int parent)
{
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i];
        if (!visited[next])
        {
            if (dfs(next, node))
                return true;
        }
        else if (next != parent)
        {
            return true;
        }
    }
    return false;
}

void solve()
{
    int T = 0;
    while (true)
    {
        T++;

        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        // init
        for (int i = 1; i <= 500; i++)
            graph[i].clear();
        memset(visited, false, sizeof(visited));

        // input
        int node1, node2;
        for (int i = 0; i < M; i++)
        {
            cin >> node1 >> node2;
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                if (!dfs(i, -1))
                {
                    cnt++;
                }
            }
        }

        if (cnt == 0)
        {
            cout << "Case " << T << ": "
                 << "No trees." << '\n';
        }
        else if (cnt == 1)
        {
            cout << "Case " << T << ": "
                 << "There is one tree." << '\n';
        }
        else
        {
            cout << "Case " << T << ": "
                 << "A forest of " << cnt << " trees." << '\n';
        }
    }
}

int main()
{
    fastIO();
    solve();
}
