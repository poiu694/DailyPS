#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int> > graph[100001];
vector<vector<int> > ans;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool isVisited(int node, vector<pair<int, int> > &path)
{
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i].first == node)
        {
            return true;
        }
    }
    return false;
}

void bfs(int N)
{
    queue<vector<pair<int, int> > > q;
    vector<pair<int, int> > path; // node & color
    path.push_back({1, 0});
    q.push(path);

    int minLen = 987654321;
    while (!q.empty())
    {
        path = q.front();
        q.pop();

        int now = path[path.size() - 1].first;

        if (now == N && path.size() <= minLen)
        {
            minLen = path.size();
            vector<int> list;
            for (int i = 0; i < path.size(); i++)
            {
                if (i == 0)
                    continue; // 0
                list.push_back(path[i].second);
            }
            ans.push_back(list);
            continue;
        }

        if (path.size() > minLen)
        {
            break;
        }

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i].first;
            int color = graph[now][i].second;

            if (!isVisited(next, path))
            {
                path.push_back({next, color});
                q.push(path);
                path.pop_back();
            }
        }
    }
}

void solve()
{
    int N, M;
    cin >> N >> M;

    queue<pair<int, int> > q;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    bfs(N);

    sort(ans.begin(), ans.end());

    cout << ans[0].size() << '\n';
    for (int i = 0; i < ans[0].size(); i++)
    {
        cout << ans[0][i] << " ";
    }
}

int main()
{
    fastIO();
    solve();
}
