#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 32000;

int N; // TEST_CASE
vector<int> powList;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void make_powList() {
    // sqrt(1e9) ~= 31622.xxx
    for (int i = 1; i <= MAX; i++) {
        powList.push_back(i * i);
    }
}

void calculate(int num) {
    // 선분이 0인 경우 : sqrt(num)이 정수인 경우
    if ((int)sqrt(num) * (int)sqrt(num) == num) {
        cout << 0 << " " << sqrt(num) << '\n';
        return;
    }
    
    int radius = 1; int line = 1;
    for (int i = 0; i < MAX; i++) {
        int temp = num + powList[i];

        if ((int)sqrt(temp) * (int)sqrt(temp) == temp) {
            radius = sqrt(powList[i]);
            line = sqrt(temp);
            break;
        }
    }

    if (radius == 1 && line == 1) {
        cout << "IMPOSSIBLE" << '\n';
    }
    else {
        cout << radius << " " << line << '\n';
    }
}

void solve() {
    cin >> N;
    make_powList();

    int temp;
    while (N--) {
        cin >> temp;
        calculate(temp);
    }
}

int main() {
    init();
    solve();
}