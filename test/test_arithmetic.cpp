

#include"../gtest/gtest.h"
#include"../include/arithmetic.h"

TEST(Aritmetic,can_return_correct_polish_entry)
{
    string str="129+11+92-147*11";
    Polish_entry obj(str);
    EXPECT_EQ("129.00000011.000000+92.000000+147.00000011.000000*-",obj.return_pol_str());
}

TEST(Aritmetic,can_calculate_the_result_1)
{
    string str="124+77+92";
    Polish_entry obj(str);
    EXPECT_EQ(true,293==obj.get_solution());
}
TEST(Aritmetic,throw_if_l_or_r_brick)
{
    string str="123+99+(77+22))";
    ASSERT_ANY_THROW(Polish_entry obj(str));
}

TEST(Aritmetic,throw_if_forbidden_symbol)
{
    string str="123+#";
    ASSERT_ANY_THROW(Polish_entry obj(str));
}

TEST(Aritmetic,can_calculate_the_result_2)
{
    string str="1+2-3^6";
    Polish_entry obj(str);
    EXPECT_EQ(-726,obj.get_solution());
}

TEST(Aritmetic,throw_when_two_operand_in_a_row)
{
    string str="127++99";
    ASSERT_ANY_THROW(Polish_entry obj(str));
}

TEST(Aritmetic,can_calculate_with_unary_minus)
{
    string str="-129+99";
    ASSERT_NO_THROW(Polish_entry obj(str));
    Polish_entry obj(str);
    EXPECT_EQ(-30,obj.get_solution());
}

TEST(Aritmetic,can_calculate_with_unary_minus_after_l_br)
{
    string str="9+3*(-18+11)";
    ASSERT_NO_THROW(Polish_entry obj(str));
    Polish_entry obj(str);
    EXPECT_EQ(-12,obj.get_solution());
}

TEST(Aritmetic, can_calculate_the_result_3)
{
    string str="(10+20)";
    Polish_entry obj(str);
    EXPECT_EQ(30,obj.get_solution());
}

TEST(Aritmetic,can_calculate_minus_after_bracket)
{
    string str="(-200+100)";
    Polish_entry obj(str);
    EXPECT_EQ(-100,obj.get_solution());
}

TEST(Aritmetic, can_calculate_with_two_pairs_of_brackets)
{
    string str="((10+20))";
    Polish_entry obj(str);
    EXPECT_EQ(30,obj.get_solution());
}

TEST(Aritmetic, can_calculate_exaltation)
{
    string str="10^10";
    Polish_entry obj(str);
    EXPECT_EQ(10000000000,obj.get_solution());
}

TEST(Aritmetic, can_calculate_exaltation_with_brackets)
{   
    string str="(10+15)^2";
    Polish_entry obj(str);
    EXPECT_EQ(625,obj.get_solution());
}

TEST(Aritmetic,cant_calculate_two_brackets)
{
    string str="()+()";
    ASSERT_ANY_THROW(Polish_entry obj(str));
}

TEST(Aritmetic,can_calculate_two_exaltation)
{
    string str="2^(2^3)";
    Polish_entry obj(str);
    EXPECT_EQ(64,obj.get_solution());
}