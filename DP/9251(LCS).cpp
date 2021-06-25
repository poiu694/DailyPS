#include <iostream>
#include <cstring>

using namespace std;

string target;
string st;
int dp[1001][1001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> target >> st;
}

// LCS Length
void solve() {
    // LCS 알고리즘을 위해 0을 앞에 붙인다.
    target = '0' + target;
    st = '0' + st;

    int target_length = target.length();
    int st_length = st.length();

    for (int i = 0; i < target_length; i++) {
        for (int j = 0; j < st_length; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }

            // 비교값이 같다면
            if (target[i] == st[j]) {
                // 왼쪽 대각선위에서 값을 가져온다
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // 비교값이 다르다면
            else {
                // 왼쪽이나 위에서 큰 값을 가져온다.
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    cout << dp[target_length - 1][st_length - 1];
}

int main() {
    init();
    input();
    solve();
}