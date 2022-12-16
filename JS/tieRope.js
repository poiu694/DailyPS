// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(K, A) {
    // write your code in JavaScript (Node.js 14)
    let answer = 0;
    let sum = 0;

    for (let i=0; i<A.length; i++) {
        sum += A[i];
        if (sum >= K) {
            answer++;
            sum = 0;
        }
    }
    return answer;
}
