#include <iostream>

using namespace std;

int answer = -1;
int minTime = 100001;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int depth, int time, int now, int nowTime, int N, int M){
    if(depth == time){
        if(nowTime < minTime){
            minTime = nowTime;
            answer = now;
        }
        return;
    }

    if(depth > time){
        return;
    }
    
    dfs(depth + N, time, now+1, nowTime, N, M);
    dfs(depth + M, time, now+1, nowTime, N, M);
    dfs(depth + 1, time, now, nowTime + 1, N, M);
}

void solve(){
    int N, M, T;
    cin >> N >> M >> T;

    int cnt = 0;
    int time = 0;
    
    dfs(0, T, 0, 0, N, M);

    cout << answer << ' ' << minTime;
}

int main(){
    fastIO();
    solve();
}