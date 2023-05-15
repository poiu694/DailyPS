#define SIZE 9

class Solution {
private:
    set<char>    s;    
public:
    bool    checkZone(vector<vector<char>> &board, int sx, int sy)
    {
        s.clear();

        for (int i = sx; i < sx + 3; i++)
        {
            for (int j = sy; j < sy + 3; j++)
            {
                if (board[i][j] != '.' && s.find(board[i][j]) != s.end())
                {
                    return (false);
                }
                s.insert(board[i][j]);
            }
        }
        return (true);    
    }

    bool    checkVertical(vector<vector<char>> &board, int index)
    {
        s.clear();

        for (int i=0; i<SIZE; i++)
        {
            if (board[index][i] != '.' && s.find(board[index][i]) != s.end())
            {
                return (false);
            }
            s.insert(board[index][i]);
        }
        return (true);
    }

    bool    checkHorizon(vector<vector<char>> &board, int index)
    {
        s.clear();

        for (int i=0; i<SIZE; i++)
        {
            if (board[i][index] != '.' && s.find(board[i][index]) != s.end())
            {
                return (false);
            }
            s.insert(board[i][index]);
        }
        return (true);
    }

    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (int i=0; i<SIZE; i++)
        {
            if (!checkVertical(board, i) || !checkHorizon(board, i))
            {
                return (false);
            }    
        }
        for (int sx=0; sx<SIZE; sx+=3)
        {
            for (int sy=0; sy<SIZE; sy+=3)
            {
                if (!checkZone(board, sx, sy))
                {
                    return (false);
                }
            }
        }
        return (true);
    }
};