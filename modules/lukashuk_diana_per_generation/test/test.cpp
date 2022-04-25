// Copyright 2022 Lukashuk Diana

#include <gtest/gtest.h>

#include "include/din_mas.h"
#include "include/per_generation.h"

TEST(Diana_Test_of_array, Array_const_push_back) {
  // Arrange
  // Act
  dinmas a(0);
  dinmas v();
  a.push_back(10);
  a.push_back(2);
  // Assert , a[1]
  EXPECT_EQ(a.size() == 2, 1);
  EXPECT_EQ(a[0] == 10, 1);
  EXPECT_EQ(a[1] == 2, 1);
}

TEST(Diana_Test_of_array, Array_resize1) {
  dinmas a(0), b(1), c(2), d(3);
  a.resize(1);
  b.resize(1);
  c.resize(2);
  d.resize(3);
  EXPECT_EQ(a.size() == 1, 1);
  EXPECT_EQ(b.size() == 1, 1);
  EXPECT_EQ(c.size() == 2, 1);
  EXPECT_EQ(d.size() == 3, 1);
}

TEST(Diana_Test_of_array, Array_brackets) {
  dinmas a(0);
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a[0] = 0;
  a[1] = a[1] - 1;
  EXPECT_EQ(a[0] == 0, 1);
  EXPECT_EQ(a[1] == 1, 1);
  EXPECT_EQ(a[2] == 3, 1);
}

TEST(Diana_Test_of_array, Array_equalsand_equality) {
  dinmas a(0), c(2);
  dinmas b(0);
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  b = a;
  c = a;
  EXPECT_EQ(a == b, 1);
  EXPECT_EQ(a == c, 1);
}

TEST(Diana_Test_of_array, Array_delete_element) {
  dinmas a(0), c(0);
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.del_elem(0);

  c.del_elem(0);
  c.del_elem(10);
  EXPECT_EQ(a[0] == 2, 1);
  EXPECT_EQ(a[1] == 3, 1);
  EXPECT_EQ(a.size() == 2, 1);

  EXPECT_EQ(c.size() == 0, 1);
}

TEST(Diana_Test_of_array, Array_delete_element_zn) {
  dinmas a(0), c(0);
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);

  a.del_elem_zn(0);
  a.del_elem_zn(2);

  EXPECT_EQ(a[0] == 1, 1);
  EXPECT_EQ(a[1] == 3, 1);
  EXPECT_EQ(a.size() == 2, 1);
}

TEST(Diana_Test_of_array, Array_min_element) {
  dinmas a(0), c(0);
  a.push_back(1);
  a.push_back(1);
  a.push_back(2);

  EXPECT_EQ(a.min_elem(), 1);
  EXPECT_EQ(c.min_elem(), 0);
  a.del_elem(1);
  a.del_elem(0);
  EXPECT_EQ(a.min_elem(), 2);
}

TEST(Diana_Test_of_array, Array_have_element) {
  dinmas a(0), c(0);
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);

  EXPECT_EQ(a.have_this_el(1), 1);
  EXPECT_EQ(a.have_this_el(0), 0);
  EXPECT_EQ(c.have_this_el(0), 0);
}

TEST(Test_of_PerGeneration, chekc_const_and_size_pair) {
  dinmas a(0);
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  PerGeneration pg(a);

  dinmas b;
  b.push_back(0);
  b.push_back(0);
  b.push_back(2);
  b.push_back(2);

  dinmas c(0);

  PerGeneration pgb(b);
  PerGeneration pgc(c);
  PerGeneration pgd;

  EXPECT_EQ(pg.get_size_pair(), 6);
  EXPECT_EQ(pgb.get_size_pair(), 6);
  EXPECT_EQ(pgc.get_size_pair(), 0);
  EXPECT_EQ(pgd.get_size_pair(), 0);
}

TEST(Test_of_PerGeneration, have_in_res) {
  dinmas a(0);
  a.push_back(0);
  a.push_back(1);
  PerGeneration pg(a);
  pg.PG_work();
  dinmas a1;
  a1.push_back(1);
  a1.push_back(0);
  EXPECT_EQ(pg.have_in_res(a), 1);
  EXPECT_EQ(pg.have_in_res(a1), 1);
}

TEST(Test_of_PerGeneration, PG_work_1) {
  dinmas a(0);
  a.push_back(0);
  a.push_back(1);
  PerGeneration pg(a);

  pg.PG_work();

  dinmas res[2];
  res[0].push_back(0);
  res[0].push_back(1);
  res[1].push_back(1);
  res[1].push_back(0);

  EXPECT_EQ(pg.get_size_pair(), 2);
  EXPECT_EQ(pg.have_in_res(res[0]), 1);
  EXPECT_EQ(pg.have_in_res(res[1]), 1);
}

TEST(Test_of_PerGeneration, PG_work_2) {
  dinmas a(0);
  PerGeneration pg(a);

  pg.PG_work();
  dinmas res;
  EXPECT_EQ(pg.get_size_pair(), 0);
  EXPECT_EQ(pg.have_in_res(res), 0);
}

TEST(Test_of_PerGeneration, PG_const_cop) {
  dinmas a(0);
  ASSERT_NO_THROW(PerGeneration(PerGeneration(a)));
}
