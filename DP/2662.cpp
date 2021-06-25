#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int dp[21][301];
vector<int> company[21];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        company[i].push_back(0);
    }

    int index, profit;
    for (int i = 1; i <= N; i++) {
        cin >> index;
        for (int j = 1; j <= M; j++) {
            cin >> profit;
            company[j].push_back(profit);
        }
    }
}

// 기업이 늘어난다고 생각하자
//N - A B C D ... 
//1   . . . . 
//2   . . . . 채워 나가는 식으로 하자.
// dp[i][money] // i번째 회사까지 있고, money가 상한선일 때 최고 이익
// dp[i][money] = max(dp[i][money], dp[i-1][money-j]+company[i][j]) . j : 0~money
void solve() {
    for (int i = 1; i <= M; i++) {
        for (int money = 1; money <= N; money++) {
            for (int j = 1; j <= money; j++) {
                dp[i][money] = max(dp[i][money], dp[i - 1][money - j] + company[i][j]);                
            }
        }
    }

    cout << dp[M][N];
}

int main() {
    init();
    input();
    solve();
}