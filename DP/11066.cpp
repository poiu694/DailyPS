
    // #3
    for(int i=0; i<id.length(); i++){
        bool flag = false;
        
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
        id.substr(0, 15);
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
    