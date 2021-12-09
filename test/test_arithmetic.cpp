#include <gtest/gtest.h>
#include "arithmetic.h"

TEST(Arithmetic,can_check_brackets)
{
	std::string s = "((a*b(5+a)))";
	EXPECT_TRUE(checkBrackets(s));
}

TEST(Arithmetic,can_check_fail_brackets)
{
	std::string s = "(a+b";
	EXPECT_FALSE(checkBrackets(s));
}

TEST(Arithmetic,can_detect_type)
{
	std::string s = "5*a+7,5";
	int type[7];
	for (int i = 0; i < 7; i++)
	{
		type[i]=DType(s[i]);
	}
	EXPECT_EQ(1,type[0]);
	EXPECT_EQ(3,type[1]);
	EXPECT_EQ(2,type[2]);
	EXPECT_EQ(3,type[3]);
	EXPECT_EQ(1,type[4]);
	EXPECT_EQ(4,type[5]);
}

TEST(Arithmetic,check_lack_of_operands)
{
	std::string s = "a-";
	EXPECT_FALSE(checkOperands(s));
}

TEST(Arithmetic,can_detect_prioritet)
{
	std::string s = "51*a+b";
	int pr1 ,pr2;
	pr1 = priority(s[2]);
	pr2 = priority(s[4]);
	EXPECT_EQ(3, pr1);
	EXPECT_EQ(2, pr2);
}

TEST(Arithmetic,can_chek_oper)
{
	std::string s = "5++a";
	EXPECT_FALSE(checkOper(s));
}

TEST(Arithmetic,check_all_is_true)
{
	char s[]="(a+b)";
	EXPECT_TRUE(checkAll(s));
}

TEST(Arithmetic,check_all_is_false)
{
	std::string s = "a+b-";
	EXPECT_FALSE(checkAll(s));
}

TEST(Arithmetic,check_comma_in_point){
	std::string s = "7.5+4";
	inPoint(s);
	EXPECT_EQ(s[1], '.');
}

TEST(Arithmetic,check_operand_is_false){
	std::string s = "а+г";
	EXPECT_FALSE(operand_true_1(s));
}

TEST(Arithmetic,check_operand_is_true){
	std::string s = "a+b";
	EXPECT_TRUE(operand_true_1(s));
}

TEST(Arithmetic,check_unarn_minus_1_is_true){
	std::string s = "-a+b";
	EXPECT_TRUE(checkUnarMinus(s));
}

TEST(Arithmetic,check_unarn_minus_2_is_true){
	std::string s = "a*(-b)";
	EXPECT_TRUE(checkUnarMinus(s));
}

TEST(Arithmetic,check_unarn_minus_3_is_true){
	std::string s = "-a-b";
	EXPECT_TRUE(checkUnarMinus(s));
}
