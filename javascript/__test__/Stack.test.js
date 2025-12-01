const Stack = require('../src/Stack');

describe('Stack 자료구조 테스트', () => {
  let s;

  beforeEach(() => {
    s = new Stack();
  })

  test('초기의 스택은 비어있어야 함', () => {
    expect(s.isEmpty()).toBe(true);
  })

  test('FIFO 구조여야 함', () => {
    s.push(1);
    s.push(2);
    expect(s.pop()).toBe(2);
    expect(s.pop()).toBe(1);
  })

  test('peek을 하면 마지막 데이터를 확인함', () => {
    s.push(1);
    s.push(2);
    expect(s.peek()).toBe(2);
    expect(s.peek()).not.toBe(1);
  })
})