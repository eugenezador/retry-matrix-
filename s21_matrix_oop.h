#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>

#define OK 0
#define WRONG_MATRIX 1
#define WRONG_CALC 2

class S21Matrix {
 public:
  // constructors
  S21Matrix() noexcept;
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // operators
  S21Matrix& operator+(const S21Matrix& other);
  S21Matrix& operator-(const S21Matrix& other);
  S21Matrix& operator*(const S21Matrix& other);
  S21Matrix& operator*(const double num);
  friend S21Matrix operator*(const double num, const S21Matrix& matrix);
  double& operator()(int i, int j);
  bool operator==(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double& num);

  // function
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // helpers
  void MemoryAllocation();
  bool isEqMatrixSize(const S21Matrix& A, const S21Matrix& B);
  bool isDiff(double a, double b);
  S21Matrix GetMinor(int minor_i, int minor_j);
  // void PrintMatrix();
  void RemoveMatrix();

  // assetors moturators
  int GetRows() noexcept;  //   Accessor
  void SetRows(int rows);  // Mutators
  int GetCols() noexcept;  //   Accessor
  void SetCols(int cols);  // Mutators

 private:
  double** matrix_ = nullptr;
  int rows_ = 0;
  int cols_ = 0;
};

#endif  //  SRC_S21_MATRIX_OOP_H_
