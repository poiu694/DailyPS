#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

bool    is_pow_of_2(int num)
{
    if (num == 0)
        return false;
 
    return (ceil(log2(num)) == floor(log2(num)));
}

bool    is_tree(string target, int st, int ed)
{
    int mid = floor((st + ed) / 2);
    
    // cout << "S : " << target << " " << st << " " << ed << '\n';
    if (ed - st <= 1 || target.length() <= mid) // leaf Node는 항상 true
        return (true);
    if (target[mid] == '0')
    {
        // 가운데가 비어있으면서 양 옆에 1이 하나라도 있으면 실패
        if (target.substr(0, mid).find_first_of("1") != string::npos)
            return (false);
        if (target.substr(mid + 1, ed).find_first_of("1") != string::npos)
            return (false);
        // cout << target.substr(mid + 1, ed) << '\n';
        return (true);
    }
    // 가운데에 1이 있으면 분할해서 확인해야 한다.
    bool left = is_tree(target.substr(0, mid), 0, mid);
    bool right = is_tree(target.substr(mid + 1, ed), 0, mid);
    
    return (left && right);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (auto number: numbers)
    {
        bitset<128>  bitsets(number);
        string  bits = bitsets.to_string();
        bits = bits.substr(bits.find_first_of("1"), bits.length() - 1);
        while (!is_pow_of_2(bits.length() + 1))
            bits = "0" + bits;    
        // cout << "T : " << bits << '\n';
        if (bits.length())
            answer.push_back(is_tree(bits, 0, bits.length() - 1) ? 1 : 0);    
        else
            answer.push_back(0);
    }
    return answer;
}