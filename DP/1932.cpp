#include <iostream>
#include <algorithm>

using namespace std;

int N, answer;
int tree[501][501]={0};
int dp[501][501];

void solve(){
    dp[1][1] = tree[1][1];

    for(int i=2; i<=N; i++){
        for(int j=1; j<=i; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + tree[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        if(answer < dp[N][i]){
            answer = dp[N][i];
        }
    }

    cout << answer;
}

void input(){
    cin >> N;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            cin >> tree[i][j];
        }
    }
}

int main(){
    input();
    solve();
}  