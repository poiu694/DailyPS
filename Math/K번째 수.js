function solution(array, commands) {
    let answer = [];
    
    for (const command of commands){
        const number = array.slice(command[0]-1, command[1])
                        .sort((a,b) => a-b)[command[2] - 1];
        answer.push(number);
    }
    return answer;
}