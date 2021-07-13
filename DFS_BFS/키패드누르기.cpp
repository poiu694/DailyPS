#include <string>
#include <vector>

using namespace std;

string answer = "";

int calculateDist(int mid, int a)
{
    if (mid == a)
        return 0;
    if (mid == 2)
    {
        if (a == 1 || a == 3 || a == 5)
            return 1;
        if (a == 4 || a == 6 || a == 8)
            return 2;
        if (a == 7 || a == 9 || a == 0)
            return 3;
        if (a == 11 || a == 12)
            return 4;
    }
    else if (mid == 5)
    {
        if (a == 1 || a == 3)
            return 2;
        if (a == 4 || a == 6 || a == 2 || a == 8)
            return 1;
        if (a == 7 || a == 9 || a == 0)
            return 2;
        if (a == 11 || a == 12)
            return 3;
    }
    else if (mid == 8)
    {
        if (a == 1 || a == 3)
            return 3;
        if (a == 4 || a == 6 || a == 2)
            return 2;
        if (a == 7 || a == 9 || a == 5 || a == 0)
            return 1;
        if (a == 11 || a == 12)
            return 2;
    }
    else if (mid == 0)
    {
        if (a == 1 || a == 3)
            return 4;
        if (a == 4 || a == 6 || a == 2)
            return 3;
        if (a == 7 || a == 9 || a == 5)
            return 2;
        if (a == 11 || a == 12 || a == 8)
            return 1;
    }
}

void dfs(vector<int> numbers, string hand, int i, int pastLeft, int pastRight)
{
    if (i == numbers.size())
        return;

    if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
    {
        answer += "L";
        pastLeft = numbers[i];
    }
    else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
    {
        answer += "R";
        pastRight = numbers[i];
    }
    else
    {
        int mid = numbers[i];
        int leftDist = calculateDist(mid, pastLeft);
        int rightDist = calculateDist(mid, pastRight);
        if (leftDist > rightDist)
        {
            answer += "R";
            pastRight = mid;
        }
        else if (leftDist < rightDist)
        {
            answer += "L";
            pastLeft = mid;
        }
        else
        {
            if (hand == "left")
            {
                answer += "L";
                pastLeft = mid;
            }
            else
            {
                answer += "R";
                pastRight = mid;
            }
        }
    }
    dfs(numbers, hand, i + 1, pastLeft, pastRight);
}

string solution(vector<int> numbers, string hand)
{
    dfs(numbers, hand, 0, 11, 12);
    return answer;
}