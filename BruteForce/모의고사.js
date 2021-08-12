function solution(answers) {
    const st1 = '12345'.split('');
    const st2 = '21232425'.split('');
    const st3 = '3311224455'.split('');
    
    const scores = [st1, st2, st3].map((st) => {
            return answers.filter((ans, i) => ans == st[i % st.length]).length;
        });
    
    return scores.reduce((acc, cur, idx) => {
        cur === Math.max(...scores) ? acc.push(idx+1) : acc;
        return acc;
    }, [])
}