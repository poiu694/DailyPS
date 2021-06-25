#include <iostream>
#include <limits.h>

using namespace std;

int N;
int maxSum = INT_MIN;
int minSum = INT_MAX;
int op[4];
int num[12];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N;

    // 숫자
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    //연산자
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }
}

void dfs(int index, int sum) {
    // 끝 숫자에 도달
    if (index == N-1) {
        if (maxSum < sum) {
            maxSum = sum;
        }
        if (minSum > sum) {
            minSum = sum;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] != 0) {
            //PLUS
            if (i == 0) {
                op[i]--;
                dfs(index + 1, sum + num[index+1]);
                op[i]++;
            }
            //MINUS
            else if (i == 1) {
                op[i]--;
                dfs(index + 1, sum - num[index+1]);
                op[i]++;
            }
            //Multi
            else if (i == 2) {
                op[i]--;
                dfs(index + 1, sum * num[index+1]);
                op[i]++;
            }
            //Divide
            else if (i == 3) {
                op[i]--;
                dfs(index + 1, sum / num[index+1]);
                op[i]++;
            }
        }
    }
}

void solve() {
    dfs(0, num[0]);

    cout << maxSum << '\n' << minSum;
}

int main() {
    init();
    input();
    solve();
}