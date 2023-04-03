#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int get_score(int pick, string mineral)
{
    int ret;
    
    if (pick == 0)
    {
        ret = 1;
    }
    else if (pick == 1)
    {
        ret = mineral == "diamond" ? 5 : 1;
    }
    else
    {
        ret = mineral == "diamond" ? 25 : mineral == "iron" ? 5 : 1;
    }
    return (ret);
}

int solution(vector<int> picks, vector<string> minerals) {    
    int answer = 0;
    priority_queue<pii> pq, pq2;
    vector<int> list;
    
    int index = 0;
    while (index < minerals.size())
    {
        int sum = 0;
        for (int cnt=0; cnt<5 && index<minerals.size(); cnt++, index++)
        {
            sum += get_score(2, minerals[index]);
        }
        pq.push({ sum, (index - 1) / 5});
    }
    int pickIndex = 0;
    while (!picks[pickIndex])
    {
        pickIndex++;
    }
    while (!pq.empty() && pickIndex < picks.size())
    {
        int index = pq.top().second;
        // cout << pq.top().first << " " << pq.top().second << '\n';
        pq.pop();
        
        pq2.push({-index, pickIndex});
        if (pickIndex >= 0) picks[pickIndex]--;
        while (pickIndex >= 0 && !picks[pickIndex] && pickIndex < picks.size())
        {
            pickIndex++;
        }
        
    }
    while (!pq2.empty())
    {
        // cout << -pq2.top().first << " " << pq2.top().second << '\n';
        list.push_back(pq2.top().second);
        pq2.pop();
    }
    index = 0;
    int listIndex = 0;
    while (index < minerals.size() && listIndex < list.size())
    {
        int sum = 0;
        for (int cnt=0; cnt<5 && index<minerals.size(); cnt++, index++)
        {
            sum += get_score((list[listIndex] == -1) ? 2 : list[listIndex], minerals[index]);
        }
        listIndex++;
        answer += sum;
    }
    return answer;
}