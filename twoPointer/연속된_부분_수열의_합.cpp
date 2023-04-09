#include <string>
#include <vector>
#include <iostream>

using namespace std;
using pii = pair<int, int>;

vector<int> solution(vector<int> sequence, int k) {
    int l, r;
    vector<int> answer;
    vector<pii> list;
    
    l = 0; r = 0;
    int sum = sequence[0];
    while (r < sequence.size())
    {
        if (sum == k)
        {
            list.push_back({ l, r });
            sum -= sequence[l];
            l++;
        }
        else if (sum < k)
        {
            r++;
            sum += sequence[r];
        }
        else
        {
            sum -= sequence[l];
            l++;
        }
    }
    int minLength = 1000001;
    int minIndex = -1;
    for (int i=0; i<list.size(); i++)
    {
        pii item = list[i];
        if (minLength > item.second - item.first)
        {
            minLength = item.second - item.first;
            minIndex = i;
        }
    }
    return { list[minIndex].first, list[minIndex].second };
}