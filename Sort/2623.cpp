#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int inDegree[1001];
vector<int> graph[1001];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    vector<int> answer;
    queue<int> q;
    int N, M;
    cin >> N >> M;

    int size, temp, prev;
    for (int i = 0; i < M; i++)
    {
        cin >> size;
        for (int j = 0; j < size; j++)
        {
            cin >> temp;
            if (j == 0)
            {
                prev = temp;
            }
            else
            {
                graph[prev].push_back(temp);
                prev = temp;
                inDegree[temp]++;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    if (q.empty())
    {
        cout << "0";
        return;
    }

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        answer.push_back(now);

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];

            inDegree[next]--;
            if (inDegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    if (answer.size() != N)
    {
        cout << "0";
    }
    else
    {
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << '\n';
        }
    }
}

int main()
{
    fastIO();
    solve();
}
