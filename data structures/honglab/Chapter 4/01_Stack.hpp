#include <iostream>
#include <cstring>
#include <cassert>

template <typename T>
class Stack {
	public:
		Stack(int capacity = 1)
		{
			assert(capacity > 0);
			this->capacity_ = capacity;
			this->top_ = -1;
			this->Resize(capacity);
		}

		~Stack()
		{
			if (this->stack_ == nullptr)
				return ;
			delete[] this->stack_;
		}

		void Resize(int new_capacity)
		{
			T* new_stack = new T[new_capacity];
			if (this->stack_ != nullptr)
			{
				// 윽... 여기서 memcpy size를 잘못 입력했었음.
				// top_는 인덱스이므로, 복사할 사이즈는 +1을 해야 함!!! 
				memcpy(new_stack, this->stack_, sizeof(T) * (this->top_ + 1));
				delete[] this->stack_;
			}
			this->stack_ = new_stack;
			this->capacity_ = new_capacity;
		}

		bool IsEmpty(void) const
		{
			return this->top_ < 0;
		}

		int Size(void) const
		{
			return this->top_ >= 0 ? this->top_ + 1 : 0;
		}

		void Print(void) const
		{
			for (int i = 0; i < this->Size(); ++i)
				std::cout << this->stack_[i] << " ";
			std::cout << std::endl;
		}

		void Push(const T& data)
		{
			if (this->Size() >= this->capacity_)
				this->Resize(this->capacity_ * 2);
			
			this->stack_[++this->top_] = data;
		}

		void Pop(void)
		{
			if (this->IsEmpty())
				return ;
			// 주로 기본 자료형을 사용하므로 소멸자를 호출할 필요가 없지만,
			// 사용자 정의 자료형을 사용할 경우 소멸자를 호출해야 한다.
			// this->stack_[top].~T();

			this->top_ -= 1;
		}

		T& Top(void) const
		{
			assert(this->top_ >= 0);
			return this->stack_[this->top_];
		}
	
	private:
		T* stack_ = nullptr;
		int top_ = -1;
		int capacity_ = -1;
};

// 템플릿을 사용한 경우에 생성자를 클래스 선언 밖에서 정의하는 방법??
