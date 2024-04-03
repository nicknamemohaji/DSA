#include <iostream>
#include <cstring>
#include <cassert>

class Matrix 
{
	public:
		Matrix(int num_rows, int num_cols);
		Matrix(const Matrix& p);
		~Matrix(void);

		void SetValue(int row, int col, float value);
		float GetValue(int row, int col) const;
		Matrix Add(const Matrix& p);
		Matrix Transpose(void);

		void Print(void);
	
	private:
		int num_rows_ = 0;
		int num_cols_ = 0;
		float* values_ = nullptr;
};

Matrix::Matrix(int num_rows, int num_cols)
{
	this->num_rows_ = num_rows;
	this->num_cols_ = num_cols;
	this->values_ = new float[num_rows * num_cols];
	memset(this->values_, 0, sizeof(float) * (num_rows * num_cols));
}

Matrix::Matrix(const Matrix& p)
{
	this->num_rows_ = p.num_rows_;
	this->num_cols_ = p.num_cols_;
	this->values_ = new float[this->num_rows_ * this->num_cols_];
	memcpy(this->values_, p.values_, sizeof(float) * (this->num_rows_ * this->num_cols_));
}

Matrix::~Matrix(void)
{
	if (this->values_ == nullptr)
		return ;
	delete[] this->values_;
}

void Matrix::SetValue(int row, int col, float value)
{
	this->values_[row * this->num_cols_ + col] = value;
}

float Matrix::GetValue(int row, int col) const	// getter이므로 멤버변수를 바꾸지 않는다는 의미의 const
{
	return this->values_[row * this->num_cols_ + col];
}

Matrix Matrix::Add(const Matrix& p)
{
	assert(this->num_rows_ == p.num_rows_);
	assert(this->num_cols_ == p.num_cols_);

	Matrix result(this->num_rows_, this->num_cols_);

	for (int r = 0; r < this->num_rows_; r++)
	{
		for (int c = 0; c < this->num_cols_; c++)
			result.SetValue(r, c, this->GetValue(r, c) + p.GetValue(r, c));
	}

	return result;
}

Matrix Matrix::Transpose(void)
{
	Matrix result(this->num_cols_, this->num_rows_);

	for (int r = 0; r < this->num_rows_; r++)
	{
		for (int c = 0; c < this->num_cols_; c++)
			result.SetValue(c, r, this->GetValue(r, c));
	}

	return result;
}

void Matrix::Print(void)
{
	for (int r = 0; r < this->num_rows_; r++)
	{
		for (int c = 0; c < this->num_cols_; c++)
			std::cout << this->values_[r * this->num_cols_ + c] << " ";
		std::cout << std::endl;
	}
}

