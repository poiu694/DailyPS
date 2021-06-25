#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N, M, idx;
vector<pair<string, string>> list;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool binarySearch(int start, int end, string target) {
    if (start > end) {
        return false;
    }
    else {
        int mid = (start + end) / 2;

        if (list[mid].first == target) {
            idx = mid;
            return true;
        }
        else if (list[mid].first > target) {
            return binarySearch(start, mid - 1, target);
        }
        else {
            return binarySearch(mid + 1, end, target);
        }
    }
}

void solve() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string site, password;
        cin >> site >> password;

        list.push_back({ site, password });
    }
    sort(list.begin(), list.end());

    for (int i = 0; i < M; i++) {
        string target;

        cin >> target;
        if (binarySearch(0, list.size() - 1, target)) {
            cout << list[idx].second << '\n';
        }
    }
}

int main() {
    init();
    solve();
}