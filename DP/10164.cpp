#include <iostream>
#include <cstring>

using namespace std;

int dp[16][16];

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    int N, M, K;
    cin >> N >> M >> K;

    pair<int, int> temp;
    
    memset(dp, -1, sizeof(dp));
    dp[1][1] = 1;
    int num = 1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dp[i][j] += dp[i-1][j] + dp[i][j-1];
            if(num == K){
                temp.first = i;
                temp.second = j;
            }
            num++;
        }
    }

    if(K == 0){
        cout << dp[N][M];
    }else{
        cout << dp[temp.first][temp.second] * dp[N][M];
    }
}

int main(){
    fastIO();
    solve();
}