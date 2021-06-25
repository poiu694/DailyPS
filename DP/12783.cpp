#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M;
int dp[1000001];
const int MAX = 987654321; // 최댓값 상수로 지정
vector<int> card; // 가지고 있는 카드


void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// dp[i] : i를 만들기 위한 곱셈의 수
// target : 만들어야 될 숫자, now : card를 이용하여 만든 숫자
int dfs(int target, int now) {
    // 만들지 못했을 때
    if (target < now) {
        return MAX;
    }
    // 만들 수 있을 때
    if (target == now) {
        return 0;
    }
    // 기존에 방문
    if (dp[now] != -1) {
        return dp[now];
    }

    // 이쪽 줄이 실행될 경우는 target보다 현재 값이 작아야하고
    // 방문한 적이 없을경우 아래 코드 실행

    dp[now] = MAX; // dp[now]는 최소의 값을 가져와야 한다.
    for (int i = 0; i < card.size(); i++) {
        // 처음에 0카드를 만났을 때
        if (card[i] == 0 && now == 0) {
            continue;
        }        
        // 0을 만나면 이어붙이기만 가능
        else if (card[i] == 0) {
            dp[now] = min(dp[now], dfs(target, now * 10));
        }

        else {
            dp[now] = min(dp[now], dfs(target, now * 10 + card[i])); // 붙여서 만들 수 있는 경우
            dp[now] = min(dp[now], dfs(target, now * card[i]) + 1); // 곱해서 만들 수 있는 경우
        }
    }

    return dp[now];
}

void solve() {
    cin >> T;

    int temp;
    while (T--) {
        card.clear();

        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            card.push_back(temp);
        }
        cin >> M;
        for (int i = 0; i < M; i++) {
            memset(dp, -1, sizeof(dp));
            cin >> temp;
            int rst = dfs(temp, 0);


            if (rst == MAX) {
                cout << -1 << '\n';
            }
            else {
                cout << rst << '\n';
            }
        }
    }
}

int main() {
    init();
    solve();
}