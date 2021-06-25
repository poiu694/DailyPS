#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[10001];
vector<int> list;
bool visited[400001];

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
        list.push_back(temp);
    }
}


// A + B + C = D
// A + B(for) = D - C(for) -> N^2
int solve() {
    int result = 0;
    for (int i = 0; i < N; i++) {
        // D-C CHECK
        for (int j = 0; j < i; j++) {
            int dc = list[i] - list[j] + 200000;

            if (visited[dc]) {
                result++;
                break; // list[d] is good number, useless overlap
            }
        }

        // Visit list[a] + list[b]
        for (int j = 0; j <= i; j++) {
            int ab = list[i] + list[j] + 200000;
            visited[ab] = true;
        }
    }

    return result;
}

int main() {
    init();
    input();
    cout << solve();
}