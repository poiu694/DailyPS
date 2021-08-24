#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    stack<int> basket;
    vector<int> idxs(board.size(), -1);

    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board.size(); j++)
            if (idxs[j] == -1 and board[i][j] != 0)
                idxs[j] = i;

    for (int move : moves)
    {
        int topOflane = board[idxs[move - 1]][move - 1];
        idxs[move - 1] = idxs[move - 1] + 1 >= board.size() ? 0 : idxs[move - 1] + 1;
        if (topOflane == 0)
            continue;
        else if (!basket.empty() and basket.top() == topOflane)
        {
            basket.pop();
            answer += 2;
        }
        else
            basket.push(topOflane);
    }

    return answer;
}