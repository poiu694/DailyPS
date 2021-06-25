#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
bool visited[17];
int dp[17][17];
vector<string> list;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N;

    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        list.push_back(temp);
    }
}

int dfs(int start, int index, int len, char bk) {
    if (dp[start][index] != -1) {
        return dp[start][index];
    }
    if (index >= N) {
        return 0;
    }

    dp[start][index] = len;
    visited[index] = true;
    for (int i = 0; i < list.size(); i++) {
        if (bk == list[i].front() && !visited[i]) {
            dp[start][index] = max(dp[start][index], dfs(start, i, len + list[i].length(), list[i].back()));
        }
    }
    visited[index] = false;

    return dp[start][index];
}

void solve() {
    int ans = -1;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) {
        memset(visited, false, sizeof(visited));
        ans = max(ans, dfs(i, i, list[i].length(), list[i].back()));
    }

    cout << ans;
}

int main() {
    init();
    input();
    solve();
}