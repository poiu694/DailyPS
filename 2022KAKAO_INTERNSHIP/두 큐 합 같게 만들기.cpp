#include <string>
#include <vector>
#include <queue>

using namespace std;
using ull = unsigned long long;

int getSum(vector<int> q) {
    int sum;
    
    sum = 0;
    for (int v: q) sum += v;
    return (sum);
}

int getMinCountOfSolution(vector<int> &v1, vector<int> &v2) {
    deque<int>  q1(v1.begin(), v1.begin() + v1.size());
    deque<int>  q2(v2.begin(), v2.begin() + v2.size());
    ull         q1Sum;
    ull         q2Sum;
    ull         val;
    ull         count;
    ull         size;
    
    size = v1.size() + v2.size();
    q1Sum = getSum(v1);
    q2Sum = getSum(v2);
    count = 0;
    while (!q1.empty() && !q2.empty()) {
        if (count >= 4 * size)
            return (-1);
        if (q1Sum == q2Sum) {
            break;
        } else if (q1Sum > q2Sum) {
            val = q1.front();
            q1.pop_front();
            q2.push_back(val);
            q1Sum -= val;
            q2Sum += val;
        } else {
            val = q2.front();
            q2.pop_front();
            q1.push_back(val);
            q2Sum -= val;
            q1Sum += val;
        }
        count++;
    }
    if (q1.empty() || q2.empty()) {
        return (-1);
    }
    return (count);
}

int solution(vector<int> q1, vector<int> q2) {
    int answer;

    answer = getMinCountOfSolution(q1, q2);
    return (answer);
}