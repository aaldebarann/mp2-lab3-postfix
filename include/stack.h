#ifndef __STACK_H__
#define __STACK_H__

#include <vector>
using namespace std;

template <typename T>
class Stack
{
  vector<T> mem;
  size_t sz; // кол-во элементов
public:
  Stack() {
    sz = 0;
  }
  Stack(size_t size) : Stack() {
    mem.reserve(size);
  }
  Stack(size_t size, const T* arr) : Stack(size) {
    for (int i = 0; i < size; i++)
      mem.push_back(arr[i]);
    sz = size;
  }
  Stack(const Stack& st) : Stack(st.size(), &st.mem[0]) {
  }

  size_t size() const noexcept {
    return sz;
  }
  bool empty() {
    return sz == 0;
  }

  void push(const T& x) {
    mem.push_back(x);
    sz++;
  }
  T top() noexcept {
    return mem[sz - 1];
  }
  void pop() {
    if (empty())
      throw out_of_range("Stack is empty");
    mem.pop_back();
    sz--;
  }

  bool operator==(const Stack& st) {
    if (this == &st)
      return true;
    return st.mem == mem;
  }
};

#endif
