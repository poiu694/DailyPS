#include <iostream>
#include <vector>

using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int foo(vector<int> &dp, vector<pair<int, int>> &list, int nowDay, int nowCost, int N){
    if(nowDay > N){
        return 0;
    }

    if(dp[nowDay] != -1){
        return dp[nowDay];
    }

    int costDay = list[nowDay].first;
    int costPrice = list[nowDay].second;
    
    return dp[nowDay] = foo(dp, list, nowDay + costDay, nowCost + costPrice, N);
}

void solve(){
    int N;
    cin >> N;

    vector<int> dp(N+1, -1);
    vector<pair<int, int>> list(N+1);

    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        list.push_back({a,b});
    }
}

int main(){
    fastIO();
    solve();
}