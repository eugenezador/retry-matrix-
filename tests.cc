#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(EqMatrix, test1) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;
  S21Matrix b(3, 3);
  b(1, 1) = 2;
  b(1, 2) = 5;
  b(1, 3) = 7;
  b(2, 1) = 6;
  b(2, 2) = 3;
  b(2, 3) = 4;
  b(3, 1) = 5;
  b(3, 2) = -2;
  b(3, 3) = -3;
  ASSERT_EQ(a.EqMatrix(b), 1);
}

TEST(EqMatrix, test2) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;
  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;
  ASSERT_EQ(a.EqMatrix(b), 0);
}

TEST(EqMatrix, test3) {
  S21Matrix a(3, 3);
  a(1, 1) = 1;
  a(1, 2) = 2;
  a(1, 3) = 3;
  a(2, 1) = 0;
  a(2, 2) = 4;
  a(2, 3) = 2;
  a(3, 1) = 5;
  a(3, 2) = 2;
  a(3, 3) = 1;
  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;
  ASSERT_EQ(a.EqMatrix(b), 1);
}

TEST(EqOperator, test) {
  S21Matrix a(3, 3);
  a(1, 1) = 1;
  a(1, 2) = 2;
  a(1, 3) = 3;
  a(2, 1) = 0;
  a(2, 2) = 4;
  a(2, 3) = 2;
  a(3, 1) = 5;
  a(3, 2) = 2;
  a(3, 3) = 1;
  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;

  ASSERT_EQ((a == b), 1);
}

TEST(SumMatrix, test) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;
  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;
  S21Matrix c(3, 3);
  c(1, 1) = 3;
  c(1, 2) = 7;
  c(1, 3) = 10;
  c(2, 1) = 6;
  c(2, 2) = 7;
  c(2, 3) = 6;
  c(3, 1) = 10;
  c(3, 2) = 0;
  c(3, 3) = -2;
  a.SumMatrix(b);
  ASSERT_EQ(a.EqMatrix(c), 1);
}

TEST(SumOperator, test) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;
  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;
  S21Matrix c(3, 3);
  c(1, 1) = 3;
  c(1, 2) = 7;
  c(1, 3) = 10;
  c(2, 1) = 6;
  c(2, 2) = 7;
  c(2, 3) = 6;
  c(3, 1) = 10;
  c(3, 2) = 0;
  c(3, 3) = -2;
  S21Matrix res = a + b;
  ASSERT_EQ(res.EqMatrix(c), 1);
}

TEST(EqSumOperator, test) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;
  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;
  S21Matrix c(3, 3);
  c(1, 1) = 3;
  c(1, 2) = 7;
  c(1, 3) = 10;
  c(2, 1) = 6;
  c(2, 2) = 7;
  c(2, 3) = 6;
  c(3, 1) = 10;
  c(3, 2) = 0;
  c(3, 3) = -2;
  a += b;
  ASSERT_EQ(a.EqMatrix(c), 1);
}

TEST(SubMatrix, test1) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;
  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;
  S21Matrix c(3, 3);
  c(1, 1) = -1;
  c(1, 2) = -3;
  c(1, 3) = -4;
  c(2, 1) = -6;
  c(2, 2) = 1;
  c(2, 3) = -2;
  c(3, 1) = 0;
  c(3, 2) = 4;
  c(3, 3) = 4;
  b.SubMatrix(a);
  ASSERT_EQ(b.EqMatrix(c), 1);
}

TEST(SubOperator, test) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;
  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;
  S21Matrix c(3, 3);
  c(1, 1) = -1;
  c(1, 2) = -3;
  c(1, 3) = -4;
  c(2, 1) = -6;
  c(2, 2) = 1;
  c(2, 3) = -2;
  c(3, 1) = 0;
  c(3, 2) = 4;
  c(3, 3) = 4;
  S21Matrix res = b - a;
  ASSERT_EQ(res.EqMatrix(c), 1);
}

TEST(EqSubOperator, test) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;
  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;
  S21Matrix c(3, 3);
  c(1, 1) = -1;
  c(1, 2) = -3;
  c(1, 3) = -4;
  c(2, 1) = -6;
  c(2, 2) = 1;
  c(2, 3) = -2;
  c(3, 1) = 0;
  c(3, 2) = 4;
  c(3, 3) = 4;
  b -= a;
  ASSERT_EQ(b.EqMatrix(c), 1);
}

