#include <iostream>
#include <queue>
#define MAX 301

using namespace std;

int T, I, startX, startY, lastX, lastY;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int check[MAX][MAX] ={ 0 };
queue<pair<int, int>> q;

/**
 * 1
 *   - 2
 *      - 3
 *        - 5    
 *   - 4
 *        - 5
 *           - 6
 *           - 7
 *        - 6
 *           - 7
 */

int bfs(){
    q.push({startX, startY});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 종료 조건
        if(x == lastX && y == lastY){
            return check[x][y];
        }

        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < I && ny >= 0 && ny <I){
                if(check[nx][ny] == 0){
                    check[nx][ny] = check[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
}

void input(){
    cin >> I;
    cin >> startX >> startY;
    cin >> lastX >> lastY;

    while(!q.empty()){
        q.pop();
    }
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            check[i][j] = 0;
        }
    }
}

int main(){
    cin >> T;
    while(T--){
        input();
        cout << bfs() << "\n";
    }
}