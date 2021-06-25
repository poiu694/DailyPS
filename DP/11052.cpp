#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int dp[1001] = { 0, };
vector<int> card;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        card.push_back(temp);
    }
}
void solve() {
    dp[0] = card[0];

    //dp[i] = max(card[i], dp[i-1] + card[0], dp[i-2] + card[1] ...)
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= i; j++) {
            int temp = max(dp[i], card[i]);
            dp[i] = max(temp, dp[i - j] + card[j - 1]);
        }
    }

    cout << dp[N - 1];
}

int main() {
    init();
    input();
    solve();
}