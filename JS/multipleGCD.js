function GCD(a, b) {
  if (b == 0) return a;
  else return GCD(b, a % b);
}

function getGCDofArray(array) {
  let result = array[0];

  for (let i = 1; i < array.length; i++) {
    result = GCD(result, array[i]);
  }
  return result;
}

function isCanDivideArrayByNumber(array, num) {
  let flag = true;

  for (let i = 0; i < array.length; i++) {
    if (array[i] % num === 0) {
      flag = false;
      break;
    }
  }
  return flag;
}

function solution(arrayA, arrayB) {
  const GCDOfA = getGCDofArray(arrayA);
  const GCDOfB = getGCDofArray(arrayB);

  const flag1 = isCanDivideArrayByNumber(arrayA, GCDOfB);
  const flag2 = isCanDivideArrayByNumber(arrayB, GCDOfA);
  if (flag1 && flag2) {
    return Math.max(GCDOfB, GCDOfA);
  } else if (flag1) {
    return GCDOfB;
  } else if (flag2) {
    return GCDOfA;
  }
  return 0;
}
