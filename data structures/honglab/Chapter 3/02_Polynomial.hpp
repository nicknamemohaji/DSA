#include <iostream>
#include <cstring>
#include <math.h>

class Polynomial
{
    public:
        Polynomial(int max_degree = 100);
        Polynomial(const Polynomial& poly);
        ~Polynomial(void);

        int MaxDegree(void);
        void NewTerm(const float coef, const int exp);
        Polynomial Add(Polynomial poly);
        Polynomial Mult(Polynomial poly);

        float Eval(float x);
        void Print(void);
    
    private:
        int capacity_ = 0;
        float* coeffs_ = nullptr;
};

Polynomial::Polynomial(int max_degree)
{
    this->capacity_ = max_degree + 1;
    this->coeffs_ = new float[this->capacity_];

    for (int i = 0; i < this->capacity_; i++)
        this->coeffs_[i] = 0.0f;
}

Polynomial::Polynomial(const Polynomial& poly)
{
    this->capacity_ = poly.capacity_;
    this->coeffs_ = new float[this->capacity_];
    for (int i = 0; i < this->capacity_; i++)
        coeffs_[i] = poly.coeffs_[i];
}

Polynomial::~Polynomial(void)
{
    if (this->coeffs_ == nullptr)
        return ;
    delete[] this->coeffs_;
}

int Polynomial::MaxDegree(void)
{
    return this->capacity_ - 1;
}

void Polynomial::NewTerm(const float coef, const int exp)
{
    this->coeffs_[exp] = coef;
}

void Polynomial::Print(void)
{
    bool is_first = true;

    for (int i = 0; i < this->capacity_; i++)
    {
        if (this->coeffs_[i] == 0.0f)
            continue ;
        
        if (!is_first)
            std::cout << " + ";
        is_first = false;

        std::cout << this->coeffs_[i];
        if (i != 0)
            std::cout << " * x^" << i;      
    }
    std::cout << std::endl;
}

float Polynomial::Eval(float x)
{
    float result = 0.0f;

    for (int i = 0; i < this->capacity_; i++)
        result += this->coeffs_[i] * (float) std::pow(x, (float) i);

    return result;
}

Polynomial Polynomial::Add(Polynomial poly)
{
	// 문제에서는 두 다항식의 최대 차수가 같다고 가정했지만 그렇지 않은 경우도 고려
    Polynomial result(this->capacity_ > poly.capacity_ ? this->capacity_ : poly.capacity_);

    for (int i = 0; i < this->capacity_; i++)
        result.NewTerm(this->coeffs_[i], i);
    for (int i = 0; i < poly.capacity_; i++)
        result.NewTerm(poly.coeffs_[i], i);

    return result;
}

Polynomial Polynomial::Mult(Polynomial poly)
{
    Polynomial result(this->capacity_ > poly.capacity_ ? this->capacity_ : poly.capacity_);

	for (int i = 0; i < this->capacity_; i++)
	{
		if (this->coeffs_[i] == 0.0f)
			continue ;
		for (int j = 0; j < poly.capacity_; j++)
		{
			if (poly.coeffs_[j] == 0.0f || i + j >= result.capacity_)
				continue ;
			result.coeffs_[i + j] += this->coeffs_[i] * poly.coeffs_[j];
		}
	}

	return result;
}