TEST(SubMatrix, test2) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;
  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;
  S21Matrix c(3, 3);
  c(1, 1) = 1;
  c(1, 2) = 3;
  c(1, 3) = 4;
  c(2, 1) = 6;
  c(2, 2) = -1;
  c(2, 3) = 2;
  c(3, 1) = 0;
  c(3, 2) = -4;
  c(3, 3) = -4;
  a.SubMatrix(b);
  ASSERT_EQ(a.EqMatrix(c), 1);
}

TEST(MulMatrix, test1) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;

  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;
  S21Matrix c(3, 3);
  c(1, 1) = 37;
  c(1, 2) = 38;
  c(1, 3) = 23;
  c(2, 1) = 26;
  c(2, 2) = 32;
  c(2, 3) = 28;
  c(3, 1) = -10;
  c(3, 2) = -4;
  c(3, 3) = 8;
  a.MulMatrix(b);

  ASSERT_EQ(a.EqMatrix(c), 1);
}

TEST(MulOperator, test1) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;

  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;
  S21Matrix c(3, 3);
  c(1, 1) = 37;
  c(1, 2) = 38;
  c(1, 3) = 23;
  c(2, 1) = 26;
  c(2, 2) = 32;
  c(2, 3) = 28;
  c(3, 1) = -10;
  c(3, 2) = -4;
  c(3, 3) = 8;
  // a.MulMatrix(b);
  S21Matrix res = a * b;

  ASSERT_EQ(res.EqMatrix(c), 1);
}

TEST(EqMulOperator, test1) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;

  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;
  S21Matrix c(3, 3);
  c(1, 1) = 37;
  c(1, 2) = 38;
  c(1, 3) = 23;
  c(2, 1) = 26;
  c(2, 2) = 32;
  c(2, 3) = 28;
  c(3, 1) = -10;
  c(3, 2) = -4;
  c(3, 3) = 8;
  a *= b;

  ASSERT_EQ(a.EqMatrix(c), 1);
}

TEST(MulMatrix, test2) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;

  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;
  S21Matrix c(3, 3);
  c(1, 1) = 29;
  c(1, 2) = 5;
  c(1, 3) = 6;
  c(2, 1) = 34;
  c(2, 2) = 8;
  c(2, 3) = 10;
  c(3, 1) = 27;
  c(3, 2) = 29;
  c(3, 3) = 40;
  b.MulMatrix(a);

  ASSERT_EQ(b.EqMatrix(c), 1);
}

TEST(MulMatrix, test3) {
  S21Matrix a(2, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;

  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;
  S21Matrix c(2, 3);
  c(1, 1) = 37;
  c(1, 2) = 38;
  c(1, 3) = 23;
  c(2, 1) = 26;
  c(2, 2) = 32;
  c(2, 3) = 28;

  a.MulMatrix(b);

  ASSERT_EQ(a.EqMatrix(c), 1);
}

TEST(MulNumber, test1) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;

  double number = 7;

  S21Matrix c(3, 3);
  c(1, 1) = 14;
  c(1, 2) = 35;
  c(1, 3) = 49;
  c(2, 1) = 42;
  c(2, 2) = 21;
  c(2, 3) = 28;
  c(3, 1) = 35;
  c(3, 2) = -14;
  c(3, 3) = -21;
  a.MulNumber(number);

  ASSERT_EQ(a.EqMatrix(c), 1);
}

TEST(MulNumber, test2) {
  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;

  double number = -6;

  S21Matrix c(3, 3);
  c(1, 1) = -6;
  c(1, 2) = -12;
  c(1, 3) = -18;
  c(2, 1) = 0;
  c(2, 2) = -24;
  c(2, 3) = -12;
  c(3, 1) = -30;
  c(3, 2) = -12;
  c(3, 3) = -6;

  b.MulNumber(number);
  ASSERT_EQ(b.EqMatrix(c), 1);
}

TEST(MulNumberOperator, test) {
  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;

  double number = -6;

  S21Matrix c(3, 3);
  c(1, 1) = -6;
  c(1, 2) = -12;
  c(1, 3) = -18;
  c(2, 1) = 0;
  c(2, 2) = -24;
  c(2, 3) = -12;
  c(3, 1) = -30;
  c(3, 2) = -12;
  c(3, 3) = -6;

  S21Matrix res = b * number;
  ASSERT_EQ(res.EqMatrix(c), 1);
}

