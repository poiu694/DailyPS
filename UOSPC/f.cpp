#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct  Club
{
    int  cnt;
    vector<char> list;
    vector<char> waitList;
};

struct  People
{
    vector<char>    list;
};

void    fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void    get_solution(void)
{
    int T, M, N;
    vector<Club>    dong;
    vector<People>  person;

    cin >> T >> M >> N;
    dong.resize(M);
    person.resize(N);
    for (int i=0; i<M; i++)
    {
        int cnt;
        char name;
        cin >> name >> cnt;
        vector<char> l;
        for (int j=0; j<N; j++)
        {
            char name2;
            cin >> name2;
            l.push_back(name2);
        }
        dong[i] = (Club){cnt, l, {}};
    }
    for (int i=0; i<N; i++)
    {
        int cnt; char name;
        cin >> name >> cnt;
        vector<char> l;
        for (int j=0; j<cnt; j++)
        {
            char name2;
            cin >> name2;
            l.push_back(name2);
        }
        person[i] = (People){l};
    }
    vector<char>    ans[30];
    bool    visited[30];
    memset(visited, false, sizeof(visited));
    int time = 0;
    while (time < T)
    {
        for (int i=0; i<N; i++)
        {
            if (person[i].list.size() > time)
            {
                char wish = person[i].list[time];
                dong[wish - 'A'].waitList.push_back(i + 'a');
            }
        }
        for (int i=0; i<M; i++)
        {
            char who;
            for (int j=0; j<dong[i].cnt; j++)
            {
                char who;
                for (int k=0; k<N; k++)
                {
                    bool flag = false;
                    who = dong[i].list[k];
                    for (char wait: dong[i].waitList)
                    {
                        if (!visited[who - 'a'] and wait == who)
                        {
                            visited[who - 'a'] = true;
                            ans[i].push_back(who);
                            flag = true;
                            break ;
                        }
                    }
                    if (flag) break;
                }
            }
        }
        for (int i=0; i<M; i++)
            dong[i].waitList.clear();
        time++;
    }
    for (int i=0; i<M; i++)
    {
        cout << (char)(i + 'A') << " ";
        for (char c: ans[i])
            cout << c << " ";
        cout << '\n';
    }
}

int main(void)
{
    fast_io();
    get_solution();
}
