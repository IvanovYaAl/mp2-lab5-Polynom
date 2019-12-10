
#include <gtest.h>
#include "Polynom.h"
#include "Monom.h"

TEST(Monom, can_create_monom)
{
	ASSERT_NO_THROW(Monom p);
}

TEST(Monom, can_create_monom_with_numbers)
{
	ASSERT_NO_THROW(Monom p(1, 2, 3, 4));
}

TEST(Monom, get_monom)
{
	Monom p;
	p.GetMonom(5.5, 6, 7, 4);
	Monom k(5.5, 6, 7, 4);
	EXPECT_TRUE(k == p);
}

TEST(Monom, check_unequal)
{
	Monom p;
	Monom k(10, 7, 5, 1);
	EXPECT_FALSE(p == k);
}

TEST(Monom, check_dif)
{
	Monom p;
	p.RetFactor(10);
	Monom k;
	k.RetFactor(10);
	p = p - k;
	EXPECT_TRUE(p.GetFactor() == 0);
}

TEST(Monom, check_ununequal)
{
	Monom p;
	Monom k(1, 2, 4, 5);
	EXPECT_TRUE(p != k);
}

TEST(Monom, can_get_factor)
{
	Monom p(10, 11, 12, 13);
	EXPECT_EQ(10, p.GetFactor());
}
TEST(Monom, can_get_power_x)
{
	Monom p(10, 11, 12, 13);
	EXPECT_EQ(11, p.GetPowerX());
}
TEST(Monom, can_get_power_y)
{
	Monom p(10, 11, 12, 13);
	EXPECT_EQ(12, p.GetPowerY());
}
TEST(Monom, can_get_power_z)
{
	Monom p(10, 11, 12, 13);
	EXPECT_EQ(13, p.GetPowerZ());
}