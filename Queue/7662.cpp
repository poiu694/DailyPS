#include<iostream>
#include<set>

using namespace std;

int T, N;
multiset<int> list; // 우선순위 큐와 같이 항상 오름차순 정렬

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            char op;
            int num;
            cin >> op >> num;

            if (op == 'I') {
                list.insert(num);
            }
            else {
                // 비어있다면 무시.
                if (list.empty()) {
                    continue;
                }

                if (num == 1) {
                    auto iter = list.end();
                    iter--;
                    list.erase(iter);
                }
                else {
                    auto iter = list.begin();
                    list.erase(iter);
                }
            }
        }

        if (list.empty()) {
            cout << "EMPTY" << '\n';
        }
        else {
            auto end = list.end();
            end--;
            cout << *end << " " << *list.begin() << '\n';
        }

        list.clear();
    }
}
int main() {
    init();
    solve();
}