#include <iostream>
#include <cstring>

class Array2D
{
	public:
		Array2D(int num_rows, int num_cols);
		Array2D(const Array2D& p);
		~Array2D(void);

		void SetValue(int row, int col, float value);
		float GetValue(int row, int col) const;
		Array2D Add(const Array2D& p);
		Array2D Transpose(void);
		void Print(void);
	
	private:
		float** arrays_ = nullptr;
		int num_rows_ = 0;
		int num_cols_ = 0;
};

Array2D::Array2D(int num_rows, int num_cols)
{
	this->num_rows_ = num_rows;
	this->num_cols_ = num_cols;
	this->arrays_ = new float*[num_rows];
	for (int r = 0; r < num_rows; r++)
	{
		this->arrays_[r] = new float[num_cols];
		memset(this->arrays_[r], 0, sizeof(float) * num_cols);
	}
}

Array2D::Array2D(const Array2D& p)
{
	this->num_rows_ = p.num_rows_;
	this->num_cols_ = p.num_cols_;
	this->arrays_ = new float*[this->num_rows_];
	for (int r = 0; r < num_rows_; r++)
	{
		this->arrays_[r] = new float[this->num_cols_];
		memcpy(this->arrays_[r], p.arrays_[r], sizeof(float) * this->num_cols_);
	}
}

Array2D::~Array2D(void)
{
	if (this->arrays_ == nullptr)
		return ;
	for (int r = 0; r < this->num_rows_; r++)
	{
		delete[] this->arrays_[r];
	}
	delete[] this->arrays_;
}

void Array2D::SetValue(int row, int col, float value)
{
	(this->arrays_[row])[col] = value;
}

float Array2D::GetValue(int row, int col) const
{
	return (this->arrays_[row])[col];
}

Array2D Array2D::Add(const Array2D& p)
{
	Array2D result(this->num_rows_, this->num_cols_);

	for (int r = 0; r < this->num_rows_; r++)
	{
		for (int c = 0; c < this->num_cols_; c++)
		{
			result.SetValue(r, c, this->GetValue(r, c) + p.GetValue(r, c));
		}
	}
	return result;
}

Array2D Array2D::Transpose(void)
{
	Array2D result(this->num_cols_, this->num_rows_);

	for (int r = 0; r < this->num_rows_; r++)
	{
		for (int c = 0; c < this->num_cols_; c++)
		{
			result.SetValue(c, r, this->GetValue(r, c));
		}
	}
	return result;
}

void Array2D::Print(void)
{
	for (int r = 0; r < this->num_rows_; r++)
	{
		for (int c = 0; c < this->num_cols_; c++)
		{
			std::cout << this->GetValue(r, c) << " ";
		}
		std::cout << std::endl;
	}
}