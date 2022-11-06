#ifndef __STACK_H__
#define __STACK_H__

#include <vector>

template <typename T>
class Stack
{
  std::vector<T> mem;
  size_t sz; // кол-во элементов
public:
  Stack() 
  {
    sz = 0;
  }
  Stack(size_t size) : Stack() 
  {
    mem.reserve(size);
  }
  Stack(size_t size, const T* arr) : Stack(size) 
  {
    for (int i = 0; i < size; i++)
      mem.push_back(arr[i]);
    sz = size;
  }

  size_t size() const noexcept
  {
    return sz;
  }
  bool empty() 
  {
    return sz == 0;
  }

  void push(const T& x) 
  {
    mem.push_back(x);
    sz++;
  }
  T top() 
  {
    if(empty())
      throw std::out_of_range("Stack is empty");
    return mem[sz - 1];
  }
  void pop() 
  {
    if (empty())
      throw std::out_of_range("Stack is empty");
    mem.pop_back();
    sz--;
  }

  bool operator==(const Stack& st) 
  {
    if (this == &st)
      return true;
    return st.mem == mem;
  }
};

#endif
