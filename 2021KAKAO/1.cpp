#include <string>
#include <algorithm>

using namespace std;

string newId(string past){
    string id = past;
    // #1 toLowwerCase
    transform(id.begin(), id.end(), id.begin(), ::tolower);
    
    // #2
    string temp;
    for(int i=0; i<id.length(); i++){
        if('a' <= id[i] && id[i] <= 'z') temp += id[i];
        if('0' <= id[i] && id[i] <= '9') temp += id[i];
        if(id[i] == '-' || id[i] == '_' || id[i] == '.') temp += id[i];            
    }
    id = temp;
    
    // #3
    bool flag = false;
    for(int i=0; i<id.length(); i++){        
        if(flag){
            if(id[i] == '.'){
                id.erase(i,1);
                i = i-2;
            }
            flag = false;
        }
        
        if(id[i] == '.'){
            flag = true;
        }
    }
    
    // #4
    for(int i=0; i<id.length(); i++){
        if(id.front() == '.'){
            id.erase(0,1);
        }else if(id.back() == '.'){
            id.pop_back();
        }
    }
    
    //#5
    if(id.empty()){
        id = "a";
    }
    
    // #6
    if(id.length() >= 16){
        id = id.substr(0, 15);
        for(int i=0; i<id.length(); i++){
            if(id.back() == '.'){
                id.pop_back();
            }
        }
    }
    
    // #7
    while(id.length() < 3){
        id.push_back(id.back());
    }
    
    
    return id;    
}

string solution(string new_id) {
    return newId(new_id);
}