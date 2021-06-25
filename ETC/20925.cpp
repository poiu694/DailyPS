 #include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
int run[220][220] = { 0 };//a사냥터에서 b사냥터로 갔을때 걸리는 시간
ll dp[220][1010] = { 0 };//a사냥터에서 b분이 지났을 때의 경험치
pair<int, int>hunt[220];//입장경험치, 분당경험치

int main()
{
    int N, T, a, b;
    cin >> N >> T;
    for (int i = 1; i <= N; i++) {
        cin >> a >> b;
        hunt[i].first = a;
        hunt[i].second = b;
    }
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= N; k++) {
            cin >> a;
            run[i][k] = a;
        }
    }

    for (int k = 1; k <= N; k++) {//기초 세팅
        if (hunt[k].first == 0) {
            dp[k][1] = hunt[k].second;
        }
    }

    for (int i = 1; i <= T; i++) {//시간
        for (int k = 1; k <= N; k++) {//현재 사냥터
            if (dp[k][i - 1] !=0 ) {
                dp[k][i] = hunt[k].second + dp[k][i - 1];
            }
            for (int p = 1; p <= N; p++) {//이동해올 사냥터
                if (i - run[p][k] > 0) {
                    if (dp[p][i - run[p][k]] >= hunt[k].first) {
                        dp[k][i] = max(dp[p][i - run[p][k]], dp[k][i]);
                    }
                }
            }
        }
    }

    ll ans=0;
    for (int k = 1; k <= N; k++) {
        if (dp[k][T] != 0) {
            ans = max(ans, dp[k][T]);
        }
    }
    cout << ans;
}