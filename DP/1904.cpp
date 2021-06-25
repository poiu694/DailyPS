#include <iostream>

using namespace std;

// N = 1 , 1 1
// N = 2 , 2 00 11
// N = 3 , 3 111 100 001
// N = 4 , 5 0000 1100 1001 0011 1111
// N = 5 , 7 00001 10000 11100 11001 10011 00111 11111
long long int dp[1000001];
int N;

int solve(int N){
    dp[1] = 1; dp[2] = 2;

    for(int i=3; i<=N; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] = dp[i] % 15746;
    }

    return dp[N];
}

int main(){
    cin >> N;
    cout << solve(N);    
}