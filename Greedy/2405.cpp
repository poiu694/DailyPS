#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> list;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    cin >> N;
    list.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
    }

    // 중위값은 잡기 애매하다. 중위값을 다 선택해보자 1~N-1 개까지 다 해보자.
    // L / M / R 구역으로 나눈다.
    // 중위값과 평균 중에서 어떤게 더 큰지 모르기 때문에, 2가지로 나누어 한다.
    // 중위값이 평균보다 큰 경우는 평균을 제일 낮추는 방향으로 돌린다.
    // 중위값이 평균보다 작은 경우는 평균을 제일 키우는 방향으로 돌린다.
    // abs(mean - medium) -> 大

    sort(list.begin(), list.end()); // sort 오름차순

    long long max = -1;
    // 중위값을 기준으로 평균을 제일 낮추는 방법. (제일 왼쪽의 값, 중위값, 중위값 바로 다음 값)
    for (int i = 1; i < N - 1; i++)
    { // 맨 처음 / 마지막 인덱스 제외
        int mid = i;
        long long temp = abs(list[0] - (2 * list[mid]) + list[mid + 1]);
        if (max < temp)
        {
            max = temp;
        }
    }

    // 중위값을 기준으로 평균을 제일 높이는 방법. (제일 오른쪽 값, 중위값, 중위값 바로 왼쪽 값)
    for (int i = 1; i < N - 1; i++)
    {
        int mid = i;
        long long temp = abs(list[mid - 1] - (2 * list[mid]) + list[N - 1]);
        if (max < temp)
        {
            max = temp;
        }
    }
    cout << max;
}

int main()
{
    fastIO();
    solve();
}