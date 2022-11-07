#include <gtest.h>
#include "postfix.h"

TEST(ArithmeticExpression, can_create_postfix)
{
  string str = "a+b";
  ASSERT_NO_THROW(ArithmeticExpression expression(str));
}
TEST(ArithmeticExpression, can_get_infix)
{
  ArithmeticExpression expression("a+b*c-d");
  EXPECT_EQ("a+b*c-d", expression.getInfix());
}
TEST(ArithmeticExpression, can_get_postfix_equal_priority)
{
  ArithmeticExpression expression("a+b - c      - d");
  EXPECT_EQ("ab+c-d-", expression.getPostfix());
}
TEST(ArithmeticExpression, can_get_postfix_different_priority)
{
  ArithmeticExpression expression("  a+b*c -  e  - d*e");
  EXPECT_EQ("abc*+e-de*-", expression.getPostfix());
}
TEST(ArithmeticExpression, can_get_postfix_brackets)
{
  ArithmeticExpression expression("  a+b*(c -  e)  - d*e + (f+g*(j-i))");
  EXPECT_EQ("abce-*+de*-fgji-*++", expression.getPostfix());
}
TEST(ArithmeticExpression, can_calculate_addition)
{
    ArithmeticExpression expression(" a + b + (c + d)");
    istringstream values("1 2 3 4");
    ostream nowhere(nullptr);

    double result = expression.Calculate(values, nowhere);
    double expected = 1 + 2 + (3 + 4);

    EXPECT_EQ(expected, result);
}
TEST(ArithmeticExpression, can_calculate_addition_repeated_values)
{
    ArithmeticExpression expression(" a + b + (b + a) + a + a");
    istringstream values("1 2");
    ostream nowhere(nullptr);

    double result = expression.Calculate(values, nowhere);
    double expected = 1 + 2 + (2 + 1) + 1 + 1;

    EXPECT_EQ(expected, result);
}
TEST(ArithmeticExpression, can_calculate_subtraction)
{
    ArithmeticExpression expression(" a - b - (c - d)");
    istringstream values("1 2 3 4");
    ostream nowhere(nullptr);

    double result = expression.Calculate(values, nowhere);
    double expected = 1 - 2 - (3 - 4);

    EXPECT_EQ(expected, result);
}
TEST(ArithmeticExpression, can_calculate_subtraction_repeated_values)
{
    ArithmeticExpression expression(" a - b - (b - a) - a - a");
    istringstream values("1 2");
    ostream nowhere(nullptr);

    double result = expression.Calculate(values, nowhere);
    double expected = 1 - 2 - (2 - 1) - 1 - 1;

    EXPECT_EQ(expected, result);
}
TEST(ArithmeticExpression, can_calculate_multiplication)
{
    ArithmeticExpression expression(" a * b * (c * d)");
    istringstream values("1 2 3 4");
    ostream nowhere(nullptr);

    double result = expression.Calculate(values, nowhere);
    double expected = 1 * 2 * (3 * 4);

    EXPECT_EQ(expected, result);
}
TEST(ArithmeticExpression, can_calculate_multiplication_repeated_values)
{
    ArithmeticExpression expression(" a * b * (b * a) * a * a");
    istringstream values("2 3");
    ostream nowhere(nullptr);

    double result = expression.Calculate(values, nowhere);
    double expected = 2 * 3 * (3 * 2) * 2 * 2;

    EXPECT_EQ(expected, result);
}
TEST(ArithmeticExpression, can_calculate_division)
{
    ArithmeticExpression expression(" a / b / (c / d)");
    istringstream values("1 2 3 4");
    ostream nowhere(nullptr);

    double result = expression.Calculate(values, nowhere);
    double expected = 1.0 / 2.0 / (3.0 / 4.0);

    EXPECT_EQ(expected, result);
}
TEST(ArithmeticExpression, can_calculate_division_repeated_values)
{
    ArithmeticExpression expression(" a / b / (b / a) / a / a");
    istringstream values("2 3");
    ostream nowhere(nullptr);

    double result = expression.Calculate(values, nowhere);
    double expected = 2.0 / 3.0 / (3.0 / 2.0) / 2.0 / 2.0;

    EXPECT_EQ(expected, result);
}
TEST(ArithmeticExpression, can_calculate)
{
    ArithmeticExpression expression(" a / b - (c / d) * e + f - g*g) / (a + b)");
    istringstream values("1 2 3 4 5 6 7");
    ostream nowhere(nullptr);

    double result = expression.Calculate(values, nowhere);
    double expected = (1.0 / 2.0 - (3.0 / 4.0) * 5.0 + 0.6 - 0.7*0.7) / (0.1 + 0.2);

    EXPECT_EQ(expected, result);
}
