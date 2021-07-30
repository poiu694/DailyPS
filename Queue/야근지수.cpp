#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works)
{
    priority_queue<int> pq;
    for (int work : works)
        pq.push(work);

    while (n-- and !pq.empty())
    {
        int work = pq.top();
        pq.pop();
        if (work - 1 != 0)
            pq.push(work - 1);
    }

    long long answer = 0;
    while (!pq.empty())
    {
        int work = pq.top();
        pq.pop();
        answer += work * work;
    }
    return answer;
}