#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

vector<string> stringToWords(string query){
    vector<string> ret;
    
    stringstream ss(query);
    string buffer;
    while(getline(ss, buffer, ' ')){
        ret.push_back(buffer);
    }
    
    return ret;
}

int toDigit0(string query){
    if(query == "cpp"){
        return 1;
    }else if(query == "java"){
        return 2;
    }else if(query == "python"){
        return 3;
    }
    return 0;
}

int toDigit1(string query){
    if(query == "backend"){
        return 1;
    }else if(query == "frontend"){
        return 2;
    }
    return 0;
}

int toDigit2(string query){
    if(query == "junior"){
        return 1;
    }else if(query == "senior"){
        return 2;
    }
    return 0;
}

int toDigit3(string query){
    if(query == "chicken"){
        return 1;
    }else if(query == "pizza"){
        return 2;
    }
    return 0;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    int list[108][100001] = {0, }; // 4*3*3*3진법 이용.
    
    for(string str : info){
        vector<string> inf = stringToWords(str);
        int index0 = toDigit0(inf[0]);
        int index1 = toDigit1(inf[1]);
        int index2 = toDigit2(inf[2]);
        int index3 = toDigit3(inf[3]);
        int score = stoi(inf[4]);
        for(int i : {0, index0}){
            for(int j : {0, index1}){
                for(int k : {0, index2}){
                    for(int l : {0, index3}){
                        int idx = i*27 + j*9 + k*3 + l;
                        list[idx][score]++;
                    }
                }
            }
        }
    }
    
    // prefix Sum
    for(int i=0; i<108; i++){
        for(int j=1; j<=100000; j++){
            list[i][j] += list[i][j-1];
        }
    }
    
    for(string str : query){
        vector<string> qry = stringToWords(str);
        int index0 = toDigit0(qry[0]);
        int index1 = toDigit1(qry[2]);
        int index2 = toDigit2(qry[4]);
        int index3 = toDigit3(qry[6]);
        
        int idx = index0 * 27 + index1 * 9 + index2 * 3 + index3;
        int score = stoi(qry[7]);
        answer.push_back(list[idx][100000] - list[idx][score-1]);
    }
    
    return answer;
}