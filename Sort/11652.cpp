#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N;
map<long long, int> mp;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        long long temp;
        cin >> temp;
        mp[temp]++;
    }
}

// value 기준 정렬
bool cmp(pair<long long, int> left, pair<long long, int> right) {
    if (left.second == right.second) return left.first < right.first; // 빈도가 같다면 오른쪽으로 갈 수록 first값이 커지게

    return left.second > right.second; // 왼쪽으로 갈 수록 second값이 커지게
}

void solve() {
    vector<pair<long long, int>> list(mp.begin(), mp.end());
    
    sort(list.begin(), list.end(), cmp);
    cout << list[0].first;
}

int main() {
    init();
    input();
    solve();
}