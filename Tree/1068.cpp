#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

int leaf = 0;
vector<int> graph[51];
queue<int> q;
int parent[51];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void bfs()
{
    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (graph[now].empty())
            leaf++;
        for (int next : graph[now])
        {
            q.push(next);
        }
    }
}

void solve()
{
    int N;
    cin >> N;

    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        parent[i] = temp;
        if (parent[i] == -1)
            continue;
        else
        {
            graph[parent[i]].push_back(i);
        }
    }
    int deleteNode;
    cin >> deleteNode;

    int parentNode = parent[deleteNode];
    if (parentNode != -1)
    {
        for (int i = 0; i < graph[parentNode].size(); i++)
        {
            int now = graph[parentNode][i];

            if (now == deleteNode)
            {
                graph[parentNode].erase(graph[parentNode].begin() + i);
                break;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (parent[i] == -1 && i != deleteNode)
        {
            q.push(i);
            bfs();
        }
    }

    cout << leaf;
}

int main()
{
    fastIO();
    solve();
}
