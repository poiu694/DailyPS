#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N, M;
int map[9][9], tempMap[9][9];
int dx[4] = {1, 0, -1, 0}; // 0 N, 1, E, 2 S, 3 W
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> cctv;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void copyMap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            tempMap[i][j] = map[i][j];
        }
    }
}

void updateMap(int x, int y, int dir){ // tempMap에 Update -> 원본 보존
    dir %= 4;
    while(true){
        x = x + dx[dir];
        y = y + dy[dir];

        if(x < 0 || x >= N || y < 0 || y >=M || tempMap[x][y] == 6){
            return;
        }

        tempMap[x][y] = 10;
    }
}

int blindSpot(){
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(tempMap[i][j] == 0){
                cnt++;
            }
        }
    }
    return cnt;
}

void solve(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j]; // Input

            if(map[i][j] != 0 && map[i][j] != 6){
                cctv.push_back({i, j});
            }
        }
    }

    int answer = 100;
    // 0 -> E 1 -> S 2 -> W 3->N 
    for(int brute=0; brute< (1<<(2*cctv.size())); brute++){
        copyMap();
        int temp = brute;
        for(int i=0; i<cctv.size(); i++){
            int direction = temp % 4;
            temp /= 4;

            int cctvX = cctv[i].first;
            int cctvY = cctv[i].second;

            if(map[cctvX][cctvY] == 1){
                updateMap(cctvX, cctvY, direction);
            }else if(map[cctvX][cctvY] == 2){
                updateMap(cctvX, cctvY, direction);
                updateMap(cctvX, cctvY, direction + 2);
            }else if(map[cctvX][cctvY] == 3){
                updateMap(cctvX, cctvY, direction);
                updateMap(cctvX, cctvY, direction + 1);
            }else if(map[cctvX][cctvY] == 4){
                updateMap(cctvX, cctvY, direction);
                updateMap(cctvX, cctvY, direction + 1);
                updateMap(cctvX, cctvY, direction + 2);
            }else{
                updateMap(cctvX, cctvY, direction);
                updateMap(cctvX, cctvY, direction + 1);
                updateMap(cctvX, cctvY, direction + 2);
                updateMap(cctvX, cctvY, direction + 3);
            }
        }

        answer = max(answer, blindSpot());
    }

    cout << answer;
}

int main(){
    fastIO();
    solve();
}