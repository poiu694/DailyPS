function solution(_, heights) {
  let sum = 0;
  const leftStack = [];
  const rightStack = [];

  for (let i = 0; i < heights.length; i++) {
    while (
      leftStack.length !== 0 &&
      leftStack[leftStack.length - 1] < heights[i]
    ) {
      leftStack.pop();
    }
    sum += leftStack.length;

    if (leftStack[leftStack.length - 1] !== heights[i]) {
      leftStack.push(heights[i]);
    }
  }

  for (let i = heights.length - 1; i >= 0; i--) {
    while (
      rightStack.length !== 0 &&
      rightStack[rightStack.length - 1] < heights[i]
    ) {
      rightStack.pop();
    }
    sum += rightStack.length;

    if (rightStack[rightStack.length - 1] !== heights[i]) {
      rightStack.push(heights[i]);
    }
  }
  return sum;
}
