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
    vector<int> list;

    cin >> N;
    list.resize(N);
    for (int i=0; i<N; i++)
        cin >> list[i];
    int aas = -1;
    int st = list[0];
    for (int i=0; i<N; i++)
    {
        int now = list[i];
        for (int j=i+1; j<N; j++)
        {
            int next = list[j];
            if (now == -1 || next == -1)
                continue ;
            else
            {
                aas = (list[j] - list[i]) / (j - i);
                if (i != 0)
                    st = list[i] - (i)* aas;
                break ;
            }
        }
        if (aas != -1)
            break ;
    }
    for (int i=0; i<N; i++)
    {
        cout << st << '\n';
        st = st + aas;
    }
}
int main(void)
{
    fast_io();
    get_solution();
}
