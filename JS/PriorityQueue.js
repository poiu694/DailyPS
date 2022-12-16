// MaxHeap을 구현한다.
class MaxHeap {
  constructor() {
    this.val = [];
  }

  insert(val) {
    this.val.push(val);
    this.bubbleUp();
  }

  bubbleUp() {
    let idx = this.val.length - 1;
    const element = this.val[idx];

    while (idx > 0) {
      let parentIdx = Math.floor((idx - 1) / 2);
      let parent = this.val[parentIdx];
      if (element <= parent) break;
      this.val[parentIdx] = element;
      this.val[idx] = parent;
      idx = parentIdx;
    }
  }

  pop() {
    if (!this.val.length) return undefined;
    const max = this.val[0];
    const end = this.val.pop();

    if (this.val.length > 0) {
      this.val[0] = end;
      this.sinkDown();
    }
    return max;
  }

  sinkDown() {
    let idx = 0;
    const element = this.val[0];

    while (true) {
      const leftIdx = idx * 2 + 1;
      const leftVal = this.val[leftIdx];
      const rightIdx = idx * 2 + 2;
      const rightVal = this.val[rightIdx];

      if (element < leftVal && element < rightVal) {
        const maxIdx = leftVal > rightVal ? leftIdx : rightIdx;
        this.val[idx] = this.val[maxIdx];
        this.val[maxIdx] = element;
        idx = maxIdx;
      } else if (element < leftVal) {
        this.val[idx] = leftVal;
        this.val[leftIdx] = element;
        idx = leftIdx;
      } else if (element < rightVal) {
        this.val[idx] = rightVal;
        this.val[rightIdx] = element;
        idx = rightIdx;
      } else {
        break;
      }
    }
  }
}
