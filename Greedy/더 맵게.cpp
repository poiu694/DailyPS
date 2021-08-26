#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
  priority_queue<int> pq;
  for (int sc : scoville)
    pq.push(-sc);

  int answer = 0;
  while (pq.size() >= 2)
  {
    if (-pq.top() >= K)
      break;
    int a = -pq.top();
    pq.pop();
    int b = -pq.top();
    pq.pop();

    answer++;
    pq.push(-(a + (2 * b)));
  }
  if (!pq.empty() and -pq.top() < K)
    return -1;
  return answer;
}