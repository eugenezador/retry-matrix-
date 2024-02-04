#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() noexcept {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  this->MemoryAllocation();
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->MemoryAllocation();
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  matrix_ = other.matrix_;
  rows_ = other.rows_;
  cols_ = other.cols_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
}

// operators
S21Matrix& S21Matrix::operator+(const S21Matrix& other) {
  if (!isEqMatrixSize(*this, other)) {
    throw std::invalid_argument("Different matrix dimensions");
  } else {
    this->SumMatrix(other);
    return *this;
  }
}

S21Matrix& S21Matrix::operator-(const S21Matrix& other) {
  if (!isEqMatrixSize(*this, other)) {
    throw std::invalid_argument("Different matrix dimensions");
  } else {
    this->SubMatrix(other);
    return *this;
  }
}

S21Matrix& S21Matrix::operator*(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("Wrong size for multiplication");
  } else {
    this->MulMatrix(other);
    return *this;
  }
}

S21Matrix& S21Matrix::operator*(const double num) {
  this->MulNumber(num);
  return *this;
}

double& S21Matrix::operator()(int row, int col) {
  if (row < 1 || col < 1 || row > rows_ || col > cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return this->matrix_[row - 1][col - 1];
}

bool S21Matrix::operator==(const S21Matrix& other) {
  return this->EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this->rows_ == other.rows_ || this->cols_ == other.cols_) {
    this->SetRows(other.rows_);
    this->SetCols(other.cols_);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        this->matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  if (!isEqMatrixSize(*this, other)) {
    throw std::invalid_argument("Different matrix dimensions");
  } else {
    this->SumMatrix(other);
    return *this;
  }
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  if (!isEqMatrixSize(*this, other)) {
    throw std::invalid_argument("Different matrix dimensions");
  } else {
    this->SubMatrix(other);
    return *this;
  }
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("Wrong size for multiplication");
  } else {
    this->MulMatrix(other);
    return *this;
  }
}

S21Matrix& S21Matrix::operator*=(const double& num) {
  this->MulNumber(num);
  return *this;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool is_eq = true;
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      if (isDiff(this->matrix_[i][j], other.matrix_[i][j])) {
        is_eq = false;
      }
    }
  }
  return is_eq;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (!isEqMatrixSize(*this, other)) {
    throw std::invalid_argument("Different matrix dimensions");
  } else {
    for (int i = 0; i < other.rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        this->matrix_[i][j] += other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (!isEqMatrixSize(*this, other)) {
    throw std::invalid_argument("Different matrix dimensions");
  } else {
    for (int i = 0; i < other.rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        this->matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("Wrong matrix size for multiplication");
  } else {
    S21Matrix copy(*this);
    for (int i = 0; i < copy.rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        this->matrix_[i][j] = 0;
        for (int k = 0; k < other.rows_; k++) {
          this->matrix_[i][j] += copy.matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::invalid_argument("Not square matrix");
  } else {
    S21Matrix result(this->rows_, this->cols_);
    if (this->rows_ == 1) {
      result.matrix_[0][0] = this->matrix_[0][0];
    } else {
      for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->cols_; j++) {
          S21Matrix minor = this->GetMinor(i, j);

          result.matrix_[i][j] = pow(-1, i + j) * minor.Determinant();
        }
      }
    }
    return result;
  }
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::invalid_argument("Not square matrix");
  } else {
    double det = 0;
    S21Matrix minor(this->rows_ - 1, this->cols_ - 1);
    if (rows_ == 1) {
      det = this->matrix_[0][0];
    } else if (rows_ == 2) {
      det = this->matrix_[0][0] * this->matrix_[1][1] -
            this->matrix_[0][1] * this->matrix_[1][0];
    } else {
      for (int j = 0; j < cols_; ++j) {
        S21Matrix minor = this->GetMinor(0, j);

        det += pow(-1, j) * matrix_[0][j] * minor.Determinant();
      }
    }
    return det;
  }
}

S21Matrix S21Matrix::InverseMatrix() {
  S21Matrix result(this->rows_, this->cols_);
  if (this->rows_ == 1) {
    result.matrix_[0][0] = 1. / this->matrix_[0][0];
  } else {
    double det = this->Determinant();
    if (!isDiff(0, det)) {
      throw std::invalid_argument("Matrix determinant = 0");
    }

    S21Matrix complements = this->CalcComplements();
    S21Matrix transposed = complements.Transpose();
    transposed.MulNumber(1 / det);
    result = transposed;
  }
  return result;
}

void S21Matrix::MemoryAllocation() {
  matrix_ = new double*[rows_];

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
}

bool S21Matrix::isEqMatrixSize(const S21Matrix& A, const S21Matrix& B) {
  return (A.rows_ == B.rows_ && A.cols_ == B.cols_) ? true : false;
}

bool S21Matrix::isDiff(double a, double b) { return fabs(a - b) > 1e-6; }

S21Matrix S21Matrix::GetMinor(int minor_i, int minor_j) {
  int A_i = 0, A_j = 0;
  S21Matrix minor(this->rows_ - 1, this->cols_ - 1);
  for (int i = 0; i < this->rows_ - 1; i++) {
    for (int j = 0; j < this->cols_ - 1; j++) {
      A_i = i;
      if (A_i >= minor_i) A_i++;
      A_j = j;
      if (A_j >= minor_j) A_j++;
      minor.matrix_[i][j] = this->matrix_[A_i][A_j];
    }
  }
  return minor;
}

// void S21Matrix::PrintMatrix() {
//   for (int i = 0; i < rows_; i++) {
//     for (int j = 0; j < cols_; j++) {
//       std::cout << matrix_[i][j] << " ";
//     }
//     std::cout << std::endl;
//   }
// }

void S21Matrix::RemoveMatrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

int S21Matrix::GetRows() noexcept { return rows_; }

void S21Matrix::SetRows(int rows) {
  if (rows < 0) {
    // error
  } else if (rows != rows_) {
    double** new_matrix = new double*[rows];

    for (int i = 0; i < rows; i++) {
      new_matrix[i] = new double[cols_];
      for (int j = 0; j < cols_; j++) {
        new_matrix[i][j] = (i < rows_ && j < cols_) ? matrix_[i][j] : 0;
      }
    }
    RemoveMatrix();
    matrix_ = new_matrix;
    rows_ = rows;
  }
}

int S21Matrix::GetCols() noexcept { return cols_; }

void S21Matrix::SetCols(int cols) {
  if (cols < 0) {
    // error
  } else if (cols != cols_) {
    double** new_matrix = new double*[rows_];

    for (int i = 0; i < rows_; i++) {
      new_matrix[i] = new double[cols];
      for (int j = 0; j < cols; j++) {
        new_matrix[i][j] = (i < rows_ && j < cols_) ? matrix_[i][j] : 0;
      }
    }
    RemoveMatrix();
    matrix_ = new_matrix;
    cols_ = cols;
  }
}