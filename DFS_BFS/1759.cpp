#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, C;
bool visited[16];
vector<char> word;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        char temp;
        cin >> temp;
        word.push_back(temp);
    }
}

bool is_AEIOU(char w) {
    if (w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u') {
        return true;
    }
    else {
        return false;
    }
}

void dfs(int depth, int index, int jaeum, int moeum, string s) {
    if (depth == L) {
        if (jaeum >= 2 && moeum >= 1) {
            cout << s << '\n';
            return;
        }
        else {
            return;
        }
    }

    for (int i = index; i < C; i++) {
        if (is_AEIOU(word[i])) {
            dfs(depth + 1, i + 1, jaeum, moeum + 1, s+word[i]);
        }
        else {
            dfs(depth + 1, i + 1, jaeum + 1, moeum, s+word[i]);
        }
    }
}

void solve() {
    sort(word.begin(), word.end());

    dfs(0, 0, 0, 0, "");
}

int main() {
    init();
    input();
    solve();
}