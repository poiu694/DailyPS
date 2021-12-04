#include <iostream>
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

void    swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void    get_solution(void)
{
    int N;
    vector<int> list;
    vector<int> wish;

    cin >> N;
    list.resize(N);
    wish.resize(N);
    for (int i=0; i<N; i++)
        cin >> list[i];
    for (int i=0; i<N; i++)
        cin >> wish[i];
    vector<int> shop;
    vector<bool> visited(N, false);
    for (int i=0; i<N; i++)
        if (list[i] != wish[i])
            shop.push_back(list[i]);
    sort(shop.begin(), shop.end());
    sort(wish.begin(), wish.end());
    int j = 0;
    int i = 0;
    int cnt = 0;
    while (i < N and j < N)
    {
        if (shop[i] < wish[j])
            i++;
        else if (shop[i] > wish[j])
            j++;
        else
        {
            i++;
            j++;
            cnt++;
        }
    }
    cout << N - cnt;
}

int main(void)
{
    fast_io();
    get_solution();
}
