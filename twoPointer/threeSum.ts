const getSum = (a: number, b: number, c: number): number => {
  return a + b + c;
};

/**
 * 
 * if sort option is empty, sort '-4 -3 -2 -1, 1, 2' -> '-1 -2 -3 -4, 1, 2'
 * 
 * @param nums: number[]
 * @returns threeSumList: number[][]
  */
function threeSum(nums: number[]): number[][] {
  const threeSumList: number[][] = [];

  nums.sort((a, b) => a - b);
  for (let i = 0; i < nums.length; i++) {
    let l = i + 1;
    let r = nums.length - 1;

    if (i && nums[i - 1] === nums[i]) continue;
    while (l < r) {
      const sum = getSum(nums[i], nums[l], nums[r]);
      if (sum === 0) {
        threeSumList.push([nums[i], nums[l], nums[r]]);
        l++;
        r--;
        while (l < r && nums[l - 1] === nums[l]) l++;
      } else if (sum < 0) l++;
      else r--;
    }
  }
  return threeSumList;
}
