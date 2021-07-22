#include <string>
#include <vector>
#include <limits.h>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;

    long long start = 0;
    long long end = (long long)times[times.size() - 1] * n;
    long long mid;
    while (start <= end)
    {
        mid = (start + end) / 2;

        long long sum = 0;
        for (int time : times)
        {
            sum += mid / time;
        }

        if (sum < n)
        {
            start = mid + 1;
        }
        else
        {
            if (mid <= end)
                answer = mid;
            end = mid - 1;
        }
    }
    return answer;
}