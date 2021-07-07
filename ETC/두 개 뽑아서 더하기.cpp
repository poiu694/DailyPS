#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;

    vector<bool> f(numbers.size(), false);
    f[0] = true;
    f[1] = true;

    do
    {
        int sum = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (f[i])
                sum += numbers[i];
        }

        answer.push_back(sum);
    } while (prev_permutation(f.begin(), f.end()));

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}