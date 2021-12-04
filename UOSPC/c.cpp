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

bool    is_all(vector<int> list)
{
    for (int i=0; i<list.size(); i++)
        if (list[i] == 0)
            return (false);
    return (true);
}

void    get_solution(void)
{
    int N;
    int bcnt = 0;
    vector<int> list;

    cin >> N;
    list.resize(N);
    for (int i=0; i<N; i++)
    {
        cin >> list[i];
        if (list[i] == 1)
            bcnt++;
    }
    if (bcnt <= 1)
    {
        cout << "0";
        return ;
    }
    if (bcnt == 2)
    {
        if (list[0] == 1 and list[N-1] == 1)
        {
            cout << "1";
            return ;
        }
    }
    if (is_all(list))
    {
        cout << N - 1;
        return;
    }
    int st = 0;
    for (int i=0; i<(N / 2); i++)
    {
        if (list[(N / 2) - i] == 1)
        {
            int j = 0;
            int temp = N/2 - i;
            while (1)
            {
                if (temp - j == -1)
                {
                    temp = N - 1; j = 0;
                }
                if (list[temp - j] == 1)
                    st = temp - j;
                else
                    break ;
                j++;
            }
            break ;
        }
        if (list[(N / 2) + i] == 1)
        {
            int j = 0;
            int temp = N/2 + i;
            while (temp + j < N)
            {
                if (temp + j == N)
                {
                    temp = 0; j = 0;
                }
                if (list[temp + j] == 1)
                    st = temp + j;
                else
                    break ;
                j++;
            }
            st = (N/2) + i;
            break ;
        }
    }
    int now1 = st;
    int i = 0;
    int tcnt = 0;
    int tdist = 0;
    while (i < N)
    {
        if (list[now1] == 1)
            tcnt++;
        if (tcnt == bcnt)
            break ;
        now1 = (now1 + 1 ) % N;
        tdist++;
    }
    int now2 = st;
    int i2 = 0;
    int tcnt2 = 0;
    int tdist2 = 0;
    while (i2 < N)
    {
        if (list[now2] == 1)
            tcnt2++;
        if (tcnt2 == bcnt)
            break ;
        now2 = (now2 - 1);
        if (now2 < 0)
            now2 = N - 1;
        tdist2++;
    }
    cout << min(tdist, tdist2);
}

int main(void)
{
    fast_io();
    get_solution();
}
