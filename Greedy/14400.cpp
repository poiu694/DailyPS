#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> list;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N;

    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        list.push_back({ x,y });
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }

    return a.second < b.second;
}

// -1,000,000 , -1,000,000 ~ 1,000,000 , 1,000,000 완전탐색 불가능
void solve() {
    // X와 Y의 중앙값이면 최소이지 않을까?

    sort(list.begin(), list.end()); // x기준 정렬
    int midX = list[(N - 1) / 2].first;

    sort(list.begin(), list.end(), cmp); // y기준 정렬
    int midY = list[(N - 1) / 2].second;

    long long sum = 0;
    for (int i = 0; i < list.size(); i++) {
        sum += abs(midX - list[i].first) + abs(midY - list[i].second);
    }

    cout << sum;
}

int main() {
    init();
    input();
    solve();
}