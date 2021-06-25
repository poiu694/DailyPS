#include <iostream>

using namespace std;

int T, N;
long long int dp[101];

void P(){
    // P(1~15) : 1 1 1 2 2 3 4 5 7 9 12 16 21 28 37
    // P(N) = P(N-1) + P(N-5)
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;

    for(int i=6; i<=100; i++){
        dp[i] = dp[i-1] + dp[i-5];
    }
}

int main(){
    cin >> T;
    P();

    while(T--){
        cin >> N;
        cout << dp[N] << '\n';
    }
}