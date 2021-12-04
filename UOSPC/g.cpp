#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void    fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void    get_solution(void)
{
    int N;
    vector<int> xList, yList;

    cin >> N;
    xList.resize(N); yList.resize(N);
    for (int i=0; i<N; i++)
        cin >> xList[i];
    for (int i=0; i<N; i++)
        cin >> yList[i];
    int ans = 0;
    bool    visited[100001];
    memset(visited, false, sizeof(visited));
    for (int i=0; i<N; i++)
    {
        int nowY = yList[i];
        for (int j=0; j<N; j++)
        {
            int nowX = xList[j];
            if (!visited[j] and (i + 1) * yList[i] == (j + 1) * xList[j])
            {
                visited[j] = true;
                ans++;
                break ;
            }

        }
    }
    cout << ans;
}

int main(void)
{
    fast_io();
    get_solution();
}
