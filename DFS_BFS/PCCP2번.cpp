#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

# define CHECK  2

using namespace std;
using pii = pair<int, int>;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int solution(vector<vector<int>> land) {
    int answer = 0;
    queue<pii>  q;
    vector<int> answers(501, 0);
    
    for (int i=0; i<land.size(); i++)
    {
        for (int j=0; j<land[0].size(); j++)
        {
            if (land[i][j] == 1)
            {
                int cnt;
                set<int>    s;
                
                q.push({ i, j });
                s.insert(j);
                cnt = 0;
                land[i][j] = CHECK;
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    cnt++;
                    for (int k=0; k<4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        
                        if (nx < 0 || ny < 0 || nx >= land.size() || ny >= land[0].size())
                            continue ;
                        if (land[nx][ny] == 1)
                        {
                            q.push({ nx, ny });
                            land[nx][ny] = CHECK;
                            s.insert(ny);
                        }
                    }
                }
                
                for (auto iter=s.begin(); iter!=s.end(); iter++)
                    answers[*iter] += cnt;
            }
        }
    }
    answer = -1;
    for (int i=0; i<501; i++)
        answer = max(answer, answers[i]);
    return answer;
}