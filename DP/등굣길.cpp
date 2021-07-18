#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;

int dx[2] = {1, 0};
int dy[2] = {0, 1};
int dp[101][101];

int findPath(int x, int y, int m, int n, vector<vector<int>> &puddles)
{
    if (x == m - 1 && y == n - 1)
    {
        return 1;
    }

    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }

    for (int i = 0; i < puddles.size(); i++)
    {
        if (x == puddles[i][0] - 1 && y == puddles[i][1] - 1)
        {
            return 0;
        }
    }

    dp[x][y] = 0;
    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n)
        {
            dp[x][y] += findPath(nx, ny, m, n, puddles) % MOD;
        }
    }

    return dp[x][y] % MOD;
}

int solution(int m, int n, vector<vector<int>> puddles)
{
    memset(dp, -1, sizeof(dp));
    int answer = findPath(0, 0, m, n, puddles);
    return answer;
}