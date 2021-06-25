#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    int dp[10001];
    int N, K;
    cin >> N >> K;

    vector<int> list(N);
    for(int i=0; i<N; i++){
        cin >> list[i];
        dp[list[i]] = 1;
    }
    
    for(int i=1; i<=K; i++){
        for(int j=0; j<list.size(); j++){
            dp[i] = min(dp[i], dp[i % list[j]] + 1);
        }
    }
}

int main()
{
    fastIO();
    solve();
}
