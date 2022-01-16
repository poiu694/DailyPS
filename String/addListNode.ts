/**
 * Definition for singly-linked list.
 */
class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

const addListNode = (
  l1: ListNode | null,
  l2: ListNode | null
): ListNode | null => {
  const head: ListNode = new ListNode();
  let node: ListNode = head;
  let sum: number = 0;

  while (l1 || l2) {
    if (l1) {
      sum += l1.val;
      l1 = l1.next;
    }
    if (l2) {
      sum += l2.val;
      l2 = l2.next;
    }
    node.next = new ListNode(sum % 10, null);
    node = node.next;
    sum = sum >= 10 ? 1 : 0;
  }
  if (sum) {
    node.next = new ListNode(1, null);
  }
  return head.next;
};

function addTwoNumbers(
  l1: ListNode | null,
  l2: ListNode | null
): ListNode | null {
  const node = addListNode(l1, l2);
  return node;
}
