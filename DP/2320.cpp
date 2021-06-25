#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
bool visited[17];
int dp[17];
vector<string> list;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> N;

    string temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        list.push_back(temp);
    }
}

int dfs(int index, char bk)
{
    if (dp[index] != -1)
    {
        return dp[index];
    }

    dp[index] = 0;
    for (int i = 0; i < list.size(); i++)
    {
        if (bk == list[i].front() && !visited[i])
        {
            visited[i] = true;
            dp[index] = max(dp[index], (int)list[i].length() + dfs(i, list[i].back()));
            visited[i] = false;
        }
    }
    return dp[index];
}

void solve()
{
    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        memset(dp, -1, sizeof(dp));
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        ans = max(ans, dfs(i, list[i].back()) + (int)list[i].length());
    }

    cout << ans;
}

int main()
{
    init();
    input();
    solve();
}