#include <gtest.h>
#include "postfix.h"

TEST(ABOBA, add)
{
    ArithmeticExpression expression("1+3+2+4");
    ostream nowhere(nullptr);

    double result = expression.Calculate(nowhere);
    double expected = (1+3+2+4);

    EXPECT_EQ(expected, result);
}
TEST(ABOBA, sub)
{
    ArithmeticExpression expression("1+3-2-4");
    ostream nowhere(nullptr);

    double result = expression.Calculate(nowhere);
    double expected = (1+3-2-4);

    EXPECT_EQ(expected, result);
}
TEST(ABOBA, mult)
{
    ArithmeticExpression expression("1*2*3*4*5");
    ostream nowhere(nullptr);

    double result = expression.Calculate(nowhere);
    double expected = (1*2*3*4*5);

    EXPECT_EQ(expected, result);
}
TEST(ABOBA, div)
{
    ArithmeticExpression expression("101/5");
    ostream nowhere(nullptr);

    double result = expression.Calculate(nowhere);
    double expected = (101/5);

    EXPECT_EQ(expected, result);
}
TEST(ABOBA, all_operations)
{
    ArithmeticExpression expression("1*2*3-101%5+101/5");
    ostream nowhere(nullptr);

    double result = expression.Calculate(nowhere);
    double expected = (1*2*3 - 101%5 + 101/5);

    EXPECT_EQ(expected, result);
}
TEST(ABOBA, all_operations_with_spaces)
{
    ArithmeticExpression expression("1*2*3 - 101%5 + 101/5");
    ostream nowhere(nullptr);

    double result = expression.Calculate(nowhere);
    double expected = (1*2*3 - 101%5 + 101/5);

    EXPECT_EQ(expected, result);
}
TEST(ABOBA, all_operations_lots_of_spaces)
{
    ArithmeticExpression expression("10     % 7    -   7  *  2  +     1*2*3 - 101%5 + 101 / 5");
    ostream nowhere(nullptr);

    double result = expression.Calculate(nowhere);
    double expected = (10%7 - 7*2 + 1*2*3 - 101%5 + 101/5);

    EXPECT_EQ(expected, result);
}
TEST(ABOBA, long_integers)
{
    ArithmeticExpression expression("1000000000000000001 % 678436475849 + 21000000*47364837 - 1000000000000000003 / 670006475849");
    ostream nowhere(nullptr);

    double result = expression.Calculate(nowhere);
    double expected = (1000000000000000001ll % 678436475849ll + 21000000ll*47364837ll - 1000000000000000003ll / 670006475849ll);

    EXPECT_EQ(expected, result);
}
TEST(ABOBA, with_brackets)
{
    ArithmeticExpression expression("1*(2 - 37 % (129 / 4))*3 - (101 - (2 - 3)) % 5 + 101/5");
    ostream nowhere(nullptr);

    double result = expression.Calculate(nowhere);
    double expected = (1*(2 - 37 % (129 / 4))*3 - (101 - (2 - 3)) % 5 + 101/5);

    EXPECT_EQ(expected, result);
}