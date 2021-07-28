#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <iostream>

using namespace std;

list<int> lt; // list
list<int>::iterator its[1000001];
list<int>::iterator pt;
stack<pair<int, int>> memory;

string solution(int n, int k, vector<string> cmd)
{
    for (int i = 0; i < n; i++)
    {
        lt.push_back(i);
    }
    lt.push_back(n); // dummy
    auto it = lt.begin();
    for (int i = 0; i < n + 1; i++)
    {
        its[i] = it++;
    }
    pt = its[k];

    // CMD
    for (string command : cmd)
    {
        if (command[0] == 'D')
        {
            int x = stoi(command.substr(2));
            while (x--)
                pt++;
        }
        else if (command[0] == 'U')
        {
            int x = stoi(command.substr(2));
            while (x--)
                pt--;
        }
        else if (command[0] == 'C')
        {
            memory.push({*pt, *next(pt)});
            pt = lt.erase(pt);
            if (*pt == n)
                pt--;
        }
        else
        { // Z Case
            int now = memory.top().first;
            int next = memory.top().second;
            memory.pop();
            its[now] = lt.insert(its[next], now);
        }
    }

    string answer(n, 'X');
    for (auto x : lt)
    {
        if (x != n)
            answer[x] = 'O';
    }

    return answer;
}