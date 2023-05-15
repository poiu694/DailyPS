#include <vector>

using namespace std;

class Solution {
public:
    private:
        vector<int> list;
    public:

    bool    binarySearch(int target)
    {
        int left = 0;
        int right = this->list.size() - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (this->list[mid] > target)
            {
                right = mid - 1;
            }
            else if (this->list[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return (true);
            }
        }
        return (false);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        this->list.resize(matrix.size() * matrix[0].size());

        int index = 0;
        for (auto m: matrix)
            for (int a: m)
                this->list[index++] = a;
        return (this->binarySearch(target));
    }
};