class Solution {
public:
    vector<int> list;
    vector<vector<int>>  result;

    void    go(vector<int> &candidates, int index, int sum, int target)
    {
        if (sum == target)
        {
            result.push_back(list);
            return ;
        }
        if (index == candidates.size())
        {
            return ;
        }
        if (sum > target)
        {
            return ;
        }
        list.push_back(candidates[index]);
        go(candidates, index, sum + candidates[index], target);
        list.pop_back();
        go(candidates, index + 1, sum, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        go(candidates, 0, 0, target);    
        return (result);
    }
};