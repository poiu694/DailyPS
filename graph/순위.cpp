#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int dist[101][101];

void makeDist(int n, vector<vector<int>> results)
{
    memset(dist, 1, sizeof(dist));

    for (auto result : results)
    {
        int winner = result[0];
        int loser = result[1];

        dist[winner][loser] = 1;
    }
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;
    makeDist(n, results);

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;

            if (dist[i][j] != 16843009 or dist[j][i] != 16843009)
                cnt++;
        }
        if (cnt == n - 1)
            answer++;
    }

    return answer;
}