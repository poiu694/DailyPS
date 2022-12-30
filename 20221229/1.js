function solution(progresses, speeds) {
  let leftSum = progresses[0];
  let rightSum = 0;
  for (let i = 2; i < progresses.length; i++) {
    rightSum += progresses[i];
  }
  for (let pivot = 1; pivot < progresses.length - 1; pivot++) {
    if (leftSum === rightSum) {
      return [pivot];
    }
    leftSum += progresses[pivot];
    rightSum -= progresses[pivot + 1];
  }
  return [-1];
}
