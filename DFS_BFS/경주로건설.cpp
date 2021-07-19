#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;

struct Jordi{
    int x;
    int y;
    int cost;
    int dir;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(vector<vector<int>> board){
    queue<Jordi> q;
    if(board[1][0] != 1) q.push({1, 0, 100, 0});
    if(board[0][1] != 1) q.push({0, 1, 100, 1});
    
    int ret = 987654321;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cost = q.front().cost;
        int dir = q.front().dir;
        q.pop();
        
        if(x == board.size()-1 and y == board.size() -1){
            if(ret > cost) ret = cost;
            continue;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nextCost = cost;
            
            if(nx < 0 or ny < 0 or nx >= board.size() or ny >= board.size()) continue;
            if(board[nx][ny] == 1) continue;
            
            if((i + dir) % 2 == 1) nextCost += 600;
            else nextCost += 100;;
            
            if(board[nx][ny] >= nextCost or !board[nx][ny]){
                board[nx][ny] = nextCost;
                q.push({nx, ny, nextCost, i});
            }
        }
    }
    
    return ret;
}

int solution(vector<vector<int>> board) {
    return bfs(board);
}