#include <iostream>
#include <cstring>

struct MatrixTerm
{
	int row;
	int col;
	float value;
};

class SparseMatrix
{
	public:
		SparseMatrix(int num_rows, int num_cols, int capacity);
		SparseMatrix(const SparseMatrix& p);
		~SparseMatrix(void);

		void SetValue(int row, int col, float value);
		float GetValue(int row, int col) const;
		SparseMatrix Transpose(void);

		void PrintTerms(void) const;
		void Print(void) const;
	private:
		MatrixTerm* terms_ = nullptr;
		int num_rows_ = 0;
		int num_cols_ = 0;
		int capacity_ = 0;
		int num_terms_ = 0;
};

SparseMatrix::SparseMatrix(int num_rows, int num_cols, int capacity)
{
	this->num_rows_ = num_rows;
	this->num_cols_ = num_cols;
	this->capacity_ = capacity;
	this->num_terms_ = 0;

	// num_terms_ 변수로 실제 사용중인 인덱스를 관리하므로 초기화가 필요 없음
	this->terms_ = new MatrixTerm[capacity];
}

SparseMatrix::SparseMatrix(const SparseMatrix& p)
{
	if (p.capacity_ <= 0)
		return ;
	
	this->num_rows_ = p.num_rows_;
	this->num_cols_ = p.num_cols_;
	this->capacity_ = p.capacity_;
	this->num_terms_ = p.num_terms_;

	this->terms_ = new MatrixTerm[this->capacity_];
	memcpy(this->terms_, p.terms_, sizeof(MatrixTerm) * this->num_terms_);
}

SparseMatrix::~SparseMatrix(void)
{
	if (this->terms_ == nullptr)
		return ;
	delete[] this->terms_;
}

void SparseMatrix::SetValue(int row, int col, float value)
{
	// 희소 행렬은 0이 아닌 값만 저장
	// ??? 이미 저장된 값을 0으로 세팅하는 경우는 ????? 
	if (value == 0.0f)
		return ;

	if (this->num_terms_ + 1 >= this->capacity_)
	{
		// 행렬을 확장
		MatrixTerm* new_terms = new MatrixTerm[this->capacity_ * 2];
		memcpy(new_terms, this->terms_, sizeof(MatrixTerm) * this->num_terms_);
		this->capacity_ = this->capacity_ * 2;
	}

	// 정렬된 상태를 유지하며 값을 설정. insertion sort의 방법 사용
	// 1. 위치를 찾고...
	const int target_index = row * this->num_cols_ + col;
	int i = 0;
	while (i < this->num_terms_)
	{
		const int current_index = this->terms_[i].row * this->num_cols_ + this->terms_[i].col;
		// 이미 값이 있는 경우 num_terms를 변경하면 안됨. 값을 변경하고 함수 종료
		if (current_index == target_index)
		{
			this->terms_[i].value = value;
			return ;
		}
		// 현재 위치가 타겟 위치보다 크면 break
		if (current_index > target_index)
			break ;
		i++;
	}
	// 2. 값을 민 다음
	// (가장 끝에 추가하는 경우는 이 과정을 생략)
	if (i < this->num_terms_)
	{
		for (int j = this->num_terms_; j > i; j--)
			this->terms_[j] = this->terms_[j - 1];
	}
	// 3. 삽입
	this->terms_[i].value = value;
	this->num_terms_++;
}

float SparseMatrix::GetValue(int row, int col) const
{
	// 저장된 값들은 정렬된 상태이므로, 이진 탐색을 사용
	const int target_index = row * this->num_cols_ + col;
	int left = 0;
	int right = this->num_terms_ - 1;
	while (left <= right)
	{
		const int mid = (left + right) / 2;
		const int current_index = this->terms_[mid].row * this->num_cols_ + this->terms_[mid].col;
		if (current_index == target_index)
			return this->terms_[mid].value;
		else if (current_index < target_index)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return 0.0f;
}

SparseMatrix SparseMatrix::Transpose(void)
{
	SparseMatrix result(this->num_cols_, this->num_rows_, this->capacity_);
	for (int i = 0; i < this->num_terms_; i++)
	{
		// 정렬된 상태를 유지하려면 SetValue를 사용해야 함..
		result.SetValue(this->terms_[i].col, this->terms_[i].row, this->terms_[i].value);
	}
	return result;
}

void SparseMatrix::PrintTerms(void) const
{
	for (int i = 0; i < this->num_terms_; i++)
	{
		std::cout << "(" << this->terms_[i].row << ", "
			<< this->terms_[i].col << ", " << this->terms_[i].value << ")";
		std::cout << std::endl;
	}
}

void SparseMatrix::Print(void) const
{
	for (int r = 0; r < this->num_rows_; r++)
	{
		for (int c = 0; c < this->num_cols_; c++)
			std::cout << this->GetValue(r, c) << " ";
		std::cout << std::endl;
	}
}
