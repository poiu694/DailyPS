#include <string>
#include <vector>
#include <iostream>

# define ENEMY 1
# define SUPPORT 2
using namespace std;

int N, M;
int map[1005][1005];
int damage[1005][1005];

int solution(vector<vector<int>> board, vector<vector<int>> skills) {
    N = board.size();
    M = board[0].size();
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            map[i][j] = board[i][j];
    
    for (vector<int> skill: skills)
    {
        int type = skill[0];
        int r1 = skill[1]; int c1 = skill[2];
        int r2 = skill[3]; int c2 = skill[4];
        int degree = skill[5];
        if (type == ENEMY)
        {
            damage[r1][c1] -= degree;
            damage[r2 + 1][c1] += degree;
            damage[r1][c2 + 1] += degree;
            damage[r2 + 1][c2 + 1] -= degree;
        }
        else
        {
            damage[r1][c1] += degree;
            damage[r2 + 1][c1] -= degree;
            damage[r1][c2 + 1] -= degree;
            damage[r2 + 1][c2 + 1] += degree;
        }
    }
    for (int i=0; i<N; i++)
        for (int j=0; j<M-1; j++)
            damage[i][j + 1] += damage[i][j];
    for (int i=0; i<N-1; i++)
        for (int j=0; j<M; j++)
            damage[i + 1][j] += damage[i][j];
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            map[i][j] += damage[i][j];
    int answer = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            if (map[i][j] > 0)
                answer++;
    return answer;
}