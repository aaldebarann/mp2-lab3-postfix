#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(Stack<int> st(5));
}
TEST(Stack, throws_when_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(Stack<int> st(-4));
}
TEST(Stack, new_stack_is_empty)
{
  Stack<int> st(4);
  EXPECT_EQ(0, st.size());
}
TEST(Stack, throws_when_top_empty_stack)
{
  Stack<int> st(4);
  ASSERT_ANY_THROW(st.top());
}
TEST(Stack, throws_when_pop_empty_stack)
{
  Stack<int> st(4);
  ASSERT_ANY_THROW(st.pop());
}
TEST(Stack, can_push_and_top)
{
  Stack<int> st;
  st.push(4);
  EXPECT_EQ(4, st.top());
}
TEST(Stack, can_push_top_pop)
{
  Stack<int> st;
  st.push(4);
  st.push(2);
  st.push(-4);

  EXPECT_EQ(-4, st.top());
  st.pop();
  EXPECT_EQ(2, st.top());
  st.pop();
  EXPECT_EQ(4, st.top());
}
TEST(Stack, compare_equal_stacks)
{
  Stack<int> st1, st2;
  st1.push(2);
  st1.push(4);

  st2.push(2);
  st2.push(4);

  EXPECT_TRUE(st1 == st2);
}
