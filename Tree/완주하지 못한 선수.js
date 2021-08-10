function solution(participant, completion) {
    const m = new Map();
    
    for ( const name of participant ) {
        if(!m.get(name)){
            m.set(name, 1);
        } else {
            m.set(name, m.get(name) + 1);   
        }
    }
    
    for ( const name of completion) {
        if (m.get(name)){
            m.set(name, m.get(name) - 1);
        }
    }
    
    let answer = "";
    for ( const name of participant) {
        if (m.get(name) >= 1) {
            answer = name;
            break;
        }
    }
    
    return answer;
}