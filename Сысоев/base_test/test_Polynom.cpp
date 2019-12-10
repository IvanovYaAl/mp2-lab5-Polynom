
#include <gtest.h>
#include "Polynom.h"
#include "Monom.h"
#include "Polynom.cpp"


TEST(Polynom, can_create_polynom)
{
	ASSERT_NO_THROW(Polynom p);
}

TEST(Polynom, can_create_polynom_from_monom)
{
	Monom k;
	ASSERT_NO_THROW(Polynom p(k));
}

TEST(Polynom, can_add_monom)
{
	Monom k;
	Polynom p;
	ASSERT_NO_THROW(p.add(k));
}

TEST(Polynom, can_return_monom)
{
	Monom p;
	Polynom k(p);
	EXPECT_TRUE(p == k.ReturnMonom());
}

TEST(Polynom, empty_or_not_1)
{
	Polynom p;
	EXPECT_TRUE(p.isEmpty());
}

TEST(Polynom, empty_or_not_2)
{
	Polynom p;
	Monom k(10, 11, 12, 13);
	p.add(k);
	EXPECT_FALSE(p.isEmpty());
}

TEST(Polynom, count_of_monoms)
{
	Monom k(10, 11, 12, 13), l(10, 11, 12, 13);
	Polynom p;
	p.add(k);
	p.add(l);
	EXPECT_EQ(2, p.Count());
}

TEST(Polynom, sum_of_two_polynoms_1)
{
	Monom k(5, 2, 3, 4), l(7, 5, 6, 7);
	Polynom p, lo;
	lo.add(k);
	lo.add(l);
	Polynom* o = new Polynom;
	p.add(k);
	o->add(l);
	EXPECT_TRUE(lo == p.Sum(o));
}

TEST(Polynom, sum_of_two_polynoms_2)
{
	Monom k(5, 2, 3, 4), l(7, 2, 3, 4);
	Polynom p, lo;
	Polynom* o = new Polynom;
	p.add(k);
	o->add(l);
	k.RetFactor(k.GetFactor() + 7);
	lo.add(k);
	EXPECT_TRUE(lo == p.Sum(o));
}

TEST(Polynom, dif_of_two_polynoms_1)
{
	Monom k(5, 2, 3, 4), l(7, 5, 6, 7);
	Polynom p, lo;
	Polynom* o = new Polynom;
	p.add(k);
	o->add(l);
	l.RetFactor(l.GetFactor() * -1);
	lo.add(k);
	lo.add(l);
	EXPECT_TRUE(lo == p.Sub(o));
}

TEST(Polynom, dif_of_two_polynoms_2)
{
	Monom k(5, 2, 3, 4), l(3, 2, 3, 4);
	Polynom p, lo;
	Polynom* o = new Polynom;
	p.add(k);
	o->add(l);
	l.RetFactor(l.GetFactor() - 3);
	lo.add(k);
	EXPECT_TRUE(lo == p.Sub(o));
}

TEST(Polynom, find_result)
{
	Monom k(5, 2, 3, 4);
	Polynom p;
	p.add(k);
	EXPECT_TRUE("2560" == p.FirndResultToString(2, 2, 2));
}

TEST(Polynom, mult_by_num)
{
	Monom k(5, 2, 3, 4);
	Polynom p;
	Polynom* w = new Polynom;
	p.add(k);
	Monom y(15, 2, 3, 4);
	w->add(y);
	p.MultByNum(3);
	EXPECT_TRUE(p == w);
}

TEST(Polynom, proizvod)
{
	Monom k(5, 2, 3, 4), l(20, 2, 3, 3);
	Polynom p;
	Polynom* w = new Polynom;
	p.add(k);
	w->add(l);
	EXPECT_FALSE(p == w);
}

TEST(Polynom, integral)
{
	Monom k(4, 2, 3, 4), l(2, 1, 3, 4);
	Polynom p;
	Polynom* w = new Polynom;
	p.add(k);
	w->add(l);
	EXPECT_FALSE(p == w);
}