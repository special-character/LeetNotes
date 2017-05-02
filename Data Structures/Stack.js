/*
  In this implementation, the top of the stack is the first element.
  I chose this option so I didn't have to pull off of this.stack[this.stack.length - 1]

  NOTE: This implementation is exactly like the queue except the push function
  has an item being added to the beginning of the array!
*/
exprt default class Stack {
  constructor() {
    this.stack = [];
  }
  push(item) {
    this.stack = [item, ...this.stack];
  }
  pop() {
    return this.empty() ? undefined : this.stack.shift();
  }
  peek() {
    return this.empty() ? undefined : this.stack[0];
  }
  empty() { return this.stack.length === 0; }
}
