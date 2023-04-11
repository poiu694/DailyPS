#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

// A - 1, 2
// B - 1
// C - 1, 2
// D - 1, 2
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, vector<string>> m;
    map<string, vector<string>>::iterator   it;
    
    for (vector<string> cloth: clothes)
        m[cloth[1]].push_back(cloth[0]);
    for (it=m.begin(); it!=m.end(); it++)
        answer *= (it->second.size() + 1);
    return answer - 1;
}