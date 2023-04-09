#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string  dir="dlru";
string  answer = "";

bool    is_possible(int x, int y, int r, int c, int k)
{
    int row_gap = abs(x - r);
    int col_gap = abs(y - c);
    if (row_gap + col_gap > k)
    {
        return (false);
    }
    else if ((k - (row_gap + col_gap)) % 2 != 0)
    {
        return (false);
    }
    return (true);
}


// ......
// .....S
// ......
// ......
// ......
// .....E
void  dfs(int n, int m, int x, int y, int r, int c, int cnt, int k, string path)
{
    if (answer != "")
        return ;
    if (x == r && y == c && cnt == k)
    {
        answer = path;
        return ;
    }
    if (cnt > k)
        return;
    if (abs(x - r) + abs(y - c) > k - cnt)
        return;
    
    for (int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 1 || ny < 1 || nx > n || ny > m)
            continue ;
        path += dir.substr(i , 1);
        dfs(n, m, nx, ny, r, c, cnt + 1, k, path);
        path = path.substr(0, path.length() - 1);
    }
}

// d, l, r, u
string solution(int n, int m, int x, int y, int r, int c, int k) {
    if (!is_possible(x, y, r, c, k))
        return "impossible";
    dfs(n, m, x, y, r, c, 0, k, "");
    return answer;
}