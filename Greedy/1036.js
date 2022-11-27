const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const inputs = [];
readline
  .on('line', function (line) {
    inputs.push(line);
  })
  .on('close', function () {
    const N = parseInt(inputs[0]);
    const K = parseInt(inputs[N + 1]);
    const stringList = [];
    for (let i = 1; i <= N; i++) {
      stringList.push(inputs[i]);
    }
    solution(N, stringList, K);
    process.exit();
  });

//  36진수 string to 10진수 BigInt
function convert36to10fromChar(val) {
  return BigInt(parseInt(val, 36).toString(10));
}

//  36진수 string to 10진수 BigInt (입력값이 number 범위보다 클 때)
function convert36to10fromString(val) {
  let result = BigInt(0);

  for (let i = val.length - 1; i >= 0; i--) {
    if (i === val.length - 1) {
      result += convert36to10fromChar(val.charAt(i));
    } else {
      result +=
        convert36to10fromChar(val.charAt(i)) *
          BigInt((36).toString()) ** BigInt((val.length - 1 - i).toString());
    }
  }

  return result;
};

//  메인 솔루션 함수
const solution = (N, inputList, K) => {


  const replacedInputListWithZ = inputList.map((input) => {
    return input.split('').map((word) => word).join('');
  })
  const result = replacedInputListWithZ.reduce((acc, input) => {
    return acc += convert36to10fromString(input)
  }, BigInt(0));

  console.log(result.toString(36).toUpperCase());
};
