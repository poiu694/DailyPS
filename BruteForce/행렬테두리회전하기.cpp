#include <string>
#include <vector>
#include <iostream>

using namespace std;

int rotate(int x, int y, int R, int C, vector<vector<int>> &map)
{
    int minValue = 10001;

    int temp = map[x][y];
    for (int i = x; i < R; i++)
    {
        map[i][y] = map[i + 1][y];
        if (minValue > map[i][y])
            minValue = map[i][y];
    }
    for (int i = y; i < C; i++)
    {
        map[R][i] = map[R][i + 1];
        if (minValue > map[R][i])
            minValue = map[R][i];
    }
    for (int i = R; i > x; i--)
    {
        map[i][C] = map[i - 1][C];
        if (minValue > map[i][C])
            minValue = map[i][C];
    }
    for (int i = C; i > y + 1; i--)
    {
        map[x][i] = map[x][i - 1];
        if (minValue > map[x][i])
            minValue = map[x][i];
    }
    map[x][y + 1] = temp;
    if (minValue > map[x][y + 1])
        minValue = map[x][y + 1];
    return minValue;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;

    int temp = 1;
    vector<vector<int>> map(rows + 1, vector<int>(columns + 1));
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            map[i][j] = temp++;
        }
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int x = queries[i][0];
        int y = queries[i][1];
        int R = queries[i][2];
        int C = queries[i][3];
        answer.push_back(rotate(x, y, R, C, map));
    }

    return answer;
}