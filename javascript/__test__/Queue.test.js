const Queue = require('../src/Queue');

describe('Queue 자료구조 테스트', () => {
  let q;
  const SIZE = 3;

  beforeEach(() => {
    q = new Queue(SIZE);
  });

  test('초기 상태에서는 비어 있어야 한다.', () => {
    expect(q.isEmpty()).toBe(true);
    expect(q.isFull()).toBe(false);
  });
})