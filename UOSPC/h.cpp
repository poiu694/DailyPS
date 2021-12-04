#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void    fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void    get_solution(void)
{
    int         N, M;
    queue<char> q1;
    queue<char> q2;
    string      temp;
    int         visited[30];

    cin >> N >> M;
    cin >> temp;
    memset(visited, 0, sizeof(visited));
    for (int i=0; i<N; i++)
    {
        q1.push(temp[i]);
        visited[(temp[i] - 'A')]++;
    }
    cin >> temp;
    for (int i=0; i<M; i++)
    {
        visited[(temp[i] - 'A')]++;
        q2.push(temp[i]);
    }
    vector<char>    ans;
    while (!q1.empty() and !q2.empty())
    {
        if (ans.empty())
        {
            if (visited[q1.front() -'A'] > visited[q2.front() -'A'])
            {
                visited[q2.front() - 'A']--;
                ans.push_back(q2.front());
                q2.pop();
            }
            else
            {
                visited[q1.front() - 'A']--;
                ans.push_back(q1.front());
                q1.pop();
            }
        }
        else if (q1.front() == ans[ans.size() - 1])
        {
            visited[q1.front() - 'A']--;
            ans.push_back(q1.front());
            q1.pop();
        }
        else if (q2.front() == ans[ans.size() - 1])
        {
            visited[q2.front() - 'A']--;
            ans.push_back(q2.front());
            q2.pop();
        }
        else if (q1.front() == q2.front())
        {
            visited[q1.front() - 'A']--;
            visited[q2.front() - 'A']--;
            ans.push_back(q2.front());
            ans.push_back(q1.front());
            q1.pop();
            q2.pop();
        }
        else
        {
            if (visited[q1.front() -'A'] > visited[q2.front() -'A'])
            {
                visited[q2.front() - 'A']--;
                ans.push_back(q2.front());
                q2.pop();
            }
            else
            {
                visited[q1.front() - 'A']--;
                ans.push_back(q1.front());
                q1.pop();
            }
        }
    }
    while (!q1.empty())
    {
        ans.push_back(q1.front());
        q1.pop();
    }
    while (!q2.empty())
    {
        ans.push_back(q2.front());
        q2.pop();
    }
    for (char c: ans)
        cout << c << " ";
    int cnt = 0;
    for (int i=1; i<ans.size(); i++)
        if (ans[i] != ans[i - 1])
            cnt++;
    cout << cnt;
}

int main(void)
{
    fast_io();
    get_solution();
}
