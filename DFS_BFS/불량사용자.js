// var answer;
var ban_case = [];

function solution(user_id, banned_id) {
    dfs(user_id, banned_id, []);
    const answer = Array.from(new Set(ban_case.map((v) => v.sort().join('')))).length;
    return answer;
}

function isMatching(id, pattern) {
    pattern = pattern.replace(/\*/g, "."); // * -> '.'
    const regex = RegExp(`\^(${pattern})$`);
    return regex.test(id);
}

function dfs(user_id, banned_id, ban_list) {
    if(banned_id.length === 0) {
        ban_case.push(ban_list);
        return;
    }
    for (let i=0; i<user_id.length; i++) {
        const id = user_id[i];
        const pattern = banned_id[0];
        if (isMatching(id, pattern)) {
            dfs([...user_id.filter((v) => v !== id)], 
                    banned_id.slice(1), [...ban_list, id]);
        }
    }
}