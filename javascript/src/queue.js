export class Queue {
  constructor(size) {
    this.data = {};
    this.size = size;
    this.front = 0;
    this.rear = 0;
    this.count = 0;
  }

  enqueue(item) {
    if (this.isFull()) {
      throw Error('Queue is full');
    }
    this.data[this.rear] = item;
    this.rear = (this.rear + 1) % this.size;
    this.count++;
  }

  dequeue() {
    if (this.isEmpty()) {
      throw Error('Queue is empty');
    }
    const item = this.data[this.front];
    delete this.data[this.front];
    this.front = (this.front + 1) % this.size;
    this.count--;
    return item;
  }

  isEmpty() {
    return this.count === 0;
  }

  isFull() {
    return this.count === this.size;
  }
}