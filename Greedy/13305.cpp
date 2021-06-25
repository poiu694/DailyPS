#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 987654321;

int N;
vector<int> city;
vector<int> oil;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N;

    int temp;
    for (int i = 0; i < N - 1; i++) {
        cin >> temp;
        oil.push_back(temp);
    }

    for (int i = 0; i < N; i++) {
        cin >> temp;
        city.push_back(temp);
    }
}

void solve() {
    long long sum = 0;


    for (int i = 0; i < N-1;) {
        long long now = 0; // 현재 index에서 얼마를 투입할 것인지.
        long long cnt = 0; // 현재 index보다 더 큰 주유소 개수

        for (int j = i; j < N-1; j++) {
            if (city[i] <= city[j]) {
                now += oil[j];
                cnt++;
            }
            else {
                break;
            }
        }

        sum += now * city[i];
        i += cnt;
    }

    cout << sum;
}

int main() {
    init();
    input();
    solve();
}