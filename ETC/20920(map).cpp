#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N, M;
vector<string> list;
map<string, int> mp;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> M;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;

        if (str.length() >= M) {
            list.push_back(str);
        }
    }
}

bool cmp(pair<string, int> s1, pair<string, int> s2) {
    if (s1.second == s2.second) {
        if (s1.first.length() == s2.first.length()) {
            return s1.first < s2.first;
        }
        else {
            return s1.first.length() > s2.first.length();
        }

    }


    return s1.second > s2.second;
}

void solve() {
    sort(list.begin(), list.end());

    string temp = list[0];
    mp.insert({ temp, 1 });

    int index = 0;
    for (int i = 1; i < list.size(); i++) {
        if (temp != list[i]) {
            index++;
            temp = list[i];
            mp.insert({ temp, 1 });
        }
        else {
            mp[temp]++;
        }
    }

    vector<pair<string, int>> result(mp.begin(), mp.end());
    sort(result.begin(), result.end(), cmp);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first << '\n';
    }
}

int main() {
    init();
    input();
    solve();
}