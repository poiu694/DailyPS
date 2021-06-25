#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int inDegree[32001];
vector<int> tree[32001];
queue<int> q;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> M;

    int node, child;
    for (int i = 0; i < M; i++) {
        cin >> node >> child;

        tree[node].push_back(child);
        inDegree[child]++;
    }
}

void solve() {
    // inDegree가 0인점 찾기 -> 0이란 것은 제일 먼저 할 수 있다는 얘기이다.
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Queue가 비어있다는 뜻은 Cycle이 생겼다는 뜻
    if (q.empty()) {
        return;
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        cout << now << " ";

        for (int i = 0; i < tree[now].size(); i++) {
            int next = tree[now][i];
            inDegree[next]--;

            if (inDegree[next] == 0) {
                q.push(next);
            }
        }
    }

}

int main() {
    init();
    input();
    solve();
}