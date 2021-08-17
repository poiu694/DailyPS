function solution(record) {
    const users = record.reduce((acc, v, i) => {
        const [op, user, name] = v.split(' ');
        acc[user] = name === undefined ? acc[user] : name;
        return acc;
    }, {});
    
    const string_list = record.map((_record) => {
        const [op, user, name] = _record.split(' ');
        if (op === "Enter") return `${users[user]}님이 들어왔습니다.`
        else if (op === "Leave") return `${users[user]}님이 나갔습니다.`
        else return undefined
    });
    
    const answer = string_list.filter((v) => v !== undefined);
    return answer;
}