TEST(EqMulNumberOperator, test) {
  S21Matrix b(3, 3);
  b(1, 1) = 1;
  b(1, 2) = 2;
  b(1, 3) = 3;
  b(2, 1) = 0;
  b(2, 2) = 4;
  b(2, 3) = 2;
  b(3, 1) = 5;
  b(3, 2) = 2;
  b(3, 3) = 1;

  double number = -6;

  S21Matrix c(3, 3);
  c(1, 1) = -6;
  c(1, 2) = -12;
  c(1, 3) = -18;
  c(2, 1) = 0;
  c(2, 2) = -24;
  c(2, 3) = -12;
  c(3, 1) = -30;
  c(3, 2) = -12;
  c(3, 3) = -6;

  b *= number;
  ASSERT_EQ(b.EqMatrix(c), 1);
}

TEST(Transpose, test1) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;

  S21Matrix c(3, 3);
  c(1, 1) = 2;
  c(1, 2) = 6;
  c(1, 3) = 5;
  c(2, 1) = 5;
  c(2, 2) = 3;
  c(2, 3) = -2;
  c(3, 1) = 7;
  c(3, 2) = 4;
  c(3, 3) = -3;

  S21Matrix b(3, 3);

  b = a.Transpose();

  ASSERT_EQ(b.EqMatrix(c), 1);
}

TEST(Transpose, test2) {
  S21Matrix a(3, 3);
  a(1, 1) = 1;
  a(1, 2) = 2;
  a(1, 3) = 3;
  a(2, 1) = 0;
  a(2, 2) = 4;
  a(2, 3) = 2;
  a(3, 1) = 5;
  a(3, 2) = 2;
  a(3, 3) = 1;

  S21Matrix c(3, 3);
  c(1, 1) = 1;
  c(1, 2) = 0;
  c(1, 3) = 5;
  c(2, 1) = 2;
  c(2, 2) = 4;
  c(2, 3) = 2;
  c(3, 1) = 3;
  c(3, 2) = 2;
  c(3, 3) = 1;

  S21Matrix b(3, 3);

  b = a.Transpose();

  ASSERT_EQ(b.EqMatrix(c), 1);
}

TEST(CalcComplements, test1) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;

  S21Matrix c(3, 3);
  c(1, 1) = -1;
  c(1, 2) = 38;
  c(1, 3) = -27;
  c(2, 1) = 1;
  c(2, 2) = -41;
  c(2, 3) = 29;
  c(3, 1) = -1;
  c(3, 2) = 34;
  c(3, 3) = -24;

  S21Matrix b(3, 3);

  b = a.CalcComplements();

  ASSERT_EQ(b.EqMatrix(c), 1);
}

TEST(CalcComplements, test2) {
  S21Matrix a(3, 3);
  a(1, 1) = 1;
  a(1, 2) = 2;
  a(1, 3) = 3;
  a(2, 1) = 0;
  a(2, 2) = 4;
  a(2, 3) = 2;
  a(3, 1) = 5;
  a(3, 2) = 2;
  a(3, 3) = 1;

  S21Matrix c(3, 3);
  c(1, 1) = 0;
  c(1, 2) = 10;
  c(1, 3) = -20;
  c(2, 1) = 4;
  c(2, 2) = -14;
  c(2, 3) = 8;
  c(3, 1) = -8;
  c(3, 2) = -2;
  c(3, 3) = 4;

  S21Matrix b(3, 3);

  b = a.CalcComplements();

  ASSERT_EQ(b.EqMatrix(c), 1);
}

TEST(CalcComplements, test3) {
  S21Matrix a(1, 1);
  a(1, 1) = 10;

  S21Matrix c(1, 1);
  c(1, 1) = 10;

  S21Matrix b(1, 1);

  b = a.CalcComplements();

  ASSERT_EQ(b.EqMatrix(c), 1);
}

TEST(Determinant, test1) {
  S21Matrix a(2, 2);
  a(1, 1) = 1;
  a(1, 2) = 2;
  a(2, 1) = 3;
  a(2, 2) = 4;
  ASSERT_EQ(a.Determinant(), -2);
}

TEST(Determinant, test2) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;
  ASSERT_EQ(a.Determinant(), -1);
}

