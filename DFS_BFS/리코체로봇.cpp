#include <string>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int visited[101][101];

int bfs(vector<string> board, int x, int y)
{
    queue<pair<pii, int>>  q;
    
    q.push({{ x, y }, 0 });
    while (!q.empty())
    {
        int rx = q.front().first.first;
        int ry = q.front().first.second;
        int count = q.front().second;
        q.pop();
        
        if (board[rx][ry] == 'G')
        {
            return (count);
        }
        for (int i=0; i<4; i++)
        {
            int nx = rx;
            int ny = ry;
            
            while (true)
            {
                nx += dx[i];
                ny += dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == 'D')
                {
                    nx -= dx[i];
                    ny -= dy[i];
                    break ;
                }
                if (board[nx][ny] == 'D')
                {
                    nx -= dx[i];
                    ny -= dy[i];
                    break ;
                }
            }
            if (visited[nx][ny])
            {
                continue ;
            }
            visited[nx][ny] = count + 1;
            q.push({{ nx, ny }, count + 1});
        }
    }
    return (-1);
}

int solution(vector<string> board) {
    int answer = 0;
    int x, y;
    n = board.size();
    m = board[0].size();
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (board[i][j] == 'R')
            {
                x = i;
                y = j;
            }
    return bfs(board, x, y);
}