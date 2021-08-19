function solution(priorities, location) {
    var cnt = 1;
    
    while(priorities.length !== 0) {
        const mx = Math.max(...priorities); // find Max
        const front = priorities.shift();
        if(mx === front) { // pop Front
            if(location === 0) {
                return cnt;
            } else {
                cnt++;
                location = location - 1; // location cant negative
            }
        } else { // go Backward
            priorities.push(front);
            location = location - 1 < 0 ? priorities.length - 1 : location - 1;
        }
    }

    return 1;
}