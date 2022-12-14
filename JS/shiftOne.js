// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function shiftOne(A) {
  if (A.length > 0) {
    const temp = A.pop();
    A.unshift(temp);
  }
  return A;
}

function solution(A, K) {
  // write your code in JavaScript (Node.js 14)
  while (A.length > 0 && K--) {
    A = shiftOne(A);
  }
  return A;
}
