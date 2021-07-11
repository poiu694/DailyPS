#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
vector<string> hear;
vector<string> both;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool binarySearch(int start, int end, string temp) {
    if (start > end) {
        return false;
    }
    else {
        int mid = (start + end) / 2;

        if (hear[mid] == temp) {
            return true;
        }
        else if (hear[mid] > temp) {
            return binarySearch(start, mid - 1, temp);
        }
        else {
            return binarySearch(mid + 1, end, temp);
        }
    }
}

void solve() {
    string temp;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        hear.push_back(temp);
    }

    sort(hear.begin(), hear.end());
    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (binarySearch(0, hear.size() - 1, temp)) {
            both.push_back(temp);
        }
    }
    
    sort(both.begin(), both.end());
    cout << both.size() << "\n";
    for (int i = 0; i < both.size(); i++) {
        cout << both[i] << "\n";
    }
}


int main() {
    init();
    solve();
}