/*
  In this implementation, the front of the queue is the first element.
  NOTE: This implementation is exactly like the stack except the push function
  has an item being added to the end of the array!
*/
class Queue {
  constructor() {
    this.queue = [];
  }
  push(item) {
    this.queue = [...this.queue, item];
  }
  pop() {
    return this.empty() ? undefined : this.queue.shift();
  }
  peek() {
    return this.empty() ? undefined : this.queue[0];
  }
  empty() { return this.queue.length === 0; }
}
