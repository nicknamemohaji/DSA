#include <iostream>
#include <cstring>
#include <math.h>

struct Term
{
	float coef;
	int exp;
};

class SparsePolynomial
{
	public:
		SparsePolynomial(void);
		SparsePolynomial(const SparsePolynomial& poly);
		~SparsePolynomial(void);

		void NewTerm(float coef, int exp);
		float Eval(float x);
		SparsePolynomial Add(const SparsePolynomial& poly);
		
		void Print();
	private:
		int capacity_ = 0;
		int num_terms_ = 0;
		Term* terms_ = nullptr;
};

SparsePolynomial::SparsePolynomial()
{
	this->capacity_ = 0;
	this->num_terms_ = 0;
	this->terms_ = nullptr;
}

SparsePolynomial::SparsePolynomial(const SparsePolynomial& poly)
{
	this->capacity_ = poly.capacity_;
	this->num_terms_ = poly.num_terms_;
	this->terms_ = new Term[this->capacity_];
	memcpy(this->terms_, poly.terms_, sizeof(Term) * this->num_terms_);
}

SparsePolynomial::~SparsePolynomial()
{
	if (this->terms_ == nullptr)
		return ;
	delete[] this->terms_;
}

void SparsePolynomial::NewTerm(float coef, int exp)
{
	if (coef == 0)
		return ;
	if (this->num_terms_ > this->capacity_)
	{
		/*
		메모리를 추가로 할당할 때, 할당하는 크기와 실행시간은 관련이 없다.
		즉, 메모리 할당 작업과 복사 작업을 몇 번이나 호출하는지가 중요하다.

		2배씩 capacity를 늘리는 작업을 한다. 항의 개수 n에 대해, 할당은 O(log n)이지만
		복사는 O(n)이므로, 총 시간복잡도는 O(n)이다.
		*/
		this->capacity_ = this->capacity_ > 0 ? this->capacity_ * 2 : 1;	// 초기 상태에서 capacity가 0이므로 예외처리
		Term* new_terms = new Term[this->capacity_];

		if (this->terms_ != nullptr)
		{
			memcpy(new_terms, this->terms_, sizeof(Term) * this->num_terms_);
			delete[] this->terms_;
		}
		this->terms_ = new_terms;
	}

	this->terms_[this->num_terms_] = {.coef = coef, .exp = exp};
	this->num_terms_ += 1;
}
void SparsePolynomial::Print()
{
	bool is_first = true;

	for (int i = 0; i < this->num_terms_; i++)
	{
		if (!is_first)
			std::cout << " + ";
		is_first = false;

		std::cout << this->terms_[i].coef;
		if (this->terms_[i].exp != 0)
			std::cout << "x^" << this->terms_[i].exp;
	}
	std::cout << std::endl;
}

float SparsePolynomial::Eval(float x)
{
	float result = 0.0f;

	for (int i = 0; i < this->num_terms_; i++)
		result += this->terms_[i].coef * (float) std::pow(x, (float) this->terms_[i].exp);
	return result;
}

SparsePolynomial SparsePolynomial::Add(const SparsePolynomial& poly)
{
	/*
	이 문제의 가정은 다항식이 오름차순으로 정렬되어 있다는 것.
	merge sort의 아이디어를 사용 가능하다. 

	정렬된 자료이므로 O(n ** 2)가 아니라 O(n)으로 해결이 가능하다.
	*/

	SparsePolynomial result;

	int poly_index = 0, this_index = 0;
	while (poly_index < poly.num_terms_ && this_index < this->num_terms_)
	{
		if (poly.terms_[poly_index].exp == this->terms_[this_index].exp)
		{
			/*
			계수의 합이 0인 상황에서 새로운 항을 추가하지 않도록 해야 하지만
			SparsePolynomial::NewTerm의 구현에서 0인 항은 추가하지 않도록 되어 있으므로
			이 부분에서는 신경쓰지 않아도 됨
			*/
			result.NewTerm(
				poly.terms_[poly_index].coef + this->terms_[this_index].coef, 
				poly.terms_[poly_index].exp
			);
			poly_index++;
			this_index++;
		}
		else if (poly.terms_[poly_index].exp > this->terms_[this_index].exp)
		{
			result.NewTerm(
				this->terms_[this_index].coef,
				this->terms_[this_index].exp
			);
			this_index++;
		}
		else
		{
			result.NewTerm(
				poly.terms_[poly_index].coef,
				poly.terms_[poly_index].exp
			);
			poly_index++;
		}
	}

	// 둘 중 하나는 끝까지 갔으니까 나머지를 추가
	for (; poly_index < poly.num_terms_; poly_index++)
		result.NewTerm(
			poly.terms_[poly_index].coef,
			poly.terms_[poly_index].exp
		);
	for (; this_index < this->num_terms_; this_index++)
		result.NewTerm(
			this->terms_[this_index].coef,
			this->terms_[this_index].exp
		);

	return result;
}