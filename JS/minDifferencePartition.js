// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(A) {
  // write your code in JavaScript (Node.js 14)
  let minSum;
  let sum1, sum2;

  sum1 = A[0];
  sum2 = A.reduce((acc, v) => acc + v, 0) - A[0];
  minSum = Math.abs(sum2 - sum1);
  for (let i = 1; i < A.length - 1; i++) {
    sum1 += A[i];
    sum2 -= A[i];
    minSum = Math.min(minSum, Math.abs(sum2 - sum1));
  }
  return minSum;
}
