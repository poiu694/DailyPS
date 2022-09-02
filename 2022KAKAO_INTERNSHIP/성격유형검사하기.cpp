#include <string>
#include <vector>

using namespace std;

string getFinalType(vector<int> scores) {
    string  type;
    
    type = "";
    type += scores[0] >= 0 ? "R" : "T";
    type += scores[1] >= 0 ? "C" : "F";
    type += scores[2] >= 0 ? "J" : "M";
    type += scores[3] >= 0 ? "A" : "N";
    return (type);
}

int getIndexByCandidate(string candidates) {
    if (candidates.find("R") != std::string::npos)
        return (candidates.find("R"));
    if (candidates.find("C") != std::string::npos)
        return (2 + candidates.find("C"));
    if (candidates.find("J") != std::string::npos)
        return (4 + candidates.find("J"));
    if (candidates.find("A") != std::string::npos)
        return (6 + candidates.find("A"));
    return (-1);
}

string solution(vector<string> survey, vector<int> choices) {
    int         sign;
    int         typeIndex;
    string      candidates;
    vector<int> scores(4);
    
    for (int idx = 0; idx < survey.size(); idx++) {
        candidates = survey[idx];
        typeIndex = getIndexByCandidate(candidates);
        sign = typeIndex % 2 == 0 ? 1 : -1;
        scores[typeIndex / 2] += (4 - choices[idx]) * sign;
    }
    return getFinalType(scores);
}