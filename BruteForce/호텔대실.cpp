#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int wait_list[1001];

int get_miniute_time(string time)
{
    int result;
    
    result = stoi(time.substr(0, 2)) * 60;
    result += stoi(time.substr(3, 5));
    return (result);
}

bool    compare(vector<string> a, vector<string> b)
{
    return (get_miniute_time(a[1]) > get_miniute_time(b[1]));
}

int solution(vector<vector<string>> book_time) {
    int answer = 1;
    
    for (int i=0; i<1000; i++)
        wait_list[i] = 987654321;
    sort(book_time.begin(), book_time.end(), compare);
    
    for (vector<string> time: book_time)
    {
        bool    isEnter = false;
        int startTime = get_miniute_time(time[0]);
        int endTime = get_miniute_time(time[1]);
        
        for (int i=0; i<answer; i++)
        {
            if (wait_list[i] >= endTime + 10)
            {
                isEnter = true;
                wait_list[i] = startTime;
                break ;
            }
        }
        cout << '\n';
        if (!isEnter)
        {
            wait_list[answer++] = startTime;
        }
    }
    return answer;
}
