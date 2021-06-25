#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int N, B, C;
vector<int> list;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N;
    list.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> list[i];
    }
    cin >> B >> C;
}

void solve() {
    long long cnt = N;

    for (int i = 0; i < N; i++) {
        list[i] -= B;
    }

    for (int i = 0; i < N; i++) {
        if(list[i] > 0 ){
            if (list[i] % C == 0) {
            cnt += list[i] / C;
            }
            else {
                cnt += (list[i] / C) + 1;
            }
        }
        
    }

    cout << cnt;
}

int main() {
    init();
    input();
    solve();
}