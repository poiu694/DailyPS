#include <iostream>

using namespace std;

int N, K;
int dp[1001][1001];

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N >> K;
}

// nCk = n-1Ck + n-1Ck-1
int nCk(int N, int K){
    if(N == K || K ==0){
        return 1;
    }
    if(dp[N][K] != 0){
        return dp[N][K];
    }

    int cnt = 0;
    cnt = nCk(n-1, K) + nCk(n-1, k-1);

    dp[N][K] = cnt;

    return dp[N][K];
}

int main(){
    init();
    input();
    solve();
}