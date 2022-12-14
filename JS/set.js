// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(A) {
  // write your code in JavaScript (Node.js 14)
  const set = new Set();

  for (let i = 0; i < A.length; i++) {
    if (set.has(A[i])) {
      set.delete(A[i]);
    } else {
      set.add(A[i]);
    }
  }
  const item = set.keys().next().value;

  return item;
}
