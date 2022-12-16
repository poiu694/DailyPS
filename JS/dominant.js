// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(A) {
  // write your code in JavaScript (Node.js 14)
  const store = {};
  const halfSize = (A.length + 1) / 2;

  for (let i = 0; i < A.length; i++) {
    const number = A[i];

    if (number in store) {
      store[number] = store[number] + 1;
    } else {
      store[number] = 1;
    }
    if (store[number] >= halfSize) {
      return i;
    }
  }
  return -1;
}
