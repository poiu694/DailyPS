#include <iostream>

using namespace std;

int list[1000050];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// 최소라는 값에 집중해보면 1근처의 값들부터 신경쓰면 된다.
// 중간쪽에 1이 있는데 왼쪽이 0이라면 자기자신부터 왼쪽은 쭉 무시해도 된다. (영향을 줄 수 있는게 x)
// 반대로 오른쪽끝에 1이있는데 오른쪽이 0이라면 자기자신부터 오른쪽은 쭉 무시해도 된다.
// -> 영향을 줄 수 있는 애들을 앞에서부터 찾아보자.
void solve()
{
    int N;
    cin >> N;

    //input
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
    }

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (list[i] % 2 != 0)
        {
            list[i + 1]++;
            list[i + 2]++;
            cnt++;
        }
    }

    cout << cnt;
}

int main()
{
    fastIO();
    solve();
}