TEST(Determinant, test3) {
  S21Matrix a(3, 3);
  a(1, 1) = 1;
  a(1, 2) = 2;
  a(1, 3) = 3;
  a(2, 1) = 0;
  a(2, 2) = 4;
  a(2, 3) = 2;
  a(3, 1) = 5;
  a(3, 2) = 2;
  a(3, 3) = 1;
  ASSERT_EQ(a.Determinant(), -40);
}

TEST(Determinant, test4) {
  S21Matrix a(1, 1);
  a(1, 1) = 5;

  ASSERT_EQ(a.Determinant(), 5);
}

TEST(InverseMatrix, test1) {
  S21Matrix a(3, 3);
  a(1, 1) = 2;
  a(1, 2) = 5;
  a(1, 3) = 7;
  a(2, 1) = 6;
  a(2, 2) = 3;
  a(2, 3) = 4;
  a(3, 1) = 5;
  a(3, 2) = -2;
  a(3, 3) = -3;

  S21Matrix c(3, 3);
  c(1, 1) = 1;
  c(1, 2) = -1;
  c(1, 3) = 1;
  c(2, 1) = -38;
  c(2, 2) = 41;
  c(2, 3) = -34;
  c(3, 1) = 27;
  c(3, 2) = -29;
  c(3, 3) = 24;

  S21Matrix b = a.InverseMatrix();

  ASSERT_EQ(b.EqMatrix(c), 1);
}

TEST(InverseMatrix, test2) {
  S21Matrix a(3, 3);
  a(1, 1) = 1;
  a(1, 2) = 2;
  a(1, 3) = 3;
  a(2, 1) = 0;
  a(2, 2) = 4;
  a(2, 3) = 2;
  a(3, 1) = 5;
  a(3, 2) = 2;
  a(3, 3) = 1;

  S21Matrix c(3, 3);
  c(1, 1) = 0;
  c(1, 2) = -0.1;
  c(1, 3) = 0.2;
  c(2, 1) = -0.25;
  c(2, 2) = 0.35;
  c(2, 3) = 0.05;
  c(3, 1) = 0.5;
  c(3, 2) = -0.2;
  c(3, 3) = -0.1;

  S21Matrix b(3, 3);

  b = a.InverseMatrix();

  ASSERT_EQ(b.EqMatrix(c), 1);
}

TEST(InverseMatrix, test3) {
  S21Matrix a(1, 1);
  a(1, 1) = 4;

  S21Matrix c(1, 1);
  c(1, 1) = 1 / 4;

  S21Matrix b(1, 1);

  b = a.InverseMatrix();

  ASSERT_EQ(b.EqMatrix(c), 1);
}

TEST(AccessorForRows, test1) {
  S21Matrix a(2, 2);

  ASSERT_EQ(a.GetRows(), 2);
}

TEST(AccessorForRows, test2) {
  S21Matrix a(4, 2);

  ASSERT_EQ(a.GetRows(), 4);
}

TEST(AccessorForCols, test1) {
  S21Matrix a(2, 2);

  ASSERT_EQ(a.GetCols(), 2);
}

TEST(AccessorForCols, test2) {
  S21Matrix a(2, 4);

  ASSERT_EQ(a.GetCols(), 4);
}

TEST(MutatorForRows, test1) {
  S21Matrix a(2, 3);
  a.SetRows(4);
  ASSERT_EQ(a.GetRows(), 4);
}

TEST(MutatorForRows, test2) {
  S21Matrix a(5, 2);
  a.SetRows(3);

  ASSERT_EQ(a.GetRows(), 3);
}

TEST(MutatorForRows, test3) {
  S21Matrix a(5, 2);
  a.SetRows(3);

  ASSERT_EQ(a.GetCols(), 2);
}

TEST(MutatorForCols, test1) {
  S21Matrix a(2, 3);
  a.SetCols(4);

  ASSERT_EQ(a.GetCols(), 4);
}

TEST(MutatorForCols, test2) {
  S21Matrix a(5, 5);
  a.SetCols(3);

  ASSERT_EQ(a.GetCols(), 3);
}

TEST(MutatorForCols, test3) {
  S21Matrix a(4, 5);
  a.SetCols(3);

  ASSERT_EQ(a.GetRows(), 4);
}

TEST(Mutators, test1) {
  S21Matrix a;
  a.SetCols(3);
  a.SetRows(4);

  ASSERT_EQ(a.GetRows(), 4);
}

TEST(Mutators, test2) {
  S21Matrix a;
  a.SetCols(3);
  a.SetRows(4);

  ASSERT_EQ(a.GetCols(), 3);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
