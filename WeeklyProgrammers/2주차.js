function getRank(score) {
    if (score < 50) return "F";
    else if(score < 70) return "D";
    else if(score < 80) return "C";
    else if(score < 90) return "B";
    else return "A";
}

function solution(scores) {
    let answer = "";
    const len = scores.length;
    const scores_flat = scores.flat();
    const score_list = new Array(len).fill([]);
    
    scores_flat.forEach((score, idx) => score_list[idx % len] = [...score_list[idx % len], score]);
    
    score_list.map((score, idx) => {
        const max_score = Math.max(...score);
        const min_score = Math.min(...score);
        const self_score = score[idx];
        
        // flag : 같은 점수가 더 있으면 유일하지 않기에 true
        const max_flag = score.filter(s => s === max_score).length === 1 ? true : false;
        const min_flag = score.filter(s => s === min_score).length === 1 ? true : false;
        
        let divide = len;
        if ((max_score === self_score && max_flag) || 
                (min_score === self_score && min_flag)) {
            score.splice(idx, 1);
            divide--;
        }
        const score_mean = score.reduce((acc, cur) => acc + cur) / divide;
        answer += getRank(score_mean);
    });
    
    return answer;
}