function solution(lottos, win_nums) {
    // correct_cnt = 맞춘 숫자의 갯수
    // zero_cnt = 0의 갯수
    // 최고 등수 : correct_cnt + zero_cnt
    // 최저 등수 : correct_cnt
    let correct_cnt = 0;
    lottos.forEach(lotto => {
        const index = win_nums.indexOf(lotto);
        if(index !== -1){
            correct_cnt++;
        }
    });
    const zero_cnt = lottos.filter(lotto => lotto === 0).length;
    
    const rank = [6, 6, 5, 4, 3, 2, 1];
    const answer = [rank[zero_cnt + correct_cnt], rank[correct_cnt]];
    
    return answer;
}