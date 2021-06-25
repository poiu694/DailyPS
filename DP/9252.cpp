#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

string target, st;
int dp[1001][1001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> target >> st;
}

// LCS LENGTH
int LCS_LENGTH() {
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

    return dp[target_length - 1][st_length - 1];
}

string LCS_ST() {
    stack<char> stck;
    string LCS_ST = "";

    int i = target.length() - 1;
    int j = st.length() - 1;
    while (dp[i][j] != 0) {
        // 왼쪽이랑 같다면 
        if (dp[i - 1][j] == dp[i][j]) {
            i--;
        }
        // 위쪽이랑 같다면
        else if (dp[i][j - 1] == dp[i][j]) {
            j--;
        }
        // 왼쪽이랑 위쪽 둘다 다르다면
        else {
            stck.push(target[i]);
            i--;
            j--;
        }
    }

    while (!stck.empty()) {
        LCS_ST = LCS_ST + stck.top();
        stck.pop();
    }

    return LCS_ST;
}

// LCS
void solve() {
    cout << LCS_LENGTH() << "\n";
    cout << LCS_ST() << "\n";
}

int main() {
    init();
    input();
    solve();
}