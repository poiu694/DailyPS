#include <iostream>
#include <algorithm>

using namespace std;

int N;
int color[1001][3];
int dp[1001][3];

// case : RGR RGB RBG RBR BGB BGR BRB BRG GRG GRB GBR GBG중에서 MIN
void solve(){
    for(int depth=1; depth<=N; depth++){
        dp[depth][0] = min(dp[depth-1][1], dp[depth-1][2]) + color[depth][0];
        dp[depth][1] = min(dp[depth-1][0], dp[depth-1][2]) + color[depth][1];
        dp[depth][2] = min(dp[depth-1][1], dp[depth-1][0]) + color[depth][2];
    }

    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);
}   

void input(){
    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }

    dp[0][0] = color[0][0];
    dp[0][1] = color[0][1];
    dp[0][2] = color[0][2];
}

int main(){
    input();
    solve();
}